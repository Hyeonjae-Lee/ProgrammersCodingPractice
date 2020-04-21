/* 2015112119 ÀÌÇöÀç */

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N;

bool check(int k) {
	int sum = 0;
	bool flag = false;

	for (int i = k; i <= N; i++) {
		sum += i;
		if (sum == N) {
			flag = true;
			break;
		}
	}
	return flag;
}

int solution(int n) {
	int answer = 0;
	N = n;
	
	for (int i = 1; i <= n; i++) {
		if (check(i)) {
			answer++;
		}
	}

	queue<int>qu;
	qu.push(1);

	while (!qu.empty()) {
		
		

	}

	return answer;
}

int main() {

}