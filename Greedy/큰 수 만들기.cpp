#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string number, int k) {
	string answer = "";
	int check = k;
	while (k > 0) {
		//가장 큰수를 찾아버린다.
		char maxChar = '9';
		int index = number.size();
		
		for (int i = 0; i < number.size(); i++) {
			if (maxChar >= number[i]) {
				maxChar = number[i];
			}
			else {
				index = i;
				break;
			}
		}

		number.erase(index - 1, 1);
		k--;
	}

	answer = number;

	return answer;
}

int main() {
	cout << solution("4177252841", 7);
}