function solution(order) {
    let answer = 0;
    const stk = [];
    let pos = 0;
    for(let i=1; i<=order.length; i++){
        // 스택에서 확인함
       if(i != order[pos]){
           stk.push(i)
           continue;           
        }
        answer++;
        pos++;
        while(stk.length > 0 && order[pos] === stk[stk.length-1]){
            stk.pop();
            answer++;
            pos++;
        }
    }
    
    return answer;
}
