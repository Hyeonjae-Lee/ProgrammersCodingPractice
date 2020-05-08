#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

//n으로 바꾸는 함수
vector<int> getVec(int i, int n) {
	vector< int > tempvec;

	while (i > 0) {

		if (i % n >= 10) {
			tempvec.push_back(i % n + 55);
		}
		else {
			tempvec.push_back(i % n);
		}
		i /= n;
	}

	reverse(tempvec.begin(), tempvec.end());

	return tempvec;
}

string solution(int n, int t, int m, int p) {
	string answer = "";

	vector< int > vec;
	vec.push_back(0);
	for (int i = 0; i < 10000; i++) {
		vector<int> tempvec = getVec(i, n);
		for (auto ele : tempvec) {
			vec.push_back(ele);
		}
	}
	int i = 0;
	int j = 1;
	p--;
	i += p;
	while ( j <= t ) {
		if (vec[i] > 64) answer += vec[i];
		else answer += to_string(vec[i]);
		i += m;
		j++;
	}
	return answer;
}

int main() {
	int n = 16;
	int t = 16;
	int m = 2;
	int p = 2;
	
	cout << solution(n, t, m, p);
}