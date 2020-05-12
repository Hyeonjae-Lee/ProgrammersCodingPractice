/* 2015112119 이현재 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <set>

using namespace std;

vector<int> solution(vector<string> gems) {
	vector<int> answer;
	vector<string> gems2 = gems;

	pair<int, int> tempAnswer = { 0, 100001 };
	
	sort(gems2.begin(), gems2.end());
	gems2.erase(unique(gems2.begin(), gems2.end()), gems2.end());

	int number = gems2.size();

	for (int i = 0; i < gems.size(); i++) {
		
		vector<string> tempvec;
		int start = i;
		int end = i;
		int finalend = i;

		for (int j = i; j < gems.size(); j++) {
			if (find(tempvec.begin(), tempvec.end(), gems[j]) != tempvec.end()) {
				//찾았을 경우
				end++;
			}
			else { // 못찾았을경우
				tempvec.push_back(gems[j]);
				finalend = end;
				end++;
				if (tempvec.size() == number) {
					break;
				}
			}
		}

		if (tempvec.size() != number) continue;

		if (tempAnswer.second - tempAnswer.first > finalend - start) {
			tempAnswer = { start, finalend };
		}
	}

	answer.push_back(tempAnswer.first + 1);
	answer.push_back(tempAnswer.second + 1);

	return answer;
}

int main() {
	vector<string> gems = { "DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA" };
	solution(gems);
}