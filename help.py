#  Time to make a real Fizzbuzz
for e in range (0,101):
    string = ''
    if e % 3 == 0:
        string = string + "Fizz"
    if e % 5 == 0:
            string = string + "Buzz"
    if e % 5 != 0 and e % 3 != 0:
        print(e)
    else:
        print(string)
        