import csv
import sys
import glob
import serial
import time

def readline_blocking():
	lineEmpty = True
	while lineEmpty:
		try:
			line=com.readline()
			line[0]
			lineEmpty=False
		except:
			pass
	return line

#### Current and Voltage Scaling #######################################################
iScaling = [0.000000009759/2**16, 0.000010064/2**16, 0.1/2**16, 100/2**16]	# nA, uA, mA, A
vScaling = 0.0003601245
#### Current and Voltage Scaling END ###################################################	
	
#### COM Setup #########################################################################
COMPORT = 8	
BAUDRATE = 2048000

try:
	com = serial.Serial(port=(COMPORT-1),baudrate=BAUDRATE,timeout = 0.01)
	print ("Connection started on %s at %s kbps\n"
		   "----------------------------------------------------------------------\n"%(com.name, BAUDRATE/1000))
except:
	print("CONNECTION FAILED.  EXITING...")
	sys.exit(0)
### COM Setup END #####################################################################

#Packet
# C-interp 	uint16_t voltage, uint16_t current, char range, "\n"
# Py-Interp	char, char, char, char, char, '\n'

if __name__ == "__main__":
	ts = time.strftime("%Y-%m-%d_%H:%M:%S")
	rawFile = "loggingFile.csv"
	parsedFile = "formatted_output.csv"#+ts+".csv"
	totalBlocks = int(input("Enter number of blocks to read: "))
	if totalBlocks>52:
		print("Total blocks should not exceed 52 for the purposes of this demo due to excel limits.  52 blocks will be read")
		totalBlocks=52
	else:
		print("Reading %d blocks...\n\n"%totalBlocks)
	
# Create raw data file	
	csvfile=open(rawFile, 'w', newline='')	
	output = csv.writer(csvfile, delimiter=',', quotechar='|',quoting=csv.QUOTE_MINIMAL)	
	
	for block in range(0,totalBlocks):
		#try:
		RXSIZE = 20000
		resultsArray = []
		com.readline()
		for i in range(0,RXSIZE):		# read block of lines
			newLine = list(readline_blocking())
			resultsArray.append(newLine)
		print("Block %d read"%block)
		
		for line in resultsArray:
			try:
				output.writerow( [int(line[0])*256+int(line[1]) , int(line[2])*256+int(line[3]) , int(line[4])])
			except:
				pass

#		 Write to csv
#		with open(rawFile, 'w', newline='') as csvfile:	
#			output = csv.writer(csvfile, delimiter=',', quotechar='|',quoting=csv.QUOTE_MINIMAL)
#			for line in resultsArray:
#				try:
#					output.writerow( [int(line[0])*256+int(line[1]) , int(line[2])*256+int(line[3]) , int(line[4])])
#				except:
#					pass
#			csvfile.close()
	# ALL BLOCKS ARE READ
	csvfile.close()
	print("Raw Data Closed")
	#try:
	
	# create formatted csv
	csvformatted = open(parsedFile, 'w', newline='')	
	writer = csv.writer(csvformatted, delimiter=',', quotechar='|',quoting=csv.QUOTE_MINIMAL)
	print("Formatted file created")
	
	## open raw csv from previous step
	rawData = open(rawFile, 'rt')
	reader = csv.reader(rawData)#, delimiter=',', quotechar='|')
	print("Raw file open")
	
#	with open(rawFile, 'r') as f:
#		reader = csv.reader(f)
#		for row in reader:
#			print("row")
	
	for row in reader:
		#print(row)
		if int(row[2])<4:
			voltage = float(row[0])*vScaling
			current = float(row[1])*iScaling[int(row[2])]
			power = voltage*current
			writer.writerow([voltage,current,power])
	
	rawData.close()	
	csvformatted.close()
		#except:
		#	pass
		#finally:
		#	#file.close()
		#	com.close()