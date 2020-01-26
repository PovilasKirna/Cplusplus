#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

void Read();
void Write(double);
double Calculate(int);

struct Butas {
    int ButoNr = 0;
    string Pavarde="";
    vector<int> menesiai;
    double suvartojimas = 0.;
};

vector<Butas> butuSarasas;

int main() {
    int price;
    double suma;
    cout<<"Price kW (ct): ";
    cin>>price;
    Read();
    suma = Calculate(price);
    Write(suma);
    return 0;
}

void Read(){
    int n, butoNr, men1, men2, men3, men4, men5, men6;
    string pavarde;
    ifstream fin ("/Users/Povilas/Documents/GitHub/Cpluplus/electricity_bills_structs /cmake-build-debug/input.txt");
    fin>>n;
    for (int i = 0; i < n; ++i) {
        butuSarasas.push_back(Butas());
        fin>>butoNr>>pavarde>>men1>>men2>>men3>>men4>>men5>>men6;
        butuSarasas[i].ButoNr = butoNr;
        butuSarasas[i].Pavarde = pavarde;
        butuSarasas[i].menesiai.push_back(men1);
        butuSarasas[i].menesiai.push_back(men2);
        butuSarasas[i].menesiai.push_back(men3);
        butuSarasas[i].menesiai.push_back(men4);
        butuSarasas[i].menesiai.push_back(men5);
        butuSarasas[i].menesiai.push_back(men6);
    }
    fin.close();
}

double Calculate(int price){
    double pricePerkW = price/100.;
    double suma = 0.;
    for (int i = 0; i < butuSarasas.size(); ++i) {
        int kWs = butuSarasas[i].menesiai[1] + butuSarasas[i].menesiai[2] + butuSarasas[i].menesiai[3] + butuSarasas[i].menesiai[4] + butuSarasas[i].menesiai[5] + butuSarasas[i].menesiai[6];
        butuSarasas[i].suvartojimas = kWs*pricePerkW;
        suma += butuSarasas[i].suvartojimas;
    }
    return suma;
}

void Write(double suma){
    ofstream fout("/Users/Povilas/Documents/GitHub/Cpluplus/electricity_bills_structs /cmake-build-debug/output.txt");

    fout<<"Duomenys:"<<endl;
    for (int j = 0; j < butuSarasas.size(); ++j) {
        fout<<butuSarasas[j].ButoNr<<" "<<butuSarasas[j].Pavarde<<" "<<butuSarasas[j].menesiai[0]<<" "<<butuSarasas[j].menesiai[1]<<" "<<butuSarasas[j].menesiai[2]<<" "<<butuSarasas[j].menesiai[3]<<" "<<butuSarasas[j].menesiai[4]<<" "<<butuSarasas[j].menesiai[5]<<" "<<endl;
    }

    fout<<endl;

    fout<<"Rezultatai:"<<endl;
    fout<<"Visas daugiabutis per puse metu sunaudojo uz: "<<suma<<" eur."<<endl;
    for (int i = 0; i < butuSarasas.size(); i++){
        fout<<"Butas: "<<butuSarasas[i].ButoNr<<" Savininkas: "<<butuSarasas[i].Pavarde<<" Suvartojo per puse metu uz: "<<butuSarasas[i].suvartojimas<<" eur."<<endl;
    }
    fout.close();
}