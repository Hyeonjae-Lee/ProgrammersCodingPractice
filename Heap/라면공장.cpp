#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

//다시풀어봐야한다.

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
	
	int answer = 0;
	int yesterDay = 0;

	priority_queue<int> qu;

	while (stock < k) {
		for (int i = yesterDay; i < dates.size() ; i++) {
			if (stock < dates[i]) break;
			qu.push(supplies[i]);
			yesterDay = i + 1;
		}
		
		stock += qu.top();
		qu.pop();
		answer++;
	}
	
	return answer;
}

int main() {

	vector<int> dates = { 4,10,15 };
	vector<int> supplies = { 20,5,10 };
	int k = 30;
	cout << solution(4, dates, supplies, k);

}