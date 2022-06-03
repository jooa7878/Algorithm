#include <iostream>
#include <string>
#include <vector>
#include <queue>


using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0,0,-1,1};

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    queue<pair<int, int>> q;
    
    for(int i=0; i<places.size(); i++)
    {
        int arr[5][5] = {0, };

        for(int j=0; j<5; j++)
        {
            for(int k=0; k<5; k++)
            {
                if(places[i][j].at(k) == 'P') arr[j][k] = 1;
                else if (places[i][j].at(k) == 'O') arr[j][k] = 0;
                else arr[j][k] = -1;
            }
        }
        
        bool flag = true;
        for(int idx = 0; idx < 5; idx++)
        {
            for(int jdx =0; jdx < 5; jdx++)
            {
                if(arr[idx][jdx] == 1)
                {
                    if(arr[idx+1][jdx] == 1 && idx < 4 || arr[idx][jdx+1] == 1  && jdx < 4)
                    {
                        flag = false;
                        break;
                    }
                    else if ( arr[idx+2][jdx] == 1 && arr[idx+1][jdx] == 0 && idx < 3 ||
                              arr[idx][jdx+2] == 1 && arr[idx][jdx+1] == 0 && jdx < 3)
                    {
                        flag = false;
                        break;
                    }
                    else if ( arr[idx+1][jdx+1] == 1 && idx < 4 && jdx < 4 && arr[idx+1][jdx] == 0 || 
                              arr[idx+1][jdx+1] == 1 && idx < 4 && jdx < 4 && arr[idx][jdx+1] == 0)
                    {
                        flag = false;
                        break;
                    }
                    else if ( arr[idx-1][jdx+1] == 1 && idx > 0 && jdx < 4 && arr[idx-1][jdx] == 0 || 
                              arr[idx-1][jdx+1] == 1 && idx > 0 && jdx < 4 && arr[idx][jdx+1] == 0)
                    {
                        flag = false;
                        break;
                    }
                }
            }
            if(!flag) break;
        }
        flag ? answer.push_back(1) : answer.push_back(0);
    }
    
    return answer;
}
