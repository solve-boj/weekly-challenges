def solution(price, money, count):
    prices = sum(price*(i+1) for i in range(count))
    if prices-money < 0:
        return 0
    else:
        return prices-money
