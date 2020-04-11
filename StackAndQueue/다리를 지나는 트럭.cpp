#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;
	queue<int> qu;

	while (!qu.empty()) {



	}

	return answer;
}

vector<int> solution(vector<int> prices) {
	vector<int> answer;

	for (int i = 0; i < prices.size(); i++) {
		int check = 0;
		for (int j = i + 1; j < prices.size(); j++) {
			if (prices[i] > prices[j]) {
				break;
			}
			else check++;
		}
		answer.push_back(check);
	}

	return answer;
}

int main() {

}