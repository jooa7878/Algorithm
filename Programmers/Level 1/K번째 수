#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    
    for(int i=0; i<commands.size(); i++){
            vector<int> example;
            int a = commands[i][0];
            int b = commands[i][1];
            int c = commands[i][2];
        for(int j = a-1; j<b; j++){
            example.push_back(array[j]);
        }
        sort(example.begin(), example.end());
        answer.push_back(example[c-1]);
        
    }
    return answer;
}
