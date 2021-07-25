'''
    팰린드롬수
    https://www.acmicpc.net/problem/1259
'''
def ispalindrome(str):
    s, e = 0, len(str) - 1
    while s < e:
        if str[s] != str[e]:
            break
        s += 1
        e -= 1
    return (s >= e)

while True:
    N = input()
    if N == "0":
        break   
    print("yes" if ispalindrome(N) else "no")
