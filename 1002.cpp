#include <iostream>
#include <cmath> 
using namespace std;

const float pi = 3.14159;

float calcArea (float &radius){
    return pi * (radius**2);
}

int main() {
    float radius, result;
    cin >> radius;
    result = calcArea(radius);
    cout << result
    return 0;
}