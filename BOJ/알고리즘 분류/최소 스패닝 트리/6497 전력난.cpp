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

int N, M, answer, sum;
vector< pair<int,int> > vec[200001];
bool visited[200001];

void solution()
{
    int cost = 0;
    priority_queue<pair<int, int>, vector< pair<int,int> >, greater< pair<int,int> > > pq;

    for(int i=0; i<vec[0].size(); i++)
    {
        int nDistance = vec[0][i].first;
        int nNode = vec[0][i].second;

        pq.push(make_pair(nDistance, nNode));
    }

    visited[0] = true;

    while(!pq.empty())
    {
        int distance = pq.top().first;
        int node = pq.top().second;

        pq.pop();
        if(visited[node]) continue;
        visited[node] = true;
        cost += distance;

        for(int i=0; i<vec[node].size(); i++)
        {
            int nDistance = vec[node][i].first;
            int nNode = vec[node][i].second;

            if(!visited[nNode]) pq.push(make_pair(nDistance, nNode));
        }
    }

    answer = sum - cost;
    cout << answer << endl; 
}

void clear()
{
    answer = 0;
    sum = 0;
    for(int i=0; i<M; i++) 
    {
        vec[i].clear();
        visited[i] = false;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(true)
    {
        cin >> M >> N;

        clear();

        if(M == 0 && N == 0) break;

        for(int i=0; i<N; i++)
        {
            int from, to, weight;
            cin >> from >> to >> weight;
            sum += weight;
            vec[from].push_back(make_pair(weight, to));
            vec[to].push_back(make_pair(weight, from));
        }

        solution();
    }

    
}
