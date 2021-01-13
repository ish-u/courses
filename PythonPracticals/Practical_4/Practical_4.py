def returnSet(num):
    num = str(num)    
    if len(num) >= 10:
        s = []
        for i in num:
            s.append(i)
        return set(s)
    else:
        return

print("SET : ",returnSet(12345678910))
print("SET : ",returnSet(1231746515961561))
print("SET : ",returnSet(12345231324))


