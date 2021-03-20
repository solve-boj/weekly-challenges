/*
    프렌즈4블록
    https://programmers.co.kr/learn/courses/30/lessons/17679
*/
let removed = {}

function count_removeable(board,i,j)
{
    if(board[i][j] == '.')
        return 0;
    
    let arr = []
    
    for(let mi=0; mi!=-2; --mi)
        for(let mj=0; mj!=-2; --mj)
            arr.push([i+mi,j+mj])
    
    if(arr.map(v=>board[v[0]][v[1]]).every(v=>v==board[i][j])){
        let removeable = 0
        arr.forEach(v=>{
            let idx = v[0]+'$'+v[1]
            removeable += !removed[idx]
            removed[idx] = true
        })
        return removeable
    }else
        return 0
}

function apply_gravity(board)
{
    for(let i in removed){
        let idx = i.split('$')
        board[idx[0]][idx[1]] = '.'
    }
    removed = {}
    
    for(let j=0; board[0][j];++j){
        let last = -1
        for(let i=board.length;i--;){
            if(board[i][j] == '.'){
                if(last == -1)last = i
            }else if(last != -1){
                board[last][j] = board[i][j]
                board[i][j] = '.'
                --last
            }
        }
    }
}

function solution(m, n, board)
{
    let total_cnt = 0
    let cnt = 0
    let moved = false
    board = board.map(v=>v.split(''))
    do{
        cnt = 0
        for(let i=1; i != m; ++i)
            for(let j=1; j != n; ++j)
                cnt += count_removeable(board,i,j)
        
        total_cnt += cnt
        
        apply_gravity(board)
    }while(cnt)
    return total_cnt
}