/* 2015112119 ÀÌÇöÀç */

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <sstream>
#include <bitset>

using namespace std;
int solution(string dartResult) {
	int answer = 0;

	queue<char> qu;

	for (auto ele : dartResult) qu.push(ele);
	
	vector<int> vec;
	int ans = 0;

	while (!qu.empty()) {
		
		char temp = qu.front();
		qu.pop();

		if (temp == '1' && qu.front() == '0') {
			vec.push_back(10);
			qu.pop();
		}
		else if (temp >= '0' && temp <= '9') {
			ans = temp - '0';
			vec.push_back(ans);
		}
		else if (temp == 'S') {
		}
		else if (temp == 'D') {
			ans = vec.back();
			vec.pop_back();
			vec.push_back(ans * ans);
		}
		else if (temp == 'T') {
			ans = vec.back();
			vec.pop_back();
			vec.push_back(ans * ans * ans);
		}
		else if (temp == '*') {
			if (vec.size() >= 2) {
				int tempb = vec.back();
				vec.pop_back();
				tempb *= 2;
				int tempc = vec.back();
				vec.pop_back();
				tempc *= 2;

				vec.push_back(tempc);
				vec.push_back(tempb);
			}
			else if (vec.size() >= 1) {
				int tempb = vec.back();
				vec.pop_back();
				tempb *= 2;

				vec.push_back(tempb);
			}
		}
		else if (temp == '#'){
			if (vec.size() >= 1) {
				int tempb = vec.back();
				vec.pop_back();
				tempb *= -1;
				vec.push_back(tempb);
			}
		}

	}

	for (auto ele : vec) answer += ele;

	return answer;
}

int main() {

	cout << solution("1D#2S*3S");
}