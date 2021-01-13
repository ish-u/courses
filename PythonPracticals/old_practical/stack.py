def stack():
    stk = []
    flag = True
    while flag:
        print("STACK", stk)
        print("1. Push")
        print("2. Pop")
        print("3. Clear")
        print("4. Exit")
        print()
        choice = int(input("What do you want to perform : "))
        if choice == 1:
            stk.append(int(input("Enter Element :")))
        elif choice == 2:
            print(stk.pop())
        elif choice == 3:
            stk.clear()
        else:
            flag = False
        print()

if __name__ == "__main__":
    stack()