def transfrom_map(n, arr):
    map = []
    
    for i, row in enumerate(arr):
        str_row = str(bin(row)).split('0b')[-1]
        if len(str_row) < n:
            str_row = '0' * (n - len(str_row)) + str_row
            # print(f"str_row: {str_row}")
        map.append(
            [int(i) for i in str_row]
        )
    return map
    
def compare(arr1, arr2):
    result = []
    
    for i, (row1, row2) in enumerate(zip(arr1, arr2)):
        # print(f"{i}: row1: {row1}, row2: {row2}")
        row = []
        for j, (col1, col2) in enumerate(zip(row1, row2)):
            if 1 == col1 or 1 == col2:
                row.append(1)
            elif col1 == 0 and col2 == 0:
                row.append(0)
                
        result.append(row)
    return result
    
def solution(n, arr1, arr2):
    answer = []
    
    trans_ar1 = transfrom_map(n, arr1)
    trans_ar2 = transfrom_map(n, arr2)
    
    # print(f"trans1: {trans_ar1}")
    # print(f"trans2: {trans_ar2}")
    
    # print(f"Compare: {compare(trans_ar1, trans_ar2)}")
    
    # answer = ''.join(compare(trans_ar1, trans_ar2)).replace('1', "#").replace('0', " ")
    answer = list(''.join(map(str, i)).replace('1', "#").replace('0', " ") for i in compare(trans_ar1, trans_ar2))
    return answer

