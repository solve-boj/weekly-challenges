def issamestr(str):
    c = str[0]
    for ch in str[1:]:
        if c != ch:
            return False
    return True

def ispalindrome(str):
    s, e = 0, len(str) - 1
    while s <= e:
        if str[s] != str[e]:
            break
        s += 1
        e -= 1
    return (s > e)

cand = input()
if issamestr(cand):
    print(-1)
elif ispalindrome(cand):
    print(len(cand) - 1)
else:
    print(len(cand))
