"""
  Check if a string is a palindrome.
  You are given a string and you should create a program to tell if the string is a palindrome or not.

  Test case:
  racecar

  Output:
  This is a palindrome.

  Solution:
  A palindrome is a word that is read the same even if it is writen in backwards. To check this we just have to check if the string is equal to
  the same string in reverse. Python has a build in function for strings to find the reverse of a string.
"""

def isPalindrome(word):
  #word[::-1] returns word string in reverse and this is the only condition we need to check.
  return word==word[::-1]

word=input()

if(isPalindrome(word)):
  print("This is a palindrome.")
else:
  print("This isn't a palindrome.")