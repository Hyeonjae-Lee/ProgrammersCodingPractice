/* 2015112119 ������ */

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <sstream>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
	int answer = 0;

	deque<string> vec;

	if (cacheSize) {
		//0�� �ƴѰ��

		for (int i = 0; i < cities.size(); i++) {

			transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::toupper);

			if (find(vec.begin(), vec.end(), cities[i]) != vec.end()) {
				//���Ҹ� ã����
				vec.erase(find(vec.begin(), vec.end(), cities[i]));
				vec.push_back(cities[i]);
				answer++;
			}
			else {
				if (vec.size() >= cacheSize) {
					vec.pop_front();
					vec.push_back(cities[i]);
				}
				else {
					vec.push_back(cities[i]);
				}

				answer += 5;
			}
		}
	}
	else {
		return cities.size() * 5;
	}

	return answer;
}

int main() {
	int cacheSize = 2;
	vector<string> cities = { "Jeju", "Pangyo", "NewYork", "newyork" };

	cout << solution(cacheSize, cities);
}