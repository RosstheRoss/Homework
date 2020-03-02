def CHILD(i,j):
    return 2*i + (j+1)

def IS_IN_MIN_HEAP(A,e):
    return FIND_ELEMENT(A,0,e)
def FIND_ELEMENT(A,i,e):
    if A[i] is e:
        return True
    else:
        bool = False
        lChild = CHILD(i, 0)
        rChild = CHILD(i, 1)
        if lChild < len(A) and A[lChild] <= e:
            bool = FIND_ELEMENT(A, lChild, e)
        if bool is not True and rChild < len(A) and A[rChild] <= e:
            bool = FIND_ELEMENT(A, rChild, e)
    return bool

#TEST MIN-HEAP
#Feel free to redefine as much as you want
l = [0, 2, 3, 5, 6, 8, 9]

#TESTS
print(IS_IN_MIN_HEAP(l, 0))
print(IS_IN_MIN_HEAP(l, 1))
print(IS_IN_MIN_HEAP(l, 2))
print(IS_IN_MIN_HEAP(l, 3))
print(IS_IN_MIN_HEAP(l, 4))
print(IS_IN_MIN_HEAP(l, 5))
print(IS_IN_MIN_HEAP(l, 6))
print(IS_IN_MIN_HEAP(l, 7))
print(IS_IN_MIN_HEAP(l, 8))
print(IS_IN_MIN_HEAP(l, 9))
