import requests
from requests.packages.urllib3.exceptions import InsecureRequestWarning
import string

requests.packages.urllib3.disable_warnings(InsecureRequestWarning)

actual = ""
key = "Z"*19
for n in range(19, -1, -1):
    res2 = requests.get("https://192.168.14.1/mac-cookie?username="+key,
                        verify=False).text.replace(".", "").split(" ")[-1].split('\n')[0]
    for c in string.printable:
        test = key[:n] + c
        res1 = requests.get("https://192.168.14.1/mac-cookie?username="+test,
                            verify=False).text.replace(".", "").split(" ")[-1].split('\n')[0]
        print(test, res1, res2)
        if res1 == res2:
            actual = c + actual
            break
    key = key[:-1]

print("Key is", actual)
