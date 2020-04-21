/* 2015112119 ÀÌÇöÀç */

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
 
int dp[100000];
bool check[100000];

vector<int> temp;
vector<int> ans;

int dfs(int depth, int start) {
	int answer = 0;

	if (depth == 3) {
		int sum = 0;
		for (auto ele : ans) sum += ele;
		if (!dp[sum]) return 1;
		else return 0;
	}

	for (int i = start; i < temp.size(); i++) {
		if (!check[i]) {
			check[i] = true;
			ans.push_back(temp[i]);
			answer += dfs(depth + 1, i+1);
			ans.pop_back();
			check[i] = false;
		}
	}

	return answer;
}

int solution(vector<int> nums) {
	int answer = -1;
	temp = nums;

	for (int i = 2; i < 100000; i++) {
		if (!dp[i]) {
			for (int j = i * 2; j < 100000; j += i) {
				dp[j] = true;
			}
		}
	}

	answer = dfs(0, 0);

	return answer;
}

int main() {

}