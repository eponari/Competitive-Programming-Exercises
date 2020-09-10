/*
  Special Pattern

  Given an nxn matrix fill the matrix in such a way that the upper right corner is one.
  And that is surrounded by zeros. And the zeros are surrounded by ones again. This continues until the matrix size n.

  Test Case:
  3
  1 0 1
  1 0 0
  1 1 1

  Solution:
  This problem can be solved if we think of a matrix as something with different layers.
  Our matrix will have n layers and since we are told to start from the upper right corner, we need to do a symmetry with respect to the y axis.
  To walk through the layers we need 2 loops: one horizontal and one vertical. This will finish each layer without changing the other elements.
*/
#include <iostream>
using namespace std;

int main() {
  //take the size n.
  int n;
  cin>>n;
  //initialize a nxn matrix.
  int matrix[n][n];
  //we have n layers
  for(int layer=0;layer<n;layer++){
    //in each layer,we are going to visit each element vertically and horizontally to fill them.
    //since the first layer is always 1,then we start with layer(=0)+1%2=1.
    int layerValue=(layer+1)%2;
    for(int i=0;i<=layer;i++){
      //each element is equal to the layerValue we evaluate when we enter a layer.
      matrix[i][layer]=layerValue;
      matrix[layer][i]=layerValue;
    }
  }
  //we print the matrix row by row.
  for(int i=0;i<n;i++){
    //we start printing the row from the last element(n-1) until the first element(0) to have symmetry to the y.
    for(int j=n-1;j>=0;j--){
      cout<<matrix[i][j]<<" ";
    }
    cout<<endl;
  }
}
