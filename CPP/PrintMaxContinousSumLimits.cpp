/*
  Print the maximum continous sum limits.
  You are given n numbers. You have to print the left and right index of the maximum continous sum in this array of numbers.

  Test Case:
  9

    2 -5 2 6 7 -10 11 -6 8

  Output:
  3 9

  Solution:
  We use dynamic programming to find the maximum continous sum for every index. If we have to start over with a new left to have a maximum, 
  we create a new left each time we have to do this. It helps us keep track of the maximum sub array.   
*/

#include <iostream>
#include <vector>
using namespace std;

vector <int> seq;

void largestContinousSum(){
  //suppose the max sub array starts and ends at 0.
  int maxSeqNow=seq[0];
  int maxSeqEver=seq[0];
  int leftNow=0,left=0;
  int rightNow=0,right=0;
  //starting from 1
  for(int i=1;i<seq.size();i++){
    //if a element is equal to 0, skip it since it doesn't effect our sum.
    if(seq[i]==0){
      continue;
    }
    //right now is the value where we are at.
    rightNow=i;
    //if it is better to start over from the index where we are at.
    if(maxSeqNow+seq[i]<seq[i]){
      //redeclare maxSeqNow and leftNow.
      maxSeqNow=seq[i];
      leftNow=i;
    }
    else{
      //else just move on.
      maxSeqNow=maxSeqNow+seq[i];
    }
    //if max we have now is bigger that we have ever seen.
    if(maxSeqNow>maxSeqEver){
      //maxSeqEver is maxSeqNow and we move left and right.
      maxSeqEver=maxSeqNow;
      left=leftNow;
      right=rightNow;
    }
  }
  //print the left and right.
  cout<<left+1<<" "<<right+1;
}

int main() {
  //get n and n integers.
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    int number;
    cin>>number;
    seq.push_back(number);
  }
  largestContinousSum();
}