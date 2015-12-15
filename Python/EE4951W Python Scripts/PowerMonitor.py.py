#==============================================================================================================================================================
# Power Monitor for Battery Powered Devices
# Team Bazargan: Alpha Mbennah, Andre Bounnakhom, Diego Martinez, James Redinger, Ryan Thompson, Ross Harvey
#
# Python Script: Computer GUI for End User
# Description:
#	+ Continuously updating display of min, max, and average values of voltage and current for DUT
#	+ Periodically updating graphs of voltage, current, and power for DUT
#	+ Provisions for self power measurements and graphs are possible but not implemented in this revision
#==============================================================================================================================================================

#========== Start Import Libraries Section ==========
import matplotlib
matplotlib.use("TkAgg")
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg, NavigationToolbar2TkAgg
from matplotlib.figure import Figure
import matplotlib.animation as animation
from matplotlib import style

import tkinter as tk
from tkinter import ttk

import serial, csv, sys, os, time, argparse, binascii	# Import full libraries
import string as string_lib
#========== End Import Libraries Section ==========

#========== Start Define Constants Section ==========
LARGE_FONT=("Verdana",14)
MEDIUM_FONT=("Verdana",12)
style.use("ggplot")
CSV_DATA_FILE = "usb_data.csv"
CSV_LOG_FILE = "usb_log.csv"
CSV_STATS_FILE = "usb_stats.csv"
DATA_MAX = 5000	# This is the max number of packets that can be read for each data update
TIME_MAX = 1	# This is the max number of seconds that is allowed for each data update
UPDATE_DATA_PERIOD = 500	# 0.5 seconds of continuous data before updating stats
UPDATE_GRAPH_PERIOD = 2000	# 2 seconds of continuous data before updating DUT graph
INFINITE_WAIT = 3600000		# 1 hour wait time is essentially infinite
BAUD_RATE = 230400
#========== End Define Constants Section ==========

#========== Start General Functions Section ==========
def enum_ports():		# Enumerate all COM ports and return the list
	ports = ['COM%s' % (i + 1) for i in range(256)]
	result = []
	for port in ports:
		try:	# Try to open a connection on some COM port, if no exception, close the connection and add the port to the list
			s = serial.Serial(port)
			s.close()
			result.append(port)
		except (OSError, serial.SerialException):
			pass
	return result	# Return the list of available ports

#Delete CSV files
if os.path.isfile(CSV_DATA_FILE):
	os.remove(CSV_DATA_FILE)
if os.path.isfile(CSV_LOG_FILE):
	os.remove(CSV_LOG_FILE)
if os.path.isfile(CSV_STATS_FILE):
	os.remove(CSV_STATS_FILE)
	
def reset_data():	# Erase all data in CSV file
	# Erase all contents of csv file to remove old data
	reset_stats()
	try:
		file = open(CSV_DATA_FILE, 'w', newline='')	#open CSV in write mode
		file.close()	#Close CSV
		file = open(CSV_LOG_FILE, 'w', newline='')	#open CSV in write mode
		file.close()	#Close CSV
		return True
	except:
		pass	#CSV file is current being used so this operation fails
		return False

def reset_stats():	# Erase all stats in CSV file
	# Erase all contents of csv file to remove old stats
	try:
		#Save all zero stats to CSV file
		file = open(CSV_STATS_FILE, 'w', newline='')	#open CSV in write mode
		outfile = csv.writer(file, delimiter=',', quotechar='|', quoting=csv.QUOTE_MINIMAL)
		outfile.writerow(["Data Type","Min Value","Max Value","Average Value"])
		outfile.writerow(["DUT Voltage",0,0,0])
		outfile.writerow(["DUT Current",0,0,0])
		outfile.writerow(["Self 3.3V Voltage",0,0,0])
		outfile.writerow(["Self 3.3V Current",0,0,0])
		outfile.writerow(["Self 5V Voltage",0,0,0])
		outfile.writerow(["Self 5V Current",0,0,0])
		file.close()	#Close CSV
		
		return True
	except:
		pass	#CSV file is current being used so this operation fails
		return False

def is_hex(s):
	hexadecimal_digits = string_lib.hexdigits
	for c in s:
		if not c in hexadecimal_digits: return False
	return True
	
def line_to_int(utf8_line):		# Convert a utf-8 string to an int
	value = 0
	try:
		for n in utf8_line:		# For each char in the utf-8 string, shift value, cast char as int and add
			if is_hex(n):
				value = 16*value + int(n,16)
		return value
	except:
		print("line_to_int failed.\n")
		return -1
#========== End General Functions Section ==========

#========== Start Decoding Functions Section ==========
def decode_DUT_V(DUT_V_code):
	# This function takes a 32 bit integer, computes a float, and returns the actual value
	CONVERSION_RATIO = 50000000	# Max range = 86V, Precision = 0.02uV
	
	return DUT_V_code / CONVERSION_RATIO
	
def decode_DUT_I(DUT_I_code):
	# This function takes a 32 bit integer, computes a float, and returns the actual value
	CONVERSION_RATIO = 500000000	# Max range = 8.6A, Precision = 2nA

	return DUT_I_code / CONVERSION_RATIO

