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
#import a library to generate random numbers
import random

#user defined class to give the idea of a point and its distance from origin
class Point:
  def __init__(self,x,y):
    self.x=x
    self.y=y
  def distanceFromOrigin(self):
    return (self.x**2+self.y**2)**0.5

def randomNumber():
  positive=bool(random.randint(0,1)%2)
  if positive:
    return random.random()
  return -random.random()


pointsInsideRadius=0
seed=100000

for i in range(seed):
  newPoint=Point(randomNumber(),randomNumber())
  if(newPoint.distanceFromOrigin()<=1):
    pointsInsideRadius+=1

probOfPointInside=pointsInsideRadius/seed
circumOfSquare=2*2

PI=circumOfSquare*probOfPointInside

print(PI)