#include <string>
#include <vector>
#include <cmath>

using namespace std;

int to_decimal(string num){
    int n = 0;
    int result = 0;
    
    while(n < num.length())
    {
        result += ((num[n]-'0') * pow(3,n));
        n++;
    }
    
    return result;
}

string to_triple(int num){
    string s ="";
    
    while(num > 0)
    {
        s.insert(0, to_string(num%3));
        num /= 3;
    }
    return s;
}
    
int solution(int n) {
    string triple_num = to_triple(n);

    return to_decimal(triple_num);
}
