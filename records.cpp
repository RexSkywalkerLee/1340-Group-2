#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<vector>
#include<map>
#include<algorithm>
#include"head.h"
using namespace std;


void info::sortRecord()//timely sort record.txt according to date
{
  ifstream fin(user + "_records.txt");
  vector<string>records; string temp;
  while (getline(fin, temp)) records.push_back(temp);
  fin.close();
  sort(records.begin(), records.end());
  ofstream fout(user + "_records.txt");
  for (int i = 0; i < records.size(); i++) fout << records[i] << endl;
  fout.close();
}


void info::addRecord()//step by step guidance for user to add a record
{
  ofstream fout(user + "_records.txt", ios::app);
  char typeChoice;
  double amount; int recordType, accountType;
  string day, month, year;
  cout << "Please choose new record type:\n" << "1. Expense (please type \"-\")\n"
       << "2. Income (please type \"+\")\n";
  cin >> typeChoice;
  cout << "Please type in the amount of the new record: ";
  cin >> amount;
  cout << "Please type in the date in the format dd mm yyyy: ";
  cin >> day >> month >> year ;
  cout << "Please choose the type from following: \n";
  if (typeChoice == '-'){
    cout << "1.Breakfast" << "\t2.Dinner" << "\t3.Snacks" << "\t4.Grocery" << "\t\t5.Social" << endl;
    cout << "6.Lunch" << "\t\t7.Beverages" << "\t8.Traffic" << "\t9.Fun" << "\t\t\t10.Clothing" << endl;
    cout << "11.Shopping" << "\t12.Gifts" << "\t13.Medical" << "\t14.Investment_Expense" << "\t15.Transfer" << endl;
    cout << "16.Rent" << "\t\t17.Cash_Gift" << "\t18.Mobile_Bill" << "\t19.Visa" << "\t\t\t20.Other_Expense" << endl;
  }
  else{
    cout << "1.Salary" << "\t2.Bonus" << "\t\t3.Allowance" << "\t4.Investment_Income" << "\t5.Other_Income" << endl;
  }
  cin >> recordType;
  cout << "Please choose account type: \n" << "1.Cash\n" << "2.Debit Card\n"
       << "3.Credit Card\n";
  cin >> accountType;
  fout << year << ' ' << month << ' ' << day << ' ' << typeChoice << ' ';
  if (typeChoice == '-') fout << balance[recordType-1];
  else fout << balance[recordType+19];
  fout << ' ' << amount << ' ' << account[accountType] << endl;
  fout.close();
  sortRecord();
  updateAccount();
}

//search for particular records by any combination of record type, date and account type
//and print out for users
void info::checkRecord()
{
  ifstream fin(user + "_records.txt");
  vector<string> records; 
  string temp;
  string* record = new string[7]; 
  while (getline(fin, temp)) records.push_back(temp);
  int choice1 = 1;
  while (choice1 == 1){
    int* recordSize = new int (tempRecords.size());
    for (int i = 0; i < *recordSize; i++) tempRecords.pop_back();
    delete recordSize;
    cout << "Please indicate the way you are searching by:\n" << "1. Type\n" << "2. Date\n"
         << "3. Account\n" << "4. Simply list recent records\n";
    cin >> choice1;
    switch (choice1){
      case 1:{ 		//by record type 
        cout << "Searching for expense(please type \"-\") or income(please type \"+\")?" << endl;
        char tKey1; int tKey2; string recordType;
        cin >> tKey1;
        if (tKey1 == '-'){
          cout << "Please type in the type your search by:\n";
          cout << "1.Breakfast" << "\t2.Dinner" << "\t3.Snacks" << "\t4.Grocery" << "\t\t5.Social" << endl;
          cout << "6.Lunch" << "\t\t7.Beverages" << "\t8.Traffic" << "\t9.Fun" << "\t\t\t10.Clothing" << endl;
          cout << "11.Shopping" << "\t12.Gifts" << "\t13.Medical" << "\t14.Investment_Expense" << "\t15.Transfer" << endl;
          cout << "16.Rent" << "\t\t17.Cash_Gift" << "\t18.Mobile_Bill" << "\t19.Visa" << "\t\t\t20.Other_Expense" << endl;
          cin >> tKey2;
          cout << endl;
          for (int i = 0; i < records.size(); i++){
            istringstream iss(records[i]);
            for (int j = 0; j < 5; j++) {if (j == 3) iss >> tKey1; else iss >> recordType;}
            if (tKey1 == '-' && balance[tKey2-1] == recordType){
              cout << tempRecords.size() + 1 << '.' << records[i] << endl;
              tempRecords.push_back(records[i]);
            }
          } 
          break;
        }
        else{		
          cout << "Please type in the type your search by:\n";
          cout << "1.Salary" << "\t2.Bonus" << "\t\t3.Allowance" << "\t4.Investment_Income" << "\t5.Other_Income" << endl;
          cin >> tKey2;
          cout << endl;
          for (int i = 0; i < records.size(); i++){
            istringstream iss(records[i]);
            for (int j = 0; j < 5; j++) {if (j == 0) iss >> tKey1; else iss >> recordType;}
            if (tKey1 == '+' && balance[tKey2+19] == recordType){
              cout << tempRecords.size() + 1 << '.' << records[i] << endl;
              tempRecords.push_back(records[i]);
            }
          }  
          break;
        }
      }
      case 2:{//by date
        string day, month, year;
	cout << "Please type in the date in the format dd mm yyyy: ";
	cin >> day >> month >> year;
        cout << endl;
        for (int i = 0; i < records.size(); i++){
          istringstream iss(records[i]);
          for (int j = 0; j < 7; j++) iss >> record[j];
          if ((day==record[2])&&(month==record[1])&&(year==record[0])){
            cout << tempRecords.size() + 1 << '.' << records[i] << endl;
            tempRecords.push_back(records[i]);
          }
        }
        break;}
      case 3:{//by account type
        cout << "Please type in the account you search by:\n" << "1. Cash\n" << "2. Debit Card\n" << "3. Credit Card\n";
        int aKey; string accountType;
        cin >> aKey;
        cout << endl;
        for (int i = 0; i < records.size(); i++){
          istringstream iss(records[i]);
          for (int j = 0; j < 7; j++) iss >> accountType;
          if (accountType == account[aKey]){
            cout << tempRecords.size() + 1 << '.' << records[i] << endl;
            tempRecords.push_back(records[i]);
          }
        }
        break;}
     case 4:{
       cout << "Please type in the maximum number of records you want to check: ";
       int max;
       cin >> max;
       if (max <= 0){
         cout << "(Invalid input! Function aborted)" << endl; 
         return;
       } 
       cout << endl;
       for (int i = records.size() - 1; i >= records.size() - max && i >= 0; i--){
         cout << tempRecords.size() + 1 << '.' << records[i] << endl;
         tempRecords.push_back(records[i]);
       }
       break;}
    }
    if (tempRecords.size() != 0){
      cout << "\n1.Further check\n2.No need for further check\n";
      cin >> choice1;
      records = tempRecords;
    }
    else{
      cout << "Whoops! No records found." << endl;
      break;
    }
  }
  delete []record;
  fin.close();
  cout << endl;
}

