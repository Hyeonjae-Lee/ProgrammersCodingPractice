#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

bool desc(int a, int b) {
	return a > b;
}

int solution(vector<int> people, int limit) {
	int answer = 0;
	int check = limit;

	deque<int> deq;
	for (auto ele : people) deq.push_back(ele);

	sort(deq.begin(), deq.end(), desc);

	while (!deq.empty()) {
		int sum = 0;

		sum += deq.front();
		deq.pop_front();

		if (!deq.empty() && sum + deq.back() <= limit) {
			sum += deq.back();
			deq.pop_back();
		}
		answer++;
	}
	return answer;
}

int main() {


	vector<int> people = { 70,80,50 }; 
	int limit = 100;

	cout << solution( people,  limit);
}