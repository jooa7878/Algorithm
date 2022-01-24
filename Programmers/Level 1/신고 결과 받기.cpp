#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    unordered_map<string, vector<string>> hs;
    unordered_map<string, int> info;
    
    for(int i=0; i<report.size(); i++)
    {
        stringstream ss(report[i]);
        string from, to;
        ss >> from >> to;
        if(find(hs[from].begin(), hs[from].end(), to) == hs[from].end()) hs[from].push_back(to);
    }
    
    for(int i=0; i<id_list.size(); i++)
    {
        for(auto a : hs[id_list[i]])
        {
            info[a]++;
        }
    }
    
    for(int i=0; i<id_list.size(); i++)
    {
        int ans = 0;
        for(auto a : hs[id_list[i]])
        {
            if(info[a] >= k) ans++;
        }
        answer.push_back(ans);
    }
    return answer;
}
