#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

int solution(vector<int> budgets, int M) {
	int answer = 0;
	int finalAnswer = 0;

	sort(budgets.begin(), budgets.end());
	int blenght = budgets.size();
	int left = 0, right = budgets[blenght-1], mid;
	mid = (left + right) / 2 + 1;//mid = »óÇÑ¾×
	int sum;

	while (left <= right) {
		sum = 0;
		for (int i = 0; i < blenght; i++) {
			if (mid >= budgets[i]) sum += budgets[i];
			else sum += mid;
		}

		if (sum == M) {
			break;
		}
		else if (sum > M) {
			right = mid - 1;
			mid = (left + right) / 2;
			answer = mid;
		}
		else {
			left = mid + 1;
			mid = (left + right) / 2;
		}
	}
	answer = mid;

	return answer;
}

int main() {
	vector<int> budgets = { 120,110,140,150 };
	solution(budgets, 485);
}