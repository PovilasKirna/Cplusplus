#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

vector<vector<int>> A;

//8
//1 4 10 5 8 7 9 7
//5 9 7 6 12 9 7 1
//6 5 3 7 9 6 12 8
//4 3 7 6 9 11 8 9
//5 6 7 3 2 1 3 4
//9 9 2 1 22 4 5 6
//7 8 7 0 7 8 1 2
//1 2 4 5 7 8 9 21

//
//               1
//            12 8
//          11 8 9
//        2 1  3 4
//      1 22 4 5 6
//    7 0 7  8 1 2
//  2 4 5 7 8 9 21

vector<int> temp;

void read();
void write(string);
void deleterow();
void findmaxrow();

int Mmaxrow = 0;

int main() {
  read();
  write("Masyvas pries operacija:");
  findmaxrow();
  deleterow();
  write("Masyvas po operacijos:");
  return 0;
}

void read(){
  int n, m;
  ifstream fin ("/Users/Povilas/Documents/GitHub/Cplusplus/testas1214/input.txt");
  fin>>n;
  for (int j = 0; j < n; ++j) {
    for (int i = 0; i < n; ++i) {
      fin>>m;
      temp.push_back(m);
    }
    A.push_back(temp);
    temp.clear();
  }
  fin.close();
}

void findmaxrow(){
  int line, max;
  for (int i = 0; i < A.size(); ++i) {
    for (int pos = 0; pos < A[i].size(); ++pos) {
      line = A[i].size()-i; // determine which cell is the middle line
      if(pos+1 > line){
        if(A[i][pos] > max) {
          max = A[i][pos];
          Mmaxrow = i;
        }
      }
    }
  }
  cout<<max<<" rastas "<<Mmaxrow<<" eiluteje."<<endl;
}

void deleterow(){
  A.erase(A.begin()+Mmaxrow);
}

void write(string message){
  ofstream fout;
  fout.open("/Users/Povilas/Documents/GitHub/Cplusplus/testas1214/output.txt", ios::app);
  fout<<message<<endl;
  for (int i = 0; i < A.size(); ++i) {
    for (int j = 0; j < A[0].size(); ++j) {
      fout<<A[i][j]<<" ";
    }
    fout<<endl;
  }
  fout<<endl;
  fout.close();
}