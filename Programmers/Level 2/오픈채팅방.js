function solution(record) {
    let answer = [];
    let test = new Map();
    
    record.forEach((item)=>{
        const [msg, id, name] = item.split(' ');
        if(msg !== "Leave")
        {
            test.set(id, name);
        }
    });
    
    for(let i=0; i<record.length; i++){
        const [msg, id, name] = record[i].split(' ');
        if(msg !== "Change"){
            msg === 'Enter' ? answer.push(test.get(id)+'님이 들어왔습니다.') : answer.push(test.get(id)+'님이 나갔습니다.')
        }
    }
    
    
    
    return answer;
}
