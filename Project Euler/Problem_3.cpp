#include <iostream>
#include <string>

using namespace std;

#define endl '\n'

void solution() {

	long long num = 600851475143;

	for (int i = 2; i * i <= num; i++)
	{
		while (num % i == 0)
		{
			num /= i;
		}
	}
	
	cout << num << endl;

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();
}
