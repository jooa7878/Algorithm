#include <string>
#include <vector>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int sum = 1;
    int check = 0;
    
    while(1){
        for(int i=0; i<citations.size(); i++){
            if(citations[i] >= sum)
                 check++;
        }
        if (sum == check)
            break;
        
        else if(sum <= check){
            answer = sum;
        }
        else{
            sum++;
            check = 0;
        }
    }    
    answer = sum;
    return answer;
}
