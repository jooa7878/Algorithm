const sum = (arr) =>{
    let res = 0;
    
    arr.forEach(item=>{
        res += item;
    })
    
    return res;
}

function solution(queue1, queue2) {
    let answer = 0;
    
    let target = parseInt(sum([...queue1, ...queue2])/2)
    let i = 0;
    let j = queue1.length -1;
    let arr = [...queue1, ...queue2];
    let temp = sum(queue1);
        
    while(i < arr.length && j < arr.length){
        if(temp === target) return answer;
        
        if(temp < target && j < arr.length - 1){
            j++;
            temp += arr[j];
            
        }else{
            temp -= arr[i];
            i++;
        }
        
        
        answer++;
    }
        
       
    return -1;
}
