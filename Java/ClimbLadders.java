/*
    Find the number of ways to climb ladders.

    You are given a number of steps a ladder has and are asked to find the number of ways to climb them.You can take 1,2 or 3 steps at a time.

    Test case:
    3

    Output:
    4

    Explanation:
    Ways to climb:
    -1,1,1
    -1,2
    -2,1
    -3

    Solution:
    There are 2 ways to solve this problem:

    -Brute Force: See each possible way you can go using recursion. This way you have a lot of redundant work because you
    can end up many times in the same number of steps left and you have to recalculate each time.We can make it more efficent using memoization.

    -Memoizing: We don't have to calculate the sum of ways each time we move in the ladder. We can save other result we have had over
    the time and if we see something we have solved already, we just use that result.
*/

import java.util.*;
import java.math.*;

public class Main{
  //we allocate memory to store solutions we find for a particular case of ladders left in order to have them if we need to recalculate that.
  static int memoizeSolution[]= new int[100000];

  public static int WaysToClimb(int laddersLeft){

    //if we have passed the 0 mark, it means we have made more steps than we should,so we return 0 because this is not a way.
    if(laddersLeft<0){
      return 0;
    }

    //if we don't have any more to climb, this means we have found a way and return 1.
    if(laddersLeft==0){
      return 1;
    }

    //if we have already seen this solution before and it is different from 0, return the result we already have caluclated.
    if(memoizeSolution[laddersLeft]!=0){
      return memoizeSolution[laddersLeft];
    }

    //we have 3 possibilities:
    //-take 1 step-> stepsLeft-1
    //-take 2 steps-> stepsLeft-2
    //-take 3 steps-> stepsLeft-3
    int waysFound=WaysToClimb(laddersLeft-1)+WaysToClimb(laddersLeft-2)+WaysToClimb(laddersLeft-3);

    //memoized the waysFound with the index of our steps left and return the result.
    memoizeSolution[laddersLeft]=waysFound;
    return waysFound;
  }

  public static void main(String[] args) {
   Scanner read= new Scanner(System.in);

   //get the number of ladders to climb
   int steps=read.nextInt();
   
   System.out.println(WaysToClimb(steps));
   read.close();
  }
}
