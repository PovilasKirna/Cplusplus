#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void read();
int calculate();

vector<int> data;

int main() {
  read();
  cout<<calculate();
}

void read(){
  int n,v,z,t;
  cin>>n;//amount
  cin>>v;//clean
  cin>>z;//paint
  cin>>t;//anksc
  data.push_back(n);
  data.push_back(v);
  data.push_back(z);
  data.push_back(t);
}

int calculate(){
  int time_to_rest = 0;
  int amount = data[0];//10
  int clean = data[0]*data[1];//2
  int paint = data[0]*data[2];//3
  int early = data[3];//2


  //

  return time_to_rest;
}