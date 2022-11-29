#include <iostream>
using namespace std;

class TMatriz {
    private:
        int qtd_line = 0, qtd_column = 0;
        string m[100][100], mt[100][100];
        
    public:
        void ler();
        void transposta();
        void mostrar();
};

void TMatriz::ler(){
    string text;
    cin >> qtd_line >> qtd_column;
    for(int line=0;line<qtd_line;line++){
        cin >> text;
        for(int column=0;column<qtd_column;column++){
            m[line][column] = text[column]; 
        }
    }
}

void TMatriz::transposta(){
    string save;
    for(int line=0;line<qtd_line;line++){
        for(int column=0;column<qtd_column;column++){
           mt[column][line] = m[line][column];
        }
    }
    
    int line = qtd_line;
    qtd_line = qtd_column;
    qtd_column = line;
}

void TMatriz::mostrar(){
    for(int line=0;line<qtd_line;line++){
        for(int column=0;column<qtd_column;column++){
            cout << mt[line][column]; 
        } 
        cout << endl;
    }
}

int main() {
    TMatriz a;
	a.ler();
	a.transposta();
    a.mostrar();
    return 0;
}