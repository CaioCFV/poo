#include <iostream>
#include <math.h>
#include <iomanip> 
using namespace std;

struct point {
    double x,y;
};

double calcDistance (point &p1, point &p2) {
    return sqrt(pow((p2.x - p1.x),2) + pow((p2.y - p1.y),2));
}

void readPoint (point &p){
    cin >> p.x >> p.y;
}

int main() {
    point initial,final;
    double distance;
    readPoint(initial);
    readPoint(final);
    distance = calcDistance(initial, final);
    cout << fixed << setprecision(4);
    cout << distance << endl;
    return 0;
}