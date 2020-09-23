/*
  Question: You are given the coordinates and radius of n circles. Find the top k circles which intersect with the most number of circles.

  Two circles are intersecting if the distance between them is smaller than or equal to the sum of the two radii.

  Test Case:
  6 2
  10 1 2
  1 2 3
  1 6 2
  3 7 2
  5 5 4
  9 8 2

  Output:
  5 3

  Explanation:
  The 5th circle intersects with 4 circles and the 3rd circle intersects with 3 circles.
*/

//libraries we need.
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

//point structure containing x and y value and also distance from another point.
struct point{
  int x,y;
  double distance(point otherPoint){
    return sqrt((this->x-otherPoint.x)*(this->x-otherPoint.x)+(this->y-otherPoint.y)*(this->y-otherPoint.y));
  }
};

//circle structure containing radius,variable to keep track with how many circle it intersects,id and a point for the center. It also contains a function to calculate if this circle intersects with another circle.
struct circle{
  point center;
  int radius,id;
  int intersects=0;
  bool does_intersect(circle otherCircle){
    return center.distance(otherCircle.center)<=radius+otherCircle.radius;
  }
};

//operator to sort circles.
bool compare(circle A,circle B){
  if(A.intersects!=B.intersects){
    return A.intersects>B.intersects;
  }
  return A.id<B.id;
}

int main() {
  //get n circle and print k with most intersections.
  int n,k;
  cin>>n>>k;
  vector <circle> circles;
  circle newCircle;
  //get all n circles.
  for(int i=0;i<n;i++){
    cin>>newCircle.center.x>>newCircle.center.y>>newCircle.radius;
    newCircle.id=1+i;
    newCircle.intersects=0;
    circles.push_back(newCircle);
  }
  //for each circle expect the last because you don't need to compare it to any other.
  for(int i=0;i<n-1;i++){
    //compare it with every circle ahead of it.
    for(int j=i+1;j<n;j++){
      //if the first circle intersect with the other.
      if(circles[i].does_intersect(circles[j])){
        //both circle intersect so we increment intersects by 1.
        circles[i].intersects++;
        circles[j].intersects++;
      }
    }
  }
  //sort the circles with the compare operator.
  sort(circles.begin(),circles.end(),compare);
  //print k circles with most intersections.
  for(int i=0;i<k;i++){
    cout<<circles[i].id<<" ";
  }
}