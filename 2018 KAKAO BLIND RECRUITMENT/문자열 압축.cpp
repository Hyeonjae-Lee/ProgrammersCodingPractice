#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

int solution(string s) {
	int answer = 0;
	string finalAnswer = "";
	int n = s.size() / 2;

	if (s.size() == 1) return 1;

	for (int i = 1; i <= s.size() / 2; i++) {
		
		string tempAnswer = "";
		int tempCheck = 1;
		vector<string> vec;

		for (int j = 0; j < s.size(); j+=i) {

			string temp = s.substr(j, i);

			if (temp.size() < i) {

				if (tempCheck == 1) {
					tempAnswer += vec.back();
					vec.pop_back();
				}
				else {
					tempAnswer += to_string(tempCheck) + vec.back();
					vec.pop_back();
				}

				tempAnswer += temp;
				break;
			}

			if (vec.empty()) {
				vec.push_back(temp);
				if (j == s.size() - i && !vec.empty()) {
					if (tempCheck == 1) {
						tempAnswer += vec.back();
						vec.pop_back();
						vec.push_back(temp);
					}
					else {
						tempAnswer += to_string(tempCheck) + vec.back();
						vec.pop_back();
						vec.push_back(temp);
						tempCheck = 1;
					}
				}
			}
			else if ( temp == vec.back() ) { //스택에 있을경우
				tempCheck++;
				if (j == s.size()-i && !vec.empty() ) {
					if (tempCheck == 1) {
						tempAnswer += vec.back();
						vec.pop_back();
					}
					else {
						tempAnswer += to_string(tempCheck) + vec.back();
						vec.pop_back();
					}
				}
			}
			else {
				//스택에 없다.
				if (tempCheck == 1) {
					tempAnswer += vec.back();
					vec.pop_back();
					vec.push_back(temp);
				}
				else {
					tempAnswer += to_string(tempCheck) + vec.back();
					vec.pop_back();
					vec.push_back(temp);
					tempCheck = 1;
				}
			}

		}
		if(!vec.empty()) tempAnswer += vec.back();

		if (finalAnswer == "") finalAnswer = tempAnswer;
		else if (finalAnswer.size() > tempAnswer.size()) {
			finalAnswer = tempAnswer;
		}

		answer = finalAnswer.size();
	}	
	return answer;
}

int main() {
	cout << solution("ababcdcdababcdcd");
}