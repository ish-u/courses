def isNum(l):
    flag = True
    for i in l:
        if not i.isnumeric():
            flag = False
            break
    return flag

def countOdd(l):
    if isNum(l):
        counter = 0
        for i in l:
            if int(i) % 2 != 0:
                counter += 1
        return counter
    return "List is not Numeric."

def maxString(l):
    flag = True
    for i in l:
        if i.isnumeric():
            flag = False
            break
    if flag:
        max = l[0]
        for i in l:
            if max < i:
                max = i
        return max
    return "List contains other datatypes than String."

def reverseList(l):
    for i in range(len(l)-1,-1,-1):
        print(l[i],end=' ')

def search(element,l):
    if element in l:
        return "Element is in List"
    return "Element is not in the List"

def sort(l):
    for i in range(1,len(l),1):
        key = l[i]
        j = i-1
        while j >= 0 and key > l[j]:
            l[j+1] = l[j]
            j = j - 1
        l[j+1] = key

def common(l1,l2):
    commmonList = []
    for i in l1:
        if i in l2:
            commmonList.append(i)
    return commmonList

def main():
    flag = True
    numberOfElements = int(input("Number of Elements in List : "))
    list1 = []
    for i in range(numberOfElements):
        list1.append(input())
    while flag:
        print("LIST :- ",list1)
        print(
'''
LIST OPERATIONS
1. Check if List is numeric or not.
2. Number of Odd Elments in List (if List is numeric)
3. Display the Largest String of the List (if all List Elements are of String Type).
4. Display the List in reverse.
5. Find a specified Element in List.
6. Remove a specified Element from List..
7. Sort the List in Descending Order.
8. Display Common Elements of List and another List from User.
9. Exit
''')
        choice = int(input("Enter Choice : "))
        if choice == 1:
            print(isNum(list1))
        elif choice == 2:
            print(countOdd(list1))
        elif choice == 3:
            print(maxString(list1))
        elif choice == 4:
            reverseList(list1)
        elif choice == 5:
            ele = input("Enter the Element : ")
            print(search(ele,list1))
        elif choice == 6:
            ele = input("Enter the Element to be removed : ")
            list1.remove(ele)
        elif choice == 7:
            sort(list1)
        elif choice == 8:
            numberOfElements = int(input("How many elements you want in List 2 :"))
            list2 = []
            for i in range(numberOfElements):
                list2.append(input())
            print("Common Elements : ",common(list1,list2))
        else:
            flag = False
        print()

if __name__ == "__main__":
    main()