#include <string>
#include <vector>

using namespace std;

int answer =0;
int N;
int arr[9];

bool check(int node){
    for(int i=0; i<node; i++)
    {
        if(arr[i] == arr[node] || abs(arr[node]-arr[i]) == node-i) return false;
    }
    
    return true;
}

void dfs(int depth){
    if(depth == N)
        answer++;
    else
    {
        for(int i=0; i<N; i++)
        {
            arr[depth] = i;
            if(check(depth))
                dfs(depth+1);
            
        }
    }
    
}

int solution(int n) {
    N = n;
    dfs(0);
    return answer;
}
