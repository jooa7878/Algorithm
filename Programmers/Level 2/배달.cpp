#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int nodes[51][51];
int visited[51];
bool checked[51];

int solution(int N, vector<vector<int>> road, int K) {
	int answer = 0;
	queue<pair<int, int>> q;
    
    for(int i=2; i<=N; i++)
    {
        visited[i] = 500001;
    }

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			nodes[i][j] = 500001;
			nodes[j][i] = 500001;
		
		}
	}

	for (int i = 0; i < road.size(); i++)
	{
		int from = road[i][0];
		int to = road[i][1];
		int weight = road[i][2];
		
		if(nodes[from][to] > weight)
			nodes[from][to] = weight;
		if(nodes[to][from] > weight)
			nodes[to][from] = weight;
	}

	q.push(make_pair(1, 0));
	visited[1] = 0;
    checked[1] = true;

	while (!q.empty())
	{
		int city = q.front().first;
		int dist = q.front().second;

		q.pop();

		for (int i = 1; i <= N; i++)
		{
			if (city != i && nodes[city][i] + dist <= K && visited[i] >= nodes[city][i] + dist&& nodes[city][i] != 500001) 
			{
				visited[i] = nodes[city][i] + dist;
				q.push(make_pair(i, dist + nodes[city][i]));
        if(!checked[i]) 
        {
            checked[i] = true;
            answer++;
        }
			}
		}
	}

	return answer == 0 ? 0 : answer + 1;

}
