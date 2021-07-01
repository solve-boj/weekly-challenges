def rotation(matrix, q):
    y1, x1, y2, x2 = q
    temp = matrix[y1 - 1][x2 - 1]
    min_val = temp

    # push top 1 block right
    matrix[y1 - 1][x1:x2] = matrix[y1 - 1][x1 - 1:x2 - 1]
    min_val = min(matrix[y1 - 1][x1:x2] + [min_val])

    # pull left 1 block up
    for i in range(y1, y2):
        matrix[i - 1][x1 - 1] = matrix[i][x1 - 1]
        min_val = min(matrix[i - 1][x1 - 1], min_val)

    # push bottom 1 block left
    matrix[y2 - 1][x1 - 1:x2 - 1] = matrix[y2 - 1][x1:x2]
    min_val = min(matrix[y2 - 1][x1 - 1:x2 - 1] + [min_val])

    # push right 1 block down
    for i in range(y2 - 1, y1 - 1, -1):
        matrix[i][x2 - 1] = matrix[i - 1][x2 - 1]
        min_val = min(matrix[i][x2 - 1], min_val)

    # finish rotation
    matrix[y1][x2 - 1] = temp

    return min_val


def solution(rows, columns, queries):
    answer = []
    numbers = [list(range(columns*i + 1, columns*(i+1) + 1)) for i in range(rows)]

    for query in queries:
        answer.append(rotation(numbers, query))

    return answer
