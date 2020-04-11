/* 2015112119 ÀÌÇöÀç */

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <set>
using namespace std;

bool desc(pair<int, int> a, pair<int, int > b) {
	return a.second > b.second;
}

vector<int> solution(string s) {
	vector<int> answer;
	map<int, int> myset;
	int start = 0;
	int end = 0;
	string srr = "";
	int k = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '{' || s[i] == '}' || s[i] == ',') {
			if (end > 0) {
				for (int j = start; j <= end; j++) {
					srr += s[j];
				}
			}

			stringstream ss;
			int n;
			ss.str(srr);
			while (ss >> n) {
				myset[n]++;
			}
			
			k = 0;
			srr = "";
			start = 0;
			end = 0;
		}
		else {
			if (start == 0) {
				start = i;
				end = i;
			}
			else end++;
		}
	}

	map<int, int>::iterator iter;
	vector<pair<int, int>> vec;
	for (iter = myset.begin(); iter != myset.end(); iter++) {
		vec.push_back({ iter->first, iter->second });
	}

	sort(vec.begin(), vec.end(), desc);
	for (auto ele : vec) {
		answer.push_back(ele.first);
	}

	return answer;
}

int main() {
	string s = "{{2},{2,1},{2,1,3},{2,1,3,4}";
	solution(s);
}