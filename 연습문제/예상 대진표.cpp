#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int n, int a, int b)
{
	int answer = 1;

	if (a > b) {
		int temp = a;
		a = b;
		b = temp;
	}
	//a가 항상 작다
	while (true) {
		if (a + b == b * 2 - 1) {
			if(a % 2 == 1 ) break;
		}
		
		int tempa = a % 2;
		a /= 2;
		if (tempa == 1)a++;

		int tempb = b % 2;
		b /= 2;
		if (tempb == 1) b++;
		
		answer++;
	}

	return answer;
}