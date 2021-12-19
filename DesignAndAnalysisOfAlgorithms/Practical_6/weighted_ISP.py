def takeInput(n):
    print()
    intervals = [None]
    for i in range(n):
        print(f"Job {i+1}")
        startTime = float(input("Start Time : "))
        finishTime = float(input("Finish Time : "))
        value = float(input("Value : "))
        print()
        interval = {
            "startTime" : startTime,
            "finishTime" : finishTime,
            "value" : value
        }
        intervals.append(interval)
    
    # Sorting the intervals according to finishTime
    for i in range(1,len(intervals)):
        for j in range(i,len(intervals)):
            if intervals[i]["finishTime"] > intervals[j]["finishTime"]:
                intervals[i],intervals[j] = intervals[j],intervals[i]
    
    return intervals

# Function that finds the first legal interval from the end of interval 'j' 
# (legal interval of 'j' => Interval whose finish time is smaller than start time of 'j' )
def p(j,intervals):
    k = j - 1
    for i in range(k,0,-1):
        if intervals[i]["finishTime"] <= intervals[j]["startTime"]:
            return i  
    return 0

def OPT(j,M,intervals):
    if j == 0:
        return 0
    elif M[j] != 0:
        return M[j]
    else:
        M[j] = max(intervals[j]["value"] + OPT(p(j,intervals),M,intervals),OPT(j-1,M,intervals))
        return M[j]

def FindSolution(j,M,intervals):
    if j == 0:
        return
    else:
        if (intervals[j]["value"] + M[p(j,intervals)]) >= M[j-1]:
             print(j,end=" ")
             FindSolution(p(j,intervals),M,intervals)
        else:
            FindSolution(j-1,M,intervals)

def main():
    # Taking input of Intervals
    n = int(input("Enter the Numbe of Intervals : "))
    intervals = takeInput(n)
    
    # Displaying the Intervals
    print(f"INTERVALS\n{'-'*10}\n  #\tStart Time\tFinish Time\tValue")
    for interval in intervals:
        if interval is not None:
            print(f'  {intervals.index(interval)}\t{interval["startTime"]:^10}\t{interval["finishTime"]:^11}\t{interval["value"]:^5}')
    print("-"*10)

    # M - List for Memoization
    M = [0]*(n+1)

    # Finding the Optimal Solution for each Interval 'j'
    for i in range(1,n+1):
        M[i] = OPT(i,M,intervals)
    
    # Displaying the Result
    for i in range(1,n+1):
        print(f" -> Optimal Solution till Interval {i} -> Set : {{ ",end="")
        FindSolution(i,M,intervals)
        print(f"}}, Value : {M[i]}")
    print("-"*10)

main()

