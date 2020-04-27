/* 2015112119 ÀÌÇöÀç */

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <sstream>

using namespace std;

int solution(int n)
{
	int ans = 0;

	while (n >= 0) {
		if (n == 0) break;
		
		if (n % 2 == 0) {
			n /= 2;
		}
		else {
			n /= 2;
			ans++;
		}
	}

	return ans;
}

int main() {
	cout << solution(6);
}