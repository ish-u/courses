def factorial(n):
    if n == 0 or n == 1:
        return 1
    return n*factorial(n-1)

# 1 - x^2/2! + x^3/3! + ..  x^n/n!
def seriesSum(x,n):
    sum = 1.0
    for i in range(2,n+1,1):
        if i%2 == 0:
            sum -= x**i/factorial(i)
        else:
            sum += (x**i)/factorial(i)
    return sum

print(seriesSum(2,3))