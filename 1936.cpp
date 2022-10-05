#include <iostream>
#include <stdlib.h>
#include <string> 
using namespace std;

struct factorTest {
    int chances = 0, total = 0, multiplicator, currentResult = 0;
};

int getFactorial (factorTest &number) {
    int result = number.multiplicator;
    for(int i=number.multiplicator; i>=2; i--){
        result = result * i;
    }

    if(result > number.total){
        number.multiplicator -= 1;
        return getFactorial(number);
    }
    
    if((number.currentResult + result) > number.total) {
        number.multiplicator -= 1;
        return getFactorial(number);
    }
    

    number.currentResult += result;
    number.chances += 1; 
    
    //cout << "--------------------------" << endl;
   
    //cout << "CHANCES: " << number.chances << endl;
    //cout << "TOTAL: " << number.total << endl;
    //cout << "multiplicator: " << number.multiplicator << endl;
    //cout << "currentResult: " << number.currentResult << endl;
    //cout << "--------------------------" << endl;
    
    if(number.chances > 4){
        return 0;
    }
    
    if(number.total != number.currentResult){
        return getFactorial(number);
    }
    
    cout << "--------------------------" << endl;
    cout << "currentResult: " << number.currentResult << endl;
    cout << "--------------------------" << endl;
    
    return number.chances;
}

int main() {
    factorTest number;
    cin >> number.total;
    number.multiplicator = number.total;
    cout << getFactorial(number) << endl;
    return 0;
}