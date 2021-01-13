
def selectionSort(n):
    for i in range(len(n)-1):
        print(n)
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
        print(n)
        for j in range(len(n)-i-1):
            if n[j] > n[j+1]:
                temp = n[j]
                n[j] = n[j+1]
                n[j+1] = temp
    return n

def insertionSort(n):
    for i in range(1,len(n)):
        print(n)
        key = n[i]
        j = i-1
        while j >= 0 and n[j] > key:
            n[j+1] = n[j]
            j -= 1
        n[j+1] = key
    return n

l = [6,1,0,8,-2,-5]
temp = l
print(selectionSort(temp),"\n")
temp = l
print(bubbleSort(temp),"\n")
temp = l
print(insertionSort(temp),"\n")