function solution(angle){ 
    return angle === 90 ? 2 : angle < 90 ? 1 : parseInt(angle / 90) + 2
}
