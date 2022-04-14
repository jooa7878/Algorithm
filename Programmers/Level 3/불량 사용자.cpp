#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int answer = 0;
set<string> s;
bool visited[9];

void dfs(int depth, vector<string> user_id, vector<string> banned_id, string str) {

	if (depth == banned_id.size())
	{
        vector<string> vec;
        string cpy = str;
        sort(cpy.begin(), cpy.end());
		if (s.find(cpy) == s.end())
		{   
            for(int i=0; i<str.length(); i++)
            {
                string tmp = user_id[str[i]-'0'];
                
                if(tmp.length() != banned_id[i].length()) return;
                for(int j=0; j<tmp.length(); j++)
                {
                    if(tmp[j] != banned_id[i][j] && banned_id[i][j] != '*') return;
                }
            }
            answer++;
            sort(str.begin(), str.end());
			s.insert(str);
		}
        
		return;
	}

	for (int i = 0; i < user_id.size(); i++)
	{
		if (!visited[i])
		{
			visited[i] = true;
			dfs(depth + 1, user_id, banned_id, str + to_string(i));
			visited[i] = false;
		}

	}	
}

int solution(vector<string> user_id, vector<string> banned_id) 
{
    dfs(0, user_id, banned_id, "");
    return answer;
}
