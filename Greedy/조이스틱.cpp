#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
#include <iostream>

using namespace std;

bool check(string name) {
	for (int i = 0; i < name.size(); i++) {
		if (name[i] != 'A') return false;
	}
	return true;
}

int solution(string name) {
	int answer = 0;
	int cursor = 0;

	while (!check(name)) {
		//���� A�� �����Ѵ�.

		


	}

	return answer;
}

int main() {

	cout << solution("AZAAAZ");
}