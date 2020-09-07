"""
  Find the kth permutation.
  Given n and k , find the kth permutation on n numbers.

  Test case:
  6 23

  Output:
  1 2 6 5 3 4

  Solution:
  Permutation is uses factorial to find the number of ways some numbers can be arranged.
  We use this to find the biggest number that fits in the kth permutation that has yet to be used.
  To make the factorial do less redundant work, we uses memoization to keep track of the previous results of our factorial.
"""

#we know that 0!=1 and 1!=1.
memoryOfFactorial={
  0:1,
  1:1
}

#recursively find factorial using previous results.
def factorial(n):
  if(n in memoryOfFactorial):
    return memoryOfFactorial[n]
  res=factorial(n-1)*n
  memoryOfFactorial[n]=res
  return res

#take n and k as input and create a list of n numbers.
n,k=[int(x) for x in input().split()]

numbers=[x for x in range(1,n+1)]

#while the list of numbers isn't empty
while(len(numbers)!=0):
  #find the ways left and use that to find the position of the number we need to print.
  waysLeft=factorial(len(numbers)-1)
  position=int((k-1)/waysLeft)
  #lower k since we eleminate some possible ways to create a premutation when we remove a number from the list.
  k-=position*waysLeft
  print(numbers[position],end=" ")
  numbers.pop(position)
