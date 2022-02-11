#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define endl '\n'
#define ll long long 

int N, M, from, to;
vector<pair<int, int>> vec;
vector<pair<double, pair<int,int>>> dist;;
double answer;
int parents[1001];

int getParents(int node)
{
    if(parents[node] == node) return node;
    return parents[node] = getParents(parents[node]);
}

void unionParents(int a, int b)
{
    a = getParents(a);
    b = getParents(b);
    if(a > b) parents[a] = b;
    else parents[b] = a;
}

int find(int a, int b)
{
    if(getParents(a) == getParents(b)) return 0;
    return 1;
}

void solution()
{
   
    for (int i = 0; i < N; i++)
    {
        int fromX = vec[i].first;
        int fromY = vec[i].second;
        for (int j = i + 1; j < N; j++)
        {
            int toX = vec[j].first;
            int toY = vec[j].second;

            double distance = sqrt(pow(fromX - toX, 2) + pow(fromY - toY, 2));
            dist.push_back({ distance, {i+1,j+1} });
        }
    }
    
    sort(dist.begin(), dist.end());

    for(int i=0; i<dist.size(); i++)
    {
        if(find(dist[i].second.first, dist[i].second.second))
        {
            answer += dist[i].first;
            unionParents(dist[i].second.first, dist[i].second.second);
        }
    }
   
    cout <<fixed;
    cout.precision(2);
    cout << answer << endl;   
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   
   cin >> N >> M;

   for(int i=1; i<=N; i++) parents[i] = i;

   for (int i = 0; i < N; i++)
   {
      int x, y;
      cin >> x >> y;

      vec.push_back({ x,y });
   }      
   

   for (int i = 0; i < M; i++)
   {
        cin >> from >> to;
        unionParents(from, to);
   }

   solution();
}
