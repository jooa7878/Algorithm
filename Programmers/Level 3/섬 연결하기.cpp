#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int parent[101];

int getParent(int node){
    if( node == parent[node]) return node;
    
    return parent[node] = getParent(parent[node]);
}

bool cmp(vector<int>& a, vector<int>& b){
    return a[2] < b[2];
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    for(int i=0; i<n; i++)
    {
        parent[i] = i;
    }
    
    sort(costs.begin(), costs.end(), cmp);
    
    
    for(int i=0; i<costs.size(); i++)
    {
        int start_node = getParent(costs[i][0]);  
        int end_node = getParent(costs[i][1]);
        int cost = costs[i][2];
        
        if(start_node != end_node)
        {
            answer += cost;
            parent[end_node] = start_node;
        }
    }
    
    return answer;
}
