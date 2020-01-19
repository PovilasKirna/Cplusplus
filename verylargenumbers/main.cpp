#include<iostream>
using namespace std;

string findSum(string, string);

int main()
{
    string str1 = "5126717910121751622546";
    string str2 = "88888888888888888888888888888";
    string str3 = findSum(str1, str2);
    string str4 = "2525255125133485451578436833138834387837";
    cout<<findSum(str3, str4)<<endl;
    return 0;
}

string findSum(string str1, string str2){
  string str = "";
  //jei ilgesnis tai apkeicia vienas case
  if (str1.length() > str2.length())
    swap(str1, str2);
  //apsuka
  reverse(str1.begin(), str1.end());
  reverse(str2.begin(), str2.end());
  //
  int carry = 0;
  for (int i=0; i<str1.length(); i++){
    int sum = ((str1[i]-'0')+(str2[i]-'0')+carry);
    str.push_back(sum%10+'0');
    carry = sum/10;
  }

  for (int i=str1.length(); i<str2.length(); i++){
    int sum = ((str2[i]-'0')+carry);
    str.push_back(sum%10 + '0');
    carry = sum/10;
  }
  if (carry)
    str.push_back(carry+'0');

  //vel apsuka kad normaliai butu
  reverse(str.begin(), str.end());

  return str;
}

//2525255125222374345594043632149474899271
//2525255125222374345594043632149474899271