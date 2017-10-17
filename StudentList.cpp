/*
Program: A list of students that you can add, delete, and print.
Author: Dieter Voegels
Date:10/13/17
*/
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

//Student struct containing the first and last name, id, and gpa
struct Student{
  char fName[80];
  char lName[80];
  int id;
  float gpa;
};

//initialize methods
void Add(vector<Student*> &vect);
void Print(vector<Student*> &vect);
void Delete(vector<Student*> &vect);

//main method
int main(){
  //initialize while loop 
  char input[10];
  bool quit = false;
  vector<Student*> vect;
  //while loop
  while(!quit){
    //ask the user to input a command, and if they do not know the commands they can type help to get commands
    cout << "Type in a command. Type 'help' for commands" << endl;
    cin.getline(input, 10);
    //add a student
    if(strcmp(input, "add") == 0){
      Add(vect);
      cin.ignore(20, '\n');
    }
    //delete a student
    if (strcmp(input, "delete") == 0){
      Delete(vect);
      cin.ignore(20,'\n');
    }
    //print out all students
    if(strcmp(input, "print") == 0){
      Print(vect);
    }
    //print out all commands
    if(strcmp(input, "help") == 0){
      cout << "type 'add' to add a student to the list" << endl;
      cout << "type 'delete' to delete a student from the list" << endl;
      cout << "type 'quit' to quit the application" << endl;
      cout << "type 'help' to open up view all commands" << endl;
    }
    //kill the program
    if(strcmp(input, "quit") == 0){
      quit = true;
    }
  }
}
//add a student to the vector method
void Add(vector<Student*> &vect){
  //create a new student pointer pointing to a student struct
  Student* student = new Student;
  
  //have the user enter in the Students first and last name, ID, and GPA
  cout << "Enter in the first name of the student" << endl;
  cin >> student->fName;
  cout << "Enter in the last name of the student." << endl;
  cin >> student->lName;
  cout << "Enter in the student's id" << endl;
  cin >> student->id;
  cout << "Enter in the student's GPA" << endl;
  cin >> student->gpa;
  
  //add the student pointer to the vector
  vect.push_back(student);
}
//delete a student from the vector and from memory method
void Delete(vector<Student*> &vect){
  //get student id
  int input;
  cout << "Enter in the ID of the student you wish to delete" << endl;
  cin >> input;
  //go through the 
  for(vector<Student*>::iterator it = vect.begin(); it != vect.end(); it++){
    //position in vector
    int position = it - vect.begin();
    //if the id matches a student, then delete it
    if(input == vect[position]->id){
      //delete the student from memory
      delete vect[position];
      //delete student from vector
      vect.erase(vect.begin() + position);
      //break from the loop because the iterator was messed with
      break;
    }
  }
}
//print all of the students
void Print(vector<Student*> &vect){
  for(vector<Student*>::iterator it = vect.begin(); it != vect.end(); it++){
    cout << (*it)->fName << endl;
    cout << (*it)->lName << endl;
    //make it show 2 decimals and zeros
    cout.setf(ios::fixed, ios::floatfield);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << (*it)->id << endl;
    cout << (*it)->gpa << endl;
  }
}
