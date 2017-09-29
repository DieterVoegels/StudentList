#include <iostream>

using namespace std;

struct Student{
  char name[10];
  int id;
  float gpa;
};

int main(){
  Student student;
  cin >> student.name;
  student.id = 333369;
  student.gpa = 3.6;
  cout << student.name << endl;
  cout << student.id << endl;
  cout << student.gpa << endl;
}
