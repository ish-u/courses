def returnSet(num):
    num = str(num)    
    if len(num) >= 10:
        s = []
        for i in num:
            s.append(i)
        return set(s)
    else:
        print('Error')
        return

print("SET : ",returnSet(979416333454))


