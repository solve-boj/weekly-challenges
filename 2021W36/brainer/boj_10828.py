# push X: 정수 X를 스택에 넣는 연산이다.
# pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
# size: 스택에 들어있는 정수의 개수를 출력한다.
# empty: 스택이 비어있으면 1, 아니면 0을 출력한다.
# top: 스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
import sys

input = sys.stdin.readline

cmd_num = int(input())
stack = []

for _ in range(cmd_num):
    cmd = input().split()

    if cmd[0] == 'push':
        stack.append(int(cmd[1]))
    elif cmd[0] == 'pop' and len(stack) == 0:
        print(-1)
    elif cmd[0] == 'pop':
        print(stack[-1])
        stack.pop()
    elif cmd[0] == 'size':
        print(len(stack))
    elif cmd[0] == 'empty' and len(stack) >= 1:
        print(0)
    elif cmd[0] == 'empty':
        print(1)
    elif cmd[0] == 'top' and len(stack) >=1:
        print(stack[-1])
    elif cmd[0] == 'top':
        print(-1)
