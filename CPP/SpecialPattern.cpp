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
using namespace std;

int main() {
  //we start from border 0 and from number 1 when creating the pattern.
  int border=0,seed=1,size;
  cin>>size;
  //create a 2D array and find the number of borders it has.
  int numbers[size][size];
  int borders=(1+size)/2;
  //iterate through each broder
  while(border<borders){
    int i=border;
    //iterate through the element of each border
    while(i<size-1-border){
      //deal with the 4 elements in each iteration in the borders
      numbers[border][i]=seed++;
      numbers[i][size-1-border]=seed++;
      numbers[size-1-border][size-i-1]=seed++;
      numbers[size-1-i][border]=seed++;
      i++;
    }
    border++;
  }
  //if we have a even number of elements, the middle one wasn't reached so we assign it now
  if(size%2==1){
    numbers[size/2][size/2]=seed;
  }
  //print the 2D array.
  for(int i=0;i<size;i++){
    for(int j=0;j<size;j++){
      cout<<numbers[i][j]<<" ";
    }
    cout<<"\n";
  }
}