def collatzCount(number):
    for n in range (1,number+1):
        collatzConjecture(n)
        print("\n")

def collatzConjecture(n):
    print(n, end = ' ')
    if n is 1:
        return 1
    else:
        if n%2:
            return collatzConjecture(int((n*3)+1))
        else:
            return collatzConjecture(int(n/2))
        raise AssertionError

#main
for i in range (1,2):
    print("")
try:
    collatzCount(100)
except AssertionError:
    print("The Collatz Conjecture is false!")
