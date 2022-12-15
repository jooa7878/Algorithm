function solution(k, tangerine) {
    let answer = 0;
    let arr = new Array(Math.max(...tangerine)+1).fill(0);
    
    tangerine.forEach((tanger)=>{
        arr[tanger]++;
    })
    
    const list = arr.filter(v=>v> 0).sort((a,b)=>b- a);
    
    let pos = 0;

    while(k>0){
        answer++;
        if(k > list[pos]){
            k-=list[pos]
        }else{
            break;
        }
        pos++;
    }
        
    
    return answer;
}
