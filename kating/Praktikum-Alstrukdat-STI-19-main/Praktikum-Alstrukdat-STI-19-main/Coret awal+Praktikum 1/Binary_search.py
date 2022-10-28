a=[1,3,4,5,7,11,12,24,26,29,40]
i=0
j=10
x=24
while (i<j):
    m=(i+j)//2
    if (x>a[m]):
        i=m+1
    else:
        j=m
if (x==a[i]):
    print(i)
else:
    print("Error")