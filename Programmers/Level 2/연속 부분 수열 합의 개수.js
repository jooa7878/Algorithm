function solution(elements) {
    const arr = [...elements, ...elements];
    const s = new Set();
    
    for(let i=0; i<elements.length; i++){
        let sum = 0
        for(let j=0; j<elements.length; j++){ // 길이가 j+1인 부분수열을 구하겠다.
            sum += arr[i + j];   
            s.add(sum);    
        }
        
    }
    
 
    return s.size;
}
