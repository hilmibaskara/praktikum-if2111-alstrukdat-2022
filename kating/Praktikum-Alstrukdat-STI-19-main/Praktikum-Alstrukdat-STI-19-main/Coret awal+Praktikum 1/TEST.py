n=int(input())
a=[[0 for j in range (n)]for i in range (n)]
for i in range (n):
    for j in range (n):
        a[i][j]=int(input("Masukkan nilai a["+str(i)+"]["+str(j)+"]= "))
for i in range (n):
    for j in range (n):
        print(a[i][j],end="\t")
    print(' ')