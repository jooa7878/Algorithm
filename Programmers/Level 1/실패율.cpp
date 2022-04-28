#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

bool cmp(pair<int, double> &a, pair<int, double> &b){
    if( a.second == b.second) {
        return a.first < b.first;
    }
    
    return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<int> vec;
    vector<pair<int, double>> v; // {스테이지, 실패율} 쌍 벡터
    
    for(int i=0; i<N; i++){
        vec.push_back(0);
        v.push_back({0,0});
    }
    
    for(int i=0; i<stages.size(); i++)        {
        vec[stages[i]-1]++;
    }
    
    for(int i=0; i<v.size(); i++){
        int sum = 0;
        for(int j=0; j<i; j++){
            sum += vec[j];    
        }
        v[i].first = i+1;
        if( stages.size() > sum){
            v[i].second = (double)vec[i] / (stages.size() - sum);
        }
        else{
            v[i].second = 0;    
        }
    }
    
    sort(v.begin(), v.end(), cmp);
    
    for(int i=0; i<N; i++){
        answer.push_back(v[i].first);
    }
    
    return answer;
}
