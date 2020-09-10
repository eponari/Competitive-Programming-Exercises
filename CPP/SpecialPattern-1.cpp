/*
  Special Pattern

  Write a program that asks for a number n and then draws n*n matrice which is completely filled with ones and zeros in borders like this:

  Test Case:
  3
  1 1 1
  1 0 1
  1 1 1

  Solution:
  We see that we have to deal only with borders of a matrix. A matrix has n/2 borders so we can use that fact to work with borders.
  Now to verify if a cell is in the border we have to check of one of these conditions:
  -x is equal to the border.
  -y is equal to the border.
  -x is equal to the symmetric with respect to n/2 or n minus border.
  -y is equal to the symmetric with respect to n/2 or n minus border.
  To start from a border with 1's , we give the value of the cells in the border cell=(border+1)%2.(because we start from 0).
*/

#include <iostream>
using namespace std;

int main() {
  //get the size n.
  int n;
  cin>>n;
  //initialize a nxn matrix.
  int num[n][n];
  //we have n/2 borders to deal with.
  for(int border=0;border<=n/2.0;border++){
    //deal with mini matrix from the border we are until n-border.
    for(int i=border;i<n-border;i++){
      for(int j=border;j<n-border;j++){
        //we check if the cell is in the border and give it the value of (border+1)%2, the first border is with 1's always.
        if((i==border||j==border||j==n-1-border||i==n-1-border)){
          num[i][j]=(border+1)%2;
        }
      }
    }
  }
  //print the matrix.
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cout<<num[i][j]<<" ";
    }
    cout<<endl;
  }
}
