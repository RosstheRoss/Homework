def ADDYHASHSEARCH(T,k):
    i=0
    j=0
    s=1
    m=len(T)
    while T[j]!=None and i<=m:
        j=(h(k)+i)%m
        if T[j] is k:
            return j
        else:
            i=i+s
            s=s+2
    return -1

def h(k):
    return k*2

T = [0,None,1,None,2,None,3,None,4]
print(ADDYHASHSEARCH(T,1))
print(ADDYHASHSEARCH(T,3))
print(ADDYHASHSEARCH(T,5))