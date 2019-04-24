#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<vector>
#include<cstdlib>
#include"DataAnalyze.h"

using namespace std;
void info::retrieve(){
	ifstream fin( user + "_records.txt");
        
	vector<string> records; 
        string* record = new string[7]; 
	string temp;
while (getline(fin, temp)) records.push_back(temp);
  for (int i = 0; i < records.size(); i++){
	  istringstream iss(records[i]);
    for (int i = 0; iss >> record[i]; i++);
    if (record[index] == keyword) fout << records[i] << endl;
	}
	fin.close();
	fout.close();}

int Data::TypetoIndex(string type){
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
  string* record = new string[7];
  double total = 0;
	string temp;
	while (getline(fin, temp)) records.push_back(temp);
	for (int i = 0; i < records.size(); i++){
	istringstream iss(records[i]);
  for (int i = 0; iss >> record[i]; i++);
  int amount = atoi(record[1].c_str());
  total += (record[0] == "-") ? (0 - amount) : amount;
	}
	delete []record;
	fin.close();
	return total;
}

