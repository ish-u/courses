# 1 , 1 , 2 , 3 , 5 , 8 , 13 , 21 ...
def factorial(n):
    if n == 0:
        return 1
    return n*factorial(n-1)

def fib(n):
    if n == 1 or n == 2:
        return 1
    else:
        return fib(n-1)+fib(n-2)

def fib_factorial(n):
    return [fib(n),factorial(fib(n))]

print(fib_factorial(1))
print(fib_factorial(2))
print(fib_factorial(3))
print(fib_factorial(4))
print(fib_factorial(5))
print(fib_factorial(6))
print(fib_factorial(7))
