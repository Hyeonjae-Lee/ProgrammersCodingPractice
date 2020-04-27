/* 2015112119 ÀÌÇöÀç */

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <sstream>

using namespace std;

vector<int> solution(int brown, int red) {
	vector<int> answer;

	int sum = brown + red;

	int x = 1;
	int y = brown / 2 + 2;

	while (x <= y) {
		if (x * (y - x) == sum) {
			break;
		} x++;
	}

	answer.push_back(x);
	answer.push_back(y - x);

	sort(answer.begin(), answer.end());
	reverse(answer.begin(), answer.end());

	return answer;
}