def isLength(id):
    if len(id) < 3 or len(id) > 15:
        return up2down(id)

    change_id = id

    return up2down(change_id)

# 1단계 new_id의 모든 대문자를 대응되는 소문자로 치환합니다.
def up2down(id):
    return remove_special_char(id.lower())

# 2단계 new_id에서 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.)를 제외한 모든 문자를 제거합니다.
def remove_special_char(id):
    for i in id:
        if i.isalpha() or i.isdigit() or i == '-' or i == '_' or i == '.':
            continue
        else:
            id = id.replace(i, '')
    return remove_double_dot(id)

# 3단계 new_id에서 마침표(.)가 2번 이상 연속된 부분을 하나의 마침표(.)로 치환합니다.
def remove_double_dot(id):
    for _ in range(len(id)):
        id = id.replace('..', '.')
    return remove_dot_at_head_or_tail(id)

# 4단계 new_id에서 마침표(.)가 처음이나 끝에 위치한다면 제거합니다.
def remove_dot_at_head_or_tail(id):
    if id:
        if id[0] == '.':
            id = id[1:]
        if id and id[-1] == '.':
            id = id[:-1]
        return new_ids_empty(id)
    return new_ids_empty(id)

# 5단계 new_id가 빈 문자열이라면, new_id에 "a"를 대입합니다.
def new_ids_empty(id):
    if id == '':
        return isOtherLength('a')
    else:
        return isOtherLength(id)

# 6단계 new_id의 길이가 16자 이상이면, new_id의 첫 15개의 문자를 제외한 나머지 문자들을 모두 제거합니다.
# 만약 제거 후 마침표(.)가 new_id의 끝에 위치한다면 끝에 위치한 마침표(.) 문자를 제거합니다.
def isOtherLength(id):
    if len(id) >= 16:
        id = id[:15]
        if id[-1] == '.':
            id = id[:-1]
    return is7thLength(id)

# 7단계 new_id의 길이가 2자 이하라면, new_id의 마지막 문자를 new_id의 길이가 3이 될 때까지 반복해서 끝에 붙입니다.
def is7thLength(id):
    for i in range(3 - len(id)):
        id += id[-1]
    return id

def solution(new_id):
    return isLength(new_id)

# if __name__ == '__main__':
    # print("bat.y.abcdefghi")
    # print(solution("...!@BaT#*..y.abcdefghijklm"))
    # print(solution("...!@BaT#*..y.abcdefghijklm") == "bat.y.abcdefghi")

    # print("----------------------------------------------------------------")

    # print("z--")
    # print(solution("z-+.^."))
    # print(solution("z-+.^.") == "z--")

    # print("----------------------------------------------------------------")

    # print("aaa")
    # print(solution("=.="))
    # print(solution("=.=") == "aaa")

    # print("----------------------------------------------------------------")

    # print("123_.def")
    # print(solution("123_.def"))
    # print(solution("123_.def") == "123_.def")

    # print("----------------------------------------------------------------")

    # print("abcdefghijklmn")
    # print(solution("abcdefghijklmn.p"))
    # print(solution("abcdefghijklmn.p") == "abcdefghijklmn")

    # print("----------------------------------------------------------------")

    # print("aaa")
    # print(solution("~!@#$%&*()=+[{]}:?,<>/"))
    # print(solution("~!@#$%&*()=+[{]}:?,<>/") == "aaa")

    # print("----------------------------------------------------------------")

    # print("111")
    # print(solution(".1."))
    # print(solution(".1.") == "111")

    # print("----------------------------------------------------------------")

    # print("abcd")
    # print(solution("./././././abcd/././././."))
    # print(solution("./././././abcd/././././.") == "abcd")
    
    # print("----------------------------------------------------------------")

    # print("aaa")
    # print(solution("........................"))
    # print(solution("........................") == "aaa")