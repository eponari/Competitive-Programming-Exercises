"""
    Are these 2 person connected?
    You are given n person with numbers from 1 to n and k connections between them.
    Given 2 people, find out if they are connected in this graph or not.

    Test Case:
    4 3
    4 2
    1 3
    3 4
    1 2

    Output:
    Yes

    Explanation:
    4-2
    |
    3-1
    1 and 2 are connected.

    Solution:
    We need to create a graph to give the connections of each person to their friends.
    We have n and k and take n connections and connect the first to the second and vice versa.
    We take the startingPerson and finalPerson and using a funtion we find out if they are connected.
    To do this we use Depth First Search with recursion. We ask each friend if they know this person and ask each friend
    of them the same question until we find the person we are interested in or we run out of people to ask.
    We keep track of already asked people using a list called seen.
"""

#graph with connections.
graph={}

#function to tell us if 2 people are connected or not.
def find_min_way(currentPerson,finishingPerson,seen=[]):
  #if the current person is the person we want to see in the finish, return 1.
  if(currentPerson==finishingPerson):
    return 1
  #if this person has already been seen, there is no point in recalculating this result.
  if(currentPerson in seen):
    return 0
  #now we have seen the currentPerson
  seen.append(currentPerson)
  #friend in the connections of currentPerson
  for friend in graph[currentPerson]:
    #result is calling this function again for each friend with the finishingPerson and a copy of seen people until now.
    res=find_min_way(friend,finishingPerson,seen[:])
    #if res is 1, we found a true value, so we just return 1. 
    if res==1:
      return 1
  #if none of our connections return 1, they are not connected and return 0 for false.
  return 0

#take n and k.
n,k=[int(x) for x in input().split()]

#initialize each person with a empty list, they have no connections when we start.
for i in range(1,1+n):
  graph[i]=[]

#take k connections.
for i in range(k):
  #take ID of person1 and person2 and connect them to each other.
  person1,person2=[int(x) for x in input().split()]
  graph[person1].append(person2)
  graph[person2].append(person1)

#take the starting and finishing people.
startingPerson,finishingPerson=[int(x) for x in input().split()]

#call the function are print Yes if it is true.
#else print No
res=find_min_way(startingPerson,finishingPerson)

if(res==1):
  print("Yes")
else:
  print("No")