# HTTP Digest Authentication cracker
import hashlib

username = "Mufasa"
realm = "testrealm@host.com"
password="Circle Of Life"
nonce = "dcd98b7102dd2f0e8b11d0f600bfb0c093"
uri = "/dir/index.html"
qop = "auth"
nc = 1
cnonce = "0a4f113b"
response = "6629fae49393a05397450978507c4ef1"
opaque = "5ccc069c403ebaf9f0171e9517f40e41"

# Calculate the response
ha1 = hashlib.md5((username + ":" + realm + ":" + password).encode('utf-8')).hexdigest()
ha2 = hashlib.md5(("GET" + ":" + uri).encode('utf-8')).hexdigest()
response = hashlib.md5((ha1 + ":" + nonce + ":" + nc + ":" + cnonce + ":" + qop + ":" + ha2).encode('utf-8')).hexdigest()

print("Response: " + response)