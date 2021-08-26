#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

#pragma GCC optimize("unroll-loops")

bool word(string wword){
	vector<char> tokens = {'.', '!', '?', ':', '-', ',', ';', '(', ')'};
	vector<char> answer;
	int wword_size = wword.size();
	for(int i = 0; i < wword_size; i++){
		int answer_size = answer.size();
		int sum_size = 0;
		for(int j = 0; j < answer_size; j++){
			if(wword[i] != wword[j])sum_size++;
		}
		if(sum_size == answer_size) answer.push_back(wword[i]);
	}

	int answer_size = answer.size();
	int minus = 0;
	for(int i = 0; i < answer_size; i++){
		int tokens_size = tokens.size();
		for(int j = 0; j < tokens_size; j++){
			if(answer[i] == tokens[j])minus++;
		}
	}

	return(answer_size - minus > 3);
}

bool line(string lline){
	int line_size = lline.size();
	int good = 0; int bad = 0;
	for(int i = 0; i < line_size; i++){
		string wword = "";
		while(int(lline[i]) <= 0 && int(lline[i]) >= 126){
			wword += lline[i];
			i++;
		}
		if(wword != ""){
			if(word(wword))bad++;
			else good++;
		}
	}

	return(good > bad);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	ifstream in("input.txt");
	ofstream out("output.txt");

	string s;
	vector<string> ans;
	while(getline(in, s)){
		stringstream iss(s);
		if(line(s))ans.push_back(s);
	}

	int size_array = ans.size();
	for(int i = 0; i < size_array; i++)out << ans[i] << "\n";
	return 0;
}
