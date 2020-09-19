"""
    You are give n lines of original text and n lines that a student wrote.
    The student is asked to write each word in the text in reverse.
    The program needs to find how many words has the student wrote wrong in reverse.

    Test Case:
    2
    The contest organization committee
    They want to form k equal level groups
    ehT tsetnc noitazinagro eettimmoc
    yehT tnow ot mrof k lauqe level spuorg

    Output:
    2

    Explanation:
    contest!=reverse(tsetnc) forgot to write "o"
    want!=reverse(tnow) "o" should be "a"

    Solution:
    Save each line of the original text as a list of words. Each line is saved in a list called text.
    Do the same for the text writen by the student. Now use the build in method of string [::-1] which returns the reverse.
    If we find that the reverse of the original isn't equal to our original word, increase mistakes by 1.
"""
#number of lines
n=int(input())

#at first we have 0 mistakes
mistakes=0

#initialize each row as a empty list by using list comprehansion.
originalText=[[] for i in range(n)]
#take each row by spliting the line each time we see a space.
for i in range(n):
  originalText[i]=input().split()

#initialize each row as a empty list by using list comprehansion.
studentText=[[] for i in range(n)]
#take each row by spliting the line each time we see a space.
for i in range(n):
  studentText[i]=input().split()
  #for each index in range of the length of row
  for j in range(len(studentText[i])):
    #if the reverse of the original word isn't equal to what the student wrote, increase mistakes by 1
    if not originalText[i][j][::-1]==studentText[i][j]:
      mistakes+=1
#print the number of mistakes
print(mistakes)
