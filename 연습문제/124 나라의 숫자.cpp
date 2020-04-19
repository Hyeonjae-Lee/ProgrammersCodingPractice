#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

string solution(int n) {
	string answer = "";

	vector<string> vec;

	while (n > 0) {
		int m = n / 3;
		int realse = n % 3; 

		if (realse == 0) {
			m--;
			realse = 4;
		}
		answer += to_string(realse);
		n = m;
	}

	reverse(answer.begin(), answer.end());

	return answer;
}

int main() {
	cout << solution(10);
}