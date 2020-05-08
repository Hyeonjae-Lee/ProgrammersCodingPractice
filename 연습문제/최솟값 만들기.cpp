#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

int dp[1001];
bool check[1001];
bool check2[1001];
vector<int> veca;
vector<int> vecb;

int dfs (int depth, int sum) {
	int answer = 9999999;

	if (depth >= veca.size()) {
		return sum;
	}

	for (int i = 0; i < veca.size(); i++) {
		if (!check[i]) {
			check[i] = true;
			for (int j = 0; j < vecb.size(); j++) {
				if (!check2[j]) {
					check2[j] = true;
					answer = min(answer, dfs(depth + 1, sum + veca[i] * vecb[j]));
					check2[j] = false;
				}
			}
			check[i] = false;
		}
	}

	return answer;
}

bool desc(int a, int b) {
	return a > b;
}


bool asc(int a, int b) {
	return a < b;
}

int solution(vector<int> A, vector<int> B)
{
	int answer = 0;
	veca = A;
	vecb = B;
	
	//answer = dfs(0, 0);

	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), desc);

	for (int i = 0; i < A.size(); i++) {
		answer += A[i] * B[i];
	}

	return answer;
}

int main() {
	vector<int> A = { 1,4,2 };
	vector<int> B = { 5,4,4 };

	cout << solution( A,  B);
}