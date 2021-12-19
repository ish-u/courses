import time
import random
import csv
import pandas as pd
import matplotlib.pyplot as plt
import math

class sortedList():
    def __init__(self,data,comparisions,runningTime):
        self.data = data
        self.comparisions = comparisions
        self.runningTime = runningTime

    def __str__(self):
        return f'{self.comparisions:<7} \t {self.runningTime:<7}'

class timeComplexity():
    def __init__(self,avg,best,worst):
            self.avg = avg
            self.best = best
            self.worst = worst
        
    def __str__(self):
        return f'{len(self.avg.data):<7}  {self.avg.__str__()} \t {self.best.__str__()} \t {self.worst.__str__()}'


counter = 0
def merge(left,right,original):
    global counter
    i = j = k = 0 
    while(i < len(left) and j < len(right)):
        if(left[i] <= right[j]):
            counter += 1
            original[k] = left[i]
            i += 1
        else:
            counter += 1
            original[k] = right[j]
            j += 1
        k += 1
    while(i < len(left)):
        original[k] = left[i]
        i += 1
        k += 1
    while(j < len(right)):
        original[k] = right[j]
        j += 1
        k += 1

def mergeSort(n):
    global counter
    if len(n) == 1:
        return
    start = time.time()
    left = n[0:len(n)//2]
    right = n[len(n)//2:]
    mergeSort(left)
    mergeSort(right)
    merge(left,right,n)
    end = time.time()
    runningTime = round(end-start)
    return sortedList(n,counter,runningTime)


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
    global counter
    data = []
    numberOfTestCases = 0
    testCases = []
    sampleSpaceSize = 1
    while numberOfTestCases != 500:
        random.shuffle(numbers)
        sampleSpaceSize = random.randint(1,1000)
        if sampleSpaceSize not in testCases:
            testCases.append(sampleSpaceSize)
            startIndex = random.randint(0,len(numbers)-sampleSpaceSize)
            sampleSpace = numbers[startIndex:startIndex+sampleSpaceSize]
            avg = mergeSort(sampleSpace)
            counter = 0
            best = mergeSort(sampleSpace)
            counter = 0
            sampleSpace.reverse()
            worst = mergeSort(sampleSpace)
            counter = 0
            data.append(timeComplexity(avg,best,worst))
            numberOfTestCases += 1
    try:
        with open('comparisions.csv', mode='w') as c:
            writer = csv.writer(c)
            writer.writerow(['SIZE','AVERAGE','BEST','WORST'])
            for t in data:
                writer.writerow([len(t.avg.data),t.avg.comparisions,t.best.comparisions,t.worst.comparisions])
    except RuntimeError:
        print(RuntimeError)
    
    # Ploting the Graph
    comparisions = pd.read_csv('comparisions.csv')
    comparisions = comparisions.sort_values("SIZE")
    size = comparisions["SIZE"]
    plt.plot(size,comparisions["WORST"])
    plt.plot(size,comparisions["AVERAGE"])
    plt.plot(size,comparisions["BEST"])
    plt.plot(size,[x*math.log2(x) for x in size],'--')
    plt.legend(["WORST","AVERAGE","BEST","nlogn"])
    plt.xlabel('Input Size')
    plt.ylabel('Number of Comparisons')
    plt.xlim(0, 1000)
    plt.savefig('graph.png')
    plt.show()
    

getData(getNumbers())