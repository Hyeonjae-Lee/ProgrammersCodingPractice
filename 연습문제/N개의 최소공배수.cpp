/* 2015112119 ÀÌÇöÀç */

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <sstream>

using namespace std;

int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

int solution(vector<int> arr) {
	int answer = 1;

	sort(arr.begin(), arr.end());

	for (int i = 0; i < arr.size(); i++) {
		answer = lcm(answer, arr[i]);
	}

	return answer;
}

int main() {

}