#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>

#define endl '\n';

using namespace std;

const int MAX = 2147483647;

int N, answer;
int arr[100001];

void solution()
{
  sort(arr, arr + N);

  for (int i = 0; i < N; i++)
  {
    if (arr[i] * (N - i) > answer)
      answer = arr[i] * (N - i);
  }

  cout << answer << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> N;

  for (int i = 0; i < N; i++)
  {
    cin >> arr[i];
  }

  solution();
}