def decode_TS(TS_code):
	# This function takes a 24 bit integer, computes a float, and returns the actual value
	CONVERSION_RATIO = 100000	# Max range = 167s, Precision = 10ns

	return TS_code / CONVERSION_RATIO
#========== End Decoding Functions Section ==========

#========== Start Update Display Functions Section ==========
def get_DUT_V(root,val,file_name):
	# Try to open the csv file and set the value of val based on its contents
	try:
		file = open(file_name, 'r', newline='')	#open in read mode
		reader = csv.reader(file, delimiter=',', quotechar='|', quoting=csv.QUOTE_MINIMAL)
		
		for row in reader:
			type_val = row[0]				
			if (type_val == 'DUT Voltage'):
				min_DUT_V = float(row[1])
				max_DUT_V = float(row[2])
				ave_DUT_V = float(row[3])
		try:
			val.set("DUT Voltage Min:\t\t%8.5fV\nDUT Voltage Max:\t\t%8.5fV\nDUT Voltage Average:\t%8.5fV"%(min_DUT_V,max_DUT_V,ave_DUT_V))
		except:
			val.set("DUT Voltage Min:\t\t%8dV\nDUT Voltage Max:\t\t%8dV\nDUT Voltage Average:\t%8dV"%(min_DUT_V,max_DUT_V,ave_DUT_V))
		file.close()	#Close CSV

	except IOError as e:
		print(e)
	else:
		# schedule the function to be run again after 1000 milliseconds  
		root.after(UPDATE_DATA_PERIOD,lambda:get_DUT_V(root,val,file_name))

def get_DUT_I(root,val,file_name):
	# Try to open the csv file and set the value of val based on its contents
	try:
		file = open(file_name, 'r', newline='')	#open in read mode
		reader = csv.reader(file, delimiter=',', quotechar='|', quoting=csv.QUOTE_MINIMAL)
		
		for row in reader:
			type_val = row[0]				
			if (type_val == 'DUT Current'):
				min_DUT_I = float(row[1])
				max_DUT_I = float(row[2])
				ave_DUT_I = float(row[3])
		try:
			val.set("DUT Current Min:\t\t%8.5fA\nDUT Current Max:\t\t%8.5fA\nDUT Current Average:\t%8.5fA"%(min_DUT_I,max_DUT_I,ave_DUT_I))
		except:
			val.set("DUT Current Min:\t\t%8dA\nDUT Current Max:\t\t%8dA\nDUT Current Average:\t%8dA"%(min_DUT_I,max_DUT_I,ave_DUT_I))
		file.close()	#Close CSV

	except IOError as e:
		print(e)
	else:
		# schedule the function to be run again after 1000 milliseconds  
		root.after(UPDATE_DATA_PERIOD,lambda:get_DUT_I(root,val,file_name))

def get_3V_V(root,val,file_name):	#Currently not used
	# Try to open the csv file and set the value of val based on its contents
	try:
		file = open(file_name, 'r', newline='')	#open in read mode
		reader = csv.reader(file, delimiter=',', quotechar='|', quoting=csv.QUOTE_MINIMAL)
		
		for row in reader:
			type_val = row[0]				
			if (type_val == 'Self 3.3V Voltage'):
				min_3V_V = float(row[1])
				max_3V_V = float(row[2])
				ave_3V_V = float(row[3])
		try:
			val.set("3.3V Voltage Min:\t\t%8.5fV\n3.3V Voltage Max:\t\t%8.5fV\n3.3V Voltage Average:\t%8.5fV"%(min_3V_V,max_3V_V,ave_3V_V))
		except:
			val.set("3.3V Voltage Min:\t\t%8dV\n3.3V Voltage Max:\t\t%8dV\n3.3V Voltage Average:\t%8dV"%(min_3V_V,max_3V_V,ave_3V_V))
		file.close()	#Close CSV

	except IOError as e:
		print(e)
	else:
		# schedule the function to be run again after 1000 milliseconds  
		root.after(INFINITE_WAIT,lambda:get_3V_V(root,val,file_name))

def get_3V_I(root,val,file_name):	#Currently not used
	# Try to open the csv file and set the value of val based on its contents
	try:
		file = open(file_name, 'r', newline='')	#open in read mode
		reader = csv.reader(file, delimiter=',', quotechar='|', quoting=csv.QUOTE_MINIMAL)
		
		for row in reader:
			type_val = row[0]				
			if (type_val == 'Self 3.3V Current'):
				min_3V_I = float(row[1])
				max_3V_I = float(row[2])
				ave_3V_I = float(row[3])
		try:
			val.set("3.3V Current Min:\t\t%8.5fA\n3.3V Current Max:\t\t%8.5fA\n3.3V Current Average:\t%8.5fA"%(min_3V_I,max_3V_I,ave_3V_I))
		except:
			val.set("3.3V Current Min:\t\t%8dA\n3.3V Current Max:\t\t%8dA\n3.3V Current Average:\t%8dA"%(min_3V_I,max_3V_I,ave_3V_I))
		file.close()	#Close CSV

	except IOError as e:
		print(e)
	else:
		# schedule the function to be run again after 1000 milliseconds  
		root.after(INFINITE_WAIT,lambda:get_3V_I(root,val,file_name))

