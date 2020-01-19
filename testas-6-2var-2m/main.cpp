#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

vector<int>X;
vector<int>Y;

string inputX = "/Users/Povilas/Documents/GitHub/Cplusplus/testas-6-2var-2m/inputX.txt";
string inputY = "/Users/Povilas/Documents/GitHub/Cplusplus/testas-6-2var-2m/inputY.txt";
string foutname = "/Users/Povilas/Documents/GitHub/Cplusplus/testas-6-2var-2m/output.txt";

void read(string name, vector<int>&);
void findMinIndex(vector<int>, int &minIndex);
void write(ofstream&);
void change(int minIndex, int, int, vector<int>);

int main() {
  int minIndex = 0;
  read(inputX, X);
  read(inputY, Y);
  ofstream fout (foutname);
  fout<<"Duomenys"<<endl;
  write(fout);
  findMinIndex(X, minIndex);
  change(minIndex, 0, X.size(), X);
  findMinIndex(Y, minIndex);
  change(minIndex, 0, 1, Y);
  fout<<endl<<"Rezultatai"<<endl;
  write(fout);
  fout.close();
}

void read(string name, vector<int>&Z){
  int z = 0, n = 0;
  ifstream fin (name);
  fin>>n;
  for (int i = 0; i < n; ++i) {
    fin>>z;
    Z.push_back(z);
  }
}

void findMinIndex(vector<int>Z, int &minIndex){
  int min = INT_MAX;
  for (int i = 0; i < Z.size(); ++i) {
    if(Z[i] < min){
      min=Y[i];
      minIndex = i;
    }
  }
}

void change(int minIndex, int z1, int z2, vector<int>Z){
  Z[minIndex] = Z[z1]+Z[z2];
}

void write(ofstream &fout){
  fout<<"X["<<X.size()<<"]"<<endl;
  for (int j = 0; j < X.size(); j++) {
    fout<<j+1<<"\t"<<X[j]<<endl;
  }
  fout<<"-----------";
  fout<<endl<<"Y["<<Y.size()<<"]"<<endl;
  for (int j = 0; j < Y.size(); j++) {
    fout<<j+1<<"\t"<<Y[j]<<endl;
  }
}