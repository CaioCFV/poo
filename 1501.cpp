#include <iostream>
#include <iomanip> 
using namespace std;

/****************************************************
    CMD
****************************************************/

enum cmd { ADICIONAR_PF, ADICIONAR_PJ, REMOVER, MOSTRAR, CONSULTAR_IR, LISTAR, SAIR };

cmd execCMD(){
    int strCmd;
    cin >> strCmd;
    switch (strCmd){
        case 1:
          	return ADICIONAR_PF;
        case 2:
            return ADICIONAR_PJ;
        case 3:
            return REMOVER;
        case 4:
            return MOSTRAR;
        case 5:
            return CONSULTAR_IR;
        case 6:
            return LISTAR;
        case 7:
            return SAIR;
        default:
            cout << "COMANDO NÃO ENCONTRADO" << endl;
			return SAIR;
    }
};

void mostrarOpcoesCMD(){
    cout << "1 - inserir pessoa fisica" << endl;
    cout << "2 - inserir pessoa juridica" << endl;
    cout << "3 - remover" << endl;
    cout << "4 - consultar" << endl;
    cout << "5 - ir" << endl;
    cout << "6 - listar" << endl;
    cout << "7 - sair" << endl;
}

/****************************************************
    PESSOA
****************************************************/

class Pessoa {
    protected:
        int codigo;
        string nome, tipo_pessoa = "NÃO DEFINIDO";
        double rendaanual, IR;

    public:
        virtual void adicionar() = 0;
        virtual void calcularIR() = 0;
        virtual void mostrar() = 0;
        int getCodigo();
        double getIR();
        string getNome();
        string getTipoPessoa();
        double getRendaAnual();
        void deletar(string &cod){};
        void listar(string &cod){};
};

int Pessoa::getCodigo(){
    return codigo;
};

double Pessoa::getIR(){
    return IR;
};

string Pessoa::getNome(){
    return nome;
};

string Pessoa::getTipoPessoa(){
    return tipo_pessoa;
};

double Pessoa::getRendaAnual(){
    return rendaanual;
};

/****************************************************
    PESSOA FISICA
****************************************************/

class PessoaFisica : public Pessoa {
    private:
        string tipo_pessoa = "F", cpf, profissao;
        int dependentes;

    public:
        void adicionar();
        void calcularIR();
        void mostrar();
};

void PessoaFisica::adicionar(){
    cin >> codigo;
    cin.ignore();
    getline(cin, nome);
    cin >> rendaanual;
    cin.ignore();
    getline(cin, cpf);
    getline(cin, profissao);
    cin >> dependentes;
    cin.ignore();
    calcularIR();
};

void PessoaFisica::mostrar(){
    cout << "Codigo : " << getCodigo() << endl;
    cout << "Nome : " << getNome() << endl;
    cout << "Renda Anual : " << getRendaAnual() << endl;
    cout << "CPF : " << cpf << endl;
    cout << "Profissao : " << profissao << endl;
    cout << "Dependentes : " << dependentes << endl;
};

void PessoaFisica::calcularIR(){
    IR = 0.07 * rendaanual;
};

/****************************************************
    PESSOA JURIDICA
****************************************************/

class PessoaJuridica : public Pessoa {
    private:
        string tipo_pessoa = "J", insc_municipal, insc_estadual, cnpj;
        int dependentes;
    public:
        void adicionar();
        void calcularIR();
        void mostrar();
};

void PessoaJuridica::adicionar(){
    cin >> codigo;
    cin.ignore();
    getline(cin, nome);
    cin >> rendaanual;
    cin.ignore();
    getline(cin, cnpj);
    cin >> insc_municipal;
    cin.ignore();
    cin >> insc_estadual;
    cin.ignore();
    calcularIR();
};

void PessoaJuridica::calcularIR(){
    if(rendaanual > 200000){
        IR = 0.25 * rendaanual;
    } else {
        IR = 0.15 * rendaanual;
    }
};

