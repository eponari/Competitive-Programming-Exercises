/*
    Symmetric Matrix

    You are given a square matrix with a size. Then you are given size*size int numbers.
    If the matrix is symmetric, output "Yes".Else output "No".

    Test Case:
    3
    1 2 3
    2 4 5
    3 5 6

    Output:
    Yes
*/

#include <iostream>
using namespace std;

int main(){
  int size;
  cin>>size;
  int matrix[size][size];
  for(int i=0;i<size;i++){
    for(int j=0;j<size;j++){
      cin>>matrix[i][j];
    }
  }
  for(int i=0;i<size;i++){
    for(int j=0;j<size;j++){
      if(matrix[i][j]!=matrix[j][i]){
        cout<<"No";
        return 0;
      }
    }
  }
  cout<<"Yes";
}