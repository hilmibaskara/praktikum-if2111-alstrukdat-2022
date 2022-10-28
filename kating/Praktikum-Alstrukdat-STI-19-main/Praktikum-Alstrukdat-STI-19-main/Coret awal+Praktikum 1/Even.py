import pandas as pd
w=int(input())
half=w//2
check=False
for i in range(1,half+1):
    test=2*i
    if ((w-test)%2==0):
        check=True
if (check==True):
    print("YES")
else:
    print("NO")
    