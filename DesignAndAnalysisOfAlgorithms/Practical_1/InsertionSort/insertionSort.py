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
def insertionSort(n):
    global counter  
    counter = 0
    start = time.time()
    for i in range(1,len(n)):
        key = n[i]
        j = i-1
        while j >= 0:
            counter += 1
            if(n[j] < key):
                n[j+1] = n[j]
                j -= 1
            else:
                break
        n[j+1] = key
    end = time.time()
    runningTime = round(end-start,5)
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
            avg = insertionSort(sampleSpace)
            best = insertionSort(sampleSpace)
            sampleSpace.reverse()
            worst = insertionSort(sampleSpace)
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
    plt.ylim(0, 20000)
    plt.xlim(0, 1000)
    plt.savefig('graph.png')
    plt.show()
    

getData(getNumbers())