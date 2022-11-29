#include <iostream>
#include <stdlib.h>
#include <iomanip> 
using namespace std;

class Contato {
    private:
        string nome;
        int idade;
        double altura;

    public: 
        void addPessoa(string nome, int idade, double altura); 
        // void remPessoa(String nome);    
        // int buscaPessoa(String nome); // informa em que posição da agenda está a pessoa    
        // void imprimeAgenda(); // imprime os dados de todas as pessoas da agenda    
        Contato imprimePessoa(int index);
};

class Agenda {
    private:
        int lastSave = 0;
        Contato c[100];
        
    public:
        void addPessoa();
        void verPessoa();
};

void Agenda::addPessoa(){
    string nome;
    double altura;
    int idade;
    Contato v;
    getline(cin, nome);
    cin >> idade;
    cin >> altura;
    v.addPessoa(nome, idade, altura);
    c[lastSave] = v;
    lastSave += 1;
}

void Agenda::verPessoa(){
    string nome;
    getline(cin, nome);
    for(int i  = 0; i < lastSave; i++){
        if(nome == c[i].nome){
           
        }
    }
}

void Contato::addPessoa(string nome, int idade, double altura){
    this->nome=nome;
    this->idade=idade;
    this->altura=altura;
    cout << "Contato " << nome << " inserido com sucesso!" << endl;
}
   
int main() {
    TPoligono p;
	p.ler();
    cout << fixed << setprecision(2);
    cout << "perimetro - " << p.perimetro() << endl;
    return 0;
}