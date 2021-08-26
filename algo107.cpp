#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int isPrime(int d){
    vector<int> arr;
    vector<int> arr1;

    for(int i = 2; i * i <= d; i++){
        if(d % i == 0){
            arr.push_back(i);
            if(i * i != d){
                arr1.push_back(d / i);
            }
        }
    }

    int t = 0;
    for(int i = 0; i < arr.size(); i++){
        for(int j = 2; j < arr[i]; j++){
            if(arr[i] % j == 0){
                t++;
            }
        }
        if(t == 0){
            cout << arr[i] << " ";
        }
    }

    int t1 = 0;
    for(int i = arr1.size() - 1; i >= 0; i--){
        for(int j = 2; j < arr1[i]; j++){
            if(arr1[i] % j == 0){
                t1++;
            }
        }
        if(t1 == 0){
            cout << arr1[i] << " ";
        }
    }

}

int main(){
    int n;
    cin >> n;
    isPrime(n);
    return 0;
}
