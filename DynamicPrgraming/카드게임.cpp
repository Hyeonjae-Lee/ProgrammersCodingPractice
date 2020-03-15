#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;
vector<int> myLeft;
vector<int> myRight;
int dp[2002][2002];

int func(int left, int right) {

	if (left == myLeft.size() || right == myRight.size()) {
		return 0;
	}

	if (dp[left][right] != -1) {
		return dp[left][right];
	}

	dp[left][right] = max(func(left + 1, right), func(left + 1, right + 1));
	
	if (myLeft[left] > myRight[right]) dp[left][right] = max(func (left, right + 1) + myRight[right], dp[left][right]);

	return dp[left][right];
}

int solution(vector<int> left, vector<int> right) {
	int answer = 0;

	myLeft = left;
	myRight = right;
	memset(dp, -1, sizeof(dp));
	answer = func(0, 0);

	return answer;
}

int main() {


}