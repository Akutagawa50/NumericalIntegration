#include <iostream>
#include <cmath>
using namespace std;
const int funcnum = 0;

double func(double x, int fn=0){ //数値積分する関数, fnの値を変えると関数が変わる
    switch (fn)
    {
    case 0:
        return pow(x, 4) - 2.0*pow(x, 3) +pow(x, 2) - 3.0*x + 1.0;
    case 1:
        return 1.0/x;
    default:
        return 999.999;//error
    }
}

//台形公式で数値積分する関数
//x1, x2: 積分範囲 (x1 <= x2)
//  n   : 積分範囲を等分する数
// fn   : 関数の番号 funcnumを入れる
double TrapezoidalRule(double x1, double x2, int n, int fn = funcnum){
    double sum=0.0;         //積分した値
    double dx = (x2-x1)/(double)n;    //dxを計算

    sum = (func(x1, fn)) / 2.0;
    for(double i=x1+dx; i<x2; i+=dx){
            sum += (func(i, fn));
    }
    sum += (func(x2, fn)) / 2.0;

    return dx * sum; 
}

//シンプソン公式で数値積分する関数
//x1, x2: 積分範囲 (x1 <= x2)
// n2   : 積分範囲を等分する数
// fn   : 関数の番号 funcnumを入れる
double SimpsonsRule(double x1, double x2, int n2, int fn = funcnum){
    double sum=0.0;         //積分した値
    double dx = 2.0*(x2-x1)/(double)n2;    //dxを計算
    int counter = 0;

    sum=func(x1, fn);
    for(double i=x1+dx; i<x2; i+=dx, counter++){
        sum += 2.0 * (double)(counter % 2 + 1)*func(i, fn);
    }
    sum += (func(x2, fn));

    return sum * dx/3.0;
}

int main(){
    int n=10000;
    cout << "function number: " << funcnum << endl;
    cout << "when n=" << n << endl;
    switch(funcnum){
        case 0:
            cout << " trapezoidal rule: " << TrapezoidalRule(0.0, 3.0, n) << endl;
            cout << " Simpson's rule: " << SimpsonsRule(0.0, 3.0, n) << endl;
            break;
        case 1:
            cout << " trapezoidal rule: " << TrapezoidalRule(1.0, 2.0, n) << endl;
            cout << " Simpson's rule: " << SimpsonsRule(1.0, 2.0, n) << endl;
            break;
        
        default:
            break;
    }
}