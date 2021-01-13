import math
def triArea():
    side1 = int(input("Side 1 : "))
    side2 = int(input("Side 2 : "))
    side3 = int(input("Side 3 : "))

    assert side1 < (side2 + side3)
    assert side2 < (side1 + side3)
    assert side3 < (side2 + side1)

    #using heron's formula
    s = (side1+side2+side3)/2
    return tuple([math.sqrt(s*(s-side1)*(s-side2)*(s-side3)),2*s])

print("(Area,Perimeter) : ",triArea())