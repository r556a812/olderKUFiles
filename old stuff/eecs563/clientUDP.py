import sys
import argparse
from socket import *
p = argparse.ArgumentParser()
p.add_argument("host")
p.add_argument("port", type=int)
args = p.parse_args()
serverIP = args.host
serverPort = args.port
bufferSize = 1024
while True:
    message = raw_input("Please enter the statement:   ")

    clientSocket = socket(AF_INET, # Internet
                            SOCK_DGRAM) # UDP
    clientSocket.sendto(message, (serverIP, serverPort))
    recvMessage, serverAddress = clientSocket.recvfrom(bufferSize)
    print "Message received from server:", recvMessage
    clientSocket.close()
