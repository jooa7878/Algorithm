#include <string>
#include <vector>


using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> v;
    int flag = 0;
    int arr1[]={1,2,3,4,5};
    int arr2[]={2,1,2,3,2,4,2,5};
    int arr3[]={3,3,1,1,2,2,4,4,5,5};
    int n1=0,n2=0,n3=0;
    
    for(int i=0; i<answers.size(); i++){
        if(arr1[i%5]==answers[i]) n1++;
        if(arr2[i%8]==answers[i]) n2++;
        if(arr3[i%10]==answers[i]) n3++;
    }
    
    v.push_back(n1);
    v.push_back(n2);
    v.push_back(n3);
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<v.size(); j++){
            v[i] >= v[j] ? flag++ : flag--;
        }
        if( flag == 3){
            answer.push_back(i+1);
        }
        flag = 0;
    }
    
    
    
    return answer;
}
