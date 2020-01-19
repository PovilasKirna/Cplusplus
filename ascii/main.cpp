#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector<char> tekstas;

void read();
int count_numbers();

int main() {
  read();
  count_numbers();
  return 0;
}

void read(){
  ifstream fin ("/Users/Povilas/Documents/GitHub/Cplusplus/ascii/input.txt");
  for (int i = 0; fin.eof() != true; ++i) {
    fin>>i;
    tekstas.push_back(i);
    cout<<" "<<tekstas[i];

  }
  fin.close();
}

int count_numbers(){
  return 0;
}