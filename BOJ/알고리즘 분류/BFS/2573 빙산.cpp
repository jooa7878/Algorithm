#include <iostream>
#include <queue>

#define endl '\n';
#define ll long long;

using namespace std;

int N, M, answer, part;
int arr[301][301];
int next_arr[301][301];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool visited[301][301];

void melt(int y, int x)
{
  int num = arr[y][x];
  int cnt = 0;

  for (int i = 0; i < 4; i++)
  {
    int ny = y + dy[i];
    int nx = x + dx[i];

    if (ny >= 0 && nx >= 0 && ny < N && nx < M && arr[ny][nx] == 0)
      cnt++;
  }

  num = num > cnt ? num - cnt : 0;
  next_arr[y][x] = num;
}

void solution(int y, int x)
{
  part++;
  queue<pair<int, int> > q;

  visited[y][x] = true;

  q.push({y, x});

  while (!q.empty())
  {
    int y = q.front().first;
    int x = q.front().second;

    q.pop();

    for (int i = 0; i < 4; i++)
    {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (nx >= 0 && ny >= 0 && ny < N && nx < M && !visited[ny][nx] && arr[ny][nx] != 0)
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
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> N >> M;

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      cin >> arr[i][j];
    }
  }

  while (true)
  {
    part = 0;
    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < M; j++)
      {
        if (arr[i][j] != 0 && !visited[i][j])
          solution(i, j);
      }
    }

    if (part != 1)
    {
      cout << answer << endl;
      return 0;
    }

    for (int i = 0; i < N; i++)
      for (int j = 0; j < M; j++)
        visited[i][j] = false;

    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < M; j++)
      {
        if (arr[i][j] != 0)
          melt(i, j);
      }
    }

    bool flag = true;

    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < M; j++)
      {
        arr[i][j] = next_arr[i][j];
        if (arr[i][j] != 0)
          flag = false;
      }
    }

    if (flag)
    {
      cout << 0 << endl;
      return 0;
    }
    answer++;
  }
}
