#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<vector>
#include"accountsManipulation.h"
using namespace std;


void account::UpdateAccount(char PosONeg,int amount, int type, string useracount){
	int n=type-1;
	if  (PosONeg=='-') amount=(0-amount);
	ifstream fin(useraccount);
	vector<string> records; 
	int i = 0;
	while (getline(fin, records[i])) i++;
	fin.close();
	string aType;
	int total;
	istringstream iss(records[n]);
	for (int j = 0; j < 2; j++) { 
	iss >> info;
	if (j==0)aType=info;	
	if (j==1)	
	{int total=stoi(info);
	total+=amount; }
				 }
	record[n]=aType+' '+to_string(total);
	ofstream fout1(useraccount);
	for(int i=0;i<3;i++)  fout1<<records[i]<<endl;
	fout.close();
} 

void account::DisplayAccount(string user){
	string item;
	cout<<"Account information of "<<user<<endl;
	ifstream fin(user + "_account.txt");
	while (getline(fin, item)) cout<<item<<endl;
	fin.close();
}

