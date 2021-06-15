#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    int first = 0;
    for(int i=0; i<s.length(); i++){
        if(s[i] == ' '){
            first =0;
        }
        else{
            if( first == 0){
                if(isalpha(s[i]) && s[i] >='a' && s[i] <= 'z') s[i]-= 32;
            }
            else{
                if(isalpha(s[i]) && s[i] >= 'A' && s[i] <='Z') s[i]+= 32;
            }
            first++;                
        }
    }
    return s;
}
