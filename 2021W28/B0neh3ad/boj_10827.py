temp = input().split()
a = temp[0]
b = int(temp[1])

digits = len(a) - 1 - a.find(".")

a = int(a[:-digits-1]) * (10**digits) + int(a[-digits:])
a = str(a**b)
if len(a) <= digits*b:
    a = "0"*(digits*b + 1 - len(a)) + a

print(a[:-(digits*b)]+"."+a[-(digits*b):])