#include<iostream>
#include<fstream>
#include<vector>
#include<cmath>
#include<string>
#include<iomanip>
using namespace std;

vector<vector<double>> trikampiuvirsunes;
vector<double> trikampis;
vector<double>biggestEquilaterTriangle;
double maxArea = 0, distance_a = 0, distance_b = 0, distance_c = 0;
string content = "";

void read();
void findequilateraltriangle();
double sidelength(double, double, double, double);
double area(double);
double findDistance(char);
void write();
void copy();

int main() {
  read();
  copy();
  findequilateraltriangle();
  write();
}

void read() {
  ifstream fin("/Users/Povilas/Documents/GitHub/Cplusplus/ND4-10/input.txt");
  int n = 0;
  double x = 0, y = 0;
  fin >> n;
  cout<<n<< " triangles" << endl;
  for (int i = 0; i < n; i++) {
    for (int t = 0; t < 3; t++) {
            fin >> x >> y;
            trikampis.push_back(y);
            trikampis.push_back(x); // trikampis {x3, y3, x2, y2, x1, y1}
    }
    trikampiuvirsunes.push_back(trikampis);
    trikampis.clear();
  }
  fin.close();
}

void findequilateraltriangle() {
  double x1 = 0, x2 = 0, x3 = 0, y1 = 0, y2 = 0, y3 = 0, a = 0, b = 0, c = 0, Area = 0;
  for (int i = 0; i < trikampiuvirsunes.size(); i++) {
      y3 = trikampiuvirsunes[i][0];
      x3 = trikampiuvirsunes[i][1];
      y2 = trikampiuvirsunes[i][2];
      x2 = trikampiuvirsunes[i][3];
      y1 = trikampiuvirsunes[i][4];
      x1 = trikampiuvirsunes[i][5];
      a = sidelength(x1, y1, x2, y2);
      b = sidelength(x2, y2, x3, y3);
      c = sidelength(x3, y3, x1, y1);
      if (abs(a-b) < 0.001 && abs(b-c) < 0.001 && abs(c-a) < 0.001) {
        cout << i+1 << " Triangle is equilateral" << endl;
        Area = area(a);
        if (Area > maxArea) {
          maxArea = Area;
          biggestEquilaterTriangle.clear();
          biggestEquilaterTriangle.push_back(y3);
          biggestEquilaterTriangle.push_back(x3);
          biggestEquilaterTriangle.push_back(y2);
          biggestEquilaterTriangle.push_back(x2);
          biggestEquilaterTriangle.push_back(y1);
          biggestEquilaterTriangle.push_back(x1);
          distance_a = findDistance('a');
          distance_b = findDistance('b');
          distance_c = findDistance('c');
        }
      }
      else {
        cout << i+1 << " Triangle isn't equilateral" << endl;
      }
  }
  if(maxArea!=0){
    cout << "Biggest area of an equilateral triangle: " << maxArea << endl;
  }
  else{
    cout << "There were no equilateral triangles found" << endl;
  }
}

double sidelength(double x1, double y1, double x2, double y2) {
  return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

double area(double side) {
  return sqrt(3) / 4 * pow(2, side);
}

double findDistance(char id){
  switch(id){
  case 'a':
    return sqrt(pow((biggestEquilaterTriangle[5]), 2) + pow((biggestEquilaterTriangle[4]), 2));
  case 'b':
    return sqrt(pow((biggestEquilaterTriangle[3]), 2) + pow((biggestEquilaterTriangle[2]), 2));
  case 'c':
    return sqrt(pow((biggestEquilaterTriangle[1]), 2) + pow((biggestEquilaterTriangle[0]), 2));
  }
}

void write(){
  ofstream fout("/Users/Povilas/Documents/GitHub/Cplusplus/ND4-10/output.txt");
  fout<<"Duomenys:"<<endl;
  fout<<endl;
  fout<<content<<endl;
  fout<<endl;
  fout<<"Rezultatai:"<<endl;
  fout<<endl;
  fout<<"Didziausio lygiasonio trikampio plotas:"<<endl;
  fout<<setprecision(3)<<maxArea<<endl;
  fout<<"Atstumai nuo jo virsuniu iki kordinaciu pradzios:"<<endl;
  fout<<"a = "<<setprecision(3)<<distance_a<<endl;
  fout<<"b = "<<setprecision(3)<<distance_b<<endl;
  fout<<"c = "<<setprecision(3)<<distance_c<<endl;
  fout.close();
}

void copy(){
  ifstream fin ("/Users/Povilas/Documents/GitHub/Cplusplus/ND4-10/input.txt");
  int i = 0;
  for(i; fin.eof()!=true ; i++)
    content += fin.get();
  i--;
  content.erase(content.end()-1);
  fin.close();
}