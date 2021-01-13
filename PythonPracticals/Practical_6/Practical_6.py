def  retrunEven(tpl):
    evenTuple = []
    for i in tpl:
        if i % 2 == 0:
            evenTuple.append(i)
    return tuple(evenTuple)

def addTuple(tpl_1,tpl_2):
    tpl_1 = list(tpl_1)
    tpl_2 = list(tpl_2)
    tpl = tpl_1 + tpl_2
    return tuple(tpl)

def max_min(tpl):
    max = tpl[0]
    min = tpl[0]
    for i in tpl:
        if i > max:
            max = i
        if i < min:
            min = i
    return (max,min)


def main():
    t1 = (1,2,5,7,9,2,4,6,8,10)
    flag = True
    while flag:
        print("Tuple t1: ", t1)
        print("1. Return a Tuple that contains \"EVEN VALUES\" of given Tuple t1 ")
        print("2. Concatenate Tuple t2 with t1")
        print("3. Return Maximum and Minimum Values of the Tuple t1")
        print("4. Exit")
        choice = int(input("What do you want to perform ? "))
        if choice == 1:
            print(retrunEven(t1))
        elif choice == 2:
            numberOfElements = int(input("Number of Elements in t2 :"))
            t2 = []
            for i in range(numberOfElements):
                t2.append(int(input()))
            t1 = addTuple(t1,tuple(t2))
            print(t1)
        elif choice == 3:
            print(max_min(t1))
        else:
            flag = False
        print("==============================================\n")

if __name__ == "__main__":
    main()