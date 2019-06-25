#  Give job please
for N in range (1,101):
    S = ''
    if N % 3 == 0:
        S = S + "Fizz"
    if N % 5 == 0:
        S = S + "Buzz"
    if N % 3 and N % 5: #I have no idea how this works at all
        print(N)
    else:
        print(S)
