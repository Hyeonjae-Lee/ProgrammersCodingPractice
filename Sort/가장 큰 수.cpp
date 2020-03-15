#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <string>
#include <deque>

using namespace std;

bool desc(int a, int b) {
	vector<int> aa;
	vector<int> bb;
	while (a > 0) {
		aa.push_back(a % 10);
		a /= 10;
	}
	while (b > 0) {
		bb.push_back(b % 10);
		b /= 10;
	}
	
	if (aa.size() > bb.size()) {
		for (int i = 0; i < bb.size(); i++) {
	
			if (aa[aa.size() - i - 1] > bb[bb.size() - i - 1]) {
				if (a > b) return false;
				else return true;
			}
			else if (aa[aa.size() - i - 1] < bb[bb.size() - i - 1]) {
				if (a > b) return false;
				else return true;
			}
			if (bb.size() - i - 1 == 0) {
				if (aa[aa.size() - i - 2] > bb[bb.size() - i - 1]) return false;
				else return true;
			}
		}
	}
	else if (aa.size() < bb.size()) {
		for (int i = 0; i < aa.size(); i++) {

			if (aa[aa.size() - i - 1] > bb[bb.size() - i - 1]) {
				 return false;
			}
			else if (aa[aa.size() - i - 1] < bb[bb.size() - i - 1]) {
				return true;
			}
			if (aa.size() - i - 1 == 0) {
				if (aa[aa.size() - i - 1] < bb[bb.size() - i - 2]) return true;
				else return false;
			}
		}
	}
	else {
		for (int i = 0; i < aa.size(); i++) {
			if (aa[aa.size() - i - 1] > bb[bb.size() - i - 1]) {
				return false;
			}
			else if (aa[aa.size() - i - 1] < bb[bb.size() - i - 1]) {
				return true;
			}
		}
	}
}

bool cmp(string& a, string& b) {
	if (a + b > b + a) return false;
	else return true;
	return a + b < b + a ? true : false;
}

string solution(vector<int> numbers) {
	string answer = "";

	vector<string> numbers1;
	for (int a : numbers) {
		numbers1.push_back(to_string(a));
	}

	sort(numbers1.begin(), numbers1.end(), cmp);

	/*deque<string> numbers2;
	for (string name : numbers1) {
		numbers2.push_front(name);
	}
	while (!numbers2.empty()) {
		string tempa = numbers2.front();
		numbers2.pop_front();
		answer += tempa;
	}*/

	while (!numbers1.empty()) {
		answer += numbers1.back();
		numbers1.pop_back();
	}

	return answer;
}

int main() {
	vector<int> numbers = {999,989,55,45,2,21,34,3 };
	solution(numbers);
}