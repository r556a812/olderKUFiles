import sys
def convert(myString):
    done = ''
    for c in myString:
        if c.islower():
            c = c.replace(c, c.upper())
            done = done + c
        elif c.isupper():
            done = done + c
        else:
            done = done + c

    return (done)

from socket import *
serverPort = int(sys.argv[1])
bufferSize = 1024
serverSocket = socket(AF_INET, # Internet
SOCK_DGRAM) # UDP
serverSocket.bind(('', serverPort))
print('The server is ready to receive')
while True:
    message, clientAddress = serverSocket.recvfrom(1024)
    print "Message received from client:", message
    message = convert(message)
    serverSocket.sendto(message, clientAddress)
