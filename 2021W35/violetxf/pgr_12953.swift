/*
    N개의 최소공배수
    https://programmers.co.kr/learn/courses/30/lessons/12953
*/
func gcd(_ a:Int, _ b:Int) -> Int {
    var num1 = a
    var num2 = b
    while(num2 != 0){
        var temp = num1 % num2
        num1 = num2
        num2 = temp
    }
    return num1
}
func lcm(_ a:Int, _ b:Int) -> Int {
    return a*b/gcd(a,b)
}
func solution(_ arr:[Int]) -> Int {
    var i = 1
    var current = arr[0]
    while(i<arr.count){
        current = lcm(current, arr[i])
        i+=1
    }
    return current
}