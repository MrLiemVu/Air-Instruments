#!/usr/bin/env python
# coding: utf-8

# from pyfirmata import Arduino, util
import serial
import time
import pygame as pg

# Load the sound player and sound files
pg.mixer.init()
pg.init()
pg.mixer.set_num_channels(50)
crash1 = pg.mixer.Sound("./sounds/Crash01.wav")
crash2 = pg.mixer.Sound("./sounds/Crash02.wav")
tom1 = pg.mixer.Sound("./sounds/Tom01.wav")
tom2 = pg.mixer.Sound("./sounds/Tom02.wav")
snare1 = pg.mixer.Sound("./sounds/Snare01.wav")
snare2 = pg.mixer.Sound("./sounds/Snare02.wav")
ride1 = pg.mixer.Sound("./sounds/Ride01.wav")
ride2 = pg.mixer.Sound("./sounds/Ride02.wav")
sdst = pg.mixer.Sound("./sounds/SdSt.wav")
cihat = pg.mixer.Sound("./sounds/CIHat.wav")
hfhat = pg.mixer.Sound("./sounds/HfHat02.wav")
ophat = pg.mixer.Sound("./sounds/OpHat.wav")
pdhat = pg.mixer.Sound("./sounds/PdHat.wav")

# Load the bluetooth serial
ser = serial.Serial('COM8', 9600)

while True:
    acc_decode = ser.readline().decode()
#     acc_num_list = list(map(float, acc_decode.split()))
#     print(acc_num_list)
    if acc_decode[0] == '1':
        crash1.play()
    elif acc_decode[0] == '2':
        crash2.play()
    elif acc_decode[0] == '3':
        tom1.play()
    elif acc_decode[0] == '4':
        tom2.play()
    elif acc_decode[0] == '5':
        snare1.play()
    elif acc_decode[0] == '6':
        snare2.play()
    elif acc_decode[0] == '7':
        ride1.play()
    elif acc_decode[0] == '8':
        ride2.play()
    elif acc_decode[0] == '9':
        sdst.play()
    elif acc_decode[0] == '10':
        cihat.play()
    elif acc_decode[0] == '11':
        hfhat.play()
    elif acc_decode[0] == '12':
        ophat.play()
    elif acc_decode[0] == '13':
        pdhat.play()
    time.sleep(0.2)
    
# Maybe faster using dict and cleaner code
# soundFiles = {'1': crash1, '2': crash2, '3': tom1, '4': tom2, '5': snare1, '6': snare2,
#               '7': ride1, '8': ride2, '9': sdst, '10': cihat, '11': hfhat, '12': ophat, '13': pdhat
#              }
# while True:
#     data = ser.readline().decode()
#     if data[0] != 0:
#         soundFiles[data[0]].play()
#     time.sleep(0.2)

#with serial.Serial('COM8', 9600, timeout=0) as ser:
#    line = ser.readline()
#    line_decode = line.decode()
#    print(line_decode)


# In[ ]:




