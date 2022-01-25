function solution(fees, records) {
    let answer = [];
    
    let timeMap = new Map();
    let payMap = new Map();
    let arr = [];
    
    const [defaultTime, defaultFee, unitTime, unitFee] = fees;
    
    for(const record of records){
        const [time, num, sign] = record.split(" ");
        if(!arr.includes(num)) arr.push(num);
        if(sign === "IN"){
            timeMap.set(num, time);
            if(payMap.get(num) === undefined) payMap.set(num, 0);
        }
        else{
            let [leaveHour, leaveMin] = time.split(":");
            let [enterHour, enterMin] = timeMap.get(num).split(":");
            let total = ((parseInt(leaveHour) - parseInt(enterHour)) * 60) + (parseInt(leaveMin) - parseInt(enterMin));
            
            timeMap.delete(num);
            payMap.set(num, payMap.get(num) + total);
        }
    }
    arr.sort((a, b) => parseInt(a) - parseInt(b));
    
    for(const num of arr){
        console.log(num);
        let totalTime;
        if(timeMap.get(num) === undefined){
            totalTime = payMap.get(num);
        }
        else {
            let [enterHour, enterMin] = timeMap.get(num).split(":");
            totalTime = ((23 - parseInt(enterHour)) * 60) + (59 - parseInt(enterMin));
            totalTime += payMap.get(num) === undefined ? 0 : payMap.get(num);
        }
        
        if(totalTime > defaultTime){
            answer.push(defaultFee + (Math.ceil((totalTime - defaultTime) / unitTime)) * unitFee);
        }
        else{
            answer.push(defaultFee);
        }
    }
    
    return answer;
}
