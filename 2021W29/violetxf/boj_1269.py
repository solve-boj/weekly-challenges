input()
s1 = input().split(" ")
s2 = input().split(" ")
print(len(set(s1).symmetric_difference(set(s2))))