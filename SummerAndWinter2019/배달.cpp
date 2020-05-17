/* 2015112119 ÀÌÇöÀç */

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <sstream>

using namespace std;
bool visited[51];

bool desc(vector<int> a, vector<int> b) {
	if (a[0] == b[0]) return a[1] < b[1];
	return a[0] < b[0];
}

struct myStruct {
	int point;
	int sum;
};

struct desc2 {
	bool operator()(myStruct t, myStruct u) {
		//if (t.sum != u.sum) 
			return t.sum > u.sum;
		/*else return t.point > u.point;*/
	}
};

int dp[51];

int solution(int N, vector<vector<int> > road, int K) {
	int answer = 0;
	vector<vector<int> > vec;

	for (int i = 1; i < 51; i++) dp[i] = 9999999;
	vector<vector<pair<int,int> >> pointVec(51);

	for (int i = 0; i < road.size(); i++) {
		pointVec[road[i][0]].push_back({ road[i][1], road[i][2] });
		pointVec[road[i][1]].push_back({ road[i][0], road[i][2] });
	}

	myStruct c;
	c.point = 1;
	c.sum = 0;
	
	priority_queue<myStruct, vector<myStruct>, desc2> qu;
	qu.push(c);
	dp[1] = 0;
	while (!qu.empty()) {
		myStruct temp = qu.top();
		qu.pop();

		if (temp.sum > dp[temp.point]) continue;
		for (int i = 0; i < pointVec[temp.point].size(); i++) {
			if (pointVec[temp.point][i].second + temp.sum < dp[pointVec[temp.point][i].first]) {
				myStruct tempC;
				tempC.point = pointVec[temp.point][i].first;
				dp[pointVec[temp.point][i].first] = pointVec[temp.point][i].second + temp.sum;
				tempC.sum = dp[pointVec[temp.point][i].first];
				qu.push(tempC);
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		if (dp[i] <= K) answer++;
	}

	return answer;
}

int main() {
	int N = 6;
	vector<vector<int> > road = { {1, 2, 1},{1,3,2},{2,3,2},{3,4,3},{3,5,2},{3,5,3},{5,6,1} };
	int K = 4;

	cout << solution( N,  road, K);
}