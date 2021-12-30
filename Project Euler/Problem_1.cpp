// 1000보다 작은 자연수 중에서 3 또는 5의 배수를 모두 더하면?

#include <iostream>
#include <string>

using namespace std;

#define endl '\n'

void solution() {

	int answer = 0;

	for (int i = 1; i < 1000; i++)
	{
		if (i % 3 == 0 || i % 5 == 0) answer += i;
	}
	
	cout << answer << endl;
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();
}
