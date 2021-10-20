# -*- coding: utf-8 -*-
"""
Created on Wed Mar 17 22:21:46 2021

@author: ojas
"""

### Import socket module  
##import socket              
##  
### Create a socket object  
##s = socket.socket()          
##  
### Define the port on which you want to connect  
##port = 12345                
##  
### connect to the server on local computer  
##s.connect(('127.0.0.1', port))  
##  
### receive data from the server  
##
##p = 137
##q = 131
##e = 3
##n = p * q
##phi = (p-1)*(q-1)
##public_key = (n,e)
##private_key = (n,modinv(e,phi))
##
##def modinv(a, m):
##    g, x, y = egcd(a, m)
##    if g != 1:
##        raise Exception('modular inverse does not exist')
##    else:
##        return x % m
##
##def egcd(a, b):
##    if a == 0:
##        return b, 0, 1
##    else:
##        g, y, x = egcd(b % a, a)
##        return g, x - (b // a) * y, y
##
##def decrypt(cipher, private_key):
##    n,d = private_key
##    msg = []
##    for i in cipher:
##        t = i**d%n
##        msg.append(t)
##    return msg
##
##c.send(public_key)
##cipher = s.recv(1024)
##print(cipher)
##
### close the connection  
##s.close()   
##
##

import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((socket.gethostname(), 13333))
