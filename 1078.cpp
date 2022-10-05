#include <iostream>
#include <stdlib.h>
#include <string> 
using namespace std;

string renderCurrentResult (int i, int number) {
    return to_string(i) + " x " + to_string(number) + " = " + to_string(i*number) + '\n';
}

int main() {
    int number;
    cin >> number;
    for(int i=1; i<=10;i++){
        cout << renderCurrentResult(i, number);
    }
    return 0;
}