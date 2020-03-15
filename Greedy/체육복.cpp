#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int arr[50] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;
	
	for (int i = 0; i < lost.size(); i++) arr[lost[i]]--;
	for (int i = 0; i < reserve.size(); i++) arr[reserve[i]]++;

	for (int i = 1; i <= n; i++) {
		if (arr[i] > 1) {
			//여벌 체육복을 가지고 있는경우
			if (i == 1 && arr[i + 1] == 0) {
				arr[i]--;
				arr[i + 1]++;
			}
			else if (i == n && arr[i - 1] == 0) {
				arr[i]--;
				arr[i - 1]++;
			}
			else if (i > 1 && i < n){
				if (arr[i] == 2 && arr[i - 1] == 0) {
					arr[i]--;
					arr[i - 1]++;
				}
				else if (arr[i] == 2 && arr[i + 1] == 0) {
					arr[i]--;
					arr[i + 1]++;
				}
			}
		}
	}

	for (int i = 1; i <= n;i++) {
		if (arr[i] > 0) {
			answer++;
		}
	}

	return answer;
}

int main() {
	int n = 5;
	vector<int> lost = { 2, 4 };
	vector<int> reserve = { 3 };
	solution(5, lost, reserve);
}