// 피보나치 수열에서 4백만 이하이면서 짝수인 항의 합
#include <iostream>
#include <string>
#include <set>

using namespace std;

#define endl '\n'

int fib[100];

void solution() {


	fib[0] = 1;
	fib[1] = 2;

	int answer = 2;

	for (int i = 2; i < 32; i++)
	{
		fib[i] = fib[i - 1] + fib[i - 2];
		if (fib[i] % 2 == 0) answer+=fib[i];
	}

	
	cout << answer << endl;
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	solution();
}
