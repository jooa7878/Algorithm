#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
/*
570 // 정답: 8

571 // 정답: 9

572 // 정답: 10, 오답: 11

642 // 정답: 10, 오답: 11

643 // 정답: 11, 오답: 12

734 // 정답: 9, 오답: 10

740 // 정답: 9, 오답: 10

842 // 정답: 11, 오답: 12
*/

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int count = 0;

	cin >> N;

	vector<int> vec(N + 1);

	vec[0] = 0;
	vec[1] = 0;
	vec[2] = 1;
	vec[3] = 1;

	for (int i = 4; i <= N; i++)
	{

		int num = i;
		int count = 0;


		if (num % 6 == 0 || num % 3 == 0 || num % 2 == 0)
		{
			if (num % 6 == 0)
			{
				if (vec[num / 3] < vec[num / 2])
					vec[num / 3] > vec[num - 1] ? num-- : num /= 3;
				else
					vec[num / 2] > vec[num - 1] ? num-- : num /= 2;
			}
			else if (num % 3 == 0)
			{
				vec[num / 3] > vec[num - 1] ? num-- : num /= 3;
			}
			else if (num % 2 == 0)
			{
				vec[num / 2] > vec[num - 1] ? num-- : num /= 2;
			}
		}
		else
		{
			num--;
		}

		count++;

		if (vec[num] != 0)
		{
			count += vec[num];
		}


		vec[i] = count;
	}

	cout << vec[N] << '\n';


}

