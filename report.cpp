#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<iomanip>
#include"head.h"

using namespace std;

void info::report()
{
  int firstChoice;
  cout << "Please indicate your choice:\n1. Year report\n2. Month report\n";
  cin >> firstChoice;
  double report[25] = {0};
  ifstream fin(user + "_records.txt");
  string temp, tempNum, newest;
  while (getline(fin,temp)) newest = temp;
  newest = firstChoice == 1 ? newest.substr(0,4) : newest.substr(5,2);
  fin.close(); fin.open(user + "_records.txt");
  while (getline(fin, temp)){
    if ((firstChoice == 1 && temp.find(newest) == 0) || 
        (firstChoice == 2 && temp.find(newest) == 5)) {
      for (int i = 0; i < 25; i++){
        if (temp.find(balance[i]) != -1){ 
          istringstream iss(temp);
          for (int j = 0; j < 6; j++) iss >> tempNum;
          report[i] += atof(tempNum.c_str());
        }
      }
    }
  }
  fin.close();
  double income = 0, expense = 0, total = 0;
  for (int i = 0; i < 25; i++){
    income += (i > 20) * report[i];
    expense += (i < 20) * report[i];
  }
  total = income - expense;
  if (firstChoice == 1) cout << "Year report:\n";
  else cout << "Month report:\n";
  cout << "Total balance of the " << (firstChoice == 1 ? "year: " : "month: ")
       << total << endl << "Total income: " << income << endl << "Total expense: "
       << expense << endl;
  cout << setfill(' ');
  for (int i = 0; i < 25; i++){
    if (i == 0)  cout << "\nEnpense type / total expense:\n";
    else if (i == 20) cout << "\nIncome type / total income:\n";

    if (i < 20)
      cout << setw(20) << left << balance[i] << report[i] << endl;
    else
      cout << setw(20) << left << balance[i] << report[i] << endl;
        
  }
} 