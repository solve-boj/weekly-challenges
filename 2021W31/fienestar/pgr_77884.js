/*
    약수의 개수와 덧셈
    https://programmers.co.kr/learn/courses/30/lessons/77884
*/
function solution(left, right)
{
    let sum = 0
    for(; left <= right; ++left){
        let sqrt = Math.sqrt(left)
        if(sqrt == (sqrt | 0))
            sum -= left
        else
            sum += left
    }
    return sum;
}