#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<vector>
#include"head.h"

using namespace std;
void info::alertBudget(){
        ifstream fin(user + "_budget.txt");
        double totalBudget;
        cin >> totalbudget;
	double remainBudget = totalBudget - sum();
        cout << "Remain Budget " << remainBudget << '/'
             << "Total Budget " << totalBudget << endl;
	if (remainBudget < 0) cout <<"Alert! Beyond Budget" << endl;
	else cout << endl; 
}

void info::setBudget(){
	double budget;
        string day, month, year;
	ofstream fout(user+"_budget.txt");
        cout << "Please type in the date in the format mm yyyy: ";
        cin >> month >> year;
	cout << "Reset your total budget as: ";
	cin >> budget;
	fout << year << month << budget;
	fout.close();
	
}
bool info::sameMonthBudget(){
        string budgetDate, recordDate;
        ifstream fin(user + "_budget.txt");
        getline(fin, budgetDate);
        fin.close();
        fin.open(user + "_records.txt");
        while (getline(fin, recordDate));
        if (budgetDate.substr(0,7) == recordDate.substr(0,7)) return 1;
        else return 0;	
}