def get_5V_V(root,val,file_name):	#Currently not used
	# Try to open the csv file and set the value of val based on its contents
	try:
		file = open(file_name, 'r', newline='')	#open in read mode
		reader = csv.reader(file, delimiter=',', quotechar='|', quoting=csv.QUOTE_MINIMAL)
		
		for row in reader:
			type_val = row[0]				
			if (type_val == 'Self 5V Voltage'):
				min_5V_V = float(row[1])
				max_5V_V = float(row[2])
				ave_5V_V = float(row[3])
		try:
			val.set("5V Voltage Min:\t\t%8.5fV\n5V Voltage Max:\t\t%8.5fV\n5V Voltage Average:\t%8.5fV"%(min_5V_V,max_5V_V,ave_5V_V))
		except:
			val.set("5V Voltage Min:\t\t%8dV\n5V Voltage Max:\t\t%8dV\n5V Voltage Average:\t%8dV"%(min_5V_V,max_5V_V,ave_5V_V))
		file.close()	#Close CSV

	except IOError as e:
		print(e)
	else:
		# schedule the function to be run again after 1000 milliseconds  
		root.after(INFINITE_WAIT,lambda:get_5V_V(root,val,file_name))

def get_5V_I(root,val,file_name):	#Currently not used
	# Try to open the csv file and set the value of val based on its contents
	try:
		file = open(file_name, 'r', newline='')	#open in read mode
		reader = csv.reader(file, delimiter=',', quotechar='|', quoting=csv.QUOTE_MINIMAL)
		
		for row in reader:
			type_val = row[0]				
			if (type_val == 'Self 5V Current'):
				min_5V_I = float(row[1])
				max_5V_I = float(row[2])
				ave_5V_I = float(row[3])
		try:
			val.set("5V Current Min:\t\t%8.5fA\n5V Current Max:\t\t%8.5fA\n5V Current Average:\t%8.5fA"%(min_5V_I,max_5V_I,ave_5V_I))
		except:
			val.set("5V Current Min:\t\t%8dA\n5V Current Max:\t\t%8dA\n5V Current Average:\t%8dA"%(min_5V_I,max_5V_I,ave_5V_I))
		file.close()	#Close CSV

	except IOError as e:
		print(e)
	else:
		# schedule the function to be run again after 1000 milliseconds  
		root.after(INFINITE_WAIT,lambda:get_5V_I(root,val,file_name))

#========== End Update Display Functions Section ==========

