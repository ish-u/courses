def findPrime(start,end):
    primeList = []
    for i in range(start,end+1,1):
        flag = 1
        for j in range(2,i):
            if i%j == 0:
                flag = 0
                break
        if flag:
            primeList.append(i)
    return primeList

def findPallindrome(start,end):
    pallindromeList = []
    for i in range(start,end+1,1):
        i = str(i)
        if i == i[::-1]:
            pallindromeList.append(int(i))
    return pallindromeList



def main():
    flag = True
    while flag:
        print("Find Primes and Pallindromes")
        print("1. Find Prime. \n2. Find Pallindrome.")
        choice = int(input("Enter Choice : "))
        if choice < 1 or choice > 2:
            print("Invalid Choice")
        else:
            start = int(input("Enter the Start : "))
            end = int(input("Enter the End : "))
            if start > end:
                print("Invaid Entries")
            elif choice == 1:
                print("Primes : ", findPrime(start,end))
            else:
                print("Pallindromes :", findPallindrome(start,end))
            print()
    
if __name__ == "__main__":
    main()