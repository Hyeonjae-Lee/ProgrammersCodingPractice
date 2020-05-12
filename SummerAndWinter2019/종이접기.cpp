#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n) {
	vector<int> answer;

	while (n--) {
		vector<int> vec;
		vec = answer;
		answer.push_back(0);
		
		reverse(vec.begin(), vec.end());

		for (int i = 0; i < vec.size(); i++) {
			if (vec[i]) answer.push_back(0);
			else answer.push_back(1);
		}

	}

	return answer;
}