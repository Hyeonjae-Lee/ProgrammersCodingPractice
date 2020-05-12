/* 2015112119 이현재 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <math.h>
using namespace std;

int dp[4][3];

string solution(vector<int> numbers, string hand) {
	string answer = "";

	pair<int, int> left = { 3,0 };
	pair<int, int> right = { 3,2 };

	for (int i = 0; i < numbers.size(); i++) {
		if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
			//왼손 무조건 이용
			left = { numbers[i] / 3, 0 };
			answer += "L";
		}
		else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {
			right = { numbers[i] / 4, 2 };
			answer += "R";
		}
		else {
			//양방이용
			if (numbers[i] == 2) {
				int leftsum = 0;
				leftsum = abs(left.second - 1) + left.first - 0;
				int rightsum = 0;
				rightsum = abs(right.second - 1) + right.first - 0;

				if (leftsum < rightsum) {
					left = { 0,1 };
					answer += "L";
				}
				else if (leftsum > rightsum) {
					right = { 0,1 };
					answer += "R";
				}
				else {
					if (hand == "right") {
						right = { 0,1 };
						answer += "R";
					}
					else {
						left = { 0,1 };  answer += "L";
					}
				}
			}else if (numbers[i] == 5) {

				int leftsum = 0;
				leftsum = abs(left.second - 1) + abs(left.first - 1);
				int rightsum = 0;
				rightsum = abs(right.second - 1) + abs(right.first - 1);

				if (leftsum < rightsum) {
					left = { 1,1 };
					answer += "L";
				}
				else if (leftsum > rightsum) {
					right = { 1,1 };
					answer += "R";
				}
				else {
					if (hand == "right") {
						right = { 1,1 };
						answer += "R";
					}
					else {
						left = { 1,1 };
						answer += "L";
					}
				}

			}else if (numbers[i] == 8) {
				int leftsum = 0;
				leftsum = abs(left.second - 1) + abs(left.first - 2);
				int rightsum = 0;
				rightsum = abs(right.second - 1) + abs(right.first - 2);

				if (leftsum < rightsum) {
					left = { 2,1 };
					answer += "L";
				}
				else if (leftsum > rightsum) {
					right = { 2,1 };
					answer += "R";
				}
				else {
					if (hand == "right") {
						right = { 2,1 }; answer += "R";
					}
					else {
						left = { 2,1 }; answer += "L";
					}
				}
			} else {
				int leftsum = 0;
				leftsum = abs(left.second - 1) + abs(left.first - 3);
				int rightsum = 0;
				rightsum = abs(right.second - 1) + abs(right.first - 3);

				if (leftsum < rightsum) {
					left = { 3,1 };
					answer += "L";
				}
				else if (leftsum > rightsum) {
					right = { 3,1 };
					answer += "R";
				}
				else {
					if (hand == "right") {
						right = { 3,1 };  answer += "R";
					}
					else { answer += "L"; left = { 3,1 }; }
				}
			}
		}
	}


	return answer;
}

int main() {
	vector<int> numbers = { 1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5 };
	solution(numbers, "right");
}