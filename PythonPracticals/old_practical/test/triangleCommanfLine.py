import math
import sys
def triArea(side1,side2,side3):

    assert side1 <= (side2 + side3)
    assert side2 <= (side1 + side3)
    assert side3 <= (side2 + side1)

    #using heron's formula
    s = side1+side2+side3
    return (math.sqrt(s*(s-side1)*(s-side2)*(s-side3)),s)

def main():
    if len(sys.argv) == 4:
        print(triArea(int(sys.argv[1]),int(sys.argv[2]),int(sys.argv[3])))
    else:
        print("parsing error")

if __name__ == "__main__":
    main()