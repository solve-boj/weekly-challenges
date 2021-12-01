input_len = int(input())
for _ in range(input_len):
    tmp = reversed(''.join(reversed(input())).split())
    print(' '.join(tmp))