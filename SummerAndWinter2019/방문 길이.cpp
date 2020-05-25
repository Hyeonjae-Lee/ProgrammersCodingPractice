/* 2015112119 ÀÌÇöÀç */

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <sstream>
#include <bitset>
#include <string.h>

using namespace std;

pair<pair<int, int>, pair<int, int>> dp[15][15];

int check(int x, int y) {
	if (x >= -5 && x <= 5 && y >= -5 && y <= 5) return true;
	else return false;
}

struct line {
	int x1;
	int y1;
	int x2;
	int y2;
	
};
bool operator==(const line& lhs, const line& rhs)
{
	return (lhs.x1 == rhs.x1 && lhs.y1 == rhs.y1 && lhs.x2 == rhs.x2 && lhs.y2 == rhs.y2);
}


int solution(string dirs) {
	int answer = 0;
	int x = 0, y = 0;

	vector<line> vec;

	for (int i = 0; i < dirs.size(); i++) {
		
		if (dirs[i] == 'L') {
			if (check(x - 1, y) ) {

				line c;
				c.x1 = x;
				c.y1 = y;
				c.x2 = x - 1;
				c.y2 = y;
				line c2;
				c2.x2 = x;
				c2.y2 = y;
				c2.x1 = x - 1;
				c2.y1 = y;

				if ( find(vec.begin(), vec.end(), c) != vec.end() || find(vec.begin(), vec.end(), c2) != vec.end()) {

				}
				else {
					vec.push_back(c);
					answer++;
				}
				x--;
			}
		}
		else if (dirs[i] == 'U') {
			if (check(x, y + 1 )) {

				line c;
				c.x1 = x;
				c.y1 = y;
				c.x2 = x;
				c.y2 = y + 1;
				line c2;
				c2.x2 = x;
				c2.y2 = y;
				c2.x1 = x;
				c2.y1 = y + 1;

				if (find(vec.begin(), vec.end(), c) != vec.end() || find(vec.begin(), vec.end(), c2) != vec.end()) {

				}
				else {
					vec.push_back(c);
					 answer++;
				}y++;
			}
		}
		else if (dirs[i] == 'D') {
			if (check(x, y - 1 )) {
				
				line c;
				c.x1 = x;
				c.y1 = y;
				c.x2 = x;
				c.y2 = y - 1;
				line c2;
				c2.x2 = x;
				c2.y2 = y;
				c2.x1 = x;
				c2.y1 = y - 1;
				
				if (find(vec.begin(), vec.end(), c) != vec.end() || find(vec.begin(), vec.end(), c2) != vec.end()) {
					
				}
				else {
					vec.push_back(c);
					 answer++;
				}y--;

			}
		}
		else if (dirs[i] == 'R') {
			if (check(x + 1, y )) {
						
				line c;
				c.x1 = x;
				c.y1 = y;
				c.x2 = x + 1;
				c.y2 = y;
				line c2;
				c2.x2 = x;
				c2.y2 = y;
				c2.x1 = x + 1;
				c2.y1 = y;

				if (find(vec.begin(), vec.end(), c) != vec.end() || find(vec.begin(), vec.end(), c2) != vec.end()) {

				}
				else {
					vec.push_back(c);
					 answer++;
				}x++;
			}
		}
	}

	return answer;
}

int main() {
	solution("LR");
}