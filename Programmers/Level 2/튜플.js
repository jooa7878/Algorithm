function solution(s) {
    let answer = [];
    const splited = s.slice(1, -1).split('}').map(v=> v.match(/[0-9]+/g)).filter(v=>v!== null).sort((a,b)=> a.length - b.length);
    
    splited.forEach(str=>{
        str.forEach(s=>{
            if(!answer.includes(+s)) answer.push(+s);
        });
    })
    
    return answer;
}
