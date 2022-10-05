#include <iostream>
using namespace std;

int main() {
    int tests;
    cin >> tests;
    int current = 1, last = 0, number;
    for(int i=0; i<tests;i++){
        if (i < 2) {
            number = i;
        } else {
            number = current + last;
            last = current;
            current = number;
        }
        if (i<tests - 1){
            cout << number << " ";
        } else {
            cout << number;
        }
    }
    return 0;
}