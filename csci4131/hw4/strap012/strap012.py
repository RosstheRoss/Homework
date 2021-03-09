#!/usr/bin/env python3
# See https://docs.python.org/3.2/library/socket.html
# for a decscription of python socket and its parameters
import socket
import os
import stat

from threading import Thread
from argparse import ArgumentParser

BUFSIZE = 4096
CRLF = '\r\n'
NOT_FOUND = 'HTTP/1.1 404 NOT FOUND{}Connection: close{}{}'.format(CRLF, CRLF, CRLF)
FORBIDDEN = 'HTTP/1.1 403 FORBIDDEN{}Connection: close{}{}'.format(CRLF, CRLF, CRLF)
METHOD_NOT_ALLOWED = 'HTTP/1.1 405  METHOD NOT ALLOWED{}Allow: GET, HEAD, POST {}Connection: close{}{}'.format(CRLF, CRLF, CRLF, CRLF)
OK = 'HTTP/1.1 200 OK{}{}'.format(CRLF, CRLF, CRLF) # head request only

# check file permissions -is file world readable?
def check_perms(resource): 
  stmode = os.stat(resource).st_mode
  return(getattr(stat, 'S_IROTH') & stmode) > 0

def POST(form):
  contents = form.decode(utf-8)
  print(contents)
  return

def getContents(type, file):
  returnValue = "".encode()
  try:
    if not check_perms(file):
      raise PermissionError
    content = open(file, 'rb')
  except FileNotFoundError:
    returnValue = NOT_FOUND.encode()
    with open("404.html", "rb") as fof:
      returnValue = b"".join(
        [returnValue, fof.read(), "{}{}".format(CRLF, CRLF).encode()])
  except PermissionError:
    returnValue = FORBIDDEN.encode()
    with open("403.html", "rb") as forb:
      returnValue = b"".join(
          [returnValue, forb.read(), "{}{}".format(CRLF, CRLF).encode()])
  else:
    returnValue = OK.encode()
    if type == "HEAD":
      returnValue = b"".join(
        [returnValue, "{}{}".format(CRLF, CRLF).encode()])
    elif type == "GET":
      returnValue = b"".join(
        [returnValue, content.read(), "{}{}".format(CRLF, CRLF).encode()])
    elif type == "POST":
      POST(content.read())
      #returnValue = b"".join(
      #  [returnValue, POST(content.read(), "{}{}".format(CRLF, CRLF).encode())])
    else:
      returnValue= METHOD_NOT_ALLOWED.encode()
    content.close()
  return returnValue

def client_recv(client_sock, client_addr):
    print('talking to {}'.format(client_addr))
    data = client_sock.recv(BUFSIZE)
    data = data.decode('utf-8').strip("\r")
    print(data)
    data = data.split("\n")
    request = data[0].split(" ")
    if len(request) > 1:
      want = getContents(request[0], request[1][1:])
      client_sock.send(want)
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

