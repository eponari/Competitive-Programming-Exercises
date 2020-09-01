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

/*

    Solution:
    We know that a matrix is symmetric if each element regarding the main diagonal is the same.
    Example: matrix[1][2] should be equal to matrix[2][1]
    So we only need to check the upper triangle of a matrix to verify if it is symmetric or not.
    
    Upper triangle marked with "*":

    - * * *
    - - * *
    - - - *
    - - - -

*/


#include <iostream>
using namespace std;

int main(){
  int size;
  cin>>size;
  int matrix[size][size];
  //get the 2D array as input
  for(int i=0;i<size;i++){
    for(int j=0;j<size;j++){
      cin>>matrix[i][j];
    }
  }

  for(int i=0;i<size;i++){
    //the second loop starts from i+1 since we only need to chech only the upper triangle
    for(int j=i+1;j<size;j++){
      if(matrix[i][j]!=matrix[j][i]){
        cout<<"No";
        return 0;
      }
    }
  }

  cout<<"Yes";
}