//delete records by straight type in 
void info::deleteRecord()
{
  cout << "Please specify the record you want to delete by check it;\n";
  int basicChoice = 1;
  while (basicChoice == 1){
    checkRecord();
    cout << "Have you found the record you are looking for?\n"
         << "1.No, check again\n2.Yes, stop checking\n3.Leave\n";
    cin >> basicChoice;
  }
  switch (basicChoice){
    case 3: return;
    case 2: 
      vector<string>records; string* temp = new string;
      int num, index;
      cout << "How many of records listed above you want to delete? ";
      cin >> num;
      if (num == 0) return;
      cout << "Please type in the indexes of the records you want to delete(separated by white space): ";
      for (int i = 0; i < num; i++){
        ifstream fin(user + "_records.txt");
        while (getline(fin,*temp)) records.push_back(*temp);
        fin.close();
        cin >> index;
        if (index > tempRecords.size()){
          cout << "(Invalid index exists!)" << endl;
          continue;
        }
        *temp = tempRecords[index - 1];
        ofstream fout(user + "_records.txt");
        for (int j = 0; j < records.size(); j++)
          if (records[j] != *temp) fout << records[j] << endl;
        fout.close();
        records.clear();
      }
      delete temp;
  }
  cout << "Record(s) deleted!" << endl;
  updateAccount();
}

//edit records by straight type in
void info::editRecord()
{
  ifstream fin(user + "_records.txt");
  vector<string>records; string* temp = new string;
  while (getline(fin,*temp)) records.push_back(*temp);
  fin.close();
  cout << "Please type in specific infomation of the record you want to edit:\n";
  cout << "(You can use check function to find the record to be edited first)\n";
  cout << "1. check records\n2. straight type in\n";
  int basicChoice; cin >> basicChoice;
  JumpToPointEdit:
  if (basicChoice == 1) checkRecord();
  cout << "Please make your choice:\n1.Check again\n2.Type in record to be edited\n3.Exit\n";
  cin >> basicChoice;
  switch (basicChoice){
    case 1: goto JumpToPointEdit;
    case 3: exit(1); 
    case 2: default: break;
  }
  cout << "Record to be edited:\n";  cin.get();
  getline(cin,*temp);
  ofstream fout(user + "_records.txt");
  for (int i = 0; i < records.size(); i++){
    if (records[i] != *temp) fout << records[i] << endl;
    else{
      fout.close();
      cout << "Please replace this record by specifying a new record:" << endl;
      addRecord();
      fout.open(user + "_records.txt", ios::app);
    }
  }
  fout.close(); delete temp;
  sortRecord();
  updateAccount();
}
  
  

