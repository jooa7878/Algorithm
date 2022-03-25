#include <iostream>
#include <vector>
#include <unordered_map>

#define endl '\n';
#define ll long long;

using namespace std;

int N, M, answer, space;
int arr[9][9];
int temp[9][9];

vector<pair<int, int> > vec;

void solution(int yIdx, int xIdx, int sharp, int map[9][9]);

int up(int y, int x, int sharp, int map[9][9])
{
  int res = sharp;
  while (y > 0)
  {
    if (map[y - 1][x] == 6)
      break;
    if (map[y - 1][x] == 0)
    {
      res++;
      map[y - 1][x] = -1;
    }

    y--;
  }

  return res;
}

int down(int y, int x, int sharp, int map[9][9])
{
  int res = sharp;
  while (y < N - 1)
  {
    if (map[y + 1][x] == 6)
      break;
    if (map[y + 1][x] == 0)
    {
      res++;
      map[y + 1][x] = -1;
    }

    y++;
  }
  return res;
}

int left(int y, int x, int sharp, int map[9][9])
{
  int res = sharp;
  while (x > 0)
  {
    if (map[y][x - 1] == 6)
      break;
    if (map[y][x - 1] == 0)
    {
      res++;
      map[y][x - 1] = -1;
    }

    x--;
  }

  return res;
}

int right(int y, int x, int sharp, int map[9][9])
{
  int res = sharp;
  while (x < M - 1)
  {
    if (map[y][x + 1] == 6)
      break;
    if (map[y][x + 1] == 0)
    {
      res++;
      map[y][x + 1] = -1;
    }

    x++;
  }
  return res;
}

void cpyArr(int src[9][9], int dest[9][9])
{
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      dest[i][j] = src[i][j];
    }
  }
}

int getZero(int tmp[9][9])
{
  int cnt = 0;
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      if (tmp[i][j] == 0)
        cnt++;
    }
  }

  return cnt;
}

