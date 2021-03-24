#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int N, K;

	cin >> N >> K;

	vector<int> units(N);

	for (int i = 0; i < N; i++)
	{
		cin >> units[i];
	}

	int pos = units.size() - 1;
	int answer = 0;

	while (pos >= 0)
	{

		if (units[pos] <= K)
		{
			answer += (K / units[pos]);
			K -= (units[pos] * (K / units[pos]));
		}
		pos--;
	}

	cout << answer << '\n';
	
}
