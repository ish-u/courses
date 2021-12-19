def takeInput(n):
    print()
    valueWeight = []
    for i in range(n):
        print(f"Item {i+1}")
        weight = int(input('Weight : '))
        value = int(input("Value : "))
        print()
        interval = {
            "weight": weight,
            "value" : value
        }
        valueWeight.append(interval)

    return valueWeight


def knapsackProblem(n,W,valueWeight):
    # W - Maximum Weight of Knapsack
    # n - Number of Items 
    # M - a (n+1)*(W+1) matrix. 
   
    # Creating a values and weight list 
    values = [value["value"] for value in valueWeight] 
    values.insert(0,0)
    weights = [weight["weight"] for weight in valueWeight]
    weights.insert(0,0)
    
    # Each M[i][w] entry will contain the maximum combined values for the subset-> {1,2,3...i} and  of atmost size 'w'
    M = [[0 for x in range(W+1)] for x in range(n+1)]

    # Calculating M[i][w]
    for i in range(n+1):
        for w in range(W+1):
            if w < weights[i]:
                M[i][w] = M[i-1][w]
            else:
                M[i][w] = max(M[i-1][w], values[i] + M[i-1][w-weights[i]])

    # Finding the Optimal Subset T of {1,2,3..n} for which Summation of Values is maximum and 
    # the Summation of Weights is smaller than or equal to the Size of Knapsack - 'W'
    tempW = W
    optimalSubset = []
    while i > 0 and tempW > 0: 
        if M[i][tempW] != M[i-1][tempW]:
            optimalSubset.append(i)
            tempW = tempW - weights[i]
        i = i - 1


    # Displaying the Solution
    print(f'\nM[i,w] i-> item, w-> weight  \n{"-"*25}')
    print(end='\t')
    for x in range(W+1):
        print(x,end='\t')
    print(end='\n\n')
    for x in range(n+1):
        print(x,end="\t")
        for y in range(W+1):
            print(M[x][y],end="\t")
        print(end='\n\n')

    print(f'\nThe Optimal Subset \n{"-"*15} \n T : {optimalSubset}\n Value : {M[n][W]}')


def main():
    # Taking Input
    n = int(input('Enter the Number of Items to be filled in Knapsack : '))
    W = int(input('Enter the Maximum Weight of the Knapsack : '))
    valueWeight = takeInput(n)

    # Solving Subset Sum / Knapsack Problem
    knapsackProblem(n=n,W=W,valueWeight=valueWeight)

main()