#========== Start CSV Data File Update Function Section ==========
def update_CSV_data_file(root):
	# Update the CSV file based on the most recent USB readings
	try:
		#Read all pending values from the USB
		readings_arr = [[0 for x in range(0,13)] for x in range(0,DATA_MAX)]	# Initialize 2D array to hold read values and the elapsed time between reads 
		read_num = 0	# stores total number of USB readings
		read_attempts = 0	# stores total number of USB reading attempts
		t0 = time.clock()
		
		# while ((read_attempts < DATA_MAX) & ((time.clock() - t0) < TIME_MAX)):
		while (read_attempts < DATA_MAX):
			read_attempts += 1
			
			try:
				first_read_success = False
				while (first_read_success == False):
					temp = int.from_bytes(k22f.read(size=1),byteorder='big')
					if (temp != 0):
						first_read_success = True
						readings_arr[read_num][0] = temp

				check_sum_1 = temp
				check_sum_2 = check_sum_1
				for i in range(1,11):
					readings_arr[read_num][i] = int.from_bytes(k22f.read(size=1),byteorder='big')
					check_sum_1 = check_sum_1 ^ readings_arr[read_num][i]
					check_sum_2 = check_sum_2 + readings_arr[read_num][i]
				# Compute two's complement of check_sum_2
				check_sum_2 = check_sum_2 % 256	#Take the least significant byte
				check_sum_2 = check_sum_2 ^ 255 #Flip all the bits
				check_sum_2 = check_sum_2 + 1	#check_sum_2 now holds 2's complement
				
				readings_arr[read_num][11] = int.from_bytes(k22f.read(size=1),byteorder='big')
				readings_arr[read_num][12] = int.from_bytes(k22f.read(size=1),byteorder='big')
				# Continue to read in more bytes until the check sum is correct
				# while (((readings_arr[read_num][11] != check_sum_1) | (readings_arr[read_num][0] == 0) | (readings_arr[read_num][12] != check_sum_2)) & ((time.clock() - t0) < TIME_MAX)):
				while ((readings_arr[read_num][11] != check_sum_1) | (readings_arr[read_num][0] == 0) | (readings_arr[read_num][12] != check_sum_2)):
				# while (False):
					# We need to shift another byte in and check the check_sum_1 again
					check_sum_1 = 0
					check_sum_2 = 0
					for i in range(0,11):
						readings_arr[read_num][i] = readings_arr[read_num][i+1]
						check_sum_1 = check_sum_1 ^ readings_arr[read_num][i]
						check_sum_2 = check_sum_2 + readings_arr[read_num][i]
					# Compute two's complement of check_sum_2
					check_sum_2 = check_sum_2 % 256	#Take the least significant bit
					check_sum_2 = check_sum_2 ^ 255 #Flip all the bits
					check_sum_2 = check_sum_2 + 1	#check_sum_2 now holds 2's complement
					
					readings_arr[read_num][11] = readings_arr[read_num][12]
					readings_arr[read_num][12] = int.from_bytes(k22f.read(size=1),byteorder='big')
				read_num += 1
			except:
				pass
	
		#Log these USB values to the CSV log file
		file = open(CSV_LOG_FILE, 'a', newline='')	#open in append mode
		outfile = csv.writer(file, delimiter=',', quotechar='|', quoting=csv.QUOTE_MINIMAL)
		row_index = 0
		while row_index < read_num:
			# Parse out the individual pieces from each packet
			voltage_val_code = 0
			current_val_code = 0
			time_stamp_code = 0
			for i in range(0,4):
				voltage_val_code = 256 * voltage_val_code + readings_arr[row_index][3-i]	#Sending little-endian
				current_val_code = 256 * current_val_code + readings_arr[row_index][i+4]
				if (i != 3):
					time_stamp_code = 256 * time_stamp_code + readings_arr[row_index][i+8]
			# print ("Here is the readings_arr:\n%s\n"%(readings_arr[row_index][0:12]))
			# print("Here is the voltage value:\n%d\n"%(voltage_val_code))
			# print("Here is the current value:\n%d\n"%(current_val_code))
			# print("Here is the time stamp:\n%d\n"%(time_stamp_code))
			
			#Next, I'll decode the required information
			voltage_val = decode_DUT_V(voltage_val_code)
			current_val = decode_DUT_I(current_val_code)
			time_stamp = decode_TS(time_stamp_code)
			
			#Output the parsed data to the CSV file
			outfile.writerow([voltage_val,current_val,time_stamp])
			row_index += 1
		file.close()	#Close CSV
		
		#Store these USB values to the CSV data file
		file = open(CSV_DATA_FILE, 'w', newline='')	#overwrite existing data values
		outfile = csv.writer(file, delimiter=',', quotechar='|', quoting=csv.QUOTE_MINIMAL)
		row_index = 0
		while row_index < read_num:
			# Parse out the individual pieces from each packet
			voltage_val_code = 0
			current_val_code = 0
			time_stamp_code = 0
			for i in range(0,4):
				voltage_val_code = 256 * voltage_val_code + readings_arr[row_index][3-i]	# Sending little-endian
				current_val_code = 256 * current_val_code + readings_arr[row_index][i+4]
				if (i != 3):
					time_stamp_code = 256 * time_stamp_code + readings_arr[row_index][i+8]
			# print("Here is the voltage value:\n%d\n"%(voltage_val_code))
			# print("Here is the current value:\n%d\n"%(current_val_code))
			# print("Here is the time stamp:\n%d\n"%(time_stamp_code))
			
			#Next, I'll decode the required information
			voltage_val = decode_DUT_V(voltage_val_code)
			current_val = decode_DUT_I(current_val_code)
			time_stamp = decode_TS(time_stamp_code)
			
			#Output the parsed data to the CSV file
			outfile.writerow([voltage_val,current_val,time_stamp])
			row_index += 1
		file.close()	#Close CSV
		
		# Now update the CSV stats file
		update_CSV_stats_file(root)
		
	except IOError as e:
		print(e)
	else:
		# schedule the function to be run again after (UPDATE_DATA_PERIOD) milliseconds 
		root.after(UPDATE_DATA_PERIOD,lambda:update_CSV_data_file(root))
#========== End CSV Data File Update Function Section ==========

#========== Start CSV Stats File Update Function Section ==========
def update_CSV_stats_file(root):
	# Update the CSV file based on the most recent USB readings
	try:
		file = open(CSV_DATA_FILE, 'r', newline='')	#open in read mode
		reader = csv.reader(file, delimiter=',', quotechar='|', quoting=csv.QUOTE_MINIMAL)
		
		# Calculate min, max, and average for each quantity in the entire file
		min_DUT_V = 'blank'
		max_DUT_V = 0.0
		sum_DUT_V = 0.0
		num_DUT_V = 0
		min_DUT_I = 'blank'
		max_DUT_I = 0.0
		sum_DUT_I = 0.0
		num_DUT_I = 0
		
		for row in reader:
			if row[0]=='Data Type':
				# print("\n\nHere is a summary of the data points:\n")
				# print(row[0],"\t",row[1],"\t",row[2],"\n")
				pass
			else:
				voltage_val = float(row[0])		# Convert string to float
				current_val = float(row[1])		# Convert string to float
				time_stamp = float(row[2])		# Convert string to float
				
				# Calculate the statistics for each measurement
				# DUT Voltage
				if min_DUT_V == 'blank':
					min_DUT_V = voltage_val
				elif voltage_val < min_DUT_V:
					min_DUT_V = voltage_val
				if voltage_val > max_DUT_V:
					max_DUT_V = voltage_val
				sum_DUT_V += voltage_val
				num_DUT_V += 1
				
				# DUT Current
				if min_DUT_I == 'blank':
					min_DUT_I = current_val
				elif current_val < min_DUT_I:
					min_DUT_I = current_val
				if current_val > max_DUT_I:
					max_DUT_I = current_val
				sum_DUT_I += current_val
				num_DUT_I += 1
				
		file.close()	#Close CSV
		
		# Calculate averages
		if num_DUT_V > 0:
			ave_DUT_V = sum_DUT_V / num_DUT_V
		else:
			min_DUT_V = 0
			max_DUT_V = 0
			ave_DUT_V = 0
		
		if num_DUT_I > 0:
			ave_DUT_I = sum_DUT_I / num_DUT_I
		else:
			min_DUT_I = 0
			max_DUT_I = 0
			ave_DUT_I = 0
		
		# Set all self power values to zero
		min_3V_V = 0
		max_3V_V = 0
		ave_3V_V = 0
		min_3V_I = 0
		max_3V_I = 0
		ave_3V_I = 0
		min_5V_V = 0
		max_5V_V = 0
		ave_5V_V = 0
		min_5V_I = 0
		max_5V_I = 0
		ave_5V_I = 0
			
		
		#Save new stats to CSV file
		file = open(CSV_STATS_FILE, 'w', newline='')	#open CSV in write mode
		outfile = csv.writer(file, delimiter=',', quotechar='|', quoting=csv.QUOTE_MINIMAL)
		outfile.writerow(["Data Type","Min Value","Max Value","Average Value"])
		outfile.writerow(["DUT Voltage",min_DUT_V,max_DUT_V,ave_DUT_V])
		outfile.writerow(["DUT Current",min_DUT_I,max_DUT_I,ave_DUT_I])
		outfile.writerow(["Self 3.3V Voltage",min_3V_V,max_3V_V,ave_3V_V])
		outfile.writerow(["Self 3.3V Current",min_3V_I,max_3V_I,ave_3V_I])
		outfile.writerow(["Self 5V Voltage",min_5V_V,max_5V_V,ave_5V_V])
		outfile.writerow(["Self 5V Current",min_5V_I,max_5V_I,ave_5V_I])
		file.close()	#Close CSV
		
	except IOError as e:
		print(e)
	else:
		pass
