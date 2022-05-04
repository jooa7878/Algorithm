#include <string>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int cost[26][26];
typedef pair<pair<int, int>, pair<int, int>> pp;

int solution(vector<vector<int>> board) {
    int answer = 987654321;
    
    priority_queue<pp, vector<pp>, greater<pp>> pq;
    
    for(int i=0; i<board.size(); i++)
    {
        for(int j=0; j<board.size(); j++)
        {
            cost[i][j] = 987654321;
        }
    }
    
    cost[0][0] = 0;
    
    pq.push({{0,0},  {0, -1}});
    
    
    while(!pq.empty())
    {
        auto item = pq.top();
        int y = item.first.first;
        int x = item.first.second;
        int pay = item.second.first;
        int dir = item.second.second;
        pq.pop();
        if( y == board.size() -1 && x == board.size() -1)
        {
            return pay;
        }
    
        for(int i=0; i<4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if(nx >= 0 && ny >= 0 && nx < board.size() && ny < board.size() && !board[ny][nx])
            {
                int nPay = pay;
                if(dir == -1 || dir == i) nPay += 100;
                else nPay += 600;
                
                if(cost[ny][nx] >= nPay)
                {
                    cost[ny][nx] = nPay;
                    pq.push({{ny, nx}, {nPay, i}});
                }
                
            }
        }
    
    }
    
    return answer;
}
