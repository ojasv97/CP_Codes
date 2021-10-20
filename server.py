# -*- coding: utf-8 -*-
"""
Created on Wed Mar 17 22:22:18 2021

@author: ojas
"""

##import socket              
##s = socket.socket()          
##print ("Socket successfully created") 
##port = 12222              
##s.bind(('', port))          
##print ("socket binded to %s" %(port))  
##  
### put the socket into listening mode  
##s.listen(5)      
##print ("socket is listening")             
##
##while True:  
##  
### Establish connection with client.  
##    c, addr = s.accept()      
##    print ('Got connection from', addr ) 
##      
##    # send a thank you message to the client.  
##    c.send('Thank you for connecting')  
##      
##    # Close the connection with the client  
##    c.close()  
##def base26to10(text):
##    concate_text  = ""
##    for i in text:
##        if(i==' '):
##            concate_text+='x'
##        else:
##            concate_text+=i
##    print(concate_text)
##    l = []
##    for i in range(0,len(concate_text),3):
##        block = concate_text[i:i+3]
##        block = block[::-1]
##        val = 0
##        for i in range(len(block)):
##            val+=pow(26,i)*(ord(block[i])-ord('a')+1)
##        l.append(val)
##    return l
##
##def encrypt(msg, public_key):
##    n,e = public_key
##    blocks = base26to10(msg)
##    cipher = []
##    for i in blocks:
##        c = i**e%n
##        cipher.append(c)
##    return cipher
##
####messagefromclient = c.recv(1024)
####
####print(c)
##
####msg = "att you"
####cipher = encrypt(msg,public_key)
####print(cipher)
####print(base10to26(cipher))
####msg = decrypt(cipher, private_key)
####print(msg)
####print(base10to26(msg))
# first of all import the socket library

import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind((socket.gethostname(), 13333))
s.listen(5)

while True:
    # now our endpoint knows about the OTHER endpoint.
    clientsocket, address = s.accept()
    print(f"Connection from {address} has been established.")
