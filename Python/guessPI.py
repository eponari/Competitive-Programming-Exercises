"""
  Guess PI.
  You are given a function to guess decimal number from -1 to 1. Using this function, give an approximation of PI.

  Solution:
  The unit circle is a circle with radius one and is used a lot in trigonometry and calculus.
  We can use it to calculate PI. 
  We know that the circumface of this circle is PI*1*1=PI 
  so we can use the probability of a point to be in this circle to calculate PI. 
  The circumface of a square starting from -1 to 1 on both sides is (1-(-1))*(1-(-1))=(1+1)*(1+1)=4. 
  4*probability of a point to be in the circle will give PI.
"""
#import a library to generate random numbers.
import random

#user defined class to give the idea of a point and its distance from origin.
class Point:
  def __init__(self,x,y):
    self.x=x
    self.y=y
  def distanceFromOrigin(self):
    #"**" operator in python is used for powers, so **2 is squared and **0.5 is root square. 
    return (self.x**2+self.y**2)**0.5

#generates numbers from -1 to 1 for our unit circle.
def randomNumber():
  #choose random number from 0 and 1 and turn it to a bool.
  positive=bool(random.randint(0,1))
  #if positive return random.random() which is a method that returns numbers from 0 to 1.
  if positive:
    return random.random()
  #else return a negative number from 0 to 1.
  return -random.random()

#initially we have 0 points inside the circle and 100000 tests we want to conduct to have a better result.
pointsInsideRadius=0
seed=100000

#of i in the range of seed.
for i in range(seed):
  #create a new point using randomNumber() for x and y.
  newPoint=Point(randomNumber(),randomNumber())
  #if the distance from the orignin is 1 or less it is inside the cicle so increase the number of pointsInsideRadius by 1.
  if(newPoint.distanceFromOrigin()<=1):
    pointsInsideRadius+=1

#probability is favorable cases divided by total cases and the circumface of the square around unit cicle is 4 like explained above.
probOfPointInside=pointsInsideRadius/seed
circumOfSquare=2*2

#PI is this probability we found that is always 1 or less times the total circumface we can have in this square(impossible to have a point outside this square).
PI=circumOfSquare*probOfPointInside
#print the approximation of PI.
print(PI)