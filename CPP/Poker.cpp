/*
    Poker hands

    There are given 5 are integers. Among them:
    If there are 5 same integers, then print "Impossible",
    otherwise if there are 4 same integer, then print "Four of a Kind",
    otherwise if there are 3 by 2, then print "Full House",
    otherwise if the integers are consecutive (sorting not important), then print "Straight",
    otherwise if there are 3 same integers, print "Three of a Kind",
    otherwise if there are 2 by 2 by 1, then output "Two Pairs",
    otherwise if there are 2 same integers, then output "One Pair",
    otherwise print "Nothing".

    Test Case:
    1 5 2 4 3

    Output:
    Straight

    Solution:
    Since the cards are given with intiger numbers from 1 to 13, we can sort them and turn the problem from a problem dealing with permutations,
    to a problem dealing with combinations.(basiclly the order of elements doesn't matter and there are less cases in combinations than in permutations.)
    After this, we can just take the statements that we are given and start with the ones with less probability to the ones that are more likely.
*/

#include <iostream>
#include <algorithm>
using namespace std;

bool straight(int cards[],int pos=0){
  //we have reached the end without a false statement so it is true
  if(pos==4){
    return true;
  }
  //see if the next card is the current card+1 and redo the funtion for the next card recursively
  return (cards[pos]==cards[pos+1]-1)&&straight(cards,pos+1);
}

string pokerHand(int cards[]){
  //sort them to make the if statements easier to understand
  sort(cards,cards+5);
  //we suppose that the hand has none of the combinations
  string result="Nothing";
  //if the first if equal to the last when they are sorted, all of them have the same value, but there can't be 5 of a kind in a normal deck of cards
  if(cards[0]==cards[4]){
    result="Impossible";
  }
  //check if 1st to 4th or 2nd to 5th are the same to have four of a kind 
  else if(cards[0]==cards[3]||cards[1]==cards[4]){
    result="Four of a Kind";
  }
  //use function to see if it is a straight
  else if(straight(cards)){
    result="Straight";
  }
  //check for a combination of 2 same cards and 3 same cards by checking(1st==3rd and 4th==5th or 1st==2nd and 3rd==5th)
  else if((cards[0]==cards[2]&&cards[3]==cards[4])||(cards[0]==cards[1]&&cards[2]==cards[4])){
    result="Full House";
  }
  //check combinations of 3 cards having the same value
  else if(cards[0]==cards[2]||cards[1]==cards[3]||cards[2]==cards[4]){
    result="Three of a Kind";
  }
  //check for 2 pairs with all their combinations
  else if((cards[0]==cards[1]&&(cards[2]==cards[3]||cards[3]==cards[4]))||(cards[1]==cards[2]&&cards[3]==cards[4])){
    result="Two Pairs";
  }
  //check for a pair in 5 cards
  else if(cards[0]==cards[1]||cards[1]==cards[2]||cards[2]==cards[3]||cards[4]==cards[3]){
    result="One Pair";
  }
  return result;
}

int main(){
  int cards[5];
  for(int i=0;i<5;i++){
    cin>>cards[i];
  }
  string yourHand=pokerHand(cards);
  cout<<yourHand;
}
