def strlen(string):
    length = 0
    for s in string:
        length = length + 1
    return length

def maxOfThree(str1,str2,str3):
    string = ""
    if str1 >= str2 and str1 >= str3:
        string = str1
    elif str2 >= str1 and str2 >= str3:
        string = str2
    else:
        string = str3
    return string

def changeVowel(string):
    vowels = "aeiou"
    newString = ""
    for i in string:
        if i.lower() in vowels:
            newString += "#"
        else:
            newString += i
    return newString

def wordCount(string):
    string = string.split()
    return len(string)

def pallindrome(string):
    flag = True
    for i in range(0,strlen(string)//2,1):
        if string[i] != string[strlen(string) - 1 - i]:
            flag = False
            break
    return flag

def main():
    flag = True
    while flag:
        print(
        '''
STRING OPERATIONS
1. Find the Length of a String.
2. Find the Maximum Of Three Strings.
3. Replace all the vowels in a String with '#'.
4. Find the Number of Words in a String.
5. Check whether a String is a 'Palindrome' or not
6. Exit.
        '''
        )
        choice = int(input("Enter Choice : "))
        if choice == 1:
            string = input("Enter String : ")
            print(strlen(string))
        elif choice == 2:
            strings = []
            for i in range(3):
                strings.append(input("String "+str(i+1)+" : "))
            print(maxOfThree(strings[0],strings[1],strings[2]))
        elif choice == 3:
            string = input("Enter String : ")
            print(changeVowel(string))
        elif choice == 4:
            string = input("Enter String : ")
            print(wordCount(string))
        elif choice == 5:
            string = input("Enter String : ")
            print(pallindrome(string))
        else:
            flag = False

if __name__ == "__main__":
    main()


