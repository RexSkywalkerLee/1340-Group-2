#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<vector>
#include"head.h"
using namespace std;


void info::updateAccount()
{
    ifstream fin(user + "_records.txt");
    vector<string> records; string temp;
    while (getline(fin,temp)) records.push_back(temp);
    fin.close();
    double Accounts[3], info[3];
    fin.open(user + "_account.txt");
    for (int i = 0; i < 3; i++){
      fin >> info[i]; Accounts[i] = info[i];
    }
    fin.close();
    
    char type; string aType; double amount;
    for (int i = 0; i < records.size(); i++){
      istringstream iss(records[i]);
      for (int j = 0; j < 7; j++){
        if (j == 3) iss >> type;
        else if (j == 5) {iss >> temp; amount = atof(temp.c_str());}
        else iss >> aType;

        if (aType == "Cash") 
          Accounts[0] += (type == '-')?(0-amount):amount;
        else if (aType == "Debit_Card") 
          Accounts[1] += (type == '-')?(0-amount):amount;
        else if (aType == "Credit_Card")
          Accounts[2] += (type == '-')?(0-amount):amount;
      }
    }
    ofstream fout(user + "_account.txt");
    for (int i = 0; i < 3; i++) fout << info[i] << ' ';
    fout << endl;
    for (int i = 0; i < 3; i++) 
      fout << account[i+1] << ' ' << Accounts[i] << endl;
    fout.close();
}

void info::displayAccount(){
    string item;
    cout<<"\nAccount information of "<<user<< ':' << endl;
    ifstream fin(user + "_account.txt");
    while (getline(fin, item)) cout<<item<<endl;
    fin.close();
    cout << endl;
}

