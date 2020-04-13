#include <string>
#include <vector>

using namespace std;

bool arr[1000001];

int solution(int n) {
	int answer = 0;

	arr[1] = 1;

	for (int i = 2; i <= n; i++) {
		if (!arr[i]) {
			answer++;
			for (int j = i; j <= n; j += i) {
				arr[j] = true;
			}
		}
	}

	return answer;
}