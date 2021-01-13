def check(n):
    temp = 0
    for a in str(n):
        z = int(a)
        temp += (z*z*z)
    if temp == n:
        return 1
    return 0

def main():
    start = int(input("Start : "))
    end = int(input("End : "))
    if start > end:
        return -1
    print("Armstrong Numbers : ", end="")
    for i in range(start,end+1,1):
        if check(i):
            print(i,end=" ")

main()