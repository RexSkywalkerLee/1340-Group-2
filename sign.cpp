#include<iostream>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<string>
#include"recordsManipulation.h"
using namespace std;
int panel();
string sign_up();
string sign_in();


int panel()
{
  int choice;
  cout << setfill('*');
  cout << setw(50) << '\0' << endl;
  cout << right << setw(41) << "Welcome to our Accounting System!";
  cout << setw(9) << '\0' << endl;
  cout << setw(50) << '\0' << endl;
  cout.unsetf(ios_base::floatfield);
  cout << "Please indicate your choice" << endl;
  cout << "1. sign up" << endl << "2. sign in" << endl << "3. exit" << endl;
  cin >> choice;
  return choice;
}

string sign_up()
{
  string username, password, password_2;
  cout << "Please set your username: ";
  cin >> username;
  JumpToPoint1:
  cout << "Please set your password: ";
  cin >> password;
  cout << "Please confirm your password: ";
  cin >> password_2;
  if (password == password_2){
    ofstream fout ("userinfo.txt", ios::app);
    fout << username << ' ' << password << endl;
    fout.close();
    fout.open(username + "_records.txt", ios::app);
    fout.close();
    fout.open(username + "_account.txt", ios::app);
    double info;
    cout << "Initiating accouting system: " << endl;
    cout << "cash: ";
    cin >> info;
    fout << "Cash: " << info << endl;
    cout << "Bank Card: ";
    cin >> info;
    fout << "Bank Card: " << info << endl;
    cout << "Credit Card: ";
    cin >> info;
    fout << "Credit Card: " << info << endl;
    fout.close();
    cout << "You have signed up! Please sign in to start account management." << endl;
    return sign_in();
  }
  else{
    cout << "Password is not correct. Please set again." << endl;
    goto JumpToPoint1;
  }
}

string sign_in(){
  string username = "", password = "", info, readname, readword;
  ifstream fin ("userinfo.txt");
  JumpToPoint2:
  cout << "Username: ";
  cin >> username;
  cout << "Password: ";
  cin >> password;
  while (getline(fin, info)){
    istringstream iss(info);
    iss >> readname;
    iss >> readword;
    if (username == readname && readword == password){
      cout << "Hello " + username + "!" << endl;
      return username;
    }
  }
  int choice;
  cout << "Username or password incorrect. Please indicate your choice. " << endl;
  cout << "1. Try again" << endl << "2. Sign up" << endl << "3. Cancel" << endl;
  cin >> choice;
  if (choice == 1) goto JumpToPoint2;
  else if (choice == 2) { fin.close(); sign_up();}
  else { fin.close(); exit(1);}
}

void Records::sign()
{
  int choice = panel();
  if (choice == 1) user = sign_up();
  else if (choice == 2) user = sign_in();
  else exit(1);
}
