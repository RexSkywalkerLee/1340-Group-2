#include<iostream>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<string>
#include"head.h"

using namespace std;

void updateDay(int &day,int month,int year){
switch (month) {
  case 0,1,3,5,7,8,10:
  day=31;
  break;
  case 4,6,9,11:
  day=30;
  break;
  case 2:
  day= year%4==0? 29:28;
  break;
}
}

void info::latest(){
  int day,month,year;

  float daily[7]={0};
  string* date= new string[7];
  cout<<"Please type in the date of today in the format dd mm yyyy:"<<endl;
  cin<<day<<month<<year;
  for (i=0;i<7;i++){
    day--;
    if (day==0) {
      month--;
      updateDay(day,month,year);}
    if (month==0){
      month=12;
      year--;}
    string day1=day<10? "0"+ to_string(day):to_string(day);
    string month1=month<10? "0"+ to_string(month):to_string(month);
    date[i]=to_string(year)+" "+month1+" "+day1;
  }
    daily[i]=sum;
    ifstream fin(user + "_records.txt");
    string record;
    while getlin(fin,record){
      for (int i=0;i<7;i++){
        if(record.find(date[i]!=-1)){
          istringstream iss(record);
          for (int j = 0; j < 6; j++) iss >> tempNum;
          daily[i] += atof(tempNum.c_str());
        }
      }
    }
  float unit;
  cout<<"You wish one \'+\' represents: "<<endl;
  cin>>unit;
  cout<<"So one \'-\' represents - "<<unit <<endl;
  for (int j=0;j<7;j++){
    cout<<date[i]<<"  ";
    string* unitnum= new string[7];
    unitnum[j]= daily[j]>0? string(daily[j]/unit,'+'):string(abs(daily[j]/unit),'-');
    cout<<unitnum[j]<<endl;
  }
}
