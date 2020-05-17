#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>

using namespace std;

string checkS = "";

bool checkPalindrom(int i, int j) {
	for (int k = i; k < (j + i) / 2 + 1; k++) {
		if (checkS[k] != checkS[j + i - k]) return false;
	}
	return true;
}

int solution(string s)
{
	checkS = s;
	int answer = 1;
	int length = s.size() - 1;
	bool check = false;

	if (s.size() == 1) return answer;
	else if (s.size() == 2 && s[0] == s[1]) return 2;
	else if (s.size() == 2) return answer;
	
	for (int i = 0; i <= length; i++) {
		for (int j = length; j > i; j--) {
			
			if (s[i] == s[j]) {
				check = checkPalindrom(i, j);
			}

			if (check) {
				answer = max(answer, j - i + 1);
				check = false;
				break;
			}
		}
	}

	return answer;
}

int main() {
	string srr;
	cin >> srr;
	cout << solution(srr);
}