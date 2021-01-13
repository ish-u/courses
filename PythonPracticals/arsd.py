# def printSquare(s):
#     print(s)
#     for i in range(0,len(s)):
#         print(s[i],' '*(len(s) - 4),s[i])
#     print(s)

# printSquare("ARSDCOLLEGE")

def multiply(m1,m2):
    if len(m1[0]) == len(m2):
        result = [[0 for i in range(len(m2[0]))] for i in range(len(m1))]
        for i in range(len(m1)):
            for j in range(len(m2[0])):
                for k in range(len(m2)):
                    result[i][j] += (m1[i][k]*m2[k][j])
    else:
        print('Not Valid')
    print(result)

def transpose(m1):
    for i in range(len(m1)):
        for j in range(len(m1[0])):
            print(m1[j][i],end=" ")
        print()


m1 = [[1,2],[3,4]]
m2 = [[1],[2]]
multiply(m1,m2)
transpose(m1)