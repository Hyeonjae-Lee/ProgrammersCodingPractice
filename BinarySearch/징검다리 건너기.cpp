
/* 2015112119 ÀÌÇöÀç */

#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

bool func(int mid, const vector<int>& stones, int k) {
	int now = 0;
	for (int i = 0; i < stones.size(); i++) {
		if (stones[i] - mid <= 0) {
			now++;
			if (now >= k) return false;
		}
		else {
			now = 0;
		}
	}
	return true;
}

int solution(vector<int> stones, int k) {
	int left = 1, right = 200000000;

	while (left <= right) {
		int mid = (left + right) / 2;
		
		if (func(mid, stones, k)) {
			left = mid + 1;
		}
		else {
			
			right = mid - 1;
		}
	}
	return left;
}

int main() {

}