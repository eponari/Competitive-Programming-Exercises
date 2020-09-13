/*
    Ladders

    You are given a numbers of identical cubes. Write a program to calculate the number of diffent ladders you can create with them.
    To form a ladder, each level should have less cubes than the last level.
    Test case:
    3

    Output:
    2

    Explanation:
    Ladder nr.1:         Ladder nr.2:
    *                    ***
    **
    
    Solution:
    This is a generally hard problem to create a efficent algorithm because we have repetition of the same element many times.
    To eleminate this, we can use Dynammic Programming and Memoization in order to reduce repetitive work. 
*/


#include <iostream>
using namespace std;

int memory[1000000];

#include <iostream>
using namespace std;

int findNumOfLadders(int cubesLeft,int previous=0){
  //if we don't have any cubes left, then we have created a ladder and return 1 to indicate that this ladder is successful.
  if(cubesLeft==0){
    return 1;
  }
  //if we have a negative number of cubesLeft, it means we need more cubes and this indicates that this ladder wasn't successful.
  if(cubesLeft<0){
    return 0;
  }
  //if we have memoized the solution of this funtion before, just return it.
  if(memory[cubesLeft]!=0){
      return memory[cubesLeft];
  }
  //count number of ladders with all possible outcomes.
  int res=0;
  for(int usedCubes=previous+1;usedCubes<=cubesLeft;usedCubes++){
    int new_res=findNumOfLadders(cubesLeft-usedCubes,usedCubes);
    //add them to our result each time the variable usedCubes changes
    res+=new_res;
  }
  //memoize the result and return it.
  memory[cubesLeft]=res;
  return res;
}

int main() {
  int cubes;
  cin>>cubes;
  cout<<findNumOfLadders(cubes);
}
