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
bool dsec(int a, int b) {
	return a > b;
}
long long solution(int n, vector<int> works) {
	long long answer = 0;
	
	priority_queue<int> qu(works.begin(), works.end());

	while (n > 0) {
		int temp = qu.top();
		temp--;
		qu.pop(); 
		qu.push(temp);
		n--;
	}

	while (!qu.empty()) {
		if(qu.top() > 0) answer += pow(qu.top(), 2);
		qu.pop();
	}

	return answer;
}

int main() {
	vector<int> works = { 1,1 };
	solution(3, works);
}