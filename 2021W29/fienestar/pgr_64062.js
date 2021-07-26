/*
    징검다리 건너기
    https://programmers.co.kr/learn/courses/30/lessons/64062
*/
function solution(stones, k) {
    let N = 1 << Math.ceil(Math.log2(stones.length))
    let tree = Array(N * 2).fill(-Infinity)
    
    for(let i in stones)
        tree[N + +i] = stones[i]
    
    for(let i=N; --i; )
        tree[i] = Math.max(tree[i<<1], tree[i<<1|1])
    
    function get(begin, end)
    {
        begin += N;
        end += N;
        
        let M = -Infinity
        
        while(begin < end){
            if(begin & 1)M = Math.max(M, tree[begin++])
            if(end & 1)M = Math.max(M, tree[--end])
            begin >>= 1;
            end >>= 1;
        }
        
        return M
    }
    
    let m = Infinity
    for(let i=k; i<=stones.length; ++i)
        m = Math.min(m, get(i-k, i))

    return m
}