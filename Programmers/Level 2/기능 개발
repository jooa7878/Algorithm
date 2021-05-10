#include <string>
#include <vector> 

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> flag;
    int rep = 0;
    int key = 1;
    
    for(int i=0; i<progresses.size(); i++){
        while(progresses[i] < 100) {
            progresses[i] += speeds[i];            
            rep++;
        }
        flag.push_back(rep);
        rep=0;
    }   
    
    for(int i=0; i<flag.size(); i++){
        int j = i+1;
        while(j < flag.size() && flag[i] >= flag[j]){
            key++;
            j++;
        }
        answer.push_back(key);
        key=1;
        i=j-1;
    }
    
    
    
    
    return answer;
}
