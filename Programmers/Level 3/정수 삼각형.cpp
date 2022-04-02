#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int arr[501][501] = { 0, };
    int N= triangle.size();
    
    
    
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j < i + 1; j++)
		{
			arr[i][j] = max(arr[i - 1][j], arr[i - 1][j-1]) + triangle[i-1][j-1];
            if(arr[i][j] > answer ) answer = arr[i][j];
		}
	}


    return answer;
}
