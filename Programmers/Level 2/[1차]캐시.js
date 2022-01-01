function solution(cacheSize, cities) {
    let answer = 0;
    let q = [];
    let range = cacheSize > cities.length ? cities.length : cacheSize;
    
    if(cacheSize === 0) return cities.length * 5;
    
    for(let city of cities){
        if(q.find(el=>el === city.toLowerCase()) === undefined){
            answer+=5;
            q.push(city.toLowerCase());
            if(q.length > cacheSize) q.shift();
        }else{
            const idx = q.indexOf(city.toLowerCase());
            q.splice(idx, 1);
            q.push(city.toLowerCase());
            answer++;
        }
    }
        
    return answer;
}
