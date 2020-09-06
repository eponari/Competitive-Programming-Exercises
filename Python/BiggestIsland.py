"""
    Find The Most Crowded Island
    A map is given as a mxn matrix. Each element that is negative or 0 represents the ocean and the positive numbers represent the number of 
    people living in a certain area. Find the most crowded island in this map.

    Test Case:
    4 4
    1 -40 11 17
    -3 -12 -32 4
    -28 -22 -26 -11
    8 10 -37 -36

    Output:
    32

    Explanation:
    The biggest island contain the cells 11(1,3),17(1,4) and 4(2,4).

    Solution:
    We can choose to solve this problem recursively. Keep track of the visited cells so we don't additional work and each time we need to see if:
    1.a cell is positive
    2.hasn't been visited 
    3.the coordinates are within the grid of the matrix.
    If all these conditions are fulfilled, then move to this cell and add its value to our result.
    We iterate through each mxn element and if we have seen it we don't have to call the function at all. 
"""


#get the matrix
m,n=[int(x) for x in input().split()]

matrix=[]

for i in range(m):
  row=[int(x) for x in input().split()]
  matrix.append(row)

#this is a piece of code that we are going to reuse many times so we can just make it a function to reduce redundancy.
def getMaxIsland(seen,x=0,y=0):
  #each iteration check if this point is on our seen list.
  point=[x,y]
  if(point in seen):
    return 0
  #add the point to the seen list and check the other 2 conditions above for each of 4 directions.
  seen.append(point)
  res=matrix[x][y]
  if(x!=0 and matrix[x-1][y]>0):
    res+=getMaxIsland(seen,x-1,y)
  if(y!=0 and matrix[x][y-1]>0):
    res+=getMaxIsland(seen,x,y-1)
  if(x!=m-1 and matrix[x+1][y]>0):
    res+=getMaxIsland(seen,x+1,y)
  if(y!=n-1 and matrix[x][y+1]>0):
    res+=getMaxIsland(seen,x,y+1)
  return res

#We suppose we don't have a island at all in the start so no population.
maximum=-1
seen=[]

#iterate through each iteration element and keep track of the maximum value we can get. 
for i in range(m):
  for j in range(n):
    if(matrix[i][j]>0):
      maximum=max(maximum,getMaxIsland(seen,i,j))

#print the maximum we found
print(maximum)
