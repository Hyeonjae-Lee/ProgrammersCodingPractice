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

vector<int> vec;

long long temp = 1;
int N;
bool visited[21];
long long ansk = 1;

vector<int> solution(int n, long long k) {
	vector<int> answer;
	
	N = n;
	k--;
	for (int i = 1; i <= n; i++) {
		vec.push_back(i);
		temp *= i;
	} 
	
	while (n > 0) {
		temp /= n--;
		answer.push_back(vec.at(k / temp));
		vec.erase(vec.begin() + k / temp);
		k %= temp;
	}

	return answer;
}

int main() {
	solution(3, 5);
}