#include<iostream>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<string>
#include"head.h"
#include<termios.h>
#include<unistd.h>

using namespace std;
int panel();
string sign_up();
string sign_in();
void terminateORnot();

int panel()//Greeting to users
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

string sign_up()//new user sign up and initial record.txt & account.txt
{
  string username, password, password_2;
  cout << "Please set your username: ";
  cin >> username;
  JumpToPoint1:
  cout << "Please set your password: ";
  termios t1;
  tcgetattr(STDIN_FILENO,&t1);
  termios t2=t1;
  t2.c_lflag &= ~ECHO;
  tcsetattr(STDIN_FILENO,TCSANOW,&t2);
  cin >> password;
  cout<<endl;
  cout << "Please confirm your password: ";
  cin >> password_2; 
  cout<<endl;
  tcsetattr(STDIN_FILENO,TCSANOW,&t1);

  if (password == password_2){
    ofstream fout ("userinfo.txt", ios::app);
    fout << username << ' ' << password << endl;
    fout.close();
    fout.open(username + "_records.txt", ios::app);
    fout.close();
    fout.open(username + "_account.txt", ios::app);
    double info1, info2, info3;
    cout << "Initiating accouting system: " << endl;
    cout << "Cash: ";
    cin >> info1;
    cout << "Debit_Card: ";
    cin >> info2;
    cout << "Credit_Card: ";
    cin >> info3;
    fout << info1 << ' ' << info2 << ' ' << info3 << endl;
    fout << "Cash " << info1 << endl;
    fout << "Debit_Card " << info2 << endl;
    fout << "Credit_Card " << info3 << endl;
    fout.close();
    cout << "You have signed up! Please sign in to start account management." << endl;
    return sign_in();
  }
  else{
    cout << "Password is not correct. Please set again." << endl;
    goto JumpToPoint1;
  }
}


string sign_in(){ //user sign in and greeting
  string username = "", password = "", info, readname, readword;
  JumpToPoint2:
  ifstream fin ("userinfo.txt");
  cout << "Username: ";
  cin >> username;
  termios t1;
  tcgetattr(STDIN_FILENO,&t1);
  termios t2=t1;
  t2.c_lflag &= ~ECHO;
  tcsetattr(STDIN_FILENO,TCSANOW,&t2);
  cout << "Password: ";
  cin >> password;
  cout<<endl;
  tcsetattr(STDIN_FILENO,TCSANOW,&t1);
  while (getline(fin, info)){
    istringstream iss(info);
    iss >> readname;
    iss >> readword;
    if (username == readname && readword == password){
      cout << "\nHello " + username + "!\n\n";
      return username;
    }
  }
  int choice;  // if wrong password
  cout << "Username or password incorrect. Please indicate your choice. " << endl;
  cout << "1. Try again" << endl << "2. Sign up" << endl << "3. Cancel" << endl;
  cin >> choice;
  if (choice == 1) goto JumpToPoint2;
  else if (choice == 2) { fin.close(); sign_up();}
  else { fin.close(); exit(1);}
}

//sign feature
string sign()
{
  int choice = panel();
  if (choice == 1) return sign_up();
  else if (choice == 2) return  sign_in();
  else exit(1);
}


void terminateORnot()  //indicate users choice to whether continue
{
  cout <<"Continue management? (y/n)" << endl;
  char finalChoice;
  cin >> finalChoice;
  if (finalChoice == 'y'){
    cout << endl;
    return;
  }
  else{
    cout << "Bye bye!" << endl;
    exit(1);
  }
}

