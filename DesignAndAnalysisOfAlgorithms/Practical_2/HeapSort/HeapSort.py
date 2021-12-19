import time
import random
import csv
import pandas as pd
import matplotlib.pyplot as plt
import math

class sortedList():
    def __init__(self,data,comparisons,runningTime):
        self.data = data
        self.comparisons = comparisons
        self.runningTime = runningTime

    def __str__(self):
        return f'{self.comparisons:<7} \t {self.runningTime:<7}'

class timeComplexity():
    def __init__(self,avg,best,worst):
            self.avg = avg
            self.best = best
            self.worst = worst
        
    def __str__(self):
        return f'{len(self.avg.data):<7}  {self.avg.__str__()} \t {self.best.__str__()} \t {self.worst.__str__()}'


class heap:
    def __init__(self,h):
        self.h = h
        self.heapSize = len(self.h)
    
    def __str__(self):
        return str(self.h)


def buildMaxHeap(A):
    comparision = 0
    for i in range((A.heapSize - 1)//2, -1, -1):
        comparision += maxHeapify(A,i)
    return comparision

def maxHeapify(A, i):
    comparisons = 0
    largest = i
    left = 2*i + 1
    right = 2*i + 2

    if(left < A.heapSize and A.h[left] > A.h[i]):
        largest = left
    
    if(right < A.heapSize and A.h[right] > A.h[largest]):
        largest = right
    
    if(largest != i):
        comparisons += 1
        temp = A.h[i]
        A.h[i] = A.h[largest]
        A.h[largest] = temp
        comparisons += maxHeapify(A,largest)
    return comparisons

def heapSort(A):
    comparisons = 0
    start = time.time()
    comparisons += buildMaxHeap(A)
    for i in range(A.heapSize -1, -1 ,-1):
        A.h[i], A.h[0] = A.h[0], A.h[i]
        A.heapSize -= 1
        comparisons += maxHeapify(A,0)
    end = time.time()
    runningTime = round(end-start)
    return sortedList(A.h,comparisons,runningTime)



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
    data = []
    numberOfTestCases = 0
    testCases = []
    sampleSpaceSize = 1
    while numberOfTestCases != 1000:
        random.shuffle(numbers)
        sampleSpaceSize = random.randint(1,1000)
        if sampleSpaceSize not in testCases:
            testCases.append(sampleSpaceSize)
            startIndex = random.randint(0,len(numbers)-sampleSpaceSize)
            sampleSpace = heap(numbers[startIndex:startIndex+sampleSpaceSize])
            avg = heapSort(sampleSpace)
            best = heapSort(heap(avg.data))
            best.data.reverse()
            worst = heapSort(heap(best.data))
            data.append(timeComplexity(avg,best,worst))
            numberOfTestCases += 1
    try:
        with open('comparisons.csv', mode='w') as c:
            writer = csv.writer(c)
            writer.writerow(['SIZE','AVERAGE','BEST','WORST'])
            for t in data:
                writer.writerow([len(t.avg.data),t.avg.comparisons,t.best.comparisons,t.worst.comparisons])
    except RuntimeError:
        print(RuntimeError)
    
    # Ploting the Graph
    comparisons = pd.read_csv('comparisons.csv')
    comparisons = comparisons.sort_values("SIZE")
    size = comparisons["SIZE"]
    plt.plot(size,comparisons["WORST"])
    plt.plot(size,comparisons["AVERAGE"])
    plt.plot(size,comparisons["BEST"])
    plt.plot(size,[x*math.log2(x) for x in size],'--')
    plt.legend(["WORST","AVERAGE","BEST","nlogn"])
    plt.xlabel('Input Size')
    plt.ylabel('Number of Comparisons')
    plt.xlim(0, 1000)
    plt.savefig('graph.png')
    plt.show()
    

getData(getNumbers())