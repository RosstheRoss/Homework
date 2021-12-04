#1

##Packet
```
IP 192.168.14.3.46826 > 192.168.14.1.80: Flags [P.], seq 1:143, ack 1, win 502, options [nop,nop,TS val 1452909150 ecr 2428281190], length 142: HTTP: GET /secret/file HTTP/1.1
E.....@.@..............P.Tw.|..j...........
V..^...fGET /secret/file HTTP/1.1
Host: 192.168.14.1
Authorization: Basic dHJhdmlzMTQ6bWFpdkRlY2d1cjIyMDI=
User-Agent: curl/7.58.0
Accept: */*
```

##User/Pass:
`travis14:maivDecgur2202`

##Contents:
```html
<p>I'm going to let you in on a little secret. Every day, once a day, give yourself a present. Don’t plan it; don’t wait for it; just let it happen.</p>
<p>&mdash; Dale Cooper</p>
```
#2
##Packet
```
182203 IP 192.168.14.2.36586 > 192.168.14.1.80: Flags [P.], seq 91:464, ack 308, win 501, options [nop,nop,TS val 422351445 ecr 1957960104], length 373: HTTP: HEAD /secret/cheese HTTP/1.1
E.....@.@..v...........P,..................
.,.Ut...HEAD /secret/cheese HTTP/1.1
Host: 192.168.14.1
Authorization: Digest username="travis14", realm="Cheese", nonce="/DPYEFbSBQA=c06893026441a70acf049b49540e97acd2bdd640", uri="/secret/cheese", cnonce="ZjdlNTk0ZGZmMDQwZTU3OTM2MTIxOGEyNzljNDJlYzc=", nc=00000001, qop=auth, response="872aafc461761e417d2df47b85e43d2b", algorithm="MD5"
User-Agent: curl/7.58.0
Accept: */*
```

##Crack
```python
import hashlib
```