#include <iostream>
#include <string> 
using namespace std;

const string letters = "abcdefghijklmnopqrstuvxzyw";

string getResult (int &n){
    if(n == 26){
        return "frase completa";
    }
    if(n > 13){
        return "frase quase completa";
    }

    return "frase mal elaborada";
}

string verifySentence (string &sentence) {
    int sentenceComplete = 0;
    
    if(sentence.length() < 13){
        sentenceComplete = sentence.length();
        return getResult(sentenceComplete);
    }

    for(int i=0; i<letters.length();i++){
        for(int j=0; j<sentence.length();j++){
            if(letters[i] == sentence[j]){
                sentenceComplete += 1;
                break;
            }
        }
    }

    return getResult(sentenceComplete);
}

int main() {
    int tests;
    cin >> tests;
    cin.ignore();
    for(int i=0; i<tests;i++){
        string sentence;
        getline(cin, sentence);
        cout << verifySentence(sentence) << endl;
    }
    return 0;
}