void PessoaJuridica::mostrar(){
    cout << "Codigo : " << getCodigo() << endl;
    cout << "Nome : " << getNome() << endl;
    cout << "Renda Anual : " << getRendaAnual() << endl;
    cout << "CPF : " << cnpj << endl;
    cout << "Inscr. Mun. : " << insc_municipal << endl;
    cout << "Inscr. Est. : " << insc_estadual << endl;
};

/****************************************************
    CONTADORA
****************************************************/

class Contadora {
    private:
        int qtd_pessoas;
        Pessoa* pessoas[100];

    public:
        Contadora() { qtd_pessoas = 0; }
        void adicionarPF();
        void adicionarPJ();
        void consultarIR(int &cod);
        void mostrar(int &cod);
        void listar();
};

void Contadora::adicionarPF(){
    PessoaFisica *p = new PessoaFisica();
    p->adicionar();
    pessoas[qtd_pessoas] = p;
    qtd_pessoas += 1;
}

void Contadora::adicionarPJ(){
    PessoaJuridica *p = new PessoaJuridica();
    p->adicionar();
    pessoas[qtd_pessoas] = p;
    qtd_pessoas += 1;
}

void Contadora::consultarIR(int &cod){
    for(int i=0;i<qtd_pessoas;i++){
        if(pessoas[i]->getCodigo() == cod){
            cout << "R$ " << fixed << setprecision(2) << pessoas[i]->getIR() << endl;
        }
    }
}

void Contadora::mostrar(int &cod){
    for(int i=0;i<qtd_pessoas;i++){
        if(pessoas[i]->getCodigo() == cod){
            pessoas[i]->mostrar();
        }
    }
}

void Contadora::listar(){
    cout 
        << setw(7)  << left   << "Codigo"
        << setw(31) << left   << "Nome"
        << setw(3)            <<  "F/J"
        << setw(21) << right << "CPF/CNPJ"
        << setw(3)  << left << ""
        << setw(10) << right << "IR"
        << endl;


    for(int i=0;i<qtd_pessoas;i++){
        cout 
            << setw(7)  << left   << 
            << setw(31) << left   << "Nome"
            << setw(3)            <<  "F/J"
            << setw(21) << right << "CPF/CNPJ"
            << setw(3)  << left << ""
            << setw(10) << right << "IR"
            << endl;
    }
}

/****************************************************
    MAIN
****************************************************/

int main() {
    Contadora contadora;
    bool finalizar = false;
    int codigo_de_pesquisa;

    mostrarOpcoesCMD();
    
    while (!finalizar){
        switch (execCMD()){
            case ADICIONAR_PF:
                contadora.adicionarPF();
                cout << "Entre com a sua escolha:" << endl;
                mostrarOpcoesCMD();
          	    break;


            case ADICIONAR_PJ:
                contadora.adicionarPJ();
                cout << "Entre com a sua escolha:" << endl;
                mostrarOpcoesCMD();
                break;


            case REMOVER:
                finalizar = true;
                break;


            case MOSTRAR:
                cin >> codigo_de_pesquisa;
                cout << "Entre com a sua escolha:" << endl;
                contadora.mostrar(codigo_de_pesquisa);
                mostrarOpcoesCMD();
                break;


            case CONSULTAR_IR:
                cin >> codigo_de_pesquisa;
                cout << "Entre com a sua escolha:" << endl;
                contadora.consultarIR(codigo_de_pesquisa);
                mostrarOpcoesCMD();
                break;


            case LISTAR:
                cout << "Entre com a sua escolha:" << endl;
                contadora.listar();
                mostrarOpcoesCMD();
                break;


            case SAIR:
                finalizar = true;
                cout << "Entre com a sua escolha:" << endl;
                cout << "Programa encerrado!" << endl;
                break;


            default:
                finalizar = true;
                cout << "COMANDO NÃO ENCONTRADO" << endl;
    			break;
        }
    }
    return 0; 
};

// cout << codigo << endl;
// cout << nome << endl;
// cout << rendaanual << endl;
// cout << cpf << endl;
// cout << profissao << endl;
// cout << dependentes << endl;


    // cout << codigo << endl;
    // cout << nome << endl;
    // cout << rendaanual << endl;
    // cout << cnpj << endl;
    // cout << insc_municipal << endl;
    // cout << insc_estadual << endl;