#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>

#define endl '\n';

using namespace std;

int T, answer[3];
int A = 300, B = 60, C = 10;

void solution()
{

  if (T >= A)
  {
    answer[0] = T / A;
    T %= A;
  }

  if (T >= B)
  {
    answer[1] = T / B;
    T %= B;
  }

  if (T >= C)
  {
    answer[2] = T / C;
    T %= C;
  }

  if (T > 0)
  {
    cout << -1 << endl;
  }
  else
  {
    cout << answer[0] << ' ' << answer[1] << ' ' << answer[2] << endl;
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> T;

  solution();
}
