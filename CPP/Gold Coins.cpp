/*
    Gold Coins

    In Byteland, they have a very strange monetary system.

    Each Bytelandian gold coin has an integer number written on it.
    A coin N can be exchanged in a bank into three coins: N/2, N/3 and N/4.
    However, these numbers are all rounded down (the banks have to make a profit).
    You can also sell Bytelandian coins for American dollars.
    The exchange rate is 1:1. However, you cannot buy Bytelandian coins.
    You have one gold coin with n value. What is the maximum amount of American dollars you can get for it?

    Test case:
    120
    
    Output:
    144

*/

#include <iostream>
using namespace std;

int findMaxExchange(int coin){
  //we are going to get a coin rounded as 0 so it can't create profit for us.
  if(coin<4){
    return coin;
  }
  //if we exchange, we need to calculate for coin/2,coin/3 and coin/4.
  int exchange=findMaxExchange(coin/2)+findMaxExchange(coin/3)+findMaxExchange(coin/4);
  //return the max between exchange and original coin.
  return max(exchange,coin);
}

int main() {
  int coin;
  cin>>coin;
  cout<<findMaxExchange(coin);
}
