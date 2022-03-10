#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>

#define endl '\n'
#define ll long long

using namespace std;

int N, mx, result, answer;
int arr[101][101];
bool visited[101][101];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void solution(int y, int x, int height)
{
  queue<pair<int, int> > q;

  result++;

  q.push({y, x});

  while (!q.empty())
  {
    int y = q.front().first;
    int x = q.front().second;

    q.pop();

    for (int i = 0; i < 4; i++)
    {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if (ny >= 0 && nx >= 0 && ny < N && nx < N && !visited[ny][nx] && arr[ny][nx] > height)
      {
        visited[ny][nx] = true;
        q.push({ny, nx});
      }
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      cin >> arr[i][j];
      if (arr[i][j] > mx)
        mx = arr[i][j];
    }
  }

  for (int h = 0; h <= mx; h++)
  {
    result = 0;
    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < N; j++)
      {
        visited[i][j] = false;
      }
    }

    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < N; j++)
      {
        if (arr[i][j] > h && !visited[i][j])
        {
          visited[i][j] = true;
          solution(i, j, h);
        }
      }
    }

    if (result > answer)
      answer = result;
  }

  cout << answer << endl;
}
