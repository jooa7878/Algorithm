function solution(numbers) {
    var answer = [];
    
    for(let number of numbers){
        if(number % 2 === 0 ) answer.push(number+1);
        else{
            let num_bin = number.toString(2);
            if(num_bin.indexOf(0) === -1){
                num_bin = "10" + num_bin.slice(1);
                answer.push(parseInt(num_bin,2));
            }else{
                let idx = num_bin.lastIndexOf(0);
                let ans = num_bin.slice(0, idx) + "10" + num_bin.slice(idx+2);
                answer.push(parseInt(ans,2));
            }
        }
        
        
    }
    
    return answer;
}
