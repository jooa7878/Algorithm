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

int N;
int set[101];
vector<pair<double, double>> vec;
vector<pair<double, pair<double, double>>> dist;
double answer;

int getSet(int x)
{
	if (set[x] == x) return x;
	return set[x] = getSet(set[x]);
}

void unionSet(int a, int b)
{
	a = getSet(a);
	b = getSet(b);

	if (a < b) set[b] = a;
	else set[a] = b;
}

int find(int a, int b)
{
	a = getSet(a);
	b = getSet(b);
	if (a == b) return 1;
	return 0;
}

void solution()
{
	sort(dist.begin(), dist.end());
		
	for (int i = 0; i < dist.size(); i++)
	{
		if (!find(dist[i].second.first, dist[i].second.second))
		{
			answer += dist[i].first;
			unionSet(dist[i].second.first, dist[i].second.second);
		}
	}
	
	cout << fixed;
	cout.precision(2);
	cout << answer << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		double x, y;
		cin >> x >> y;

		vec.push_back({ x,y });
	}

	for (int i = 0; i < N; i++)
	{
		double fromX = vec[i].first;
		double fromY = vec[i].second;
		for (int j = i + 1; j < N; j++)
		{
			double toX = vec[j].first;
			double toY = vec[j].second;

			double distance = sqrt(pow(fromX - toX, 2) + pow(fromY - toY, 2));
			dist.push_back({ distance, {i+1, j+1 } });
		}
	}

	for (int i = 1; i <= N; i++)
	{
		set[i] = i;
	}

	solution();
}
