#include <bits/stdc++.h>
#include <fstream>
#include <string>

using namespace std;


bool good_word(string word){
  char point[] = {'.', '!', '?', ':', '-', ',', ';', '(', ')'};
  set<char> set_word;

  int size_word = word.size();
  int size_point = 9;

  for(int i = 0; i < size_word; i++){
    int count = 0;
    for(int j = 0; j < size_point; j++){
      if(word[i] == point[j])count++;
    }
    if(count == 0){
      set_word.insert(word[i]);
    } else {
      count = 0;
    }
  }
  return(set_word.size() > 3);
}

bool good_line(string s1){
  int size = s1.length();
  int good = 0; int bad = 0;
  string line = "";
  for(int i = 0; i < size; i++){
    while(s1[i] != ' '){
      line += s1[i];
      i++;
    }
    if(good_word(line) && line.size() > 0)good++;
    else if(line.size() > 0)bad++;
    line = "";
  }

  return(good > bad);
}

int main(){
  ifstream in("input.txt");
  ofstream out("output.txt");
  string s;
  while(getline(in, s)){
    getline(in, s);
    if(good_line(s)) out << s << "\n";
  }
  return 0;
}
