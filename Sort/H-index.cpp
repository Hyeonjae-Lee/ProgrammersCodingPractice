#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool desc(int a, int b) {
	return a > b;
}

int solution(vector<int> citations) {
	int answer = 0;

	sort(citations.begin(), citations.end(), desc);

	int high = 0;
	int low = 0;

	for (int i = 0; i < citations.size(); i++) {
		high = 0;
		low = 0;
		if (i == 3);
		for (int j = 0; j < citations.size(); j++) {
			if (citations.size()-i <= citations[j]) {
				high++;
			}
		}
		low = citations.size() - high;

		if (high >= citations.size() - i && low <= citations.size() - i) {
			return citations.size() - i;
		}
	}

	return citations[citations.size() - 1];
}

int main() {
	vector<int> citations = {22, 42 };
	cout << solution(citations);
}