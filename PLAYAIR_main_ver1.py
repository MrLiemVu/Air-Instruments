#!/usr/bin/env python
# coding: utf-8

# In[ ]:


from pyfirmata import Arduino, util
import serial
import time


# In[ ]:


ser = serial.Serial('COM8', 9600)
while True:
    acc = ser.readline()
    acc_decode = acc.decode()
    acc_num_list = list(map(float, acc_decode.split()))
    print(acc_num_list)


#with serial.Serial('COM8', 9600, timeout=0) as ser:
#    line = ser.readline()
#    line_decode = line.decode()
#    print(line_decode)


# In[ ]:




