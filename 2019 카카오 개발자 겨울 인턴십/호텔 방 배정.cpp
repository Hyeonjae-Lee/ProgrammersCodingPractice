/* 2015112119 ������ */

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
long long arr[200001];

/* find(x): ��� �̿� */
long long find(long long x) {
	if (arr[x] == x) {
		arr[x] = x + 1;
		return x;
	}
	else {
		// "��� ����(Path Compression)"
		// find �ϸ鼭 ���� ��� ���� �θ� ��带 root�� �����.
		arr[x] = find(arr[x]) + 1;
		return arr[x];
	}
}

vector<long long> solution(long long k, vector<long long> room_number) {
	vector<long long> answer;
	long long temp = 0;
	long long check = 1;

	for (int i = 0; i < room_number.size(); i++) {
		if (!arr[room_number[i]]) {//�濡 �������
			answer.push_back(room_number[i]);
			arr[room_number[i]] = room_number[i] + 1;
		}
		else {//�濡 ����� �������
			temp = find(room_number[i]+1);
			answer.push_back(temp);
		}
	}

	return answer;
}

int main() {
	
	long long k = 10;
	vector<long long> room_number = { 1,3,4,1,3,1 };

	solution(k,room_number);
}