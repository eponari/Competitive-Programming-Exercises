/*
  Special Pattern
  Create a pattern by using a 2D array.The steps are:
  -First you put 4 numbers to the corners of the square.
  -Then you write 4 other numbers next to each corner until finish outer layer of the square. 
  -After you finish this layer, you go to the inner layer and you repeat.

  Test Case:
  4

  Output:
  1 5 9 2
  12 13 14 6
  8 16 15 10
  4 11 7 3

  Solution:
  Just follow the algorithm given above. What we have to be careful with are 2 things:
  1. The borders in a matrix are given by the value int((1+size)/2).
  2. If the size is odd, we need to take care of the element in the middle of the matrix because the borders above are for even numbers.
*/

#include <iostream>
#include <vector>
using namespace std;

vector <int> seq;

void largestContinousSum(){
  int maxSeqNow=seq[0];
  int maxSeqEver=seq[0];
  int leftNow=0,left=0;
  int rightNow=0,right=0;
  for(int i=1;i<seq.size();i++){
    if(seq[i]==0){
      continue;
    }
    rightNow=i;
    if(maxSeqNow+seq[i]<seq[i]){
      maxSeqNow=seq[i];
      leftNow=i;
    }
    else{
      maxSeqNow=maxSeqNow+seq[i];
    }
    if(maxSeqNow>maxSeqEver){
      maxSeqEver=maxSeqNow;
      left=leftNow;
      right=rightNow;
    }
  }
  cout<<left+1<<" "<<right+1;
}

int main() {
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    int number;
    cin>>number;
    seq.push_back(number);
  }
  largestContinousSum();
}