#include <iostream>
#include <stdlib.h>
#include <iomanip> 
using namespace std;


class Data {
    private:
        int dia, mes, ano;

    public: 
        void   setDate(string &data);
        string getFormatedDate();
        int verIdadeEm(int &ref_dia, int &ref_mes, int &ref_ano);
};

void Data::setDate(string &data){
    int ref = 0;
    string s_dia, s_mes, s_ano;

    for(int i = 0; i<data.length();i++){
        if(data[i] == '/'){
            ref += 1;
        } else if (ref == 0){
            s_dia += data[i];
        } else if(ref == 1){
            s_mes += data[i];
        } else if(ref == 2){
            s_ano += data[i];
        }
    }

    int ref_ano = stoi(s_ano);

    if(ref_ano < 2000 && ref_ano > 25){
        ref_ano += 1900;
    } else if(ano < 2000 && ref_ano <= 25) {
        ref_ano += 2000;
    }

    this->dia = stoi(s_dia);
    this->mes = stoi(s_mes);
    this->ano = ref_ano;
}

int Data::verIdadeEm(int &ref_dia, int &ref_mes, int &ref_ano){
    int idade;
    
    idade = ref_ano - ano;

    if((ref_mes - mes) < 0){
        idade -= 1;
    }else if ((ref_dia - dia) < 0){
        idade -= 1;
    }

    return idade;
}

string Data::getFormatedDate(){
    string
        f_dia = to_string(this->dia),
        f_mes = to_string(this->mes);

    return 
        (f_dia.length() < 2 ? "0"+f_dia : f_dia) + "/" +
        (f_mes.length() < 2 ? "0"+f_mes : f_mes) + "/" +
        to_string(this->ano);
}

/****************************************************
    PESSOA
****************************************************/

class Pessoa {
    private:
        string nome, data_nascimento;
        double altura;
        int idade;

    public: 
        string  getNome();
        string  getDataNascimento();
        double  getAltura();
        int     getIdade();
        void    setNome(string &nome);
        void    setDataNascimento(string &idade);
        void    setAltura(double &altura);
        void    setIdade(int &idade);
};

string Pessoa::getNome(){
    return nome;
};

string Pessoa::getDataNascimento(){
    return data_nascimento;
};

double Pessoa::getAltura(){
    return altura;
};

int Pessoa::getIdade(){
    return idade;
};

void Pessoa::setNome(string &nome){
    this->nome = nome;
};

void Pessoa::setIdade(int &idade){
    this->idade = idade;
};

void Pessoa::setDataNascimento(string &data_nascimento){
    this->data_nascimento = data_nascimento;
};

void Pessoa::setAltura(double &altura){
    this->altura = altura;
};


/****************************************************
    LISTA
****************************************************/

class Lista {
    private:
        int qtd_pessoas = 0;
        Pessoa pessoas[100];
        
    public:
        void lerPessoa();
        void listarPessoas();
};  

void Lista::lerPessoa(){
    Pessoa p;
    Data d;
    string nome, data_nascimento;
    double altura;

    getline(cin, nome);
    getline(cin, data_nascimento);
    
    d.setDate(data_nascimento);
    data_nascimento = d.getFormatedDate();

    int 
        ref_dia = 31,
        ref_mes = 12,
        ref_ano = 2021;

    int idade = d.verIdadeEm(ref_dia,ref_mes,ref_ano);



    cin >> altura;
    cin.ignore();

    p.setNome(nome);
    p.setDataNascimento(data_nascimento);
    p.setAltura(altura);
    p.setIdade(idade);
    pessoas[qtd_pessoas] = p;
    qtd_pessoas += 1;
};

void Lista::listarPessoas(){
    for(int i=0;i<qtd_pessoas;i++){
        cout
            << setw(15)  << left  << "Nome"
            << setw(2)   << left  << ":"
            << pessoas[i].getNome()
            << endl;

        cout
            << setw(15)  << left  << "Data Nascimento"
            << setw(2)   << left  << ":"
            << pessoas[i].getDataNascimento()
            << endl;

        cout
            << setw(15)  << left  << "Altura"
            << setw(2)   << left  << ":"
            << fixed << setprecision(2) << pessoas[i].getAltura()
            << endl;
        
        cout
            << setw(15)  << left  << "Idade"
            << setw(2)   << left  << ":"
            << pessoas[i].getIdade()
            << endl;
        
        if(i < qtd_pessoas-1){
            cout << endl;
        }
    }

};

/****************************************************
    MAIN
****************************************************/

int main() {
    Lista l;
    int qtd_pessoas;
    cin >> qtd_pessoas;
    cin.ignore();
    for(int i=0; i<qtd_pessoas; i++){
        l.lerPessoa();
    }

    l.listarPessoas();

    return 0; 
};