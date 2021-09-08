a, b = map(str, input().split())

a = ''.join(reversed(a))
b = ''.join(reversed(b))

if int(a) > int(b):
    print(int(a))
else:
   print(int(b))
