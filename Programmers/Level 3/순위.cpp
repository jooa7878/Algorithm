#include <iostream>
#include <string>
#include <vector>

using namespace std;



int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    int arr[101][101];
    
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            arr[i][j] = 1000;
        }
    }
    
    for(int i=0; i<results.size(); i++)
    {
        arr[results[i][0]][results[i][1]] = 1;
    }
    
    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(arr[i][k] == 1 && arr[k][j] == 1) arr[i][j] = 1;           
            }
        }
    }
    
    for(int i=1; i<=n; i++)
    {
        int cnt = 0;
        for(int j=1; j<=n; j++)
        {
            if(i != j && arr[i][j] == 1 || arr[j][i] == 1) cnt++;
        }
        if(n - 1 == cnt) answer++;        
    }

    return answer;
}
