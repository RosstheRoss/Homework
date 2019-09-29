#"New" functions
def Reduce(F,S):
    if len(S)==0:
        return -255
    else:
        return F(Reduce(F,S[:-1]),S[-1])
def returnGreater(a,b):
    if a > b:
        return a
    return b

#Implementation from Lab
def Sort(T):
    if len(T)==0:
        return ()
    else:
        return (Sort(Remove(T,Maximum(T))))+(Maximum(T),)
def Maximum(T):
    return Reduce(returnGreater,T)
def Remove(T,E):
    if len(T)==0:
        return ()
    elif T[0] is E:
        return T[1:]
    else:
        return (T[0],)+Remove(T[1:],E)


#
#  TESTS. Tests for CSci 1913 Lab 3.
#
#    James Moen
#    11 Feb 19
#
#  Each test is worth 2 points, for 40 points total. Comments show what must be
#  printed to receive credit. Note that your function SORT must work for tuples
#  with negative elements.
#

print(Maximum((1,)))                      #  1                            2 pt.
print(Maximum((-2, -1)))                  # -1                            2 pt.
print(Maximum((1, 1)))                    #  1                            2 pt.
print(Maximum((1, 2, 3)))                 #  3                            2 pt.

print(Remove((), 1))                      #  ()                           2 pt.
print(Remove((1,), 1))                    #  ()                           2 pt.
print(Remove((0, 1), 0))                  #  (1,)                         2 pt.
print(Remove((0, 1, 2, 1, 3), 1))         #  (0, 2, 1, 3)                 2 pt.
print(Remove((0, 1, 2, 1, 3), 2))         #  (0, 1, 1, 3)                 2 pt.
print(Remove((1, 2, 3), 3))               #  (1, 2)                       2 pt.

print(Sort(()))                           #  ()                           2 pt.
print(Sort((0,)))                         #  (0,)                         2 pt.
print(Sort((0, -1)))                      #  (-1, 0)                      2 pt.
print(Sort((1, 0)))                       #  (0, 1)                       2 pt.
print(Sort((0, 0, 1)))                    #  (0, 0, 1)                    2 pt.
print(Sort((0, -1, 0)))                   #  (-1, 0, 0)                   2 pt.
print(Sort((0, 0, 1)))                    #  (0, 0, 1)                    2 pt.

print(Sort((9, 8, 7, 6, 5, 4, 3, 2, 1)))  #  (1, 2, 3, 4, 5, 6, 7, 8, 9)  2 pt.
print(Sort((1, 2, 3, 4, 5, 6, 7, 8, 9)))  #  (1, 2, 3, 4, 5, 6, 7, 8, 9)  2 pt.
print(Sort((1, 2, 1, 4, 2, 5, 4, 5, 3)))  #  (1, 1, 2, 2, 3, 4, 4, 5, 5)  2 pt.
