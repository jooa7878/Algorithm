function solution(distance, rocks, n) {
    let answer = 1000000001;
    rocks.push(distance);
    rocks.sort((a,b)=>a-b);
    
    let left = 0;
    let right = 1000000001;
    
    while(left <= right){
        let mid = parseInt((left+right) / 2);
        let temp = 0
        let cnt = 0;
        for(let i = 0; i < rocks.length; i++){
            if(rocks[i] - temp >= mid) {
                temp = rocks[i];
                continue;
            }            
            cnt++;
        }

        if(cnt <= n){
            answer = mid;
            left = mid + 1;
            continue;
        }
        right = mid - 1;
    }
    
    return answer;
}
