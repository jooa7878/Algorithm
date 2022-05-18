#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define endl '\n';

int N, M, R;
vector<int> adj[100001];
int visited[100001];
int cnt = 2;

void solution(int node)
{
    for (int i = 0; i < adj[node].size(); i++)
    {
        if (visited[adj[node][i]] == 0)
        {
            visited[adj[node][i]] = cnt++;
            solution(adj[node][i]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> N >> M >> R;

    for (int i = 0; i < M; i++)
    {
        int from, to;
        cin >> from >> to;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }

    for (int i = 1; i <= N; i++)
    {
        sort(adj[i].begin(), adj[i].end());
    }

    visited[R] = 1;
    solution(R);

    for (int i = 1; i <= N; i++)
    {
        cout << visited[i] << endl;
    }
}
