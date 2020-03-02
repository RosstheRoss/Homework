def CHILD(i,j):
    return 2*i + (j+1)
def IS_IN_MIN_HEAP(A,e):
    return FIND_ELEMENT(A,0,e)
def FIND_ELEMENT(A,i,e):
    if A[i] is e:
        return True
    elif CHILD(i,0) < len(A) and A[CHILD(i,0)] <= e:
        return IS_IN_MIN_HEAP(A[1:],e)
    if CHILD(i,1) < len(A) and A[CHILD(i,1)] <= e:
        return IS_IN_MIN_HEAP(A[2:],e)
    return False

#TEST MIN-HEAP
#Feel free to redefine as much as you want
l = [0, 2, 4, 5, 8, 12, 20]

#TESTS
print(IS_IN_MIN_HEAP(l, 0))
print(IS_IN_MIN_HEAP(l, 1))
print(IS_IN_MIN_HEAP(l, 2))
print(IS_IN_MIN_HEAP(l, 3))
print(IS_IN_MIN_HEAP(l, 4))
print(IS_IN_MIN_HEAP(l, 5))
print(IS_IN_MIN_HEAP(l, 8))
print(IS_IN_MIN_HEAP(l, 10))
print(IS_IN_MIN_HEAP(l, 11))
print(IS_IN_MIN_HEAP(l, 20))
