#include<iostream>
#include<string>
#include"recordsManipulation.h"
#include"accountsManipulation.h"
using namespace std;

int main()
{
  Records userRecord;
  userRecord.sign();
  string user=userRecord.username();
  account user1;
  int choice;
  JumpToPointMain:
  cout << "Please indicate your choice to start account management:\n";
  cout << "1. Add\n" << "2. Check\n" << "3. Edit\n" << "4. Delete\n"
       << "5. Set Budget\n" << "6. Report\n" << "7. Latest\n" <<"8. Accounts information\n" << "9.Exit\n";
  cin >> choice;
  switch (choice){
    case 1:
    userRecord.add();
    break;
    case 2:
    userRecord.check();
    break;
    case 3:
    break;
    case 4:
    break;
    case 5:
    break;
    case 6:
    break;
    case 7:
    break;
    case 8:
    user1.DisplayAccount(user);
    break;
    case 9:
    exit(1);
  }
  goto JumpToPointMain;
}
