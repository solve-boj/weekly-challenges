'''
코드는 맞는 것 같으나 시간 초과...
'''

class Node:
    def __init__(self, char, prev_node, next_node):
        self.data = char
        self.prev_node = prev_node
        self.next_node = next_node


class Editor:
    def __init__(self):
        self.head = Node(None, None, None)
        self.tail = Node(None, self.head, None)

        self.head.next_node = self.tail

    def delete_data(self, p):
        if p.prev_node is not self.head:
            temp = p.prev_node
            p.prev_node = p.prev_node.prev_node
            p.prev_node.next_node = p
            del temp

    def insert_data(self, p, data):
        node = Node(data, p.prev_node, p)
        p.prev_node.next_node = node
        p.prev_node = node

    def traversal(self):
        temp = self.head.next_node
        while not temp == self.tail:
            print(temp.data, end="")
            temp = temp.next_node
        

init_string = input()
m_edit = Editor()
cursor = m_edit.tail
for c in init_string:
    m_edit.insert_data(cursor, c)

cnt = int(input())
for _ in range(cnt):
    cmd = input()
    if cmd[0] == "L":
        if cursor.prev_node is not m_edit.head:
            cursor = cursor.prev_node
    elif cmd[0] == "D":
        if cursor is not m_edit.tail:
            cursor = cursor.next_node
    elif cmd[0] == "B":
        m_edit.delete_data(cursor)
    elif cmd[0] == "P":
        m_edit.insert_data(cursor, cmd[2])

m_edit.traversal()
