#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <sstream>
#include <cmath>

#define endl '\n';

using namespace std;

const int MAX = 2147483647;

int N, M, answer;
int arr[9][9];
bool visited[9][9];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int bfs(int y, int x)
{
  int res = 1;
  visited[y][x] = true;
  bool flag = true;
  queue<pair<int, int> > q;
  q.push({y, x});

  while (!q.empty())
  {
    int yy = q.front().first;
    int xx = q.front().second;

    q.pop();

    for (int i = 0; i < 4; i++)
    {
      int ny = yy + dy[i];
      int nx = xx + dx[i];
      if (ny >= 0 && nx >= 0 && ny < N && nx < M && !visited[ny][nx])
      {
        if (arr[ny][nx] == 2)
        {
          flag = false;
        }

        if (arr[ny][nx] == 0)
        {
          visited[ny][nx] = true;
          res++;
          q.push({ny, nx});
        }
      }
    }
  }

  if (flag)
    return res;
  return 0;
}

void solution()
{

  for (int i_1 = 0; i_1 < N; i_1++)
  {
    for (int j_1 = 0; j_1 < M; j_1++)
    {

      for (int i_2 = 0; i_2 < N; i_2++)
      {
        for (int j_2 = 0; j_2 < M; j_2++)
        {
          for (int i_3 = 0; i_3 < N; i_3++)
          {
            for (int j_3 = 0; j_3 < M; j_3++)
            {
              if (i_1 == i_2 && j_1 == j_2 ||
                  i_1 == i_3 && j_1 == j_3 ||
                  i_2 == i_3 && j_2 == j_3)
              {
                continue;
              }

              if (arr[i_1][j_1] == 0 && arr[i_2][j_2] == 0 && arr[i_3][j_3] == 0)
              {
                arr[i_1][j_1] = 1;
                arr[i_2][j_2] = 1;
                arr[i_3][j_3] = 1;
                int result = 0;
                for (int i = 0; i < N; i++)
                {
                  for (int j = 0; j < M; j++)
                  {
                    visited[i][j] = false;
                  }
                }

                for (int i = 0; i < N; i++)
                {
                  for (int j = 0; j < M; j++)
                  {
                    if (!visited[i][j] && arr[i][j] == 0)
                    {
                      result += bfs(i, j);
                    }
                  }
                }
                if (result > answer)
                  answer = result;
                arr[i_1][j_1] = 0;
                arr[i_2][j_2] = 0;
                arr[i_3][j_3] = 0;
              }
            }
          }
        }
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

  solution();

  cout << answer << endl;
}
