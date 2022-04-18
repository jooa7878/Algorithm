#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    int answer = 0;
    char arr[8] = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};

    do{
        bool flag = true;
        
        for(int i=0; i<data.size(); i++)
        {
            char first = data[i][0];
            char second = data[i][2];
            char condition = data[i][3];
            int distance = data[i][4] - '0';
            
            int first_idx, second_idx;
            
            for(int i=0; i<8; i++)
            {
                if(first == arr[i]) first_idx = i;
                if(second == arr[i]) second_idx = i;
            }
            
            if(condition == '=')
            {
                if(abs(first_idx-second_idx) -1 == distance) continue;
                flag = false;
            }
            else if(condition == '>')
            {
                if(abs(first_idx - second_idx) - 1 > distance) continue;
                flag = false;
            }
            else  
            {
                if(abs(first_idx - second_idx) - 1  < distance) continue;
                flag = false;
            }
            
            if(!flag) break;
        }

        if(flag) answer++;
    }while(next_permutation(arr, arr+8));
    
    return answer;
}
