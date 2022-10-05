#include <iostream>
using namespace std;

int soma (int &n1, int &n2){
    return n1 + n2;
}

int main() {
    int number1, number2, result;
    cin >> number1;
    cin >> number2;
    result = soma(number1, number2);
    cout << "X = " << result << endl;
    return 0;
}