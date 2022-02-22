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

int N, B, C;
ll arr[1000000];
ll answer;

void solution()
{
    for (int i = 0; i < N; i++)
    {
        if (arr[i] >= B)
        {
            answer++;
            arr[i] -= B;
            answer += arr[i] % C == 0 ? arr[i] / C : (arr[i] / C) + 1;
        }
        else
        {
            answer++;
        }
    }

    cout << answer << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    cin >> B >> C;

    solution();
}
