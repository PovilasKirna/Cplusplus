#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

vector<vector<string>> mokiniai;
vector<vector<string>> sorted;


void Read();
void Write();
void Sort(string);
void PrintOut();

int main() {
    string str="";
    cout<<"Month: ";
    getline(cin, str);
    Read();
    Sort(str);
    Write();
    //PrintOut();
    return 0;
}

void Read(){
    int n;
    string mokinys="";
    string kodas="";
    string pavarde = "";
    vector<string> Mokinys;
    ifstream fin ("/Users/Povilas/Documents/GitHub/Cplusplus/testas1-20/input.txt");
    fin>>n;
    for (int i = 0; i < n; ++i) {
        fin>>mokinys>>pavarde>>kodas;
        Mokinys.push_back(mokinys);
        Mokinys.push_back(pavarde);
        Mokinys.push_back(kodas);
        mokiniai.push_back(Mokinys);
        Mokinys.clear();
    }
    fin.close();
}

void Sort(string month){
    vector<string> Mokinys;
    for(int x =0; x<mokiniai.size(); x++){
        for (int i = 0; i < mokiniai[x].size(); ++i) {
            if(i != 0 && i != 1){
                string kodas = mokiniai[x][i];
                char lytis = kodas[0];
                string menesis = kodas.substr(3, 2);
                if(lytis == '4' && menesis == month){
                    string diena = kodas.substr( 5, 2);
                    cout<<mokiniai[x][0]<<" "<<diena<<endl;
                    Mokinys.push_back(mokiniai[x][0]);
                    Mokinys.push_back(diena);
                    sorted.push_back(Mokinys);
                    Mokinys.clear();
                }
            }
        }
    }
}

void Write(){
    ofstream fout ("/Users/Povilas/Documents/GitHub/Cplusplus/testas1-20/output.txt");
    for (int i = 0; i < sorted.size(); ++i) {
        fout<<sorted[i][0]<<" "<<sorted[i][1]<<endl;
    }
    fout.close();
}

void PrintOut(){
    for(int x =0; x<mokiniai.size(); x++){
        for (int i = 0; i < mokiniai[x].size(); ++i) {
            cout<<mokiniai[x][i]<<" ";
        }
        cout<<endl;
    }
}