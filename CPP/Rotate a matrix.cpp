/*
  Rotate a matrix

  You are given a mxn matrix. Rotate it by a degree divisable by 90. Print the new matrix.

  Test Case:
  5 3
  7 9 17
  9 14 12
  6 11 7
  13 15 5
  5 7 7
  90

  Output:
  5 13 6 9 7
  7 15 11 14 9
  7 5 7 12 17

  Explanation:
  When rotating by 90 degree, the new matrix has reversed size so it is nxm.

  Solution:
  We know a complete rotation is 360 degree, so we care about degree%360.
  After this,we can create a case for each rotation and print the elements using simple rotation logic with loops.
*/

#include <iostream>
using namespace std;

int main() {
  //get the size and elements of the matrix.
  int m,n;
  cin>>m>>n;
  int matrix[m][n];
  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
      cin>>matrix[i][j];
    }
  }
  //get degree of rotation.
  int degree;
  cin>>degree;
  //switch for each case 0,90,180,270.
  switch(degree%360){
    //each case relies on loops to print the matrix in a different way.
    case 0:
      for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
          cout<<matrix[i][j]<<" ";
        }
        cout<<"\n";
      }
      break;
    case 90:
      for(int i=0;i<n;i++){
        for(int j=m-1;j>=0;j--){
          cout<<matrix[j][i]<<" ";
        }
        cout<<"\n";
      }
      break;
    case 180:
      for(int i=m-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
          cout<<matrix[i][j]<<" ";
        }
        cout<<"\n";
      }
      break;
    case 270:
      for(int i=n-1;i>=0;i--){
        for(int j=0;j<m;j++){
          cout<<matrix[j][i]<<" ";
        }
        cout<<"\n";
      }
      break;
  }
}