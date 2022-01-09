#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define endl '\n'

int N, M, B, mx, height_ans;
int time_ans = 2002201090;

int arr[501][501];

void solution()
{

	for (int height = 0; height <= 256; height++)
	{
		int add = 0; // 블록 위에 추가
		int remove = 0; // 블록을 제거해서 인벤토리에 넣는다
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (height >= arr[i][j])
				{
					add += height - arr[i][j];
				}
				else
				{
					remove += arr[i][j] - height;
				}
			}
		}

		if (add + (remove * 2) <= time_ans && remove + B >= add)
		{
			time_ans = add + (remove * 2);
			height_ans = height;
		}
	}

	cout << time_ans << ' ' << height_ans << endl;
	
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> B;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] > mx) mx = arr[i][j];
		}
	}

	solution();
}
