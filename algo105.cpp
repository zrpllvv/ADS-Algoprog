#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <fstream>
#include <sstream>

using namespace std;

#pragma GCC optimize("unroll-loops")
#define Kazakhstan ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define end return 0;
#define pb push_back

int main(){
	Kazakhstan
	int n;
	cin >> n;
	int a[n][n];
	char dp[n][n];
	int sum[n][n];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
			sum[0][0] = a[0][0];
			if(i == 0 && j != 0){
				sum[i][j] += a[i][j] + sum[i][j - 1];
			} else if(i != 0 && j == 0){
				sum[i][j] += a[i][j] + sum[i - 1][j];
			}
			dp[i][j] = '-';
			dp[0][0] = '#';
			dp[n - 1][n - 1] = '#';
		}
	}

	for(int i = 1; i < n; i++){
		for(int j = 1; j < n; j++){
			sum[i][j] += min(sum[i - 1][j], sum[i][j - 1]);
		}
	}
	int i = n - 1, j = n - 1;
	while(i >= 0 && j >= 0){
		if(sum[i - 1][j] > sum[i][j - 1]){
			if(j - 1 >= 0){
				dp[i][j - 1] = '#';
			    j -= 1;
			} else if(i - 1 >= 0){
				dp[i - 1][j] = '#';
				i -= 1;
			}
		} else if(sum[i][j - 1] > sum[i - 1][j]){
			if(i - 1 >= 0){
				dp[i][j - 1] = '#';
				i -= 1;
			} else if(j - 1 >= 0){
				dp[i][j - 1] = '#';
				j -= 1;
			}
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << dp[i][j];
			cout << " ";
		}
		cout << "\n";
	}

	return 0;
}