void dfs(int idx, int sharp, int src[9][9])
{
  if (idx == vec.size())
    return;
  int temp_sharp = sharp;
  int cctv = arr[vec[idx].first][vec[idx].second];
  int before[9][9];

  cpyArr(src, before);
  cpyArr(src, temp);

  if (cctv == 1)
  {
    temp_sharp = up(vec[idx].first, vec[idx].second, sharp, temp);
    int test = getZero(temp);
    if (answer > test)
      answer = test;
    dfs(idx + 1, temp_sharp, temp);

    temp_sharp = sharp;
    cpyArr(before, temp);
    temp_sharp = down(vec[idx].first, vec[idx].second, sharp, temp);
    test = getZero(temp);
    if (answer > test)
      answer = test;
    dfs(idx + 1, temp_sharp, temp);

    temp_sharp = sharp;
    cpyArr(before, temp);
    temp_sharp = left(vec[idx].first, vec[idx].second, sharp, temp);
    test = getZero(temp);
    if (answer > test)
      answer = test;
    dfs(idx + 1, temp_sharp, temp);

    temp_sharp = sharp;
    cpyArr(before, temp);
    temp_sharp = right(vec[idx].first, vec[idx].second, sharp, temp);
    test = getZero(temp);
    if (answer > test)
      answer = test;
    dfs(idx + 1, temp_sharp, temp);

    cpyArr(before, temp);
  }
  else if (cctv == 2)
  {
    temp_sharp = up(vec[idx].first, vec[idx].second, sharp, temp);
    temp_sharp = down(vec[idx].first, vec[idx].second, temp_sharp, temp);
    int test = getZero(temp);
    if (answer > test)
      answer = test;
    dfs(idx + 1, temp_sharp, temp);

    temp_sharp = sharp;
    cpyArr(before, temp);
    temp_sharp = left(vec[idx].first, vec[idx].second, sharp, temp);
    temp_sharp = right(vec[idx].first, vec[idx].second, temp_sharp, temp);
    test = getZero(temp);
    if (answer > test)
      answer = test;
    dfs(idx + 1, temp_sharp, temp);

    cpyArr(before, temp);
  }
  else if (cctv == 3)
  {
    temp_sharp = up(vec[idx].first, vec[idx].second, sharp, temp);
    temp_sharp = right(vec[idx].first, vec[idx].second, temp_sharp, temp);
    int test = getZero(temp);
    if (answer > test)
      answer = test;
    dfs(idx + 1, temp_sharp, temp);

    temp_sharp = sharp;
    cpyArr(before, temp);
    temp_sharp = up(vec[idx].first, vec[idx].second, sharp, temp);
    temp_sharp = left(vec[idx].first, vec[idx].second, temp_sharp, temp);
    test = getZero(temp);
    if (answer > test)
      answer = test;
    dfs(idx + 1, temp_sharp, temp);

    temp_sharp = sharp;
    cpyArr(before, temp);
    temp_sharp = down(vec[idx].first, vec[idx].second, sharp, temp);
    temp_sharp = left(vec[idx].first, vec[idx].second, temp_sharp, temp);
    test = getZero(temp);
    if (answer > test)
      answer = test;
    dfs(idx + 1, temp_sharp, temp);

    temp_sharp = sharp;
    cpyArr(before, temp);
    temp_sharp = down(vec[idx].first, vec[idx].second, sharp, temp);
    temp_sharp = right(vec[idx].first, vec[idx].second, temp_sharp, temp);
    test = getZero(temp);
    if (answer > test)
      answer = test;
    dfs(idx + 1, temp_sharp, temp);

    cpyArr(before, temp);
  }
  else if (cctv == 4)
  {
    temp_sharp = up(vec[idx].first, vec[idx].second, sharp, temp);
    temp_sharp = left(vec[idx].first, vec[idx].second, temp_sharp, temp);
    temp_sharp = right(vec[idx].first, vec[idx].second, temp_sharp, temp);
    int test = getZero(temp);
    if (answer > test)
      answer = test;
    dfs(idx + 1, temp_sharp, temp);

    temp_sharp = sharp;
    cpyArr(before, temp);
    temp_sharp = down(vec[idx].first, vec[idx].second, sharp, temp);
    temp_sharp = left(vec[idx].first, vec[idx].second, temp_sharp, temp);
    temp_sharp = right(vec[idx].first, vec[idx].second, temp_sharp, temp);
    test = getZero(temp);
    if (answer > test)
      answer = test;
    dfs(idx + 1, temp_sharp, temp);

    temp_sharp = sharp;
    cpyArr(before, temp);
    temp_sharp = up(vec[idx].first, vec[idx].second, sharp, temp);
    temp_sharp = down(vec[idx].first, vec[idx].second, temp_sharp, temp);
    temp_sharp = right(vec[idx].first, vec[idx].second, temp_sharp, temp);
    test = getZero(temp);
    if (answer > test)
      answer = test;
    dfs(idx + 1, temp_sharp, temp);

    temp_sharp = sharp;
    cpyArr(before, temp);
    temp_sharp = up(vec[idx].first, vec[idx].second, sharp, temp);
    temp_sharp = down(vec[idx].first, vec[idx].second, temp_sharp, temp);
    temp_sharp = left(vec[idx].first, vec[idx].second, temp_sharp, temp);
    test = getZero(temp);
    if (answer > test)
      answer = test;
    dfs(idx + 1, temp_sharp, temp);

    cpyArr(before, temp);
  }
  else if (cctv == 5)
  {
    temp_sharp = up(vec[idx].first, vec[idx].second, sharp, temp);
    temp_sharp = down(vec[idx].first, vec[idx].second, temp_sharp, temp);
    temp_sharp = left(vec[idx].first, vec[idx].second, temp_sharp, temp);
    temp_sharp = right(vec[idx].first, vec[idx].second, temp_sharp, temp);

    int test = getZero(temp);

    if (answer > test)
      answer = test;
    dfs(idx + 1, temp_sharp, temp);
    cpyArr(before, temp);
  }
}

void solution(int yIdx, int xIdx, int sharp, int map[9][9])
{
  dfs(0, sharp, map);
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
      if (arr[i][j] != 0 && arr[i][j] != 6)
        vec.push_back({i, j});
      if (arr[i][j] == 0)
        space++;
    }
  }

  answer = space;
  solution(0, 0, 0, arr);

  cout << answer << endl;
}
