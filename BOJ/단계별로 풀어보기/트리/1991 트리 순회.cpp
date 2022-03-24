#include <iostream>
#include <vector>
#include <unordered_map>

#define endl '\n';
#define ll long long;

using namespace std;

int N;
unordered_map<char, pair<char, char> > hs;

void preorder(char node)
{
  cout << node;

  if (hs[node].first != '.')
  {
    preorder(hs[node].first);
  }
  if (hs[node].second != '.')
  {
    preorder(hs[node].second);
  }
}

void inorder(char node)
{
  if (hs[node].first != '.')
  {
    inorder(hs[node].first);
  }
  cout << node;

  if (hs[node].second != '.')
  {
    inorder(hs[node].second);
  }
}

void postorder(char node)
{
  if (hs[node].first != '.')
  {
    postorder(hs[node].first);
  }

  if (hs[node].second != '.')
  {
    postorder(hs[node].second);
  }
  cout << node;
}

void solution()
{
  preorder('A');
  cout << endl;
  inorder('A');
  cout << endl;
  postorder('A');
  cout << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> N;

  for (int i = 0; i < N; i++)
  {
    char node, child_1, child_2;

    cin >> node >> child_1 >> child_2;

    hs[node].first = child_1;
    hs[node].second = child_2;
  }

  solution();
}
