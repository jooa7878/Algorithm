#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>

#define endl '\n'
#define ll long long

using namespace std;

int F, S, U, G, D;
bool visited[1000001];

void solution()
{
  queue<pair<int, int> > q;

  q.push({S, 0});
  visited[S] = true;

  while (!q.empty())
  {
    int pos = q.front().first;
    int cnt = q.front().second;

    q.pop();

    if (pos == G)
    {
      cout << cnt << endl;
      return;
    }

    if (pos + U <= F && !visited[pos + U])
    {
      visited[pos + U] = true;
      q.push({pos + U, cnt + 1});
    }

    if (pos - D > 0 && !visited[pos - D])
    {
      visited[pos - D] = true;
      q.push({pos - D, cnt + 1});
    }
  }

  // if impossible, print "use the stairs"
  cout << "use the stairs" << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> F >> S >> G >> U >> D;

  solution();
}
