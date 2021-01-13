def oddLineCpoier():
    try:
        f1 = open("file1.txt","rt")
        f2 = open("file2.txt","w")
        counter = 1
        for x in f1:
            if counter % 2 != 0:
                f2.write(x)
            counter += 1
    except FileNotFoundError:
        print("File Not Found")
        exit(-1)
    finally:
        f1.close()
        f2.close()

def main():
    oddLineCpoier()

if __name__ == "__main__":
    main()
