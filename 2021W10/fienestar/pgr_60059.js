/*
    자물쇠와 열쇠
    https://programmers.co.kr/learn/courses/30/lessons/60059
*/
function rotate(key)
{
    let arr = []
    for(let i in key){
        arr.push([])
        for(let j in key)
            arr[i].push(key[key.length-j-1][i])
    }
    return arr
}

function check(lock, key, baseX, baseY)
{
    for(let i in lock)
        for(let j in lock[i]){
            let mi = +i+baseX
            let mj = +j+baseY
            let not_in_range = key[mi] === undefined || key[mj] === undefined
            
            if(not_in_range){
                if(!lock[i][j])
                    return false
            }else{
                if(lock[i][j] == key[mi][mj])
                    return false
            }
        }
    return true
}

function solution(key, lock) {
    let rotated = [key]
    
    for(let i=0;i!=3;++i)
        rotated.push(rotate(rotated[i]))
    
    let m = key.length
    
    for(let baseX = -2*m; baseX != 2*m; ++baseX)
        for(let baseY = -2*m; baseY != 2*m; ++baseY)
            for(let i=0; i!=4; ++i)
                if(check(lock,rotated[i],baseX,baseY))
                    return true
    
    return false
}