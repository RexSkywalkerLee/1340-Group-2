#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int info::report()
{
  int firstChoice;
  cout << "Please indicate your choice:\n1. Year report\n2. Month report\n";
  ifstream fin(user + "_records.txt");
  
