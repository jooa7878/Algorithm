function solution(n, k, enemy) {
    let answer = 0;
    
    if(k === enemy.length) return k;
    
    let left = 0;
    let right = enemy.length;
    
    while(left <= right){
        let mid = parseInt((left + right)/2);
        let op = k;
        let temp = enemy.slice(0, mid).sort((a,b)=> b-a)        
        for(let i=0; i<k; i++) temp[i] = 0;
        const sum = temp.reduce((total, item) => total + item); 
        if(n >= sum){
            answer = mid;
            left = mid+1;
        }else{
            right = mid-1;
        }
    }     
    
    return answer;
}
