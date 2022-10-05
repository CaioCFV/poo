#include <iostream>
#include <stdlib.h>
#include <iomanip> 
using namespace std;

class IRPF {
    private:
        string nome, cpf;
        int dependentes;
        double valorAnual;
        
    public:
        void ler();
        void ver();
        int calc();
};

void IRPF::ler(){
    getline(cin, nome);
    getline(cin, cpf);
    cin >> valorAnual;
    cin >> dependentes;
}

void IRPF::ver(){
    cout << "Nome: " << nome << endl;
    cout << "CPF: " << cpf << endl;
    cout << "Valor Anual: " << fixed << setprecision(2) << valorAnual << endl;
    cout << "Dependentes: " << dependentes << endl;
    calc();
}

int IRPF::calc(){
    double rMensal = valorAnual / 12;
    if(rMensal >= 1903.99 && rMensal <= 2826.65){
        cout << "IRPF: R$ "  << fixed << setprecision(2) << (valorAnual / 100) * 7.5 << endl;
        return 0;
    }
    if(rMensal >= 2826.66 && rMensal <= 3751.05){
        cout << "IRPF: R$ "  << fixed << setprecision(2) << (valorAnual / 100) * 15 << endl;
        return 0;
    }
    if(rMensal >= 3751.06 && rMensal <= 4664.68){
        cout << "IRPF: R$ " << fixed << setprecision(2) << (valorAnual / 100) * 22.5 << endl;
        return 0;
    }
    if(rMensal > 4664.68){
        cout << "IRPF: R$ " << fixed << setprecision(2) << (valorAnual / 100) * 27.5 << endl;
        return 0;
    }
    cout <<  "isentos" << endl;
}


int main(){
    IRPF f;
    f.ler();
    f.ver();
    return 0;
}