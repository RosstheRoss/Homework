#  Time to make a real FizzBuzz
for N in range (1,101):
    S = ''
    if N % 3 == 0:
        S = S + "Fizz"
    if N % 5 == 0:
        S = S + "Buzz"
# I have no idea how this works
    if N % 3 and N % 5:
        print(N)
    else:
        print(S)