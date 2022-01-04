// 이백만 이하 소수의 합

#include <iostream>
#include <cmath>

using namespace std;

#define endl '\n'

bool is_prime(int num)
{
	for (int i = 2; i <= sqrt(num); i++) if (num % i == 0) return false;

	return true;
}

void solution() {

	int range = 2000000;
	long long sum = 0;

	for (int i = 2; i < range; i++)
	{
		if (is_prime(i)) sum += i;

	}

	cout << sum << endl;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();
}
