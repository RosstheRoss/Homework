#!/usr/bin/env python3
# See https://docs.python.org/3.2/library/socket.html
# for a decscription of python socket and its parameters
import socket

from threading import Thread
from argparse import ArgumentParser

BUFSIZE = 4096
CRLF = '\r\n'
METHOD_NOT_ALLOWED = 'HTTP/1.1 405  METHOD NOT ALLOWED{}Allow: GET, HEAD, POST {}Connection: close{}{}'.format(CRLF, CRLF, CRLF, CRLF)
OK = 'HTTP/1.1 200 OK{}{}'.format(CRLF, CRLF, CRLF) # head request only

def getContents(type, file):
  returnValue = "".encode()
  try:
    content = open(file, 'rb')
  except FileNotFoundError:
    returnValue = getContents(type, "404.html")
  except PermissionError:
    returnValue = getContents(type, "403.html")
  else:
    if type == "HEAD" or "GET":
      returnValue = OK.encode()
      if type == "GET":
        returnValue = b"".join([returnValue, content.read(), "{}{}".format(CRLF, CRLF).encode()])
      else:
        returnValue = b"".join([returnValue, "{}{}".format(CRLF, CRLF).encode()])
    elif type == "POST":
      print("B")
    else:
      returnValue= METHOD_NOT_ALLOWED.encode()
    content.close()
  return returnValue

def client_recv(client_sock, client_addr):
    print('talking to {}'.format(client_addr))
    data = client_sock.recv(BUFSIZE)
    data = data.decode('utf-8').strip("\r")
    data = data.split("\n")
    request = data[0].split(" ")
    want = getContents(request[0], request[1][1:])
    client_sock.send(want)
    print(want)
    client_sock.shutdown(1)
    client_sock.close()
   
    print('connection closed.')


class EchoServer:
  def __init__(self, host, port):
    print("Server")
    print('listening on port {}'.format(port))
    self.host = host
    self.port = port

    self.setup_socket()

    self.accept()

    self.sock.shutdown()
    self.sock.close()

  def setup_socket(self):
    self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    self.sock.bind((self.host, self.port))
    self.sock.listen(128)

  def accept(self):
    while True:
      (client, address) = self.sock.accept()
      th = Thread(target=client_recv, args=(client, address))
      th.start()

def parse_args():
  parser = ArgumentParser()
  parser.add_argument('--host', type=str, default='localhost',
                      help='specify a host to operate on (default: localhost)')
  parser.add_argument('-p', '--port', type=int, default=9001,
                      help='specify a port to operate on (default: 900)')
  args = parser.parse_args()
  return (args.host, args.port)


if __name__ == '__main__':
  (host, port) = parse_args()
  EchoServer(host, port)

