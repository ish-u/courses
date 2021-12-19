import random

# Counting Sort
def countingSort(toSort,d):
    smallestElement = min(toSort)
    if smallestElement < 0:
        toSort = [x - smallestElement for x in toSort]
    sortedArray = [0]*len(toSort)
    A = [x//(10**d) for x in toSort]
    A = [x%10 for x in A]
    k = max(list(set(A)))
    C = []
    B = [x for x in A]
    for i in range(0,k+1):
        C.append(0)
    for j in range(0,len(A)):
        C[A[j]] += 1
    for i in range(1,k+1):
        C[i] = C[i] + C[i-1]
    for j in range(len(A)-1,-1,-1):
        B[C[A[j]]-1] = A[j]
        sortedArray[C[A[j]]-1] = toSort[j]
        C[A[j]] = C[A[j]] - 1
    if smallestElement < 0:
        sortedArray = [x + smallestElement for x in sortedArray]
    return sortedArray

# Radix Sort
def RadixSort(A):
    d = len(str(max(A)))
    for x in range(d):
       A = countingSort(A,x)
    return A

def getNumbers():
    try:
        numbersFile = open('numbers.txt', "r")
        numbers = []
        for number in numbersFile:
            numbers.append(int(number))
    except FileNotFoundError:
        print("File Not Found")
        exit(-1)
    finally:
        numbersFile.close()
    return numbers

def getData(numbers):
    numberOfTestCases = 0
    sampleSpaceSize = 1
    print("\t\t100 Unique Test Cases\n")
    while numberOfTestCases != 100:
        random.shuffle(numbers)
        sampleSpaceSize = random.randint(1,20)
        startIndex = random.randint(0,len(numbers)-sampleSpaceSize)
        sampleSpace = numbers[startIndex:startIndex+sampleSpaceSize]
        print(f"#{numberOfTestCases+1:<3}->  ",sampleSpace)
        sampleSpace = RadixSort(sampleSpace)
        print("\t",sampleSpace,"\n")
        numberOfTestCases += 1

getData(getNumbers())