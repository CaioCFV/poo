#include <iostream>
#include <stdlib.h>
#include <string> 
using namespace std;

string isPrime (int &number) {
    bool isPrime = true;
    for(int i=2; i<=5;i++){
        int mod, test = 0;
        mod = number / i;
        if(mod != 1 || mod == number && test > 1){
            isPrime = false;
            break;
        }else { 
            test += 1;
        }
        
    }
    return isPrime ? to_string(number) + " eh primo" : to_string(number) + " nao eh primo";
}

int main() {
    int tests;
    cin >> tests;
    for(int i=0; i<tests;i++){
        int number;
        cin >> number;
        cout << isPrime(number) << endl;
    }
    return 0;
}