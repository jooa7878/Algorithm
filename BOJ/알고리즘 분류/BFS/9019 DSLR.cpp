#include <iostream>
#include <queue>
#include <algorithm>
#include <unordered_map>

#define endl '\n';

using namespace std;

int T, N, answer, src, target;
int arr[501][501];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void solution()
{
  queue<pair<int, string> > q;

  bool visited[10000] = {
      false,
  };

  q.push({src, ""});

  visited[src] = true;
  while (!q.empty())
  {
    int num = q.front().first;
    string str = q.front().second;

    if (num == target)
    {
      cout << str << endl;
      while (!q.empty())
        q.pop();
      return;
    }

    q.pop();

    if (!visited[(num * 2) % 10000])
    {
      q.push({(num * 2) % 10000, str + "D"});
      visited[(num * 2) % 10000] = true;
    }

    if (!visited[(num == 0 ? 9999 : num - 1)])
    {
      q.push({num == 0 ? 9999 : num - 1, str + "S"});
      visited[num == 0 ? 9999 : num - 1] = true;
    }

    if (num >= 1000)
    {
      if (!visited[(num - ((num / 1000) * 1000)) * 10 + (num / 1000)])
      {
        q.push({(num - ((num / 1000) * 1000)) * 10 + (num / 1000), str + "L"});
        visited[(num - ((num / 1000) * 1000)) * 10 + (num / 1000)] = true;
      }

      if (!visited[(num / 10) + ((num % 10) * 1000)])
      {
        q.push({(num / 10) + ((num % 10) * 1000), str + "R"});
        visited[(num / 10) + ((num % 10) * 1000)] = true;
      }
    }
    else if (num >= 100)
    {
      if (!visited[num * 10])
      {
        q.push({num * 10, str + "L"});
        visited[num * 10] = true;
      }

      if (!visited[(num / 10) + ((num % 10) * 1000)])
      {
        q.push({(num / 10) + ((num % 10) * 1000), str + "R"});
        visited[(num / 10) + ((num % 10) * 1000)] = true;
      }
    }
    else if (num >= 10)
    {
      if (!visited[num * 10])
      {
        q.push({num * 10, str + "L"});
        visited[num * 10] = true;
      }

      if (!visited[(num / 10) + ((num % 10) * 1000)])
      {
        q.push({(num / 10) + ((num % 10) * 1000), str + "R"});
        visited[(num / 10) + ((num % 10) * 1000)] = true;
      }
    }
    else
    {
      if (!visited[num * 10])
      {
        q.push({num * 10, str + "L"});
        visited[num * 10] = true;
      }

      if (!visited[(num / 10) + ((num % 10) * 1000)])
      {
        q.push({(num / 10) + ((num % 10) * 1000), str + "R"});
        visited[(num / 10) + ((num % 10) * 1000)] = true;
      }
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> T;

  for (int i = 0; i < T; i++)
  {
    cin >> src >> target;

    solution();
  }
}
