#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<vector>
#include"head.h"
using namespace std;

void info::retrieve(string keyword){
	ifstream fin( user + "_records.txt");
	ofstream fout("temp.txt");
	vector<string> records;
    vector<string> record;
    for (int i = 0; i < records.size(); i++){
	istringstream iss(records[i]);
    for (int j = 0; j < 7; j++) iss >> record[j];
    if (record[index]==keyword) fout<<records[i]<<endl;
	}
	fin.close();
	fout.close();}

void info::Mretrieve(string month, string year){//month
	ifstream fin( user + "_records.txt");
	ofstream fout("temp.txt");
	vector<string> records;
    vector<string> record;
    for (int i = 0; i < records.size(); i++){
	istringstream iss(records[i]);
    for (int j = 0; j < 7; j++) iss >> record[j];
    if ((record[1]==month)&&(record[0]==year)) fout<<records[i]<<endl;
	}
	fin.close();
	fout.close();}


double info::sum(){
	ifstream fin("temp.txt");
	vector<string> records;
    vector<string> record;
    double total=0;
	for (int i = 0; i < records.size(); i++)
	{

	istringstream iss(records[i]);
    for (int j = 0; j < 7; j++)
		{ iss >> record[j];
       	double amount=stod(record[1]);
       	if  (record[3]=='-') amount=(0-amount);//����income expense ��total
		  total+=amount;
	    }
	}
	fin.close();
	return total;
}

double info::expense1(){
	ifstream fin("temp.txt");
	vector<string> records;
    vector<string> record;
    double total=0;
	for (int i = 0; i < records.size(); i++)
	{	istringstream iss(records[i]);
    for (int j = 0; j < 7; j++)
		{ iss >> record[j];
       	double amount=stod(record[1]);
       	if  (record[3]=='-') total+=amount;// expense ��total
	    }
	}
	fin.close();
	return total;
}

double info::income1(){
	ifstream fin("temp.txt");
	vector<string> records;
    vector<string> record;
    double total=0;
	for (int i = 0; i < records.size(); i++)
	{	istringstream iss(records[i]);
    for (int j = 0; j < 7; j++)
		{ iss >> record[j];
       	double amount=stod(record[4]);
       	if  (record[3]=='+') total+=amount;
	    }
	}
	fin.close();
	return total;
}
