def left(exp):
	return exp[0]
def op(exp):
	return exp[1]
def right(exp):
	return exp[2]


def isInside(var, e):
	if type(e) is tuple:
		return isInside(var, left(e)) or isInside(var, right(e))
	elif type(e) is str:
		return var==e
	else:
	    return -1

def solve(v, e):
	if isInside(v, left(e)):
		return solving(v, e)
	elif isInside(v,right(e)):
		newE=(right(e),op(e),left(e))
		return solving(v,newE)
	    #Solving defined on line 52
	else:
		return None

#Four major solving means
def solvingAdd(v,q):
	if isInside(v, left(left(q))):
		return left(left(q)), '=', (right(q), '-', right(left(q)))
	else:
		return right(left(q)), '=', (right(q), '-', left(left(q)))
def solvingSubtract(v,q):
	if isInside(v, left(left(q))):
		return left(left(q)), '=', (right(q), '+', right(left(q)))
	else:
		return right(left(q)), '=', (left(left(q)), '-', right(q))
def solvingMultiply(v,q):
	if isInside(v, left(left(q))):
		return left(left(q)), '=', (right(q), '/', right(left(q)))
	else:
		return right(left(q)), '=', (right(q), '/', left(left(q)))
def solvingDivide(v,q):
	if isInside(v, left(left(q))):
		return left(left(q)), '=', (right(q), '*', right(left(q)))
	else:
		return right(left(q)), '=', (left(left(q)), '/', right(q))

#Dict based off of lecture 13th Sept. 2019
dispatcher={'+':solvingAdd,'-':solvingSubtract,'*':solvingMultiply,'/':solvingDivide}

def solving(v,q):
    if left(q) is v:
        return q
    else:
        if op(left(q)) in dispatcher:
		    newQ=dispatcher[op(left(q))](v,q)
        else:
            raise ValueError
    return solving(v,newQ)

#
#  TESTS. Test the equation solver for CSci 1913 Lab 1.
#
#    James Moen
#    10 Sep 18
#
#  Every test is followed by a comment which shows what must be printed if your
#  code works correctly. It also shows how many points the test is worth, for a
#  total of 35 possible points.
#

print(isInside('x', 'x'))                          #  True   1 point
print(isInside('x', 'y'))                          #  False  1 point
print(isInside('x', ('x', '+', 'y')))              #  True   2 points
print(isInside('x', ('a', '+', 'b')))              #  False  2 points
print(isInside('+', ('a', '+', 'b')))              #  False  2 points
print(isInside('x', (('m', '*', 'x'), '+', 'b')))  #  True   2 points

print(solve('x', (('a', '+', 'x'), '=', 'c')))
#  ('x', '=', ('c', '-', 'a'))  2 points

print(solve('x', (('x', '+', 'b'), '=', 'c')))
#  ('x', '=', ('c', '-', 'b'))  2 points

print(solve('x', (('a', '-', 'x'), '=', 'c')))
#  ('x', '=', ('a', '-', 'c'))  2 points

print(solve('x', (('x', '-', 'b'), '=', 'c')))
#  ('x', '=', ('c', '+', 'b'))  2 points

print(solve('x', (('a', '*', 'x'), '=', 'c')))
#  ('x', '=', ('c', '/', 'a'))  2 points

print(solve('x', (('x', '*', 'b'), '=', 'c')))
#  ('x', '=', ('c', '/', 'b'))  2 points

print(solve('x', (('a', '/', 'x'), '=', 'c')))
#  ('x', '=', ('a', '/', 'c'))  2 points

print(solve('x', (('x', '/', 'b'), '=', 'c')))
#  ('x', '=', ('c', '*', 'b'))  2 points

print(solve('y', ('y', '=', (('m', '*', 'x'), '+', 'b'))))
# ('y', '=', (('m', '*', 'x'), '+', 'b'))  2 points

print(solve('x', ('y', '=', (('m', '*', 'x'), '+', 'b'))))
# ('x', '=', (('y', '-', 'b'), '/', 'm'))  2 points

print(solve('a', (('b', '+', 'c'), '=', ('d', '*', (('a', '/', 'e'), '-', 'f')))))
# ('a', '=', (((('b', '+', 'c'), '/', 'd'), '+', 'f'), '*', 'e'))  5 points