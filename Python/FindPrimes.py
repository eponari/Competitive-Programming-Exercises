"""
  Find Prime Numbers
  In a certain range, find the number of prime number

  Test case:
  10 20

  Output:
  4

  Solution:
  Use the idea of Sieve of Eratosthenes(https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes).
  While we find Primes, make sure to store them and delete their multiples as we seen it in the range.
  In the end use a list comprehansion comprehension to target the primes within our range.
"""

#The only even prime number is going to be our starting point
primes=[2]

def findPrimes(lowerLimit,upperlimit):
  #we know that primes expect 2 are all odd, so we start from 3 until upperLimit and add 2 each itteration: 3,5,7,9...
  for number in range(3,upperlimit+1,2):
    for prime in primes:
      #according to number theory,a non-prime number should have a factor smaller or equal to its squared root.  
      if prime>number**(0.5):
        primes.append(number)
        break
      #if it is divisable then it isn't prime and we need to move on
      if number%prime==0:
        break
  desiredPrimes=[x for x in primes if x>=lowerLimit and x<=upperlimit]
  #return the number of primes within limits
  return len(desiredPrimes)

#list comprehension trick to get multiple inputs from a line in Python 
lowerLimit,upperLimit=[int(x) for x in input().split()]

print(findPrimes(lowerLimit,upperLimit))