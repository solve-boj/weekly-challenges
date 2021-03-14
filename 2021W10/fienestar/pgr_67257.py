'''
    수식 최대화
    https://programmers.co.kr/learn/courses/30/lessons/6725
'''
def mul(a,b):
    return a*b
def add(a,b):
    return a+b
def sub(a,b):
    return a-b
#       **, *, +
calc = [(mul,'*'),(add,'+'),(sub,'-')]
ch = ['&','^','|']

class Number:
    def __init__(self,value):
        self.value = value
    def __and__(self,oth): # 3
        return Number(calc[0][0](self.value,oth.value))
    def __xor__(self,oth): # 2
        return Number(calc[1][0](self.value,oth.value))
    def __or__(self,oth): # 1
        return Number(calc[2][0](self.value,oth.value))

def solution(expression):
    last = 0
    translated = ""
    for i,e in enumerate(expression):
        if expression[i] in ['*','+','-']:
            translated += 'Number(' + expression[last:i] + ')' + expression[i]
            last = i+1
    translated += 'Number('+expression[last:]+')'
    
    def find_all(i):
        
        if i == 3:
            result = translated[::]
            for i in range(len(ch)):
                result = result.replace(calc[i][1],ch[i])
            return abs(eval(result).value)
        else:
            answer = 0
            for j in range(i,3):
                calc[i],calc[j] = calc[j],calc[i]
                answer = max(answer,find_all(i+1))
                calc[i],calc[j] = calc[j],calc[i]
            return answer
                

    return find_all(0)