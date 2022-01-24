function isPrime(num){
    for(let i=2; i<=Math.sqrt(num); i++){
        if(num % i === 0) return false;
    }
    
    return true;
}

function solution(n, k) {
    let answer = 0;
    let tmp = n.toString(k);
    let s = tmp.split('0');

    for(const n of s){
        const num = parseInt(n);
        if(num !== NaN && num > 1 && isPrime(num)) {
            answer++;
        }
    }
    
    return answer;
}
