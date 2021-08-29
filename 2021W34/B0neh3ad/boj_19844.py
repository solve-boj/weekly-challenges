'''
    단어 개수 세기
    https://www.acmicpc.net/problem/19844
'''
sen = input()
prefix_list = ["c", "j", "n", "m", "t", "s", "l", "d", "qu"]
vowels = ["a", "e", "i", "o", "u", "h"]

word = ""
word_list = []
for c in sen:
    if c == "-" or c == " ":
        word_list.append(word)
        word = ""
    else:
        word += c
if word:
    word_list.append(word)
answer = len(word_list)

for w in word_list:
    if "'" in w:
        temp = w.split("'")
        if not temp[1]:
            continue
        if temp[0] in prefix_list and temp[1][0] in vowels:
            answer += 1

print(answer)