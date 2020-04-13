#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool desc(char a, char b) {
	return a > b;
}

string solution(string s) {
	string answer = "";
	vector<char> answer1;
	vector<char> answer2;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 'A' && s[i] < 'a') {
			answer1.push_back(s[i]);
		}
		else {
			answer2.push_back(s[i]);
		}
	}

	sort(answer1.begin(), answer1.end(), desc);
	sort(answer2.begin(), answer2.end(), desc);

	for (auto ele : answer2) {
		answer += ele;
	}for (auto ele : answer1) {
		answer += ele;
	}

	return answer;
}