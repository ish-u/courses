import os
#initializing the letterCounter as dictionary to count the alphabet count
letterCounter = dict()
def init():
    for i in range(26):
        letterCounter[chr(65+i).lower()] = 0

def counter(sentence):
    sentence = sentence.lower()
    sentence = [x for x in sentence]
    for x in sentence:
        if x in letterCounter:
            letterCounter[x] += 1
    print("Letter Frequency")
    for letter in letterCounter:
        if letterCounter[letter] > 0:
            print(letter.upper().center(len("Letter")), str(letterCounter[letter]).center(len("Frequency")))

def main():
    print("Letter Frequency Finder")
    print("* /cls to Clear \n* /exit to Exit")
    while(True):
        init()
        inp = input("> ")
        if(inp[0] == "/"):
            if inp == "/cls":
                os.system("CLS")
            elif inp == "/exit":
                exit(0)
        else:
            counter(inp)
        

if __name__ == "__main__":
    main()