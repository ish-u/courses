def fibo(n):
    if n < 0:
        return 0
    if n == 1 or n == 2:
        return 1
    return fibo(n-1) + fibo(n-2)

def factorial(n):
    if n == 1 or n == 0:
        return 1
    return n*factorial(n-1)

# #printing first 10 fibonacci numbers
# print("No","Fib","Fact")
# for x in range(1,11):
#     print(x,fibo(x),factorial(fibo(x)))


#Practical 4
def returnDigits(n):
    n = str(n)
    if len(n) < 10:
        raise RuntimeError("Number is Smaller than 10")
    return set(n) 


# while True:
#     try:
#         print(returnDigits(str(input("-> "))))
#         break
#     except RuntimeError:
#         print("Error")

#Practical 5
def tupleFunction():
    t1 = (1,2,5,7,9,2,4,6,8,10)
    t2=(11,13,15)
    t1 = tuple(list(t1) + list(t2))
    print(max(t1),min(t1))
    print(t1)

#Practical 7

# s =  []
# for i in range(3):
#     s.append(str(input(":")))

# #finding length
# for x in s:
#     print(len(x), end=" ")

# #find the maximum of 3 strings
# print(max(max(s[0],s[1]),s[2]))

# #replacing the vowels with #
# for x in s:
#     v = ['a','e','i','o','u']
#     newStr = ""
#     for c in x:
#         if c in v:
#             newStr += "#"
#         else:
#             newStr += c
#     print(newStr,end = " ")

# #check pallindrome
# print( )
# for x in s:
#     print(x == x[::-1])



#Practical 8


