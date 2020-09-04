/*
    Find the maximum Sequential Sum for a array.

    You are given the size of the array and then the numbers in the array. Print the maximum value of a sequential sum of
    this array.

    Test case:
    10
    -2 3 5 8 -10 13 4 -1 -5 2

    Output:
    23

    Explanation:
    The sum from the second element(3) till the seventh element(4).
*/

/*
    Solution:
    There are 2 ways to solve this problem:
    
    -Brute Force: get 2 pointers and iterate over each index to find the sum of different sequences and pick the maximum you get.

     | right pointer
     v
    -2 3 5 8 -10 13 4 -1 -5 2
     ^
     | left pointer
    -Linear Time Solution: we don't have to calculate the sum each time we move the pointer. We use just one pointer to 
    iterate over the array and along the way we keep track of the ideal sum on 1 cell of this array and the best sum we have
    had overall. We compare them over time and find out in linear time what is the maximum sequential sum in this array.

    Array cells: -2 3 5 8 -10 13 4 -1 -5 2
    Maximum QS:  -2 3 8 16 6 19 23 22 17 19
                                 ^
                                 |
                        maximum for the array
*/

import java.util.*;
import java.math.*;

public class Main{

  public static int largestContinousSum(int numbers[],int size){
    //we suppose that the minimum sequential sum starts and ends at 0.
    int maxSumNow=numbers[0];
    //this is the largest sum we have seen yet.
    int maxSumEver=numbers[0];
    for(int i=1;i<size;i++){
      //we have 2 options:continue the summation adding this cell, start clean with this cell. We select the maximum.
      maxSumNow=Math.max(maxSumNow+numbers[i],numbers[i]);
      //We see if this is bigger than our maxSumEver and changed them if it is true. If it isn't we continue with our biggest maximum yet.
      maxSumEver=Math.max(maxSumEver,maxSumNow);
    }
    //return the biggest sum we saw during the process
    return maxSumEver;
  }

  public static void main(String[] args) {
   Scanner read= new Scanner(System.in);
   //get the size of the array and its elements
   int size=read.nextInt();
   //allocate memory for our array
   int numbers[]= new int[size];
   for(int i=0;i<size;i++){
     numbers[i]=read.nextInt();
   }
   System.out.println(largestContinousSum(numbers,size));
   read.close();
  }
}
