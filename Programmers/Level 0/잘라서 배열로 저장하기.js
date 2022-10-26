function solution(my_str, n) {
    var answer = [];
    let str = '';
    for(let i=0; i<my_str.length; i++){
        str += my_str[i];
        
        if((i + 1) % n === 0){
            answer.push(str);
            str = '';
        }
    }
    
    if(str.length > 0) answer.push(str);
    return answer;
}
