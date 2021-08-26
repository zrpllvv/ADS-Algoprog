#include <bits/stdc++.h>
using namespace std;

int binary(int x, vector<int> array){
  int l = 0; int r = array.size();
  while(r >= l){
    int m = (r + l) / 2;
    if(array[m] == x) return m;
    if(array[m] > x) r = m - 1;
    if(array[m] < x) l = m + 1;
  }
  return -1;
}

int main(){
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for(int i = 0; i <= n; i++){
    a[0] = i;
  }

  for(int i = 2; i * i <= n; i++){
    if(a[i]){
      for(int j = i * i; j <= n; j += i){
        a[j] = 0;
      }
    }
  }

  vector<int> prime;

  for(int i = 0; i <= n; i++){
    if(a[i]){
      prime.push_back(a[i]);
    }
  }

  int prime_size = prime.size();
  for(int i = 0; i < prime_size; i++){
    int try = n - prime[i];
    int seacrhing = binary(try, prime);
    if(searching != -1){
      cout << prime[i] << " " << searching;
      break;
    }
  }
  return 0;
}
