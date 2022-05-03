#include <iostream>
#include <algorithm>
#include <queue>
#define endl '\n';

using namespace std;

int N, answer;
pair<int, int> arr[200001];

void solution()
{
  sort(arr, arr + N);

  priority_queue<int, vector<int>, greater<int> > pq;

  for (int i = 0; i < N; i++)
  {
    pq.push(arr[i].second);
    if (pq.top() <= arr[i].first)
      pq.pop();
  }

  cout << pq.size() << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> N;

  for (int i = 0; i < N; i++)
  {
    cin >> arr[i].first >> arr[i].second;
  }

  solution();
}
