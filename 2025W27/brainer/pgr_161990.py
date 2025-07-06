def get_x_high(wallpaper):
    max_x_pos = 0
    for y in wallpaper:
        for x_pos, x in enumerate(y):
            if x == "#" and max_x_pos < x_pos:
                max_x_pos = x_pos
    return max_x_pos

def get_x_low(wallpaper):
    min_x_pos = 9999
    for y in wallpaper:
        for x_pos, x in enumerate(y):
            if x == "#" and min_x_pos > x_pos:
                min_x_pos = x_pos
    return min_x_pos

def get_y_high(wallpaper):
    for i, paper in enumerate(wallpaper):
        if "#" in paper:
            return i

def get_y_low(wallpaper):
    for i, paper in enumerate(list(reversed(wallpaper))):
        if "#" in paper:
            return len(wallpaper) - 1 - i

def solution(wallpaper):    
#     print(get_y_high(wallpaper))
#     print(get_x_low(wallpaper))

#     print(get_y_low(wallpaper) + 1)
#     print(get_x_high(wallpaper) + 1)
    
    answer = [
        get_y_high(wallpaper),
        get_x_low(wallpaper),
        get_y_low(wallpaper) + 1,
        get_x_high(wallpaper) + 1
    ]
    
    return answer

