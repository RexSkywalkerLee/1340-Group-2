#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<vector>
#include"head.h"
using namespace std;


void info::alertBudget(){
	string month, year;
	cout<<"Budget Checking..."<<endl;
	cout<<"enter month: "<<endl;
	cin>>month;
	cout<<"enter year: "<<endl;
	cin>>year;
  Mretrieve(month, year);
  double expense=expense1();
	if (expense > budget) cout<<"Beyond Budget"<<endl;
	else if(expense>(budget-200)) cout<<"Alert! Insufficient Budget"<<endl;
}

double info::setBudget(){
	ofstream fout(user+"_budget.txt");
	cout<<"Reset your budget as: " << endl;
	cin>>budget;
	fout<<budget;
	fout.close();
	return budget;

}
bool info::samemonth(){
	ifstream fin( user + "_records.txt");
	vector<string> records;
    vector<string> record;
    string temp,temp1;
    for (int i = 0; i < records.size(); i++){
    if (records.size()<2) return true;
	istringstream iss(records[i]);
    for (int j = 0; j < 7; j++) iss >> record[j];
    if (i==records.size()-2) temp=record[1];
    if (i==records.size()-1) temp1=record[1];
	}
	fin.close();
	if(temp==temp1) return true;
	if(temp!=temp1) return false;

}
