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
