#include <iostream>
#include <string> 
using namespace std;

string validadePassword (int &upper, int &lower, int &number, int &invalid, int& len){
    string msg = "Senha valida.";
    if(upper < 1 || lower < 1 || invalid > 0 || len < 6 || len > 32 || number < 1){
        msg = "Senha invalida.";
    }
    return msg;
}

string getPassword (string &password) {
    int upper = 0, lower = 0, invalid = 0, number = 0, len = password.length(); 
    for(int i=0; i<len; i++){
        if(!!isupper(password[i])){
            upper += 1;
        }
        if(!!islower(password[i])){
            lower += 1;
        }
        if(!!isdigit(password[i])){
            number += 1;
        }
        if(!isalpha(password[i]) && !isdigit(password[i])){
            invalid += 1;
        }
        
    }
    return validadePassword(upper, lower, number, invalid, len);
}

int main() {
    bool tests = true;
    while(tests){
        string password;
        getline(cin, password);
        if(password.length() < 1){
            tests = false;
        }else {
            cout << getPassword(password) << endl;
        }
    }
}