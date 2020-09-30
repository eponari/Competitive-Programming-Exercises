/*
    N pattern
    Crate a N shape using "N" with n lines.

    Test Case:
    5

    Output:
    N   N
    NN  N
    N N N
    N  NN
    N   N

    Solution:
    This shape has 3 components:
    -first column.
    -last column.
    -diagonal.
    Fill these 3 with "N" and everything else should be " ".

*/

#include <iostream>
using namespace std;

int main() {
  int n;
  cin>>n;
  char figure[n][n];
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      //i==0->first column
      //i==n-1->last column
      //i==j->diagonal
      if(j==0||j==n-1||i==j){
        figure[i][j]='N';
      }
      else{
        figure[i][j]=' ';
      }
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cout<<figure[i][j];
    }
    cout<<"\n";
  }
}