#include <iostream>
#include <string>
#include <iomanip> 
#include <locale>
using namespace std;

/****************************************************
    CMD
****************************************************/

enum cmd { ADICIONAR, REMOVER, ALTERAR, MOSTRAR, CONSULTAR, SAIR };

cmd execCMD(){
    int strCmd;
    cin >> strCmd;
    cin.ignore();
    switch (strCmd){
        case 1:
          	return ADICIONAR;
        case 2:
            return REMOVER;
        case 3:
            return ALTERAR;
        case 4:
            return MOSTRAR;
        case 5:
            return CONSULTAR;
        case 6:
            return SAIR;
        default:
            cout << "COMANDO NÃO ENCONTRADO: " << strCmd << endl;
			return SAIR;
    }
};

void esperarOK(){
    string ok;
    cin >> ok;
    if(ok == "ok"){
        cin.ignore();
    }else {
        esperarOK();
    }
}

void mostrarOpcoesCMD(){
    cout << "1. inserir cliente" << endl;
    cout << "2. remover cliente pelo cpf" << endl;
    cout << "3. alterar dados do cliente pelo cpf" << endl;
    cout << "4. listar todos os clientes" << endl;
    cout << "5. listar os clientes, dado parte do nome ou cpf" << endl;
    cout << "6. sair" << endl;
}

/****************************************************
    PESSOA
****************************************************/

class Pessoa {
    private:
        string  nome, cpf;
        double  valorAnual, IR;
        int     dependentes;

    public:
        string  getNome();
        string  getCPF();
        int     getDependentes();
        double  getIR();
        double  getValorAnual();
        void    setNome(string &nome);
        void    setCPF(string &cpf);
        void    setValorAnual(double &valorAnual);
        void    setIR(double &IR);
        void    setDependentes(int &dependentes);
        void    adicionar();

};

void Pessoa::adicionar(){
    getline(cin, nome);
    getline(cin, cpf);
    cin >> valorAnual;
    cin >> dependentes;
    cin.ignore();
    cout << "Pessoa inserida com sucesso!" << endl;
};

string Pessoa::getNome(){
    return nome;
};

string Pessoa::getCPF(){
    return cpf;
};

double Pessoa::getValorAnual(){
    return valorAnual;
};

double Pessoa::getIR(){
    return IR;
};

int Pessoa::getDependentes(){
    return dependentes;
};

void Pessoa::setNome(string &nome){
    this->nome = nome;
};

void Pessoa::setCPF(string &cpf){
    this->cpf = nome;
};

void Pessoa::setValorAnual(double &valorAnual){
    this->valorAnual = valorAnual;
};

void Pessoa::setIR(double &IR){
    this->IR = IR;
};

void Pessoa::setDependentes(int &dependentes){
    this->dependentes = dependentes;
};

/****************************************************
    CONTABILIDADE
****************************************************/

class Contabilidade {
    private:
        int qtd_pessoas;
        Pessoa *pessoas[100];

    public:
        Contabilidade() { qtd_pessoas = 0; }
        ~Contabilidade() {
            for(int i=0;i<qtd_pessoas;i++){
                delete pessoas[i];
            }
        }
        void adicionar();
        void mostrar();
        void consultar(string &texto);
        void remover(string &texto);
        void alterar(string &texto);
};

void Contabilidade::adicionar(){
    Pessoa *p = new Pessoa();
    p->adicionar();
    pessoas[qtd_pessoas] = p;
    qtd_pessoas += 1;
}

void Contabilidade::mostrar(){
    double resumo = 0;
    
    cout 
        << setw(200) << left << "Nome"
        << setw(16)  << left  << "!CPF"
        << setw(3)   << left  << "!"
        << setw(3)   << left  << "Vl"
        << setw(5)   << left  << "Anual"
        << setw(2)   << left  << ""
        << setw(4)   << right << "!Dep"
        << setw(3)   << left << "!"
        << setw(2)   << left << ""
        << setw(8)   << left  << "IRPF"
        << setw(1)   << left  << "!"
        << endl;


    for(int i=0;i<qtd_pessoas;i++){
        cout 
            << setw(200) << left  << pessoas[i]->getNome()
            << setw(16)  << left  << "!" + pessoas[i]->getCPF()
            << setw(3)   << left  << "!R$"
            << setw(10)  << right  << fixed << setprecision(2) << pessoas[i]->getValorAnual();

        cout
            << setw(1)   << left  << "!"
            << setw(3)   << right << pessoas[i]->getDependentes()
            << setw(3)   << left <<  "!R$"
            << setw(10)  << right  << pessoas[i]->getIR()
            << setw(1)   << "!" 
            << endl;

        resumo += pessoas[i]->getValorAnual();
    }

    cout 
        << setw(11)  << left << "Quantidade "
        << setw(1)   << qtd_pessoas
        << setw(222) << ""
        << setw(2)   << "R$"
        << setw(10)  << right << resumo
        << setw(1)   << right  << "!"
        << endl;

}

void Contabilidade::consultar(string &texto){
    string cpf, nome;
    size_t indexCPF, indexNome;
    int qtd_pessoas_encontradas = 0;
    double resumo = 0;
    cout 
        << setw(200) << left << "Nome"
        << setw(16)  << left  << "!CPF"
        << setw(3)   << left  << "!"
        << setw(3)   << left  << "Vl"
        << setw(5)   << left  << "Anual"
        << setw(2)   << left  << ""
        << setw(4)   << right << "!Dep"
        << setw(3)   << left << "!"
        << setw(2)   << left << ""
        << setw(8)   << left  << "IRPF"
        << setw(1)   << left  << "!"
        << endl;

    for(int i=0;i<qtd_pessoas;i++){
        cpf = pessoas[i]->getCPF();
        nome = pessoas[i]->getNome();
        indexCPF = cpf.find(texto,0);
        indexNome = nome.find(texto,0);
        if(indexCPF != string::npos || indexNome != string::npos){
            cout 
                << setw(200) << left  << pessoas[i]->getNome()
                << setw(16)  << left  << "!" + pessoas[i]->getCPF()
                << setw(3)   << left  << "!R$"
                << setw(10)  << right  << fixed << setprecision(2) << pessoas[i]->getValorAnual();

            cout
                << setw(1)   << left  << "!"
                << setw(3)   << right << pessoas[i]->getDependentes()
                << setw(3)   << left <<  "!R$"
                << setw(10)  << right  << pessoas[i]->getIR()
                << setw(1)   << "!" 
                << endl;

            resumo += pessoas[i]->getValorAnual();
            qtd_pessoas_encontradas += 1;
        }
    }

    cout 
        << setw(11)  << left << "Quantidade "
        << setw(1)   << qtd_pessoas_encontradas
        << setw(222) << ""
        << setw(2)   << "R$"
        << setw(10)  << right << resumo
        << setw(1)   << right  << "!"
        << endl;
}

void Contabilidade::remover(string &texto){
    string cpf;
    size_t indexCPF;
    int qtd_pessoas_encontradas = 0, referencia = 0;
    for(int i=0;i<qtd_pessoas;i++){
        cpf = pessoas[i]->getCPF();
        indexCPF = cpf.find(texto,0);
        if(indexCPF != string::npos){
            qtd_pessoas -= 1;
            referencia += 1;
        }
        pessoas[i] = pessoas[referencia];
        referencia += 1;
    }
    if(referencia == 0){
        cout << "CPF nao encontrado" << endl;
    }
}

void Contabilidade::alterar(string &texto){
    string cpf, nome;
    double valorAnual;
    int dependentes, ref = 0;
    size_t indexCPF;
    for(int i=0;i<qtd_pessoas;i++){
        cpf = pessoas[i]->getCPF();
        indexCPF = cpf.find(texto,0);
        if(indexCPF != string::npos){
            ref = 1;
            getline(cin, nome);
            getline(cin, cpf);
            cin >> valorAnual;
            cin >> dependentes;
            cin.ignore();
            pessoas[i]->setNome(nome);
            pessoas[i]->setCPF(cpf);
            pessoas[i]->setValorAnual(valorAnual);
            pessoas[i]->setDependentes(dependentes);
            cout << "Pessoa alterada com sucesso!" << endl;
        }
    }
    if(ref == 0){
         cout << "CPF nao encontrado" << endl;
    }
}



/****************************************************
    MAIN
****************************************************/

int main() {
    Contabilidade contabilidade;
    bool finalizar = false;
    string texto_de_pesquisa;

    mostrarOpcoesCMD();
    
    while (!finalizar){
        switch (execCMD()){
            case ADICIONAR:
                cout << "Entre com a sua opcao:" << endl;
                contabilidade.adicionar();
                esperarOK();
                mostrarOpcoesCMD();
          	    break;


            case REMOVER:
                cout << "Entre com a sua opcao:" << endl;
                cin >> texto_de_pesquisa;
                cin.ignore();
                contabilidade.remover(texto_de_pesquisa);
                esperarOK();
                mostrarOpcoesCMD();
                break;

            case ALTERAR:
                cout << "Entre com a sua opcao:" << endl;
                cout << "Entre com o CPF para alterar:" << endl;
                cin >> texto_de_pesquisa;
                cin.ignore();
                contabilidade.alterar(texto_de_pesquisa);
                esperarOK();
                mostrarOpcoesCMD();
                break;


            case MOSTRAR:
                cout << "Entre com a sua opcao:" << endl;
                contabilidade.mostrar();
                esperarOK();
                mostrarOpcoesCMD();
                break;


            case CONSULTAR:
                cout << "Entre com a sua opcao:" << endl;
                cout << "entre com parte do nome ou cpf para listar:" << endl;
                cin >> texto_de_pesquisa;
                cin.ignore();
                contabilidade.consultar(texto_de_pesquisa);
                esperarOK();
                mostrarOpcoesCMD();
                break;


            case SAIR:
                finalizar = true;
                cout << "Entre com a sua opcao:" << endl;
                cout << "Obrigado por utilizar o programa e volte sempre." << endl;
                break;

            default:
    			break;
        }
    }
    return 0; 
};