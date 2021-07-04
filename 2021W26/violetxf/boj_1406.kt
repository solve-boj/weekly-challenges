fun main(args: Array<String>){
    val str = StringBuilder(readLine()!!)
    var num = readLine()!!.toInt()
    var cursor = str.length;
    while(num-->0){
        val cmd = readLine()!!
        val type = cmd[0];
        when(type){
            'L'->{
                if(cursor>0)cursor--;
            }
            'D'->{
                if(cursor<str.length)cursor++;
            }
            'B'->{
                if(cursor>0){
                    cursor--;
                    str.deleteAt(cursor);
                }
            }
            'P'->{
                val chr = cmd[2]
                str.insert(cursor, chr)
                cursor++
            }
        }
    }
    println(str)
}