"""
  Find the minimum value taking a path while jumping 1 cell.
  You are given n numbers. You can take a number or jump over it.Find the minimum path.

  Test case:
  4
  2 3 4 5

  Output:
  6

  Explanation:
  Get first number(2) and third number(4). Jump over the 4th and finish.

  Solution:
  We use memoization to solve the problem for smaller problems. Each time we calculate a path, save the minimum path in memory
  and use it over time if we need to do it again.
"""

#get the size of the array and the numbers
n=input()
n=int(n)
numbers=[int(x) for x in input().split()]

#memory for each instance is 0 for the moment
memory=[0 for i in range(n)]

def findMinPath(pos):
  #if pos is bigger than the size of the array break by returning 0
  if(pos>=n):
    return 0
  
  #if memory isn't 0, we have already calculated this and we don't need to redo it.
  if(memory[pos]!=0):
    return memory[pos]
  #we have 2 posibilities: go to the next pos or skip 1
  res=numbers[pos]+min(findMinPath(pos+1),findMinPath(pos+2))
  #save the res in memory
  memory[pos]=res
  #return res
  return res

#start from 0 or 1 depends if we skip the first element
print(min(findMinPath(0),findMinPath(1)))
