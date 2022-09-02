#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// 1 = 매우 비동의,  7 = 매우 동의
string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    unordered_map<char, int> hs;
    
    hs['R'] = 0;
    hs['T'] = 0;
    hs['F'] = 0;
    hs['C'] = 0;
    hs['M'] = 0;
    hs['J'] = 0;
    hs['A'] = 0;
    hs['N'] = 0;
    
    for(int i=0; i<survey.size(); i++)
    {
        
        choices[i] < 4 ? hs[survey[i][0]] += abs(4 - choices[i]) : hs[survey[i][1]] += abs(4 - choices[i]);
    }
    
    answer += hs['T'] > hs['R'] ? 'T' : 'R';
    answer += hs['F'] > hs['C'] ? 'F' : 'C';
    answer += hs['M'] > hs['J'] ? 'M' : 'J';
    answer += hs['N'] > hs['A'] ? 'N' : 'A';
    
    return answer;
}
