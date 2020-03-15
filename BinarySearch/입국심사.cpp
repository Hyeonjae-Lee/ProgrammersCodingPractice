#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

long long solution(int n, vector<int> times) {
	
	sort(times.begin(), times.end());

	long long left = 1;
	long long right = (long long)(times[times.size() - 1]) * n;
	long long mid = (left + right) / 2;

	long long answer = right;
	//long long sum = 0;
	while (left <= right) {
		long long sum = 0;
		for (int i = 0; i < times.size(); i++) {
			sum += mid / times[i];
		}

		if (sum < n) left = mid + 1;
		else {
			if (answer >= mid ) answer = mid;
			right = mid - 1;
		}
		mid = (left + right) / 2;
	}
	return answer;
}

#include <string>
#include <algorithm>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
	sort(times.begin(), times.end());
	long long left = 1;
	long long right = (long long)(times[times.size() - 1]) * n;
	long long answer = right;

	while (left <= right) {
		long long mid = (left + right) / 2;
		long long sum = 0;
		for (int i = 0; i < times.size(); i++)
			sum += mid / times[i]; 
		if (n > sum) left = mid + 1;
		else {
			if (mid <= answer)
				answer = mid;
			right = mid - 1;
		}
	}
	return answer;
}


int main() {
	vector<int> times = { 7, 10 };
	solution(6, times);
}