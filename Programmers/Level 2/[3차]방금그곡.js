function solution(m, musicinfos) {
    let answer = "(None)"; // 22, 23, 24, 29
    let time = 0;
    while(m.includes("C#")) m = m.replace("C#", "c");     
    while(m.includes("D#")) m = m.replace("D#", "d");
    while(m.includes("F#")) m = m.replace("F#", "f");
    while(m.includes("G#")) m = m.replace("G#", "g");
    while(m.includes("A#")) m = m.replace("A#", "a");
    
    for(const info of musicinfos){
        let [startTime, endTime, title, code] = info.split(',');
        while(code.includes("C#")) code = code.replace("C#", "c");     
        while(code.includes("D#")) code = code.replace("D#", "d");
        while(code.includes("F#")) code = code.replace("F#", "f");
        while(code.includes("G#")) code = code.replace("G#", "g");
        while(code.includes("A#")) code = code.replace("A#", "a");
        
        const total = 60 *  (parseInt(endTime.slice(0,2)) - parseInt(startTime.slice(0,2)))  + (parseInt(endTime.slice(3)) - parseInt(startTime.slice(3)));
        let tmp = m;
        if(m.length > total) tmp = (m.slice(0, total));
        
        if(code.length > total) code = code.slice(0,total);
        else if(total > code.length){ // 코드보다 재생 시간이 더 길어서 반복 재생 된 경우
            let realCode = '';
            let idx = 0;
            while(realCode.length < total){
                realCode += code[idx];
                idx++;
                if(idx == code.length) idx = 0;
            }
            
            code = realCode;
        }
        
        // 조건이 일치하는 음악이 여러 개인 경우 재생 시간이 제일 긴 음악이 answer
        if(code.indexOf(tmp) !== -1){
            if(total > time) {
                time = total;
                answer = title;
            }
        }
        
    }
    
    return answer;
}
