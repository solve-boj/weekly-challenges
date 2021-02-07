/*
    메뉴 리뉴얼
    https://programmers.co.kr/learn/courses/30/lessons/72411
*/
let orderCount={};
function choose(str, n){
    let temp=[];
    var fn=function(tar, idx, num){
        if(num==0){
            let s=temp.join('')
            if(!orderCount[s])orderCount[s]=1;
            else orderCount[s]++;
            return;
        }
        for(let i=idx;i<tar.length;i++){
            temp.push(tar[i]);
            fn(tar, i+1, num-1);
            temp.pop();
        }
    }
    
    fn(str, 0, n);
}
function solution(orders, course) {
    var answer = [];
    for(let num of course){
        for(let order of orders){
            choose(order.split('').sort().join(''), num);
        }
        let maxcnt=0;
        let maxcand=[];
        for(let k in orderCount){
            if(k.length!=num)continue;
            let cnt = orderCount[k];
            if(cnt>1&&cnt>=maxcnt){
                if(cnt==maxcnt){
                    maxcand.push(k);
                } else {
                    maxcand=[k];
                }
                maxcnt=cnt;
            }
        }
        answer = answer.concat(maxcand);
    }
    
    return answer.sort();
}