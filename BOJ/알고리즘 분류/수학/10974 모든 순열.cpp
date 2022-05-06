#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[10001];

void solution() {

	do {

		for (int i = 1; i <= N; i++)
		{
			cout << arr[i] << ' ';
		}

		cout << '\n';
	} while (next_permutation(arr + 1, arr + N + 1));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		arr[i] = i;
	}

	solution();
}
