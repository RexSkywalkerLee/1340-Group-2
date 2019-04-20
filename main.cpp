#include<iostream>
#include<string>
#include"head.h"

using namespace std;

int main()
{
  info userInfo;
  userInfo.set(sign());
  int choice;
  JumpToPointMain:
  cout << "Please indicate your choice to start account management:\n";
  cout << "1. Add\n" << "2. Check\n" << "3. Edit\n" << "4. Delete\n"
       << "5. Set Budget\n" << "6. Report\n" << "7. Latest\n" <<"8. Accounts information\n" << "9. Exit\n";
  cin >> choice;
  switch (choice){
    case 1:
    userInfo.addRecord();
    break;
    case 2:
    userInfo.checkRecord();
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
    userInfo.displayAccount();
    break;
    case 9:
    exit(1);
  }
  goto JumpToPointMain;
}
