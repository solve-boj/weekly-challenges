def main():
    x = input()
    
    left = x.count("(")
    right = x.count(")")

    if left == right:
        print("YES")
    else:
        print("NO")

if __name__=="__main__":
    main()
