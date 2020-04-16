#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<bool> dp(10000000);

vector<int> vec;
bool check[100000];
vector<int> ans;

void dfs(int a, int depth) {
	if (depth >= vec.size()) return;
	for (int i = 0; i < vec.size(); i++) {
		if (!check[i]) {
			check[i] = true;
			ans.push_back(a * 10 + vec[i]);
			dfs(a * 10 + vec[i], depth + 1);
			check[i] = false;
		}
	}
}

int solution(string numbers) {
	int answer = 0;

	dp[1] = true;
	dp[0] = true;

	for (int i = 2; i < 10000000; i++) {
		if (!dp[i]) {
			for (int j = i * 2; j < 10000000; j += i) {
				dp[j] = true;
			}
		}
	}

	for (int i = 0; i < numbers.size(); i++) {
		vec.push_back(numbers[i] - '0');
	}

	dfs(0, 0);

	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());

	for (auto ele : ans) {
		if (!dp[ele]) answer++;
	}

	return answer;
}