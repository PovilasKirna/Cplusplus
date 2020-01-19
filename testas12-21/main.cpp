#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

void Read();
void CountInLine(string);
void CheckLines();
void Write();

int MaxSkyrikliu = 0;
int MaxLine = 1;
vector<int> SkyrikliuCount;

int main() {
  Read();
  CheckLines();
  Write();
  return 0;
}

void Read() {
  string line;
  ifstream fin ("/Users/Povilas/Documents/GitHub/Cplusplus/testas12-21/input.txt");

  while(!fin.eof()) {
    getline(fin, line);
    CountInLine(line);
    line.clear();
  }
  fin.close();
}

void CountInLine(string line) {
  int cc = 0;
  char symbol = ' ';

  for (int i= 0; i < line.size(); i++) {
    symbol = line[i];
    if(symbol == ' ' || symbol == '.' || symbol == ',')
      cc++;
  }

  SkyrikliuCount.push_back(cc);
  cout << cc << endl;
  if(cc > MaxSkyrikliu)
    MaxSkyrikliu = cc;
}

void CheckLines() {
  int MaxSkyrikliuInLine = SkyrikliuCount[0];
  for (int i = 0; i < SkyrikliuCount.size(); ++i) {
    if(SkyrikliuCount[i] > MaxSkyrikliuInLine)
      MaxLine = i+1;
  }
}

void Write() {
  ofstream fout ("/Users/Povilas/Documents/GitHub/Cplusplus/testas12-21/output.txt");
  for(int i = 0; i < SkyrikliuCount.size(); i++) {
    fout << SkyrikliuCount[i] << endl;
  }
  fout << "Daugiausiai skyrikliu yra " << MaxLine << "-oje eiluteje." << endl;
  fout.close();
}





/*
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

void read();
void countinline(string);
void checklines();
void write();

int Mmaxskyrikliu = 0;
int Mlinemax = 1;
vector<int> skyrikliucount;

int main() {
  read();
  checklines();
  write();
  return 0;
}

void read(){
  string line;
  ifstream fin ("/Users/Povilas/Documents/GitHub/Cplusplus/testas12-21/input.txt");
  int i=0;
  while(!fin.eof()){
    getline(fin, line);
    countinline(line);
    line.clear();
    i++;
  }
  fin.close();
}

void countinline(string line){
  int cc = 0;
  char symbol = ' ';
  for (int i= 0; i < line.size(); i++){
    symbol = line[i];
    if(symbol == ' ' || symbol == '.' || symbol == ',')
      cc++;
  }
  skyrikliucount.push_back(cc);
  cout<<cc<<endl;
  if(cc > Mmaxskyrikliu)
    Mmaxskyrikliu = cc;
}

void checklines(){
  int max = skyrikliucount[0];
  for (int i = 0; i < skyrikliucount.size(); ++i) {
    if(skyrikliucount[i] > max)
      Mlinemax = i+1;
  }
}

void write(){
  ofstream fout ("/Users/Povilas/Documents/GitHub/Cplusplus/testas12-21/output.txt");
  for(int i = 0; i < skyrikliucount.size(); i++){
    fout<<skyrikliucount[i]<<endl;
  }
  fout<<"Daugiausiai skyrikliu yra "<<Mlinemax<<"-oje eiluteje."<<endl;
  fout.close();
}*/
