//@author: zrpllvv
#include <iostream>
#include <cmath>
#include <vector>
#include <set>

using namespace std;

#pragma GCC optimize("unroll-loops")

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int n;
  cin >> n;
  char a[n][n];
  int dp[n][n];
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> a[i][j];
      dp[i][j] = 0;
    }
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(a[i][j] == '#'){
        int rowB = i, columnB = j;
        bool good = true;
        int newR = i, newC = j;
        for(int t = i; t < n; t++){
          if(a[t][j] == '#' && good) rowB = t;
          else good = false;
        }

        good = true;
        for(int t = j; t < n; t++){
          if(a[i][t] == '#' && good)columnB = t;
          else good = false;
        }

        good = true;
        for(int t = i; t <= rowB; t++){
          for(int p = j; p <= columnB; p++){
            if(a[t][p] == '#' && good){
              newR = t;
              newC = p;
            } else good = false;
          }
        }

        dp[i][j] = min(newR - i + 1, newC - j + 1);
      }
    }
  }

  int sum = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      sum = max(sum, dp[i][j]);
    }
  }
  cout << sum;
  return 0;
}
