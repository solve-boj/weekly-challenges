/*
    로또의 최고 순위와 최저 순위
    https://programmers.co.kr/learn/courses/30/lessons/77484
*/
import kotlin.math.*
class Solution {
    fun solution(lottos: IntArray, win_nums: IntArray): IntArray {
        var zeros = lottos.count{it==0}
        var common = lottos.filter{win_nums.contains(it)}.size
        return intArrayOf(getRank(common+zeros), getRank(common))
    }
    fun getRank(common:Int):Int = min(6,7-common)
}