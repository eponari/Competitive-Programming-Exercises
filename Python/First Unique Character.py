"""
    You are given a string. Find the first unique non repeating character. If there are only repeated characters, print 
    "No unique char found".

    Test Case:
    uylerlluAjkH

    Output:
    y

    Solution:
    Initialize a empty list of unique characters as the result of our problem.
    Keep track of seen characters in this list and if a character isn't seen there, add it to them.
    If it is seen, delete it from unique as it can't be used because it is repeating and add it to nonUnique.
    If the length of the unique character list is 0, we don't have any unique characters in this string.
    Otherwise return the first unique character (unique[0]).

"""

def findFirstUniqueChar(txt):
    unique=[]
    nonUnique=[]
    #solved in linear time.
    for i in range(len(txt)):
        if txt[i] in nonUnique:
            continue
        if txt[i] in unique:
            unique.remove(txt[i])
            nonUnique.append(txt[i])
            continue
        unique.append(txt[i])
    if(len(unique)==0):
      return "No unique char found"
    return unique[0]

word=input()

print(findFirstUniqueChar(word))