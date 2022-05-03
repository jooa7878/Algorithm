#include <iostream>
#include <algorithm>

#define endl '\n';

using namespace std;

int N;
string str;

void solution()
{
  for (int i = str.length() - 1; i > 0; i--)
  {
    if (str[i] > str[i - 1])
    {
      int num = str[i];
      int idx = i;
      for (int j = i; j < str.length(); j++)
      {
        if (str[j] < num && str[j] > str[i - 1])
        {
          num = str[j];
          idx = j;
        }
      }

      str[idx] = str[i - 1];
      str[i - 1] = num;
      sort(str.begin() + i, str.end());
      cout << str << endl;
      return;
    }
  }

  cout << "BIGGEST\n";
}

int main()
{
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> N;

  for (int i = 0; i < N; i++)
  {
    cin >> str;
    solution();
  }
}
