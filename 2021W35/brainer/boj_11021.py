t = int(input())

a_list = []
b_list = []

for _ in range(t):
    a, b = map(int, input().split())
    a_list.append(a)
    b_list.append(b)

for i, (a, b) in enumerate(zip(a_list, b_list)):
    print(f"Case #{i+1}:", a+b)
