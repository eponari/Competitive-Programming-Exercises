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
"""

n=int(input())
cnt=0
lst1=[[] for i in range(n)]
for i in range(n):
    lst1[i]=input().split()
lst2=[[] for i in range(n)]
for i in range(n):
    lst2[i]=input().split()
    for j in range(len(lst2[i])):
        if not lst1[i][j]==lst2[i][j][::-1]:
            cnt+=1
print(str(cnt))
