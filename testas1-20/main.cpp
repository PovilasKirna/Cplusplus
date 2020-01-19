#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

void Read();
void Write();
void Sort(string);
void PrintOut();

struct Mokinys {
    string Vardas ="";
    string Pavarde="";
    string AsmensKodas="";
};

vector<Mokinys> mokiniusarasas;

int main() {
    string str="";
    cout<<"Month: ";
    getline(cin, str);
    Read();
    Sort(str);
    Write();
    return 0;
}

void Read(){
    int n;
    string vardas, pavarde, kodas;
    ifstream fin ("/Users/Povilas/Documents/GitHub/Cpluplus/testas1-20/input.txt");
    fin>>n;
    for (int i = 0; i < n; ++i) {
        mokiniusarasas.push_back(Mokinys());
        fin>>vardas>>pavarde>>kodas;
        mokiniusarasas[i].Vardas = vardas;
        mokiniusarasas[i].Pavarde = pavarde;
        mokiniusarasas[i].AsmensKodas = kodas;
    }
    fin.close();
}

void Sort(string month){
    int x=0;
    for (auto it = mokiniusarasas.begin(); it != mokiniusarasas.end(); ++it) {
        char lytis = mokiniusarasas[x].AsmensKodas[0];
        string menesis = mokiniusarasas[x].AsmensKodas.substr(3, 2);
        if(lytis != '4' && menesis != month){
            mokiniusarasas.erase(it);
        }
        x++;
    }
}

void Write(){
    ofstream fout ("/Users/Povilas/Documents/GitHub/Cpluplus/testas1-20/output.txt");
    int x = 0;
    for (auto i : mokiniusarasas) {
        string diena = mokiniusarasas[x].AsmensKodas.substr(5, 2);
        fout<<mokiniusarasas[x].Vardas<<" "<<diena;
        cout<<mokiniusarasas[x].Vardas<<" "<<diena;
        x++;
    }
    fout.close();
}
