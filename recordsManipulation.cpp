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
    cout << "16.Rent" << "\t\t17.Cash Gift" << "\t18.Mobile Bill" << "\t19.Visa" << "\t\t20.Other" << endl;
  }
  else{
    cout << "1.Salary" << "\t2.Bonus" << "\t\t3.Allowance" << "\t4.Investment" << "\t5.Other" << endl;
  }
  cin >> recordType;
  cout << "Please choose account type: \n" << "1.Cash\n" << "2.Debit Card\n"
       << "3.Credit Card\n";
  cin >> accountType;
  fout << typeChoice << ' ' << amount << ' ' << date << ' ' << recordType << ' ' << accountType << endl;
  
  UpdateAccount(typeChoice,amount,accountType, user+ "_account.txt")
  
  fout.close();
}

void Records::check()
{
  ifstream fin(user + "_records.txt");
  vector<string> records; int i = 0;
  while (getline(fin, records[i])) i++;
  int choice1;
  cout << "Please indicate the way you are searching by:\n" << "1. Type\n" << "2. Date\n"
       << "3. Account\n";
  cin >> choice1;
  switch (choice1){
    case 1:
      break;
    case 2:{
      cout << "Please type in the date in the format dd/mm/yyyy: ";
      string date, dKey;
      cin >> date;
      for (int i = 0; i < records.size(); i++){
        istringstream iss(records[i]);
        for (int j = 0; j < 3; j++) iss >> dKey;
        if (dKey == date) cout << records[i] << endl;
      }
      break;}
    case 3:{
      cout << "Please type in the account you search by:\n" << "1. Cash\n"
           << "2. Debit Card\n" << "3. Credit Card\n";
      string account, aKey;
      cin >> account;
      for (int i = 0; i < records.size(); i++){
        istringstream iss(records[i]);
        for (int j = 0; j < 4; j++) iss >> aKey;
        if (aKey == account) cout << records[i] << endl;
      }
      break;}
  }
  fin.close();
}
