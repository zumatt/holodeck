from time import sleep
from serial import Serial
import serial.tools.list_ports
import pyautogui

ports = serial.tools.list_ports.comports()

for port, desc, hwid in sorted(ports):
        if (port.__contains__("cu.usbmodem")):
            arduinoPort = port
            print(arduinoPort)

ser = Serial(arduinoPort,9600)

while True:
    getVal = ser.readline().decode('utf-8')
    cleanVal = getVal.split("\n")
    rightVal = cleanVal[0].split("\r") 
    if (rightVal[0] == "next"):
        pyautogui.hotkey('command', 'left')
        print("Next video")
    if (rightVal[0] == "play"):
        pyautogui.hotkey('space')
        print("Play video")