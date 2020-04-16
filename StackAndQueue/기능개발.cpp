#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	int finalcheck = 0;
	for (int i = 0; i < progresses.size(); i++) {
		int temp = 100 - progresses[i];

		int check = temp / speeds[i];
		if (temp % speeds[i] != 0) {
			check++;
		}

		if (finalcheck < check)
		{
			finalcheck = check;
			answer.push_back(1);
		}
		else {
			//finalcheck에 위배된다.
			answer.back()++;
		}
	}

	return answer;
}