#========== End CSV Stats File Update Function Section ==========

#========== Start Update Graphs Function Section ==========
def animate_DUT(i):
	
	# junk = input("Annotating DUT...\n")	#Use for debugging purposes
	#Read the entire CSV file and store in an array
	file = open(CSV_DATA_FILE, 'r', newline='')	#open CSV in read mode
	reader = csv.reader(file, delimiter=',', quotechar='|', quoting=csv.QUOTE_MINIMAL)
	csv_arr = [[0 for x in range(0,3)] for x in range(0,10*DATA_MAX)]	# Initialize 2D array to hold type, value, and time for each data point
	row_index = 0
	for row in reader:
		# Store the data in the csv_arr
		if row_index != 0:
			for index in range(0,3):
				csv_arr[row_index][index] = row[index]
		row_index += 1
	file.close()	#Close CSV
	
	xList = []
	yList_V = []
	yList_I = []
	yList_P = []
	
	for index in range(0,row_index):
		xList.append(csv_arr[index][2])
		yList_V.append(csv_arr[index][0])
		yList_I.append(csv_arr[index][1])
		yList_P.append(float(csv_arr[index][0]) * float(csv_arr[index][1]))
		
	# Calculate the limits for the graphs
	x_min = round(float(csv_arr[int(row_index/2)][2]),2)	#This eliminates any discontinuities in data gathering
	x_max = round(float(csv_arr[row_index - 1][2]),2)
	
	a1_DUT.clear()
	a1_DUT.plot(xList,yList_V,'y.-')
	a2_DUT.clear()
	a2_DUT.plot(xList,yList_I,'r.-')
	a3_DUT.clear()
	a3_DUT.plot(xList,yList_P,'b.-')
	
	a1_DUT.set_xlabel("time (s)")
	a1_DUT.set_ylabel("Voltage (V)")
	a2_DUT.set_xlabel("time (s)")
	a2_DUT.set_ylabel("Current (A)")
	a3_DUT.set_xlabel("time (s)")
	a3_DUT.set_ylabel("Power (W)")
	
	a1_DUT.set_xlim([x_min,x_max])
	a2_DUT.set_xlim([x_min,x_max])
	a3_DUT.set_xlim([x_min,x_max])

def animate_3V(i):
	
	# junk = input("Annotating 3V...\n")	#Use for debugging purposes
	#Read the entire CSV file and store in an array
	file = open(CSV_DATA_FILE, 'r', newline='')	#open CSV in read mode
	reader = csv.reader(file, delimiter=',', quotechar='|', quoting=csv.QUOTE_MINIMAL)
	csv_arr = [[0 for x in range(0,3)] for x in range(0,2*DATA_MAX)]	# Initialize 2D array to hold type, value, and time for each data point
	row_index = 0
	for row in reader:
		# Store the data in the csv_arr
		for index in range(0,3):
			csv_arr[row_index][index] = row[index]
		row_index += 1
	file.close()	#Close CSV
	
	xList_V = []
	yList_V = []
	length_V = 0
	
	xList_I = []
	yList_I = []
	length_I = 0
	
	xList_P = []
	yList_P = []
	
	for index in range(0,row_index):
		if csv_arr[index][0] == 'Self 3.3V Voltage':
			xList_V.append(csv_arr[index][2])
			yList_V.append(csv_arr[index][1])
			length_V += 1
		elif csv_arr[index][0] == 'Self 3.3V Current':
			xList_I.append(csv_arr[index][2])
			yList_I.append(csv_arr[index][1])
			length_I += 1
	for index in range(0,min(length_V,length_I)):
		xList_P.append(xList_V[index])
		yList_P.append(float(yList_V[index]) * float(yList_I[index]))
	
	a1_3V.clear()
	a1_3V.plot(xList_V,yList_V,'y.-')
	a2_3V.clear()
	a2_3V.plot(xList_I,yList_I,'r.-')
	a3_3V.clear()
	a3_3V.plot(xList_P,yList_P,'b.-')
	
	a1_3V.set_xlabel("time (s)")
	a1_3V.set_ylabel("Voltage (V)")
	a2_3V.set_xlabel("time (s)")
	a2_3V.set_ylabel("Current (A)")
	a3_3V.set_xlabel("time (s)")
	a3_3V.set_ylabel("Power (W)")

