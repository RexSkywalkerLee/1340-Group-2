#ifndef head_h
#define head_h
#include<string>
#include<vector>
#include<map>

using namespace std;

string sign();
void terminateORnot();
void emptyTemp();

class info{
public:

  void emptyTemp();
  void sortRecord();
  void addRecord();
  void checkRecord();
  void editRecord();
  void deleteRecord();

  void updateAccount();
  void displayAccount();

  void updateBudget();
  void setBudget();
  bool checkBudget();
  bool sameMonthBudget();

  void latest();
  void report();

  void set(string username) {user = username;}

private:
  string user;
  vector <string> tempRecords;
  map <int, string> balance = {{0,"Breakfast"},{1,"Dinner"},{2,"Snacks"},{3,"Grocery"},{4,"Social"},
                               {5,"Lunch"},{6,"Beverages"},{7,"Traffic"},{8,"Fun"},{9,"Clothing"},
                               {10,"Shopping"},{11,"Gifts"},{12,"Medical"},{13,"Investment_Expense"},{14,"Transfer"},
                               {15,"Rent"},{16,"Cash_Gift"},{17,"Mobile_Bill"},{18,"Visa"},{19,"Other_Expense"},
                               {20,"Salary"},{21,"Bonus"},{22,"Allowance"},{23,"Investment_Income"},{24,"Other_Income"}};
  map <int, string> account = {{1,"Cash"}, {2,"Debit_Card"}, {3,"Credit_Card"}};
};

#endif
