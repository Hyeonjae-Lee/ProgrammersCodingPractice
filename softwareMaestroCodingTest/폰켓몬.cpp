/* 2015112119 ÀÌÇöÀç */

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <sstream>

using namespace std;

int solution(vector<int> nums)
{
	int answer = 0;

	int k = nums.size() / 2;
	sort(nums.begin(), nums.end());
	nums.erase(unique(nums.begin(), nums.end()), nums.end());

	if (k <= nums.size()) {
		answer = k;
	}
	else {
		answer = nums.size();
	}

	return answer;
}

int main() {
	vector<int> nums = { 3,3,3,2,2,2 };
	cout << solution(nums);
}