function checkStr(str){
    if(str.length === 0) return str;
    let answer = "";
    let open = 0, close = 0
    let u = "", v = "", idx = 0;

    for(let i=0; i<str.length; i++){
        if(str[i] === '(') {
            open++;
            u += str[i];
        } else {
            close++;
            u += str[i];
        }
        if( open === close){
            idx = i;
            break;
        }
    }    
    
    v = str.substr(idx+1);
    let stk = [];
    let flag = true;
    
    for(let i=0; i<u.length; i++){
        if(stk.length === 0 && u[i] === ')'){
            flag = false;
            break;
        }
        else if (u[i] === '(') stk.push(u[i]);
        else if (u[i] === ')') stk.pop();
    }
    
    if(stk.length > 0) flag = false;
    
    if(flag){
        answer += u;
        answer += checkStr(v);
    }else{
        const vResult = '(' + checkStr(v) + ')';       
        u = u.slice(1, -1)
             .split('')
             .map(value => value === ')' ? '(' : ')')
             .join('');
    
   
        answer += vResult;
        answer += u;
    }
    
    
    return answer;
}

function solution(p) {
    

    return checkStr(p);
}
