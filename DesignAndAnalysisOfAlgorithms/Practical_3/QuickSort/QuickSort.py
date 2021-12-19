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

class Node:
    def __init__(self,data):
        self.data = data
        self.left = None
        self.right = None

def toBST(array):
    if not array:
        return None

    mid = len(array)//2

    root = Node(array[mid])
    root.left = toBST(array[:mid])
    root.right = toBST(array[mid+1:])

    return root

def postorder(root,sampleSpaceBestCase):
    if not root :
        return
    postorder(root.left,sampleSpaceBestCase)
    postorder(root.right,sampleSpaceBestCase)
    sampleSpaceBestCase.append(root.data)


def quickSort(A,p,r):
    comparison = 0
    start = time.time()
    if p < r:
        fromPartition = partition(A,p,r) 
        q = fromPartition[0]
        comparison += fromPartition[1]
        comparison += quickSort(A,p,q-1).comparisons
        comparison += quickSort(A,q+1,r).comparisons
    end = time.time()
    runningTime = round(end - start)
    return sortedList(A,comparison,runningTime)
    

def partition(A,p,r):
    toExchange = random.randint(p,r)
    A[toExchange],A[r] = A[r],A[toExchange]
    comparison = 0
    x = A[r]
    i = p - 1
    for j in range(p,r):
        comparison += 1
        if A[j] <= x:
            i += 1
            A[i],A[j] = A[j],A[i]
    A[i+1],A[r] = A[r],A[i+1]
    return i+1,comparison


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
    while numberOfTestCases != 900:
        random.shuffle(numbers)
        sampleSpaceSize = random.randint(1,900)
        if sampleSpaceSize not in testCases:
            testCases.append(sampleSpaceSize)
            startIndex = random.randint(0,len(numbers)-sampleSpaceSize)
            sampleSpace = numbers[startIndex:startIndex+sampleSpaceSize]
            avg = quickSort(sampleSpace,0,len(sampleSpace)-1)
            # the post order of the Balanced BST formed from the Sorted Array gives Best Case of Quick Sort
            sampleSpaceBestCase = []
            root = toBST(sampleSpace)
            postorder(root,sampleSpaceBestCase)
            sampleSpace = sampleSpaceBestCase
            best = quickSort(sampleSpace,0,len(sampleSpace)-1)
            # the already sorted array gives the Worst Case of Quick Sort
            worst = quickSort(sampleSpace,0,len(sampleSpace)-1)
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
    plt.plot(size,[x*x for x in size],'--')
    plt.legend(["WORST","AVERAGE","BEST","nlogn","n^2"])
    plt.xlabel('Input Size')
    plt.ylabel('Number of Comparisons')
    plt.xlim(0, 925)
    plt.savefig('graph.png')
    plt.show()
    

getData(getNumbers())