#include <iostream>
#include <algorithm>

#define endl '\n';

using namespace std;

int answer;
string str;

void solution()
{
  sort(str.begin(), str.end(), greater<int>());

  for (int i = 0; i < str.length(); i++)
  {
    answer += str[i] - '0';
  }

  if (answer % 3 == 0 && str.back() == '0')
  {
    cout << str << endl;
  }
  else
    cout << -1 << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> str;

  solution();
}
