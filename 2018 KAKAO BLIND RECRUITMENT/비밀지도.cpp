/* 2015112119 ÀÌÇöÀç */

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <sstream>
#include <bitset>

using namespace std;
vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer;

	vector<string> ans1;
	vector<string> ans2;
	const int checkN = n;

	for (int i = 0; i < arr1.size(); i++) {
		
		int tempA = arr1[i];
		string temp = "";
		
		while (tempA) {
			
			int a = tempA % 2;
			tempA /= 2;
			temp += to_string(a);

		}
		reverse(temp.begin(), temp.end());

		if (temp.size() < n) {
			while (temp.size() < n) temp = "0" + temp;
		}

		ans1.push_back(temp);

	}
	for (int i = 0; i < arr2.size(); i++) {

		int tempA = arr2[i];
		string temp = "";

		while (tempA) {
			int a = tempA % 2;
			tempA /= 2;
			temp += to_string(a);
		}

		reverse(temp.begin(), temp.end());

		if (temp.size() < n) {
			while (temp.size() < n) temp = "0" + temp;
		}
		ans2.push_back(temp);
	}

	for (int i = 0; i < n; i++) {
		string temp = "";
		for (int j = 0; j < n; j++) {
			if (ans1[i][j] != ans2[i][j] || ans1[i][j] == '1') {
				temp += "#";
			}
			else {
				temp += " ";
			}
		}
		answer.push_back(temp);
	}

	return answer;
}

int main() {
	vector<int> arr1 = { 46, 33, 33 ,22, 31, 50 };
	vector<int> arr2 = { 27 ,56, 19, 14, 14, 10 };
	int n = 6;

	solution(n, arr1, arr2);
}