def animate_5V(i):
	
	# junk = input("Annotating 5V...\n")	#Use for debugging purposes
	#Read the entire CSV file and store in an array
	file = open(CSV_DATA_FILE, 'r', newline='')	#open CSV in read mode
	reader = csv.reader(file, delimiter=',', quotechar='|', quoting=csv.QUOTE_MINIMAL)
	csv_arr = [[0 for x in range(0,3)] for x in range(0,2*DATA_MAX)]	# Initialize 2D array to hold type, value, and time for each data point
	row_index = 0
	for row in reader:
		# Store the data in the csv_arr
		for index in range(0,3):
			csv_arr[row_index][index] = row[index]
		row_index += 1
	file.close()	#Close CSV
	
	xList_V = []
	yList_V = []
	length_V = 0
	
	xList_I = []
	yList_I = []
	length_I = 0
	
	xList_P = []
	yList_P = []
	
	for index in range(0,row_index):
		if csv_arr[index][0] == 'Self 5V Voltage':
			xList_V.append(csv_arr[index][2])
			yList_V.append(csv_arr[index][1])
			length_V += 1
		elif csv_arr[index][0] == 'Self 5V Current':
			xList_I.append(csv_arr[index][2])
			yList_I.append(csv_arr[index][1])
			length_I += 1
	for index in range(0,min(length_V,length_I)):
		xList_P.append(xList_V[index])
		yList_P.append(float(yList_V[index]) * float(yList_I[index]))
	
	a1_5V.clear()
	a1_5V.plot(xList_V,yList_V,'y.-')
	a2_5V.clear()
	a2_5V.plot(xList_I,yList_I,'r.-')
	a3_5V.clear()
	a3_5V.plot(xList_P,yList_P,'b.-')
	
	a1_5V.set_xlabel("time (s)")
	a1_5V.set_ylabel("Voltage (V)")
	a2_5V.set_xlabel("time (s)")
	a2_5V.set_ylabel("Current (A)")
	a3_5V.set_xlabel("time (s)")
	a3_5V.set_ylabel("Power (W)")
#========== End Update Graphs Function Section ==========

#========== Start Main Application Section ==========
class PMapp(tk.Tk):
	
	def __init__(self, *args, **kwargs):
		tk.Tk.__init__(self, *args, **kwargs)
		container = tk.Frame(self)
		tk.Tk.wm_title(self, "Power Monitoring Device")
		
		container.pack(side="top", fill="both", expand = True)
		container.grid_rowconfigure(0,weight=1)
		container.grid_columnconfigure(0,weight=1)
		
		self.frames = {}
		
		for F in (HomePage, PageDUT, Page3V, Page5V):
			frame = F(container, self)
			self.frames[F] = frame
			frame.grid(row=0, column=0, sticky="nsew")
			
		self.show_frame(HomePage)
	
	def show_frame(self, cont):
		frame = self.frames[cont]
		frame.tkraise()
#========== End Main Application Section ==========

#========== Start Individual Pages Section ==========
class HomePage(tk.Frame):
	
	def __init__(self,parent,controller):
		tk.Frame.__init__(self,parent)
		label = tk.Label(self, text="Home Page", font=LARGE_FONT)
		label.grid(row=0, column=1, sticky="nsew")
		update_CSV_data_file(self)
		
		# Create separate frames for each section: DUT, 3.3V, 5V
		
#====== Create a larger frame to hold all DUT related material ========
		frame1 = ttk.Frame(self)
		frame1.grid(row=1,column=0,sticky="nsew",pady=10,padx=10)
		frame1['borderwidth'] = 2
		frame1['relief'] = 'solid'
		label_frame1 = ttk.Label(frame1,text="Device Under Test",font=MEDIUM_FONT)
		label_frame1.pack()
		
		#Create a subframe to hold data specific to DUT Voltage
		frame11 = ttk.Frame(frame1)
		frame11.pack(side=tk.TOP,pady=10,padx=10)
		frame11['borderwidth'] = 2
		frame11['relief'] = 'solid'
		string_DUT_V = tk.StringVar()
		label_frame11 = ttk.Label(frame11,textvariable=string_DUT_V)
		label_frame11.pack()
		get_DUT_V(frame11,string_DUT_V,CSV_STATS_FILE)
		
		button1 = ttk.Button(frame1, text="Display DUT Graphs",
							command=lambda: controller.show_frame(PageDUT))
		button1.pack(side=tk.BOTTOM)
		
		#Create a subframe to hold data specific to DUT Current
		frame12 = ttk.Frame(frame1)
		frame12.pack(side=tk.BOTTOM,pady=10,padx=10)
		frame12['borderwidth'] = 2
		frame12['relief'] = 'solid'
		string_DUT_I = tk.StringVar()
		label_frame12 = ttk.Label(frame12,textvariable=string_DUT_I)
		label_frame12.pack()
		get_DUT_I(frame12,string_DUT_I,CSV_STATS_FILE)
