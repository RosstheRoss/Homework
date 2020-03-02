
# Watch the value of K!!!
# - Jeremiah
def making_sets(n, k, e, s):
    if k == 0:
        print(s)
    else:
        for e_i in range(e, n + 1):
            s = set.union(s, {e_i})
            making_sets(n, k - 1, e_i + 1, s)
            s = set.difference(s, {e_i})

def make_sets(n, k):
    making_sets(n, k, 1, set())

make_sets(4,3)
print()
make_sets(6,1)
