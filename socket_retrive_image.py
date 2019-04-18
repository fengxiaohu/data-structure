import socket
import time
HOST='data.pr4e.org'
PORT=80
mysocket=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
'''
int socket(int domain,int type,int protocol)
domain:protocol domain
AF_INET AF_INET6
type:type of socket 
SOCK_STREAM SOCK_DGRAM SOCK_RAW
protocol:
IPPROTO_TCP IPPROTO_UDP
'''
mysocket.connect((HOST,PORT))
mysocket.sendall(b'GET http://data.pr4e.org/cover3.jpg HTTP/1.0\r\n\r\n')
count=0
picture=b""
while True:
    data=mysocket.recv(5120)
    if len(data)<1:
        break
    count=count+len(data)
    print(len(data),count)
    picture=picture+data
mysocket.close()
pos = picture.find(b"\r\n\r\n")
print('Header length', pos)
print(picture[:pos].decode())
# Skip past the header and save the picture data
picture = picture[pos+4:]
fhand = open("stuff.jpg", "wb")
fhand.write(picture)
fhand.close()