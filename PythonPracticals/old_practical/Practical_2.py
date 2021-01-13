
def triangle(n):
    for i in range(n):
        for j in range(n-i-1):
            print(end=' ')
        for k in range(i):
            print('*',end=' ')
        print()
    n = n - 1
    for i in range(n):
        for j in range(i+1):
            print(end=' ')
        for k in range(n-i-1):
            print('*',end=' ')
        print()

def numberTriangle():
    print( 
    '''
         1
        232
       34534
      4567654
     567898765
    ''')

triangle(5)
numberTriangle()