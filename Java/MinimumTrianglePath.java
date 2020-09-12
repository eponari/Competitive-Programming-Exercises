/*
    Find the minimum path in a triangle array.

    You are given the size of a array and then given numbers in a triangular pattern.
    (First line contains one number, second one contains two numbers and so on...)
    Find the minimum path you can follow from the first element to reach the base of the triangle.
    You can only move directly down(x+1,y) or down and right(x+1,y+1).

    Test case:
    3
    1
    5 2
    1 1 2

    Output:
    4

    Explanation:
    The path is:
    -select 1(1,1) and move x+1,y+1.
    -select 2(2,2) and move x+1,y.
    -select 1(3,2) and you have reached the base.

    Solution:
    There are 2 ways to solve this problem:

    -Brute Force: See each possible way you can go using recursion. This way you have a lot of redundant work because you
    can end up many times in the same cell and you have to recalculate each time.We can make it more efficent using memoization.

    -Memoizing: We don't have to calculate the sum each time we move in the triangle. We can save other result we have had over
    the time and if we see something we have solved already, we just use that result.

*/

import java.util.*;
import java.math.*;

public class Main{
  //we allocate memory for two 2D arrays:
  //-The triangle values.
  //-The memoized solutions of our function over time.
  static int Triangle[][]= new int[1000][1000];
  static int memoizeSolution[][]= new int[1000][1000];

  public static int findMinimumPath(int size,int x,int y){
    //if we reach the base just return what we found there and we are done with this path.
    if(x==size-1){
      return Triangle[x][y];
    }
    //if the value of the allocared memory above isn't 0, then return this value we have found before.
    if(memoizeSolution[x][y]!=0){
      return memoizeSolution[x][y];
    }
    //for this position we are currently, we find the minimim path.
    //we have 2 choices:
    //-down (x+1,y).
    //-down and right(x+1,y+1).
    int minimumResult=Triangle[x][y]+Math.min(findMinimumPath(size,x+1,y),findMinimumPath(size,x+1,y+1));
    //save this minimum path found with indexes x and y so if we ever need this result again, we don't have to recalculate it.
    memoizeSolution[x][y]=minimumResult;
    //return the value found.
    return minimumResult;
  }

  public static void main(String[] args) {
   Scanner read= new Scanner(System.in);
   //get the size of the 2D matrix and its elements
   int size=read.nextInt();
   for(int i=0;i<size;i++){
     //we don't need to pass the diagonal so we go until j passes i.
     for(int j=0;j<=i;j++){
       Triangle[i][j]=read.nextInt();
     }
   }
   //we start from the top 0,0 and find the minimum path.
   System.out.println(findMinimumPath(size,0,0));
   read.close();
  }
}
