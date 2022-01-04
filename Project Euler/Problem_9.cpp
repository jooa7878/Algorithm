//a + b + c = 1000 이 되는 피타고라스 수

#include <iostream>
#include <queue>

using namespace std;

#define endl '\n'

void solution() {

	for (int i = 1; i < 1000; i++)
	{
		for (int j = 1; j < 1000; j++)
		{
			for (int k = 1; k < 1000; k++)
			{
				if (k*k == i * i + j * j && i + j + k == 1000)
				{
					cout << i * j * k << endl;
					return;
				}

			}
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();
}
