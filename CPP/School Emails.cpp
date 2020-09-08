/*
    School emails

    There are n students in a class. You want to create a general message and sent it to the parents of a specific student.
    Each student has:
    Student ID: an string with chars and numbers only.
    Name and surname: at most 15 chars strings (separated by a space).
    Class: 5 char string containing letters and digits.
    Gender: a single char 'f' or 'm'.
    Grades: 5 integers for 5 courses (Language, Math, Computer, Art, Music).
    Then you will be given the ID of the student for whom the mail will be prepared. At the end of input, you will be given a text of unknown length for the mail merge. In the text, you can have #keywords with (#) before. The keywords may be followed by a space ' ', a period '.', a comma ',', an exclamation mark '!', or an end of line character. Here, is the list of keywords:
    ID, name, surname, class, child, language, math, computer, art, music
    where child will be replaced with son or daughter and the first grade is language, the second grade is math, etc.
    
    Test Case:
    3
    223 Andi Gjoba 10B m 75 56 88 93 67
    541 Klevin Zyka 10C m 54 88 85 93 67
    476 Stacey Stevenson 11A f 94 75 88 67 69
    476
    Dear Parent
    Your #child #name #surname
    from #class did not come to school today.
    Best wishes

    Output:
    Dear Parent
    Your daughter Stacey Stevenson from
    11A did not come to school today.
    Best wishes

    Explanation:
    Student to send: 476
    #child->daughter
    #name->Stacey
    #surname->Stevenson
    #class->11A
*/

#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

//create a vector to keep track of the general multy line email
vector <string> mail;

//struct that represent the data of a student
struct student{
  string name,surname,klas;
  char gend;
  string Language, Math, Computer, Art, Music;
};

int main() {
  //take as input the number of students
  int n;
  string id;
  cin>>n;
  //create a map to make the access process faster
  map <string,student> students;
  student new_student;
  //take information for each student as new_student
  for(int i=0;i<n;i++){
   cin>>id;
   cin
   >>new_student.name
   >>new_student.surname
   >>new_student.klas
   >>new_student.gend
   >>new_student.Language
   >>new_student.Math
   >>new_student.Computer
   >>new_student.Art
   >>new_student.Music;
   students[id]=new_student;
  }
  //take the main id and create a student called main_std to keep track of the student we want to sent the email about.
  cin>>id;
  student main_std=students[id];
  string word;
  //each line in the input is cleared from keywords and replaced with information from main_std.
  while(!cin.eof()){
    getline(cin,word);
    if(word.find("#ID")!=string::npos){
      word.replace(word.find("#ID"),3,id);
    }
    if(word.find("#name")!=string::npos){
      word.replace(word.find("#name"),5,main_std.name);
    }
    if(word.find("#surname")!=string::npos){
      word.replace(word.find("#surname"),8,main_std.surname);
    }
    if(word.find("#class")!=string::npos){
      word.replace(word.find("#class"),6,main_std.klas);
    }
    if(word.find("#child")!=string::npos){
      if(main_std.gend=='m'){
        word.replace(word.find("#child"),6,"son");
      }
      else{
        word.replace(word.find("#child"),6,"daughter");
      }
    }
    if(word.find("#language")!=string::npos){
      word.replace(word.find("#language"),9,main_std.Language);
    }
    if(word.find("#math")!=string::npos){
      word.replace(word.find("#math"),5,main_std.Math);
    }
    if(word.find("#computer")!=string::npos){
      word.replace(word.find("#computer"),9,main_std.Computer);
    }
    if(word.find("#art")!=string::npos){
      word.replace(word.find("#art"),4,main_std.Art);
    }
    if(word.find("#music")!=string::npos){
      word.replace(word.find("#music"),6,main_std.Music);
    }
    //print the line we just got.
    cout<<word<<"\n";
  }
}
//Keywords: ID, name, surname, class, child, language, math, computer, art, music