#====== End of frame for all DUT related material ========

#====== Create a larger frame to hold all 3.3V related material ========
		frame2 = ttk.Frame(self)
		frame2.grid(row=1,column=1,sticky="nsew",pady=10,padx=10)
		frame2['borderwidth'] = 2
		frame2['relief'] = 'solid'
		label_frame2 = ttk.Label(frame2,text="Self 3.3V Rail",font=MEDIUM_FONT)
		label_frame2.pack()
		
		#Create a subframe to hold data specific to 3.3V Rail Voltage
		frame21 = ttk.Frame(frame2)
		frame21.pack(side=tk.TOP,pady=10,padx=10)
		frame21['borderwidth'] = 2
		frame21['relief'] = 'solid'
		string_3V_V = tk.StringVar()
		label_frame21 = ttk.Label(frame21,textvariable=string_3V_V)
		label_frame21.pack()
		get_3V_V(frame21,string_3V_V,CSV_STATS_FILE)
		
		button2 = ttk.Button(frame2, text="Display 3.3V Graphs",
							command=lambda: controller.show_frame(Page3V))
		button2.pack(side=tk.BOTTOM)
		
		#Create a subframe to hold data specific to 3.3V Current
		frame22 = ttk.Frame(frame2)
		frame22.pack(side=tk.BOTTOM,pady=10,padx=10)
		frame22['borderwidth'] = 2
		frame22['relief'] = 'solid'
		string_3V_I = tk.StringVar()
		label_frame22 = ttk.Label(frame22,textvariable=string_3V_I)
		label_frame22.pack()
		get_3V_I(frame22,string_3V_I,CSV_STATS_FILE)
#====== End of frame for all 3.3V related material ========

#====== Create a larger frame to hold all 5V related material ========
		frame3 = ttk.Frame(self)
		frame3.grid(row=1,column=2,sticky="nsew",pady=10,padx=10)
		frame3['borderwidth'] = 2
		frame3['relief'] = 'solid'
		label_frame3 = ttk.Label(frame3,text="Self 5V Rail",font=MEDIUM_FONT)
		label_frame3.pack()
		
		#Create a subframe to hold data specific to 5V Rail Voltage
		frame31 = ttk.Frame(frame3)
		frame31.pack(side=tk.TOP,pady=10,padx=10)
		frame31['borderwidth'] = 2
		frame31['relief'] = 'solid'
		string_5V_V = tk.StringVar()
		label_frame31 = ttk.Label(frame31,textvariable=string_5V_V)
		label_frame31.pack()
		get_5V_V(frame31,string_5V_V,CSV_STATS_FILE)
		
		button3 = ttk.Button(frame3, text="Display 5V Graphs",
							command=lambda: controller.show_frame(Page5V))
		button3.pack(side=tk.BOTTOM)
		
		#Create a subframe to hold data specific to 5V Current
		frame32 = ttk.Frame(frame3)
		frame32.pack(side=tk.BOTTOM,pady=10,padx=10)
		frame32['borderwidth'] = 2
		frame32['relief'] = 'solid'
		string_5V_I = tk.StringVar()
		label_frame32 = ttk.Label(frame32,textvariable=string_5V_I)
		label_frame32.pack()
		get_5V_I(frame32,string_5V_I,CSV_STATS_FILE)
#====== End of frame for all 5V related material ========
		
		# Add a text box description in bottom left
		frame_text = ttk.Frame(self)
		frame_text.grid(row=2,column=0,sticky="nsew",pady=125,padx=10)
		frame_text['borderwidth'] = 2
		frame_text['relief'] = 'solid'
		label_frame_text_1 = ttk.Label(frame_text,text="\nDescription",font=MEDIUM_FONT)
		label_frame_text_1.pack()
		text_description = 'This page updates the min, max, and average values\nevery second. By clicking the buttons, you can see\nthe voltage, current, and power graphs at each \nlocation (which update every 10 seconds). Click the\nreset button to reset the running storage of the \nlast 1000 data points.'
		label_frame_text_2 = ttk.Label(frame_text,text=text_description)
		label_frame_text_2.pack()
		
		# Add a reset button
		button_reset = ttk.Button(self, text="Reset",command=reset_data)
		button_reset.grid(row=2,column=1,sticky="nsew",pady=175,padx=50)
		
		# Add a photo in bottom right
		p = tk.PhotoImage(file="lightning_bolt.gif")
		l=ttk.Label(self, image=p)
		l.image = p
		l.grid(row=2,column=2, sticky = "nsew")
		
