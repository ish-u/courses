import os
def linearSearch(a,n):
    for i in n:
        if a == i:
            print("Found")
            return 0
    print("Not Found")
    return -1

def binarySearch(a,n):
    n = insertionSort(n)
    start = 0
    end = len(n) - 1
    while(start <= end):
        middle = (start + end)//2
        if n[middle] == a:
            print("Found")
            return 0
        elif a > n[middle]:
            start = middle + 1
        elif a < n[middle]:
            end = middle - 1
    print("Not Found")
    return -1

def selectionSort(n):
    for i in range(len(n)-1):
        min = i
        for j in range(i+1,len(n)):
            if n[min] > n[j]:
                min = j
        if min != i:
            temp = n[min]
            n[min] = n[i]
            n[i] = temp
    return n

def bubbleSort(n):
    for i in range(len(n)):
        for j in range(len(n)-i-1):
            if n[j] > n[j+1]:
                temp = n[j]
                n[j] = n[j+1]
                n[j+1] = temp
    return n

def insertionSort(n):
    for i in range(1,len(n)):
        key = n[i]
        j = i-1
        while j >= 0 and n[j] > key:
            n[j+1] = n[j]
            j -= 1
        n[j+1] = key
    return n

def main():
    numberOfStudents = int(input("Number of Students :"))
    students = []
    for i in range(numberOfStudents):
        students.append(str(input(f"Student {i+1} : ")))
    os.system("CLS")
    while(True):
        print('''
1. Search
2. Sort
3. Restart''')    
        op = int(input("What do you want to perform ? :"))
        if op == 1:
            binarySearch(str(input("Element :")),students)
        elif op == 2:
            print(insertionSort(students))
        elif op == 3:
            numberOfStudents = int(input("Number of Students : "))
            students = []
            for i in range(numberOfStudents):
                students.append(str(input("Student 1 : ")))
        else:
            exit(0)
        input()
        os.system("CLS")

if __name__ ==  "__main__":
    main()

        
