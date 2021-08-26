#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

int main(){
  ifstream in("input.txt");
  ofstream out("output.txt");

  string s;
  string news = "";
  string word = "";
  while(getline(in, s)){
      getline(in, s);
      for(int i = 0; i < s.length(); i++){
      if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')){
      word += s[i];
      }else{
      reverse(word.begin(), word.end());
      for(auto n: word){
        news.push_back(n);
      }
      word = "";
      news.push_back(s[i]);
    }
  }
    for(auto now: news){
      cout << now;
    }
    cout << "\n";
  }
  return 0;
}
