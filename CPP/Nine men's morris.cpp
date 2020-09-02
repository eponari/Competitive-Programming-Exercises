/*
    Nine Men's Morris game

    In this game, you try to create lines of 3 rocks in a unique board. (Photo:https://upload.wikimedia.org/wikipedia/commons/thumb/a/ab/Nine_Men%27s_Morris_board_with_coordinates.svg/1200px-Nine_Men%27s_Morris_board_with_coordinates.svg.png)
    Create a program to get 4 rocks that a user has in the board and determine if he has created a line of 3 rocks or not.

    Test Case:
    a7 d6 d7 g7

    Output:
    Yes
*/

/*
    Solution:
    Since the positions are given with strings from a character and a number, we can sort them and turn the problem from a problem dealing with permutations,
    to a problem dealing with combinations.(basiclly the order of elements doesn't matter and there are less cases in combinations than in permutations.)
    After this, we should study the unique form of the board used for this game and conclude that there are only 16 ways to form a line.
    Group the positions we have 3 by 3 and if one of them fills the requirments, then we conclude that we have at least one line.
*/

#include <iostream>
#include <algorithm>
using namespace std;

string possibleLines[16][3]={
  {"a1","d1","g1"},
  {"a7","d7","g7"},
  {"a1","a4","a7"},
  {"g1","g4","g7"},
  {"b2","d2","f2"},
  {"b2","b4","b6"},
  {"b6","d6","f6"},
  {"f2","f4","f6"},
  {"c3","c4","c5"},
  {"e3","e4","e5"},
  {"c3","d3","e3"},
  {"c5","d5","e5"},
  {"a4","b4","c4"},
  {"e4","f4","g4"},
  {"d1","d2","d3"},
  {"d5","d6","d7"}
};

bool isLine(string rock1,string rock2,string rock3){
  //check each of 16 combinations that this game has.
  for(int i=0;i<16;i++){
    if(rock1==possibleLines[i][0]&&rock2==possibleLines[i][1]&&rock3==possibleLines[i][2]){
      return true;
    }
  }
  //if none of 16 winning combinations doesn't match with these 3 rocks, then it isn't a line
  return false;
}

int main(){
  string pos[4];
  for(int i=0;i<4;i++){
    cin>>pos[i];
  }
  //sort the positions so we can deal with combination rather than permutations(there are fewer combination).
  sort(pos,pos+4);
  //check every combination of 3 rocks from the 4 given.If one of them is true,that is enough for us so we can use ||(or). 
  if(isLine(pos[0],pos[1],pos[2])||isLine(pos[0],pos[1],pos[3])||isLine(pos[1],pos[2],pos[3])||isLine(pos[0],pos[2],pos[3])){
    cout<<"Yes";
  }
  else{
    cout<<"No";
  }
}