def highestMarks(n):
    dictionary = dict()
    for i in range(n):
        temp = []
        print("Enter the Marks of Student ",(i+1))
        for j in range(4):
            temp.append(int(input(f"Subject {j+1} : ")))
        dictionary[(i+1)] = temp
    maxMarks = []
    temp = 0
    for x in dictionary.values():
        for marks in x:
            temp += marks
        maxMarks.append(temp)
        temp = 0
    highest = 0
    for i in maxMarks:
        if i > maxMarks[(highest)]:
            highest = maxMarks.index(i)
    print(f"\nStudent {highest+1} scored the highest marks : {maxMarks[(highest)]}")

def main():
    highestMarks(4)
        
if __name__ == "__main__":
    main()
    