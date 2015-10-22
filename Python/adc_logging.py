import serial
import csv
import time
import sys
import os
import glob
import ctypes

def enum_ports():
    ports = ['COM%s' % (i + 1) for i in range(256)]
    result = []
    for port in ports:
        try:
            s = serial.Serial(port)
            s.close()
            result.append(port)
        except (OSError, serial.SerialException):
            pass
    return result

def readline_blocking(serial_port):
	line = ""
	while(line == ""):
		line = serial_port.readline()
	return line

def is_number(s):
	try:
		float(s)
		return True
	except ValueError:
		return False
		
def parse_line(st):
	tempst = st.decode("utf-8")
	adc1 = 0
	adc2 = 0
	mult1 = 10000
	mult2 = 10000
	adc1str = tempst[0:5]
	adc2str = tempst[6:11]
	
	#for i in adc1str:
	#	adc1 += mult1*int(i)
	#	mult1 /= 10
	#for i in adc2str:
	#	adc2 += mult2*int(i)
	#	mult2 /= 10
	#print(adc1str, adc2str)
	return (int(adc1str),int(adc2str))
	
print("Python Version ", sys.version)
print("\nAvailable COM Ports: %s\n"%enum_ports())

#if __name__ == "__main__":

#### Start serial connection ##################################################
COM_PORT = int(input("Select COM Port: "))
BAUD = 115200
try:
	k22f = serial.Serial(port=COM_PORT-1, baudrate=BAUD)
	print("Serial Connection established on COM%d"%COM_PORT)
except:	
	print("Serial Connection Failed. Exiting...")
	sys.exit(0)
#### Start Serial COnnection END ##############################################
	
#### Create CSV ###############################################################
filename = "ADC_TEST.csv"
outfile = open(filename,'a',newline='\n')
cfile = csv.writer(outfile, delimiter=',', quotechar='|', quoting=csv.QUOTE_MINIMAL)
#### Create CSV END ###########################################################

cfile.writerow(["Count","ADC1","ADC2"])
try:
	count = 0
	k22f.readline()
	print()
	while(True):
		count+=1
		val1,val2 = parse_line(k22f.readline())
		#print("%s %s"%(val1,val2), end="\r")
		print("%05.0d, %05.0d\t%d"%(val1,val2,count), end='\r')
		cfile.writerow([count,val1,val2])
except:
	print()
	outfile.close()
	print("Exiting...")
	sys.exit(0)
	


	


