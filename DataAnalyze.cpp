#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<vector>
#include"DataAnalyze.h"

using namespace std;
void Data::retrieve(){//单元素搜索,日期不行 
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

int Data::TypetoIndex(string type){//根据需要再加,有关日期的要单独出来 
	switch (type){
    case "Yreport":
    return 4 ;
    break;
    case "recordType":
    return 5;
    break;
    case "accountType":
    return 6;
    break;
};

double Data::sum(){
	ifstream fin("temp.txt");
	vector<string> records; 
    vector<string> record; 
    double total=0;
	for (int i = 0; i < records.size(); i++)
	{
		
	istringstream iss(records[i]);
    for (int j = 0; j < 7; j++) 
		{ iss >> record[j];
       	  int amount=stoi(record[1]);
       	if  (record[0]=='-') amount=(0-amount);//不分income expense 的total 
		  total+=amount;
	    }
	}
	fin.close();
	return total;
}
