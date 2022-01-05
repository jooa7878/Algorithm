// 500개 이상의 약수를 갖는 가장 작은 삼각수는?
#include <iostream>
#include <cmath>

using namespace std;

#define endl '\n'

int getMeasureCnt(int num){
	int res = 2;

	for (int i = 2; i <= sqrt(num); i++)
	{
		if (num % i == 0) res += 2;
	}

	return res;
}

void solution() {

	long long answer = 0;
	
	int n = 1;


	while (true)
	{
		answer = (n * (n + 1)) / 2;

		if (getMeasureCnt(answer) > 500) break;

		n++;
	}

	cout << answer << endl;

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();
}
