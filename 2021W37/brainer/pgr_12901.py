import datetime

def solution(a, b):
    day_week = ["MON","TUE","WED","THU","FRI","SAT","SUN"]

    answer = day_week[datetime.date(2016, a, b).weekday()]
    print(b)
    
    return answer
