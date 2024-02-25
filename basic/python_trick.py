int(eval(num.replace("/","//"))) # parser string num

from fractions import Fraction
from decimal import Decimal, getcontext
getcontext().prec = 250 # set precision (MAX_PREC)
getcontext().Emax = 250 # set exponent limit (MAX_EMAX)
getcontext().rounding = ROUND_FLOOR # set round floor
itwo,two,N = Decimal(0.5),Decimal(2),200
def angle(cosT):
  """given cos(theta) in decimal return theta"""
  for i in range(N):
    cosT = ((cosT + 1) / two) ** itwo
  sinT = (1 - cosT * cosT) ** itwo
  return sinT * (2 ** N)
pi = angle(Decimal(-1))
Fraction('3.1415926535897932').limit_denominator(1000)

format(x, '0.10f') # set precision

x = Fraction(1, 2), y = Fraction(1)
print(x.as_integer_ratio()) # print 1/2
print(x.is_integer()) # return is divisible
print(x.__round__()) 
print(float(x)) # print 0.5