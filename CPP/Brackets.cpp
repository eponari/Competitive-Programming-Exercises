/*
  Brackets

  You are given the length of a string and the string itself. It contains only {,[,(,),] and }. Find out if the expression with brackets is regular according to mathematics or not.

  Test Case:
  6
  ([())]

  Output:
  No

  Explanation:
  ) and ] have wrong order.

  Solution:
  We need to use stacks for this because of their form. Stack is a data structure known for the first in-first out principle. We can check the last element inserted by checking the top of the stack. 
  For the opening brackets we just insert them in the stack. If we encounter a closing bracket, we check the top of the stack. If it matches we delete the top of the stack and just move on to the next bracket,but if they don't match,just print No because it isn't regular. In the end we need to check if we have any opening bracket that isn't matched because this would make our expression irregular. If everything is finished successfully, we just print "Yes" to indicate a regular expression. 
*/

//import stack library
#include <iostream>
#include <stack>
using namespace std;

int main() {
  //get the length and the txt string.
  int length;
  cin>>length;
  string txt;
  stack <char> parth;
  getline(cin,txt);
  getline(cin,txt);
  //push a ' ' character to make sure the first bracket isn't a closing one and we can compare it to space.
  parth.push(' ');
  for(int i=0;i<length;i++){
    //if it is a opening one, we don't have to check to close any brackets, so we just add it in the top of the stack.
    if(txt[i]=='{'||txt[i]=='['||txt[i]=='('){
      parth.push(txt[i]);
    }
    //if it is a closing one...
    if(txt[i]=='}'||txt[i]==']'||txt[i]==')'){
      char top=parth.top();
      //if the top of the stack is the corrent opening bracket for our closing bracket, just pop the top of the stack and continue to the next one.
      if((txt[i]=='}'&&top=='{')||(txt[i]==']'&&top=='[')||(txt[i]==')'&&top=='(')){
        parth.pop();
        continue;
      }
      //else we don't have a regular bracket formation, so we print "No" and return 0.
      else{
        cout<<"No";
        return 0;
      }
    }
  }
  //if we have a clear stack with only the space character we used in the beginning, just print "Yes" for a regular expresion.
  if(parth.size()==1){
    cout<<"Yes";
  }
  //if it has a bigger length, it means that there are more opening brackets than closing brackets.
  else{
    cout<<"No";
  }
}