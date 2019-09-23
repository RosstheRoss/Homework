class Zillion:
  def __init__(self,digits):
    self.digits = digits
    self.__x=0
    self.List = []
    self.toList()
  def toList(self):
    badBoolean=False
    if len(self.digits) == 0:
      raise RuntimeError      #Cannot make a list of nothing
    for n in range (0,len(self.digits)):
      if self.digits[n] is not ',':
        if self.digits[n] is not ' ':
          try:
            self.List+=[int(self.digits[n])]
            badBoolean=True
          except ValueError:
            raise RuntimeError
    if badBoolean is False:
      raise RuntimeError
    else:
      return self.List
  def increment(self):
    length = len(self.List) - 1
    newList = self.List
    newList[len(self.List)-1] += 1
    if newList[length]>=10:
      for n in range (0,length):
        newList[length-n]=0
        newList[length-n-1]+=1
  def isZero(self):
    for p in range (0,len(self.List)-1):
      if self.List[p] is not 0 or not '0':
        return False
    return True
  def toString(self):
    string=''
    for q in range (0,len(self.List)):
      string+=str(self.List[q])
    return string



#
#  TESTS. Test the class Zillion for CSci 1913 Lab 2.
#
#    James Moen
#    18 Sep 17
#
#  Every test is followed by a comment which shows what must be printed if your
#  code works correctly. It also shows how many points the test is worth.
#

try:
  z = Zillion('')
except RuntimeError:
  print('Empty string')

# It must print 'Empty string' without apostrophes. 2 points.

try:
  z = Zillion(' , ')
except RuntimeError:
  print('No digits in the string')

# It must print 'No digits in the string' without apostrophes. 2 points.

try:
  z = Zillion('1+0')
except RuntimeError:
  print('Non-digit in the string')

# It must print 'Non-digit in the string' without apostrophes. 2 points.

try:
  z = Zillion('0')
except RuntimeError:
  print('This must not be printed')

#  It must print nothing. 2 points.

print(z.isZero())    #  It must print True. 2 points.

try:
  z = Zillion('000000000')
except RuntimeError:
  print('This must not be printed')

#  It must print nothing. 2 points.

print(z.isZero())    #  It must print True. 2 points.

try:
  z = Zillion('000 000 000')
except RuntimeError:
  print('This must not be printed')

#  It must print nothing. 2 points.

print(z.isZero())    #  It must print True. 2 points.

try:
  z = Zillion('997')
except RuntimeError:
  print('This must not be printed')

#  It must print nothing.  2 points.

print(z.isZero())    #  It must print False. 2 points.

print(z.toString())  #  It must print 997. 2 points.

z.increment()

print(z.toString())  #  It must print 998. 2 points.

z.increment()

print(z.toString())  #  It must print 999. 2 points.

z.increment()

print(z.toString())  #  It must print 1000. 2 points.

try:
  z = Zillion('0 9,9 9')
except:
  print('This must not be printed')

#  It must print nothing.  3 points.

z.increment()
print(z.toString())  #  It must print 1000. 2 points.
