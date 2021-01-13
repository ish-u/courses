
#hcf function
def hcf(num_1,num_2):
    result = 1
    smallest = num_2 if num_1 > num_2 else num_1
    for i in range(1,smallest+1,1):
        if(num_1%i == 0 and num_2%i == 0):
            result = i
    return result

#lcm function
def lcm(num_1,num_2):
    prodcut = num_1*num_2
    result = int(prodcut/hcf(num_1,num_2))
    return result

print(lcm(5,10),hcf(7,70))
    