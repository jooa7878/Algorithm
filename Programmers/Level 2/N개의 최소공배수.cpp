#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b){
	while(b!=0){
		int r = a%b;
		a= b;
		b= r;
	}
	return a;
}

int lcm(int a, int b){
    return a * b / gcd(a,b);
}


int solution(vector<int> arr) {
    int answer = 0;
    
    sort(arr.begin(), arr.end());
    
    if(arr.size() == 1) return arr[0];
    
    answer = lcm(arr[0], arr[1]);
    
    int idx = 2;
    
    while(idx < arr.size())
    {
        answer = lcm(answer, arr[idx]);
        idx++;
    }

    return answer;
}
