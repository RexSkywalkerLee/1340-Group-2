#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<vector>
#include"recordsManipulation.h"

using namespace std;

void Records::add()
{
  ofstream fout(user + "_records.txt", ios::app);
  char typeChoice;
  int amount, recordType, accountType;
  string date;
  cout << "Please choose new record type:\n" << "1. Expense (please type \"-\")\n"
       << "2. Income (please type \"+\")\n";
  cin >> typeChoice;
  cout << "Please type in the amount of the new record: ";
  cin >> amount;
  cout << "Please type in the date in the format dd/mm/yyyy: ";
  cin >> date;
  cout << "Please choose the type from following: \n";
  if (typeChoice == '-'){
    cout << "1.Breakfast" << "\t2.Dinner" << "\t3.Snacks" << "\t4.Grocery" << "\t5.Social" << endl;
    cout << "6.Lunch" << "\t\t7.Beverages" << "\t8.Traffic" << "\t9.Fun" << "\t\t10.Clothing" << endl;
    cout << "11.Shopping" << "\t12.Gifts" << "\t13.Medical" << "\t14.Investment" << "\t15.Transfer" << endl;
    cout << "16.Rent" << "\t\t17.Cash_Gift" << "\t18.Mobile_Bill" << "\t19.Visa" << "\t\t20.Other" << endl;
  }
  else{
    cout << "1.Salary" << "\t2.Bonus" << "\t\t3.Allowance" << "\t4.Investment" << "\t5.Other" << endl;
  }
  cin >> recordType;
  cout << "Please choose account type: \n" << "1.Cash\n" << "2.Bank_Card\n"
       << "3.Credit_Card\n";
  cin >> accountType;
  fout << typeChoice << ' ' << amount << ' ' << date << ' ';
  if (typeChoice == '-') fout << expense[recordType];
  else fout << income[recordType];
  fout << ' ' << account[accountType] << endl;
  fout.close();
  cout << "Record added! Continue management? (Y/N)" << endl;
  char finalChoice;
  cin >> finalChoice;
  if (finalChoice == 'Y') return;
  else exit(1);
}

void Records::check()
{
  ifstream fin(user + "_records.txt");
  vector<string> records; string temp;
  while (getline(fin, temp)) records.push_back(temp);
  int choice1;
  cout << "Please indicate the way you are searching by:\n" << "1. Type\n" << "2. Date\n"
       << "3. Account\n";
  cin >> choice1;
  switch (choice1){
    case 1:{
      cout << "Searching for expense(please type \"-\") or income(please type \"+\")?" << endl;
      char tKey1; int tKey2; string recordType;
      cin >> tKey1;
      if (tKey1 == '-'){
        cout << "Please type in the type your search by:\n";
        cout << "1.Breakfast" << "\t2.Dinner" << "\t3.Snacks" << "\t4.Grocery" << "\t5.Social" << endl;
        cout << "6.Lunch" << "\t\t7.Beverages" << "\t8.Traffic" << "\t9.Fun" << "\t\t10.Clothing" << endl;
        cout << "11.Shopping" << "\t12.Gifts" << "\t13.Medical" << "\t14.Investment" << "\t15.Transfer" << endl;
        cout << "16.Rent" << "\t\t17.Cash_Gift" << "\t18.Mobile_Bill" << "\t19.Visa" << "\t\t20.Other" << endl;
        cin >> tKey2;
        for (int i = 0; i < records.size(); i++){
          istringstream iss(records[i]);
          for (int j = 0; j < 4; j++) {if (j == 0) iss >> tKey1; else iss >> recordType;}
          if (tKey1 == '-' && expense[tKey2] == recordType) cout << records[i] << endl;
        }
        break;
      }
      else{
        cout << "Please type in the type your search by:\n";
        cout << "1.Salary" << "\t2.Bonus" << "\t\t3.Allowance" << "\t4.Investment" << "\t5.Other" << endl;
        cin >> tKey2;
        for (int i = 0; i < records.size(); i++){
          istringstream iss(records[i]);
          for (int j = 0; j < 4; j++) {if (j == 0) iss >> tKey1; else iss >> recordType;}
          if (tKey1 == '+' && income[tKey2] == recordType) cout << records[i] << endl;
        }
        break;
      }
    }
    case 2:{
      cout << "Please type in the date in the format dd/mm/yyyy: ";
      string date, dKey;
      cin >> dKey;
      for (int i = 0; i < records.size(); i++){
        istringstream iss(records[i]);
        for (int j = 0; j < 3; j++) iss >> date;
        if (dKey == date) cout << records[i] << endl;
      }
      break;}
    case 3:{
      cout << "Please type in the account you search by:\n" << "1. Cash\n"
           << "2. Bank Card\n" << "3. Credit Card\n";
      int aKey; string accountType;
      cin >> aKey;
      for (int i = 0; i < records.size(); i++){
        istringstream iss(records[i]);
        for (int j = 0; j < 5; j++) iss >> accountType;
        if (accountType == account[aKey]) cout << records[i] << endl;
      }
      break;}
  }
  fin.close();
  cout << "Continue management? (Y/N)" << endl;
  char finalChoice;
  cin >> finalChoice;
  if (finalChoice == 'Y') return;
  else exit(1);
}
