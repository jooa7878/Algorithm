#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define endl '\n';

int N, M, R;
vector<int> adj[100001];
int visited[100001];
int cnt = 1;

void solution(int node)
{
    queue<int> q;

    q.push(node);

    while (!q.empty())
    {
        int next = q.front();

        q.pop();

        for (int i = 0; i < adj[next].size(); i++)
        {
            int nn = adj[next][i];
            if (!visited[nn])
            {
                visited[nn] = cnt++;
                q.push(nn);
            }
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

    visited[R] = cnt++;
    solution(R);

    for (int i = 1; i <= N; i++)
    {
        cout << visited[i] << endl;
    }
}
