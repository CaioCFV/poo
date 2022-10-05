#include <iostream>
#include <stdlib.h>
//#include <math.h>
//#include <iomanip> 
using namespace std;

struct diamond {
    string text;
};

struct testCase {
    double diamondOpen = 0, diamondClose = 0, diamondsFound = 0;
};

void readDiamond (diamond &d){
    cin >> d.text;    
}

int main() {
    int numberTests;
    cin >> numberTests;
    for(int i=0; i<numberTests;i++){
        diamond d;
        testCase currentCase;
        readDiamond(d);
        for(int j=0; j<d.text.length();j++){
            string current;
            current = d.text.at(j);
            if(current == "<"){
                currentCase.diamondOpen += 1;
            }
            if(current == ">" && currentCase.diamondOpen > 0){
                currentCase.diamondOpen -= 1;
                currentCase.diamondsFound += 1;
            }
        }
        cout << currentCase.diamondsFound << endl;
    }
    return 0;
}