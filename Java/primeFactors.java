/*
    Find the prime factors of a number.

    You are given a number and you need to print its prime factor seperated by "*".

    Test case:
    57212312

    Output:
    2*2*2*257*27827

    Solution:
    According to number theory, there is a theorem called the fundamental theorem of arithmetic. It states that each number can be expressed as a
    unique product of primes. This means we don't have to look to prime numbers specifically. We have to check 2 being the only prime even number and
    after that we have to look each odd number from 3 to number. Each time we find a devider for our number, we add it to the string and divide our number.
    When the factor we are looking at is equal to the number,we need to break and return the string.
*/

import java.util.*;
import java.math.*;

public class Main{
  //create a function that takes as input the number and returns our output.
  public static String factorizeNumber(int number){
    //the string starts empty.
    String factorization="";
    //check for 2 since it is the only even prime number.
    while(number%2==0){
      //each step we devide and check if we reach a point where number==2.
      if(number==2){
        //if it is the case, return the string we have + "2" which is the last factor.
        factorization+="2";
        return factorization;
      }
      factorization+="2*";
      number/=2;
    }
    //start with the first odd prime number.
    int factor=3;
    //while the factor is smaller than the number.
    while(number>factor){
      //if this factor devides our number, devide it as many times as we can.
      while(number%factor==0){
        //if we encounter the same with 2 above, do the same procedure.
        if(number==factor){
          factorization+=String.valueOf(factor);
          return factorization;
        }
        factorization+=String.valueOf(factor)+"*";
        number/=factor;
      }
      //the next potentical factor is odd again so we add 2.
      factor+=2;
    }
    //if we break the loop above, add the last factor and return the factorization.
    factorization+=String.valueOf(factor);
    return factorization;
  }

  public static void main(String[] args) {
   //get a scanner to get the input from the user.
   Scanner read= new Scanner(System.in);
   //get the number we want to factorize and print the result the function above returns.
   int number=read.nextInt();
   System.out.println(factorizeNumber(number));
   read.close();
  }
}
