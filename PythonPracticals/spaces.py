def spaces(s):
    total = 0
    for a in s:
        if a.isalpha():
            total += 1
        if a.isspace():
            total += 1
    print("Count : ",total)
    print("".join(s.split()))

def main():
    s = str(input("Enter String: "))
    print("Removing Spaces and Counting...")
    spaces(s)

main()
