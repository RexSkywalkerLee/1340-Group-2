#include<iostream>
#include<string>
#include"head.h"


using namespace std;

int main()
{
  info userInfo;
  userInfo.set(sign());
  JumpToPointMain:
  if (userInfo.checkBudget()){
    if (userInfo.sameMonthBudget()) userInfo.updateBudget();
    else cout << "Please set budget for a new month!\n\n";
  }

  else cout << "You don't have your budget yet. Please set a budget!\n\n";//remind users to set budget and timely update budget infomation
  int choice;
  cout << "Please indicate your choice to start account management:\n";
  cout << "1. Add\n" << "2. Check\n" << "3. Edit\n" << "4. Delete\n"
       << "5. Set Budget\n" << "6. Report\n" << "7. Latest\n" <<"8. Accounts Information\n" << "9. Exit\n";//indicate diverse functions for user

  cin >> choice;
  switch (choice){
    case 1:
    userInfo.addRecord();
    cout << "\nRecord added!\n";
    break;
    case 2:
    userInfo.checkRecord();
    break;
    case 3:
    userInfo.editRecord();
    cout << "\nRecord edited!\n";
    break;
    case 4:
    userInfo.deleteRecord();
    break;
    case 5:
    userInfo.setBudget();
    cout << "\nNew budget set!\n";
    break;
    case 6:
    userInfo.report();
    break;
    case 7:
    userInfo.latest();
    break;
    case 8:
    userInfo.displayAccount();
    break;
    case 9:
    cout << "Bye bye!" << endl;
    exit(1);
    default:
    cout << "Invalid input. Please try again." << endl;
  }
  terminateORnot();
  goto JumpToPointMain;
}
