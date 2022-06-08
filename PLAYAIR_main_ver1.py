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
    if acc_decode[0:2] == '01':
        crash1.play()
    elif acc_decode[0:2] == '02':
        crash2.play()
    elif acc_decode[0:2] == '03':
        tom1.play()
    elif acc_decode[0:2] == '04':
        tom2.play()
    elif acc_decode[0:2] == '05':
        snare1.play()
    elif acc_decode[0:2] == '06':
        snare2.play()
    elif acc_decode[0:2] == '07':
        ride1.play()
    elif acc_decode[0:2] == '08':
        ride2.play()
    elif acc_decode[0:2] == '09':
        sdst.play()
    elif acc_decode[0:2] == '10':
        cihat.play()
    elif acc_decode[0:2] == '11':
        hfhat.play()
    elif acc_decode[0:2] == '12':
        ophat.play()
    elif acc_decode[0:2] == '13':
        pdhat.play()
    time.sleep(0.2)
    
# Maybe faster using dict and cleaner code
# soundFiles = {'01': crash1, '02': crash2, '03': tom1, '04': tom2, '05': snare1, '06': snare2,
#               '07': ride1, '08': ride2, '09': sdst, '10': cihat, '11': hfhat, '12': ophat, '13': pdhat
#              }
# while True:
#     data = ser.readline().decode()
#     if data[0:2] != '00':
#         soundFiles[data[0:2]].play()
#     time.sleep(0.2)

#with serial.Serial('COM8', 9600, timeout=0) as ser:
#    line = ser.readline()
#    line_decode = line.decode()
#    print(line_decode)


# In[ ]:




