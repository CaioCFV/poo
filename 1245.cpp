#include <iostream>
#include <stdlib.h>
#include <iomanip> 
using namespace std;

class AAluno {
    private:
        double nota1, nota2;
        string nome;
        
    public:
        void ler();
        void showResult();
};

class TTurma {
    private:
        int qtd_aluno;
        AAluno a[100];
        
    public:
        void ler();
        void listar();
};

void AAluno::ler(){
    getline(cin, nome);
    cin >> nota1 >> nota2;
    cin.ignore();
}

void AAluno::showResult(){
    double result;
    string situation = "Reprovado";
    string nomeFormatado = "                                            ";
    result = (nota1 + (nota2 * 2))/3;
    if(result >= 6){
        situation = "Aprovado";
    }
    for(int i = 0; i < nome.length(); i++){
        nomeFormatado[i] = nome[i];
    }
    cout << nomeFormatado << " " << fixed << setprecision(2) << result << " " << situation << " " << endl;
}

void TTurma::ler(){
    cin >> qtd_aluno;
    cin.ignore();
    for (int i = 0; i < qtd_aluno; i++){
        AAluno aluno;
        aluno.ler();
        a[i] = aluno;
    }
}

void TTurma::listar(){
    for (int i = 0; i < qtd_aluno; i++){
      a[i].showResult();
    }
}

int main() {
    TTurma t;
	t.ler();
    t.listar();
    return 0;
}