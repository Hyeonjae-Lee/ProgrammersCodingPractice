#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

long long gcd(long long a, long long b)
{
	long long c;
	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

long long solution(int w, int h)
{
	long long answer = 1;
	long long temp;
		if (w > h) temp = gcd(w, h);
		else temp = gcd(h, w);

	answer = (long long)w*h - (long long)(w + h - temp);

	return answer;
}

