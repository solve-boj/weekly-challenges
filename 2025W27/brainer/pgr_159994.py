def solution(cards1, cards2, goal):
    answer = ''
    goal_words = goal[:]
    proces_words = []
    while True:
        front_word = not goal_words or goal_words[0]
        if (not cards1 or cards1[0] != front_word) and (not cards2 or cards2[0] != front_word):
            return "No"
        
        if cards1 and cards1[0] == front_word:
            # print(f"cards1: {cards1[0]}, front_word: {front_word}")
            goal_words.remove(front_word)
            cards1.pop(0)
            proces_words.append(front_word)
        elif cards2 and cards2[0] == front_word:
            # print(f"cards2: {cards2[0]}, front_word: {front_word}")
            goal_words.remove(front_word)
            cards2.pop(0)
            proces_words.append(front_word)
        
        print(proces_words == goal)
        if proces_words == goal:
            return "Yes"
    return answer

