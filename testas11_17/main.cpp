#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector<int> A;
vector<int> A_old;
vector<int> pos;

void read();
void find_same();
void delete_same();
void write();

int main() {
  read();
  find_same();
  delete_same();
  write();
}

void read(){
  ifstream fin ("/Users/Povilas/Documents/GitHub/Cplusplus/testas11_17/input.txt");
  for (int i = 0; fin.eof() != true; ++i) {
    fin >> i;
    A.push_back(i);
    A_old.push_back(i);
  }
}

void find_same(){
  for (int i = 0; i < A.size(); ++i) {
    for (int j = i+1; j < A.size(); ++j) {
      if(A[i]==A[j] && j != i){
        pos.push_back(j);
      }
    }
  }r
}

void delete_same(){
  for (int i = pos.size()-1; i >= 0; i--) {
    A.erase(A.begin()+pos[i]);
  }
}

void write(){
  ofstream fout ("/Users/Povilas/Documents/GitHub/Cplusplus/testas11_17/output.txt");
  fout<<"Masyvas pries salinima: ";
  for (int i = 0; i < A_old.size(); ++i) {
    fout<<A_old[i]<< " ";
  }
  fout<< "\n" << "Masyvas po salinimo: ";
  for (int j = 0; j < A.size(); ++j) {
    fout<<A[j]<<" ";
  }
}
