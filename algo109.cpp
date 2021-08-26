#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    string s;
    getline(cin, s);
    string news = "";
    string word = "";
    for(int i = 0; i < s.length(); i++){
      if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')){
        word += s[i];
      }else{
        reverse(word.begin(), word.end());
        for(auto n: word)news.push_back(n);
        word = "";
        news.push_back(s[i]);
      }
    }
    reverse(word.begin(), word.end());
    for(auto n: word)news.push_back(n);

    for(auto now: news)cout << now;

    return 0;
}
