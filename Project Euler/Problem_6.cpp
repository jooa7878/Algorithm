// 1부터 100까지 "제곱의 합"과 "합의 제곱"의 차는?
#include <iostream>
#include <string>

using namespace std;

#define endl '\n'

void solution() {

	long long a = 0; // 제곱의 합
	long long b = 0; // 합의 제곱

	for (int i = 1; i < 101; i++)
	{
		a += i * i;
		b += i;
	}

	b *= b;

	cout << b - a << endl;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	solution();
}