class PageDUT(tk.Frame):
	
	def __init__(self,parent,controller):
		tk.Frame.__init__(self,parent)
		label = tk.Label(self, text="Device Under Test", font=LARGE_FONT)
		label.pack(pady=10,padx=10)
		
		button1 = ttk.Button(self, text="Back to Home",
							command=lambda: controller.show_frame(HomePage))
		button1.pack()
		
		canvas = FigureCanvasTkAgg(f1, self)
		canvas.show()
		canvas.get_tk_widget().pack(side=tk.TOP, fill=tk.BOTH, expand=True)
		
		toolbar = NavigationToolbar2TkAgg(canvas, self)
		toolbar.update()
		canvas._tkcanvas.pack(side=tk.TOP, fill=tk.BOTH, expand=True)
		
class Page3V(tk.Frame):
	
	def __init__(self,parent,controller):
		tk.Frame.__init__(self,parent)
		label = tk.Label(self, text="Self 3.3V Rail", font=LARGE_FONT)
		label.pack(pady=10,padx=10)
		
		button1 = ttk.Button(self, text="Back to Home",
							command=lambda: controller.show_frame(HomePage))
		button1.pack()
		
		canvas = FigureCanvasTkAgg(f2, self)
		canvas.show()
		canvas.get_tk_widget().pack(side=tk.TOP, fill=tk.BOTH, expand=True)
		
		toolbar = NavigationToolbar2TkAgg(canvas, self)
		toolbar.update()
		canvas._tkcanvas.pack(side=tk.TOP, fill=tk.BOTH, expand=True)

class Page5V(tk.Frame):
	
	def __init__(self,parent,controller):
		tk.Frame.__init__(self,parent)
		label = tk.Label(self, text="Self 5V Rail", font=LARGE_FONT)
		label.pack(pady=10,padx=10)
		
		button1 = ttk.Button(self, text="Back to Home",
							command=lambda: controller.show_frame(HomePage))
		button1.pack()
		
		canvas = FigureCanvasTkAgg(f3, self)
		canvas.show()
		canvas.get_tk_widget().pack(side=tk.TOP, fill=tk.BOTH, expand=True)
		
		toolbar = NavigationToolbar2TkAgg(canvas, self)
		toolbar.update()
		canvas._tkcanvas.pack(side=tk.TOP, fill=tk.BOTH, expand=True)
#========== End Individual Pages Section ==========

#========== Start Actual Program Section ==========

# Erase all contents of csv file to remove old data
reset_data

#### Startup Text #############################################################
print("\nPower Monitor for Battery Powered Devices\n"
	  "USB Communication\n"	
      "Python Version %s\n"
	  "James Redinger\n"
	  "11/12/2015\n\n"
	  "Run with arg -h (i.e. python %s -h) to see help menu.\n"%(sys.version, sys.argv[0]))
print("Available COM ports: %s\n"%enum_ports())
#### Startup Text END #########################################################

### Serial Init ##############################################################
COM_PORT = int(input("Select COM port: "))	# Prompt user to enter the COM port
k22f = serial.Serial(port=(COM_PORT-1),		# Initialize the serial connection with given parameters
					 baudrate=BAUD_RATE,
					 timeout = 0.01)
print("Connection started on %s\n"
		   "----------------------------------------------------------------------\n"%k22f.name)
				
### Serial Init END ##########################################################

# Add DUT voltage, current, and power graphs on the DUT Page
f1 = Figure(figsize=(5,5), dpi=100)
a1_DUT = f1.add_subplot(311,xlabel="time(s)",ylabel="Voltage(V)",xlim=[0,100],ylim=[0,25])
a2_DUT = f1.add_subplot(312,xlabel="time (s)",ylabel="Current (A)",xlim=[0,100],ylim=[1e-10,10],yscale='log')
a3_DUT = f1.add_subplot(313,xlabel="time (s)",ylabel="Power (W)",xlim=[0,100],ylim=[1e-10,100],yscale='log')

# Add 3.3V Rail voltage, current, and power graphs on the Self 3.3V Rail Page
f2 = Figure(figsize=(5,5), dpi=100)
a1_3V = f2.add_subplot(311,xlabel="time(s)",ylabel="Voltage(V)",xlim=[0,100],ylim=[2,5])
a2_3V = f2.add_subplot(312,xlabel="time (s)",ylabel="Current (A)",xlim=[0,100],ylim=[1e-6,1],yscale='log')
a3_3V = f2.add_subplot(313,xlabel="time (s)",ylabel="Power (W)",xlim=[0,100],ylim=[1e-6,1],yscale='log')

# Add 5V Rail voltage, current, and power graphs on the Self 5V Rail Page
f3 = Figure(figsize=(5,5), dpi=100)
a1_5V = f3.add_subplot(311,xlabel="time(s)",ylabel="Voltage(V)",xlim=[0,100],ylim=[3,7])
a2_5V = f3.add_subplot(312,xlabel="time (s)",ylabel="Current (A)",xlim=[0,100],ylim=[1e-6,1],yscale='log')
a3_5V = f3.add_subplot(313,xlabel="time (s)",ylabel="Power (W)",xlim=[0,100],ylim=[1e-6,1],yscale='log')

app = PMapp()
ani1 = animation.FuncAnimation(f1, animate_DUT, interval=UPDATE_GRAPH_PERIOD)
ani2 = animation.FuncAnimation(f2, animate_3V, interval=INFINITE_WAIT)
ani3 = animation.FuncAnimation(f3, animate_5V, interval=INFINITE_WAIT)
app.mainloop()

k22f.close()	# Close serial connection
sys.exit(0)

#========== End Actual Program Section ==========