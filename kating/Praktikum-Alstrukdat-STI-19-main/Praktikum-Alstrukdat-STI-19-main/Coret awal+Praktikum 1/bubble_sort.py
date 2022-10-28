arr=[3,5,4,1,7]
temp=0
for i in range ((len (arr))):
    if (arr[i+1]<arr[i]):
        temp=arr[i]
        arr[i]=arr[i+1]
        arr[i+1]=temp
for i in range((len (arr))):
    print(arr[i])