#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<vector>
#include"head.h"
using namespace std;


void info::updateAccount(int amount, int type){
    ifstream fin(user + "_account.txt");
    vector<string> records; string temp;
    while (getline(fin, temp)) records.push_back(temp); 
    fin.close();
    string aType;
    istringstream iss(records[type]);
    string info;
    iss >> aType >> info;	
    int total=atoi(info.c_str()) + amount;
    records[type]=aType+' '+to_string(total);
    ofstream fout1(user + "_account.txt");
    for(int i=0;i<3;i++)  fout1<<records[i]<<endl;
    fout1.close();
}
 
void info::displayAccount(){
	string item;
	cout<<"\nAccount information of "<<user<< ':' << endl;
	ifstream fin(user + "_account.txt");
	while (getline(fin, item)) cout<<item<<endl;
	fin.close();
        cout << "Continue management? (Y/N)" << endl;
        char finalChoice;
        cin >> finalChoice;
        if (finalChoice == 'Y') return;
        else exit(1);
}

