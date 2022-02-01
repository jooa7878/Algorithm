#include <string>
#include <vector>

using namespace std;

int dp[100001];
int mod = 1000000007;

int solution(int n, vector<int> money) {
    int answer = 0;

    dp[0] = 1;
    
    for(int i=1; i<=money.size(); i++)
    {   
        for(int j=money[i-1]; j<=n; j++)
        {
            dp[j] = (dp[j] + dp[j-money[i-1]]) %mod;
        }
    }
    
    answer = dp[n] % mod;
    
    return answer;
}
