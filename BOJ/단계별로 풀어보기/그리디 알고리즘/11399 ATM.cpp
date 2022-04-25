#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int answer = 0;

	cin >> N;
	vector<int> vec(N);

	for (int i = 0; i < N; i++)
	{
		cin >> vec[i];
	}

	sort(vec.begin(), vec.end());

	for (int i = 0; i < vec.size(); i++)
	{
		answer += (vec[i] * (N-i));
	}

	cout << answer << '\n';
	
}
