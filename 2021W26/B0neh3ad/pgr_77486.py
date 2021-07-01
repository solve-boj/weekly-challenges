class Node:
    def __init__(self, name):
        self.name = name
        self.super = None
        self.money = 0


class Tree:
    def __init__(self):
        self.root = Node("center")

    def make_tree(self, node, high):
        if high is None:
            node.super = self.root
        else:
            node.super = high

    def share_money(self, node, money):
        now_node = node
        remain = money
        while now_node != self.root and remain > 0:
            now_node.money += remain - int(remain * 0.1)
            remain = int(remain * 0.1)
            now_node = now_node.super


def solution(enroll, referral, seller, amount):
    answer = []
    node_dict = {}

    for member in enroll:
        node_dict[member] = Node(member)

    group = Tree()
    for i in range(len(referral)):
        if referral[i] == "-":
            group.make_tree(node_dict[enroll[i]], None)
        else:
            group.make_tree(node_dict[enroll[i]], node_dict[referral[i]])

    for name, count in zip(seller, amount):
        group.share_money(node_dict[name], count*100)

    answer = [node_dict[member].money for member in enroll]
    return answer
