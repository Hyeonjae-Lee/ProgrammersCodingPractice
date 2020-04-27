/* 2015112119 ÀÌÇöÀç */

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <sstream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
	vector<int> answer;
	vector<string> vec;

	int check = 1;
	int	turn = 1;
	char lastWord = 'a';
	
	for (int i = 0; i < words.size(); i++) {
		if (check > n) {
			check = 1;
			turn++;
		}
		if (i == 0) {
			lastWord = words[i].back();
			check++;
			vec.push_back(words[i]);
			continue;
		}

		if (lastWord != words[i].front() || find(vec.begin(), vec.end(), words[i]) != vec.end() ) {
			answer.push_back(check);
			answer.push_back(turn);
			break;
		} 

		vec.push_back(words[i]);
		lastWord = words[i].back();
		check++;
	}

	if (answer.empty()) {
		answer.push_back(0);
		answer.push_back(0);
	}

	return answer;
}

int main() {
	int n = 2;
	//vector<string> words = { "tank", "kick", "know", "wheel", "land", "dream", "mother", "bot", "tank" };
	vector<string> words = { "qwe", "eqwe", "eqwe" };
	vector<int> word = solution( n, words);

	for (auto ele : word) {
		cout << ele << " ";
	}
}