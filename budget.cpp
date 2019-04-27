#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<vector>
#include"head.h"

using namespace std;

//update total budget & remain budget when accounts infomation changes
//send alert to user when remaining budget is negative
void info::updateBudget()
{
        ifstream fin(user + "_budget.txt");
        double totalBudget;
        for (int i = 0; i < 3; i++) fin >> totalBudget;
        fin.close();
        fin.open(user + "_records.txt");
        string temp; double sum; int key;
        while (getline(fin, temp)){
          istringstream iss(temp);
          for (int i = 0; i < 6; i++) iss >> temp;
          for (int i = 0; i < 25; i++)
            if (balance[i] == temp) key = i;
          sum += key > 20 ? 0 - atof(temp.c_str()) : atof(temp.c_str());
        }
	double remainBudget = totalBudget - sum;
        cout << "Remain Budget " << remainBudget << " / "
             << "Total Budget " << totalBudget << endl;
	if (remainBudget < 0) cout <<"Alert! Beyond Budget" << endl;
	else cout << endl; 
}

//set and reset budget
void info::setBudget(){
	double budget;
        string day, month, year;
	ofstream fout(user+"_budget.txt");
        cout << "Please type in the date in the format mm yyyy: ";
        cin >> month >> year;
	cout << "Reset your total budget as: ";
	cin >> budget;
	fout << year << ' ' << month << ' ' << budget;
	fout.close();
	
}

//check budget.txt can be successfully opened
bool info::checkBudget()
{
  ifstream fin(user + "_budget.txt");
  if (fin.fail()) return 0;
  else return 1;
}


//check whether newliest record and last record are in the same month
//make sure user set budget monthly
bool info::sameMonthBudget(){
        string budgetDate, recordDate, temp;
        ifstream fin(user + "_budget.txt");
        if (fin.fail()) return 0;
        getline(fin, budgetDate);
        fin.close();
        fin.open(user + "_records.txt");
        while (getline(fin, temp)) recordDate = temp;
        fin.close();
        if (budgetDate.substr(0,7) == recordDate.substr(0,7)) return 1;
        else return 0;
}

