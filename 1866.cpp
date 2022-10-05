#include <iostream>
#include <string> 
using namespace std;

string validate (string &password) {
    return password;
}

int main() {
    for(int i=0; i<tests;i++){
        string password;
        if(password.length() < 1){
            break;
        }
        getline(cin, password);
        cout << validate(password) << endl;
    }
    return 0;
}