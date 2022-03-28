#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>

#define endl '\n';

using namespace std;

const int MAX = 2147483647;

int N, T;

void solution()
{
  cin >> N;
  multiset<int> ms;

  for (int i = 0; i < N; i++)
  {
    char inst;
    int num;
    cin >> inst >> num;
    if (inst == 'I')
    {
      ms.insert(num);
    }
    if (inst == 'D')
    {
      if (!ms.empty())
      {
        if (num == -1)
        {
          ms.erase(ms.begin());
        }
        else
        {
          ms.erase(--ms.end());
        }
      }
    }
  }

  if (ms.empty())
  {
    cout << "EMPTY" << endl;
  }
  else
  {
    cout << *(--ms.end()) << ' ' << *(ms.begin()) << endl;
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
    solution();
  }
}
