#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

typedef long long ll;
using namespace std;

int main(){
  int l, n;
  cin >> l >> n;
  bool t = 0;
  vector<ll> arr(n + 1);

  for(int i = 2; i <= n; i++){
    arr[i] = i;
  }

  for(int i = 2; i * i <= n; i++){
    if(arr[i]){
      for(int j = i * i; j <= n; j += i){
        arr[j] = 0;
      }
    }
  }

  for(int i = l + 2, j = l; i <= n, j <= n - 2; j++, i++){
    if(arr[i] && arr[j]){
      if(i - j == 2){
        t = 1;
        cout << j << " " << i;
        cout << "\n";
      }
    }
  }

  if(!t){
    cout << "empty";
  }
  return 0;
}
