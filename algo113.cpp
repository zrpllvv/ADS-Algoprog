#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    int a, b, plus, sum;
    cin >> plus >> sum;
    int z = plus * plus - 4*sum;
    if(z >= 0){
        int sqrz = sqrt(z);
        a = (plus + sqrz)/2;
        b = plus - a;
        if(a > b){
            int temp = a;
            a = b;
            b = temp;
        }
        cout<< a <<" "<< b;
    } else {
        cout << "NO SOLUTION";
    }
    return 0;
}
