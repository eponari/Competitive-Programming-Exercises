/*
    Scheduale the maximum number of events without overlapping

    You have a lot of clients to deal with every day. Create a program that takes the time interval you need for each client and find the maximum
    number of clients you can consult without overlapping.

    Test Case:
    11
    0 6
    1 4
    8 13
    3 5
    8 12
    3 8
    5 9
    6 10
    5 7
    2 13
    12 14

    Output:
    4

    Explanation:
    You can take:
    1 4
    5 7
    8 12
    12 14

    Solution:
    We can create all the subsets with these time events and see if they fit without overlapping, but this would take a lot of time.
    In the other side we can sort the time events so we have them in a chronological order. In this way we can just include or exclude a event
    to make the subsets to not overlap.
    To make it even faster we can use dynammic programming and keep track of all subproblems we solve and memoize them. In this way we don't have
    to resolve problems that we already know over and over again.
*/



//include libraries from input,output,vectors(lists) and algorithms like sort.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//basic structure for a time interval.
struct timeInterval{
  int start,finish;
};

//sorting operator that helps us sort events based on their start time or when they have the same start time, by their finishing time.
//we want to be able to make as many appoints as possible.
bool compare(timeInterval a,timeInterval b){
  if(a.start!=b.start){
    return a.start<b.start;
  }
  return a.finish<b.finish;
}

//declare a global vector to keep track of the clients and a memory array to memoize work so we don't have to recalculate values we know.
vector <timeInterval> customers;
int memory[100000];

//lastUser is -1 by default because we are free and any positive hour is ok for us.
int getMaxTime(int size,int pos=0,int lastUsed=-1){
  //if we reach the end of the list just return 0 we are finished.
  if(pos==size){
    return 0;
  }
  //if this customer can't fit in our scheduale, just skip him and keep lastUsed time unchanged.
  if(customers[pos].start<lastUsed){
    return getMaxTime(size,pos+1,lastUsed);
  }
  //if we can fit him in our scheduale:
  //if we know the most optimal solution because we might have done it before for this client, just use that and don't recalcluate again.
  if(memory[pos]!=0){
    return memory[pos];
  }
  //result is the maximum between 2 choises:
  //1.Skip this event and keep the lastUsed unchanged.
  //2.Take this event(+1 in our result) and change the lastUsed to this event's finish time.
  int res=max(getMaxTime(size,pos+1,lastUsed),1+getMaxTime(size,pos+1,customers[pos].finish));
  //register this result in our array in the entry with the same index(pos) as our problem. 
  memory[pos]=res;
  return res;
}

int main() {
  //get inputs
  int size;
  cin>>size;
  timeInterval newCustomer;
  for(int i=0;i<size;i++){
    cin>>newCustomer.start>>newCustomer.finish;
    customers.push_back(newCustomer);
  }
  //sort the elements according to the operator above named compare
  sort(customers.begin(),customers.end(),compare);
  cout<<getMaxTime(size);
}