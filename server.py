from time import gmtime, strftime
import serial


ser = serial.Serial("/dev/cu.usbmodem411", 9600)
with open("WaterData", 'a', 1) as outfile:
    while True:
        outfile.write(strftime("%Y/%m/%d-%H:%M:%S", gmtime()) + " " + ser.readline())
