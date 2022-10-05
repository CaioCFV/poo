#include <iostream>
#include <stdlib.h>
#include <iomanip> 
using namespace std;

class TVet {
    private:
        int qtd_numeros = 0;
        double v[100], nMenor, nMaior;
        
    public:
        void ler();
        double maior();
        double menor();
        double mediaEx();
};

void TVet::ler(){
    cin >> qtd_numeros;
    for(int i=0;i<qtd_numeros;i++){
        cin >> v[i]; 
    }
    
    nMaior = v[0];
    nMenor = v[0];
    
    for(int i=0;i<qtd_numeros;i++){
        if(v[i] > nMaior) {
            nMaior = v[i];
        }
    }
    
    for(int i=0;i<qtd_numeros;i++){
        if(v[i] < nMenor) {
            nMenor = v[i];
        }
    }
}

double TVet::maior(){
    return nMaior;
}

double TVet::menor(){
    return nMenor;
}

double TVet::mediaEx(){
    double soma, divsion = 0;
    for(int i=0;i<qtd_numeros;i++){
        if(v[i] != nMenor && v[i] != nMaior) {
            soma += v[i];
            divsion += 1;
        }
    }
    return (soma / divsion);
}

    int main()
    {
        TVet v;
        v.ler();
        cout << fixed << setprecision(2);
        cout << "Maior: "<< v.maior() << endl;
        cout << "Menor: "<< v.menor() << endl;
        cout << "Media sem extremos: "<< v.mediaEx() << endl;
        return 0;
    }