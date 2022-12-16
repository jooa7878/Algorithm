function solution(want, number, discount) {
    let answer = 0;
    
    for(let i=0; i<discount.length; i++){
        const arr = discount.slice(i, i+10); 
        let flag = true
        for(let j=0 ; j<want.length; j++){
            if(arr.filter(v=> v == want[j]).length !== number[j]){
                flag = false;
                break;
            }
        }
            
        flag && answer++;
    }
    
    return answer;
}
