/*
 셔틀버스
 https://programmers.co.kr/learn/courses/30/lessons/17678
 */
func solution(_ n:Int, _ t:Int, _ m:Int, _ timetable:[String]) -> String {
    var timetable2 = timetable
    timetable2.sort()
    let inttimetable = timetable2.map({(value: String) -> Int in return Int(value.split(separator:":")[0])!*60+Int(value.split(separator:":")[1])!})
    var ride_count = 0 
    var crew_in_bus = 0
    for i in 0..<n {
        let time = 540+i*t
        crew_in_bus = 0
        for k in ride_count..<inttimetable.count{
            if crew_in_bus == m{
                break
            }
            if inttimetable[k] <= time{
                crew_in_bus += 1
                ride_count += 1
            } else {
                break
            }
        }
    }
    var answer_number = 0;
    if(ride_count>0){ride_count-=1}
    if(crew_in_bus == m){
        answer_number = inttimetable[ride_count]-1
    } else {
        answer_number = 540+(n-1)*t
    }
    
    let hour:Int = answer_number/60
    let min:Int = answer_number%60
    
    return String(format: "%02d:%02d", hour, min)
}
