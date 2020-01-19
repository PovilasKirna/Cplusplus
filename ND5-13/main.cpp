#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;

void read(vector<vector<int>> &, string name);
void write(vector<vector<int>>&, vector<vector<int>>&, string);
void compareBoth(vector<vector<int>> &, vector<vector<int>> &);
void print(vector<vector<int>>);
void swap(int, vector<vector<int>> &, vector<vector<int>> &);
void printOut(vector<vector<int>> vect, string message, ofstream& fout);


int main() {
    vector<vector<int>> V;
    vector<vector<int>> Z;
    string InputV = "/Users/Povilas/Documents/GitHub/Cplusplus/ND5-13/inputV.txt";
    string InputZ = "/Users/Povilas/Documents/GitHub/Cplusplus/ND5-13/inputZ.txt";
    string outputFile = "/Users/Povilas/Documents/GitHub/Cplusplus/ND5-13/output.txt";
    //---
    cout << "Pries pakeituimus" << endl;
    //---reads and prints out the created vectors
    read(Z, InputZ);
    print(Z);
    read(V, InputV);
    print(V);
    //---first write to save unchanged vectors
    write(Z, V, "Pries pakeitimus");
    //---compares both of them (---changes values)
    compareBoth(Z, V);
    cout << "Po galutiniu pakeitimu" << endl;
    print(Z);
    print(V);
    //---writes to an external file
    write(Z, V, "Po galutiniu pakeitimu");
}

void read(vector<vector<int>> &vect, string filename) {
    int rowCount, colCount, x;
    vector<int> temp;
    ifstream fin(filename);
    fin >> rowCount >> colCount;
    for (unsigned i = 0; i < rowCount; i++) {
        for (unsigned j = 0; j < colCount; j++) {
            fin >> x;
            temp.push_back(x);
        }
        vect.push_back(temp);
        temp.clear();
    }
    fin.close();
}

void print(vector<vector<int>> vect) {
    for (unsigned i = 0; i < vect.size(); i++) {
        for (unsigned j = 0; j < vect[i].size(); j++) {
            cout << vect[i][j] << "  ";
        }
        cout << endl;
    }
    cout << endl;
}

void compareBoth(vector<vector<int>>& Z, vector<vector<int>>& V) {
    int smaller;
    if (Z.size() < V.size())
        smaller = Z.size();
    else
        smaller = V.size();
    for (int i = 0; i < smaller; i++) {
        int lineMin = Z[i][0];
        int lineMax = V[i][0];
        for (unsigned j = 0; j < V[i].size(); j++) {
            if (V[i][j] > lineMax) {
                lineMax = V[i][j];
            }
        }
        //---find both Z line max and V line min then choose whether to swap them
        for (unsigned k = 0; k < Z[i].size(); k++) {
            if (Z[i][k] < lineMin) {
                lineMin = Z[i][k];
            }
        }
        if (lineMax > lineMin)
            swap(i, Z, V);
    }
}

void swap(int i, vector<vector<int>>& Z, vector<vector<int>>& V) {
    vector<int>& Z1 = Z[i];
    vector<int>& V1 = V[i];
    string message = "Pakeista eilute: ";
    message += to_string(i + 1);
    Z1.swap(V1);
    cout << message << endl;
    print(Z);
    print(V);
}

void write(vector<vector<int>>& Z, vector<vector<int>>& V, string message) {
    ofstream fout;
    fout.open("output.txt", fstream::app);
    fout << message << endl;
    printOut(Z, "Vektorius Z(n,m)", fout);
    printOut(V, "Vektorius V(n,m)", fout);
    fout.close();
}

void printOut(vector<vector<int>> vect, string message, ofstream &fout) {
    fout << message << endl;
    fout << "    ";
    for (unsigned i = 1; i < vect[0].size()+1; i++) {
        fout << setw(2) << i << ". ";
    }
    fout << endl;
    for (unsigned i = 0; i < vect.size(); i++) {
        fout << i+1 << ".  ";
        for (unsigned j = 0; j < vect[i].size(); j++) {
            fout << setw(2) << vect[i][j] << "  ";
        }
        fout << endl;
    }
    fout << endl;
}