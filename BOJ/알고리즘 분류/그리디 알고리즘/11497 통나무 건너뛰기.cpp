#include <iostream>
#include <algorithm>

#define endl '\n';

using namespace std;

int T, N;
int arr[10001];
int cpy[10001];

void solution()
{
  int idx = 0;

  sort(arr, arr + N);

  for (int i = 0; i < N; i += 2)
  {
    cpy[idx] = arr[i];
    idx++;
  }

  for (int i = N % 2 == 0 ? N - 1 : N - 2; i > 0; i -= 2)
  {
    cpy[idx] = arr[i];
    idx++;
  }

  int answer = 0;

  for (int i = 0; i < N - 1; i++)
  {
    if (abs(cpy[i] - cpy[i + 1]) > answer)
      answer = abs(cpy[i] - cpy[i + 1]);
  }

  if (abs(cpy[0] - cpy[N - 1]) > answer)
    answer = abs(cpy[0] - cpy[N - 1]);

  cout << answer << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> T;

  for (int i = 0; i < T; i++)
  {
    cin >> N;
    for (int j = 0; j < N; j++)
    {
      cin >> arr[j];
    }
    solution();
  }
}
