import random
import math

# Insertin Sort
def InsertionSort(A):
    for i in range(1,len(A)):
        key = A[i]
        j = i-1
        while j >= 0 and A[j] > key:
            A[j+1] = A[j]
            j -= 1
        A[j+1] = key
    return A

# Bucket Sort
def BucketSort(A):
    smallestElement = min(A)
    if smallestElement < 0:
        A = [x - smallestElement for x in A]
    divide = len(str(max(A)))
    A = [x/(10**divide) for x in A]
    B = []
    n = len(A)
    sortedArray = []
    for i in range(n):
        B.append([])
    for i in range(n):
        B[math.floor(n*A[i])].insert(0,A[i])
    for i in range(n):
        B[i] = InsertionSort(B[i])
    for i in range(n):
        sortedArray.extend(B[i])
    sortedArray = [int(x*(10**divide)) for x in sortedArray]  
    if smallestElement < 0:
        sortedArray = [x + smallestElement for x in sortedArray]
    return sortedArray

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
        sampleSpace = BucketSort(sampleSpace)
        print("\t",sampleSpace,"\n")
        numberOfTestCases += 1

getData(getNumbers())