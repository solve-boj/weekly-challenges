def even_food_num(foods):
    for i, food in enumerate(foods):
        # print(f"foods[{i}]: {foods[i]}")
        if food <= 1:
            foods[i] = 0
        elif food % 2 == 0:
            foods[i] = int(foods[i] / 2)
        else:
            foods[i] = int((foods[i]-1) / 2)
        # print(f"foods[{i}]: {foods[i]}")
    return foods

def make_table(foods):
    left_table = []
    
    # Make Left table
    for i, food in enumerate(foods):
        # print(f"i: {i}, food: {food}")
        i_table = [i+1] * food
        # print(f"i: {i_table}")
        left_table.extend(i_table)
        # print(f"table: {table}")
    # print(f"left_table: {left_table}")
    
    # Make Right Table
    right_table = list(reversed(left_table))
    # print(f"right_table: {right_table}")
    
    # Merge Table
    table = left_table + [0] + right_table
    print(table)
    return table

def solution(food):
    # print(f"food: {food}")
    
    food_without_water = food[1:]
    # print(f"food_without_water: {food_without_water}")
    
    even_food = even_food_num(food_without_water)
    # print(f"even_food: {even_food}")
    
    table = make_table(even_food)
    answer = ''.join(map(str, table))
    
    # print(answer)
    return answer

