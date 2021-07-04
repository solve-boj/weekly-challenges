/*
    에디터
    https://www.acmicpc.net/problem/1406
*/
import java.io.*
import java.util.*
fun main(args: Array<String>){
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val tokens = StringTokenizer(br.readText())
    val str = tokens.nextToken()
    var num = tokens.nextToken().toInt()
    val lst : LinkedList<String> = LinkedList()
    for(k in str){
        lst.add(k.toString())
    }
    val iter = lst.listIterator(str.length)
    while(num-->0){
        val cmd = tokens.nextToken()
        when(cmd){
            "L"->{
                if(iter.hasPrevious())
                    iter.previous()
            }
            "D"->{
                if(iter.hasNext())
                    iter.next()

            }
            "B"->{
                if(iter.hasPrevious()){
                    iter.previous()
                    iter.remove()
                }
            }
            "P"->{
                iter.add(tokens.nextToken())
            }
        }
    }
    for(k in lst){
        bw.write(k)
    }
    bw.flush()
    bw.close()
}