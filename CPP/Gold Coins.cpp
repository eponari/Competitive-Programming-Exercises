#include <iostream>
using namespace std;
bool worth(int n){
  return (n%2==0&&n%3==0)||(n%4==0);
}
int findMax(int n){
  int res;
  if((n<=11)){
    return n;
  }
  else{
    res=findMax(n/2)+findMax(n/3)+findMax(n/4);
    return (n>res)?n:res;
  }
}
int main() {
  int coin;
  cin>>coin;
  cout<<findMax(coin);
}
