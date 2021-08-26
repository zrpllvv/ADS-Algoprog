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

inline bool prime_sum(int first1, int second1){
	 string s1 = to_string(first1);
	 s1 += to_string(second1);

	 int sum = 0;
	 sum = stoi(s1);

	 vector<int> a;
	 for(int i = 2; i <= sqrt(sum); i++){
		 while(sum % i == 0){
			a.pb(i);
			sum /= i;
		}
	}

	if((int)a.size() > 0) return false;
	return true;
}

int main(){
	Kazakhstan
	int n;
	cin >> n;
	int firstt = 1;
	int secondd = 1;

	vector<pair<int>> ans;
	int sum = 1;
	ans[0].first = 1;
	ans[0].second = 1;
	ans[1].first = 2;
	ans[1].second = 1;


	if(n == 1){
		cout << 1;
		return 0;
	}

	vector<int> dp;
	dp[0] = 1;
	dp[1] = 1;

	//in dp array we store guaranteed max prime sums
	int rest  = n * 2 - 1;
	for(int i = 1; i < rest; i++){
		if(prime_sum(ans[i].first, ans[i].second + 1) && ans[i].second + 1 <= n){
			ans[i + 1].first = ans[i].first;
			ans[i + 1].second = ans[i].second + 1;
			dp[i]++;
		} else if()
		else {
			if(prime_sum(ans[i].first + 1, ans[i].second) && ans[i].first + 1 <= n){
				ans[i + 1].first = ans[i].first + 1;
			    ans[i + 1].second = ans[i].second;
			    dp[i]++;
			} else if(ans[i].first + 1 <= n){
				ans[i + 1].first = ans[i].first + 1;
			    ans[i + 1].second = ans[i].second;
			}
		}
	}


}
