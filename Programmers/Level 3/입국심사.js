function solution(n, times) {
    let answer = 10000000000000;
    
    times.sort((a,b) => a-b);
    let left = 0;
    let right = 10000000000000;
    
    while(left <= right){
        let mid = parseInt((left + right) / 2);
        let cnt = 0;
        times.forEach(time=>{
            cnt += parseInt(mid / time);
        })
        if(cnt >= n){
            answer = mid;
            right = mid - 1;
            continue
        }
        left = mid + 1;
    }
    
    return answer;
}
