#include <string.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

long long dp[1000001];
long long dp2[1000001];

int solution(vector<int> money) {
	int answer = 0;
	for (int i = 0; i < money.size(); i++) {
		dp[i] = money[0];
		dp2[i] = money[1];
	}
	dp2[0] = 0;

	for (int i = 0; i < money.size() - 3; i++) dp[i + 2] = max(dp[i] + money[i + 2], dp[i + 1]);
	for (int i = 0; i < money.size() - 2; i++) dp2[i + 2] = max(dp2[i] + money[i + 2], dp2[i + 1]);

	return max(dp[money.size() - 2], dp2[money.size() - 1]);
}

int solution(vector<int> money) {
	vector <long> one;
	vector <long> two;
	int msize = money.size();
	one.resize(msize, money[0]);
	two.resize(msize, money[1]);

	//i = a + 2;

	two[0] = 0;
	for (int a = 0; a  < money.size() - 3; a++)
		one[a + 2] = max(one[a] + money[a + 2], one[a + 1]);

	for (int a = 0; a  < money.size() - 2; a++)
		two[a + 2] = max(two[a] + money[a + 2], two[a + 1]);

	return max(one[money.size() - 2], two[money.size() - 1]);
}

int main() {
	vector<int> money = { 1,2,3,1 };
	solution(money);
}