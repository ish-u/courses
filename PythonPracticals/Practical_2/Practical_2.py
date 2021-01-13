def sales():
    print('How good did you Sell ?')
    print('Enter the Sales per Week :- ')
    sales = [0,0,0,0] # [0]*4
    totalSales = 0
    #taking input for each sales
    for i in range(1,5,1):
        print('Week ', i,' :',end=' ')
        sales[i-1] = int(input())
        totalSales += sales[i-1]
    #checking if the total sales is more than 50000 or not
    comm = 0
    if totalSales > 50000:
        comm = 5
    #giving Remarks
    remark = ""
    if totalSales >= 80000:
        remark = "Excellent"
    elif totalSales < 80000 and totalSales >= 60000:
        remark = "Good"
    elif totalSales < 60000 and totalSales >= 40000:
        remark = "Average"
    else:
        remark = "WORK HARD"
    #printing the Output
    print()
    print("REPORT")
    for i in range(1,5,1):
        print("WEEK ",i," :",sales[i-1])
    print("TOTAL SALES :", totalSales)
    print("COMMISSION :",comm/100*totalSales)
    print("REMARK :",remark)

sales()