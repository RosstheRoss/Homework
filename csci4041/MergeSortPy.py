def head(Q):
    return Q[0]
def tail(Q):
    return Q[1:]
def mergesort(U):
    if U == [] or tail(U) == []:
        return U
    else:
        L = []
        R = []
        while U != [] and tail(U) != []:
            L = L+[head(U)]
            U = tail(U)
            R = R+[head(U)]
            U = tail(U)
        L = L + U
        L = mergesort(L)
        R = mergesort(R)
        s = []
        while L != [] and R != []:
            if head(L) <= head(R):
                s = s + [head(L)]
                L = tail(L)
            else:
                s = s + [head(R)]
                R = tail(R)
        s = s + L + R
        return s

print(mergesort([9,3,7,5,6,4,8,2]))