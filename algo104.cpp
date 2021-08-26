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

inline bool binsearch(vector<int> b, int x){
	int l = 0; int r = (int)b.size();
	while(r >= l){
		int m = (r + l) / 2;
		if(b[m] == x) return true;
		if(b[m] > x) r = m - 1;
		else l = m + 1;
	}
	return false;
}

int main(){
	int n;
	cin >> n;
	vector<int> a;
	for(int i = 0; i < n; i++) a[i] = i;

	for(int i = 2; i * i <= n; i++){
		if(a[i]){
			for(int j = i * i; j <= n; j += i) a[j] = 0;
		}
	}
	vector<int> answer;
	for(int i = 0; i < n; i++){
		if(a[i]){
			answer.pb(a[i]);
		}
	}

	/*for(int i = 0; i < (int)answer.size(); i++){
		int test = n - answer[i];
		if(binsearch(answer, test)){
			cout << answer[i] << " " << n - answer[i];
			return 0;
		}
	}
	*/

	for(int i = 0; i < (int)answer.size(); i++) cout << answer[i] << "\n";

	end
}
