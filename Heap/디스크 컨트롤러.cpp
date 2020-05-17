#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>
#include <map>
#include <queue>

using namespace std;

int solution(vector<vector<int>> jobs) {
	int answer = 0;

	vector<pair<int, int>> vec;
	for (auto ele : jobs) {
		vec.push_back({ ele[0], ele[1] });
	}

	for (int i = 0; i < vec.size(); i++) {
		for (int j = 0; j < vec.size(); j++) {

			if(vec[i].second > vec)

		}
	}
	

	return answer;
}