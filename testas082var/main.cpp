#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;

vector<vector<int>> mokiniai;
vector<int> temp;
int mMokinys;
int mNeneigiami;

void input();
void output();
void mosttens();
void negative();

int main() {
  input();
  mosttens();
  negative();
  output();
  return 0;
}

void input(){
  int n, m, x;
  ifstream fin ("/Users/Povilas/Documents/GitHub/Cplusplus/testas082var/input.txt");
  fin>>n>>m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      fin>> x;
      temp.push_back(x);
    }
    mokiniai.push_back(temp);
    temp.clear();
  }
  mNeneigiami = n; // kiek isvis mokiniu
  fin.close();
}


void output(){
  ofstream fout ("/Users/Povilas/Documents/GitHub/Cplusplus/testas082var/Rezultatai.txt");
  fout<< "Mokinio nr." << "\t" << "Ivertinimai" << endl;

  for (int i = 0; i < mokiniai.size(); ++i)
  {
    fout<<setw(10)<<"Nr. "<<i+1<<"\t";
    for (int j = 0; j < mokiniai[0].size(); ++j)
    {
      fout << mokiniai[i][j] << ' ';
    }
    fout << endl;
  }

  fout<<endl<<"Daugiausiai desimtuku turi mokinys nr. "<<mMokinys<<endl;
  fout<<endl<<"Neigiamu pazymiu neturi "<<mNeneigiami<<endl;
  fout.close();
}

void mosttens(){
  int cc= 0, maxCC = cc;
  for (int i = 0; i < mokiniai.size(); ++i)
  {
    for (int j = 0; j < mokiniai[0].size(); ++j)
    {
      if(mokiniai[i][j] == 10)
        cc++;
    }
    if(maxCC < cc){
      maxCC = cc;
      mMokinys = i+1;
    }
    cc=0;
  }
}

void negative(){
  int currentline = -1;
  for (int i = 0; i < mokiniai.size(); ++i)
  {
    for (int j = 0; j < mokiniai[0].size(); ++j) {
      if (mokiniai[i][j] < 4 && currentline != i){
        mNeneigiami--;
        currentline++;
      }
    }
    if(currentline!=i)
      currentline++;
  }
}