"""
    Find people with least connections

    Police is running after a thief. They think that the thief is trying to hide himself and very few people know him.
    Possible candidates are known in the region by less than a number given (k).
    Write a program that will read list of people and a list of friendship relations.
    Then, the program lists possible candidates which are known by less than k people.
    Note that a person cannot be the friend of himself. As in the example Jonara knows herself too, but this is not count as another person.

    Test Case:
    6 3
    Nail
    Klajd
    Imelda
    Jonara
    Lori
    Luela
    10
    Imelda Lori
    Lori Nail
    Jonara Imelda
    Nail Luela
    Klajd Nail
    Jonara Lori
    Klajd Imelda
    Lori Jonara
    Jonara Jonara
    Luela Lori

    Output:
    3
    Jonara
    Klajd
    Luela

    Explanation:
    We can use a disctionary to keep track of the friends each person has. We make sure they don't add themselves as friends.
    After that for each person we iterate through their friends recursively and look who has less than k friends.
    Keep them in a list of suspects and print in the end the length of the list and each name in the list.
"""

#dictionary to keep track of friends.
friends={}

#take number of people and k.
numOfPeople,k=[int(x) for x in input().split()]

#take the  name of each person and initialize a list in the dictionary above.
for i in range(numOfPeople):
  name=input().strip()
  friends[name]=[]

#take the number of connections.
numOfFriendships=input()
numOfFriendships=int(numOfFriendships)

#take the friendships.
for i in range(numOfFriendships):
  person_A,person_B=input().split(" ")
  person_A.strip()
  person_B.strip()
  #check that the person doesn't add himself.
  if person_A!=person_B:
    friends[person_A].append(person_B)
    friends[person_B].append(person_A)

#create a list to keep track of potential suspects.
suspects=[]

#iterate through friends dictionary using .items() method.
for name,listOfFriends in friends.items():
  #set creates a list without duplicates to make sure that we don't have a friend twice.
  listOfFriends=list(set(listOfFriends))
  #if the length of this list is less than k, this person is a suspect.
  if len(listOfFriends)<k:
    suspects.append(name)

#print the length of the list and each suspect.
print(len(suspects))
for name in suspects:
  print(name)
