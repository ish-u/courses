def isPrime(n):
    if n <= 1:
        return False
    else:
        for i in range(2,n,1):
            if n%i == 0:
                return False
        return True

print(isPrime(5),isPrime(50),isPrime(51),isPrime(67))