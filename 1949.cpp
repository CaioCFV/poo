#include <iostream>
#include <stdlib.h>
#include <iomanip> 
using namespace std;

/****************************************************
    CMD
****************************************************/

enum cmd { INSERIR, REMOVER, VER, LISTAR, SAIR };

cmd execCMD(){
    string strCmd;
    cin >> strCmd;
    cin.ignore();
    if(strCmd == "INS"){
        return INSERIR;
    } else if (strCmd == "REM"){
        return REMOVER;
    } else if (strCmd == "VER"){
        return VER;
    } else if (strCmd == "LST"){
        return LISTAR;
    } else if (strCmd == "SAIR"){
        return SAIR;
    } else {
        cout << "COMANDO NÃO ENCONTRADO: " << strCmd << endl;
		return SAIR;
    }
};

/****************************************************
    CONTATO
****************************************************/

class Contato {
    private:
        string nome;
        int idade;
        double altura;

    public: 
        string  getNome();
        int     getIdade();
        double  getAltura();
        void    setNome(string &nome);
        void    setIdade(int &idade);
        void    setAltura(double &altura);
};

string Contato::getNome(){
    return nome;
};

int Contato::getIdade(){
    return idade;
};

double Contato::getAltura(){
    return altura;
};

void Contato::setNome(string &nome){
    this->nome = nome;
};

void Contato::setIdade(int &idade){
    this->idade = idade;
};

void Contato::setAltura(double &altura){
    this->altura = altura;
};


/****************************************************
    AGENDA
****************************************************/

class Agenda {
    private:
        int qtd_contatos = 0;
        Contato contatos[100];
        
    public:
        void addPessoa(string &nome, int &idade, double &altura); 
        void imprimeAgenda();   
        void verPessoa(string &nome);
        void remPessoa(string &nome);    
        int  buscaPessoa(string &nome);
        void imprimePessoa(int &index);
};

void Agenda::imprimeAgenda(){
    double resumo = 0;
    
    cout 
        << setw(31)  << left  << "!Nome"
        << setw(11)  << left  << "!Idade"
        << setw(11)  << left  << "!Altura"
        << setw(1)   << left   << "!"
        << endl;


    for(int i=0;i<qtd_contatos;i++){
        cout 
            << setw(31)  << left  << "!" + contatos[i].getNome()
            << setw(1)   << left  << "!"
            << setw(10)  << right  << contatos[i].getIdade()
            << setw(1)   << left  << "!"
            << setw(10)  << right  << contatos[i].getAltura()
            << setw(1)   << left  << "!"
            << endl;
    }
}

void Agenda::addPessoa(string &nome, int &idade, double &altura){
    Contato c;
    c.setNome(nome);
    c.setIdade(idade);
    c.setAltura(altura);
    contatos[qtd_contatos] = c;
    qtd_contatos += 1;
    cout << "Contato " << nome << " inserido com sucesso!" << endl;
}

void Agenda::verPessoa(string &nome){
    string contato_nome;
    for(int i=0;i<qtd_contatos;i++){
        contato_nome = contatos[i].getNome();
        if(contato_nome == nome){
            cout
                << setw(15)  << left  << "Nome"
                << setw(2)   << left  << ":"
                << contatos[i].getNome()
                << endl;

            cout
                << setw(15)  << left  << "Idade"
                << setw(2)   << left  << ":"
                << contatos[i].getIdade()
                << endl;

            cout
                << setw(15)  << left  << "Altura"
                << setw(2)   << left  << ":"
                << fixed << setprecision(2) << contatos[i].getAltura()
                << endl;
        }
    }
}

void Agenda::remPessoa(string &nome){
    string contato_nome;
    int referencia = 0, i;
    for(i=0;i<qtd_contatos;i++){
        contato_nome = contatos[i].getNome();
        if(contato_nome == nome){
            qtd_contatos -= 1;
            referencia += 1;
        }
        contatos[i] = contatos[referencia];
        referencia += 1;
    }
    if(referencia == i){
        cout << "Nao foi encontrado o contato " << nome << " para remover!" << endl;
    }
}

int Agenda::buscaPessoa(string &nome){
    string contato_nome;
    int referencia = -1, i;
    for(i=0;i<qtd_contatos;i++){
        contato_nome = contatos[i].getNome();
        if(contato_nome == nome){
            referencia = i;
        }
    }
    return referencia;
}

void Agenda::imprimePessoa(int &index){
    if(index < qtd_contatos){
        cout
            << setw(15)  << left  << "Nome"
            << setw(2)   << left  << ":"
            << contatos[index].getNome()
            << endl;

        cout
            << setw(15)  << left  << "Idade"
            << setw(2)   << left  << ":"
            << contatos[index].getIdade()
            << endl;

        cout
            << setw(15)  << left  << "Altura"
            << setw(2)   << left  << ":"
            << fixed << setprecision(2) << contatos[index].getAltura()
            << endl;
    }
}

/****************************************************
    MAIN
****************************************************/

int main() {
    Agenda agenda;
    bool finalizar = false;
    string nome;
    int idade;
    double altura;

    while (!finalizar){
        switch (execCMD()){
            case INSERIR:
                getline(cin, nome);
                cin >> idade;
                cin >> altura;
                cin.ignore();
                agenda.addPessoa(nome, idade, altura);
          	    break;

            case REMOVER:
                getline(cin, nome);
                agenda.remPessoa(nome);
                break;

            case VER:
                getline(cin, nome);
                agenda.verPessoa(nome);
                break;


            case LISTAR:
                agenda.imprimeAgenda();
                break;


            case SAIR:
                finalizar = true;
                break;

            default:
    			break;
        }
    }
    return 0; 
};