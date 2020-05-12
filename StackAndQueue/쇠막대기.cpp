/* 2015112119 ÀÌÇöÀç */

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <deque>

using namespace std;

int solution(string arrangement) {
	int answer = 0;

	vector<char> vec;
	
	bool stick = false;
	int tempLazerNum = 0;
	int lazerNum = 0;

	deque<char> deq;

	for (auto ele : arrangement) deq.push_back(ele);

	while (!deq.empty()) {
		char temp = deq.front();
		deq.pop_front();

		if (temp == '(' && deq.front() == ')') {
			answer += vec.size();
			deq.pop_front();
		}
		else if (temp == '(') {
			vec.push_back('(');
		}
		else {
			vec.pop_back();
			answer++;
		}

	}

	return answer;
}

int main() {
	cout << solution("()(((()())(())()))(())") << endl;
	cout << solution("((())()(()))");
	//cout << solution("((( (()) () () ))) (()())  (((()()(()))))");
}