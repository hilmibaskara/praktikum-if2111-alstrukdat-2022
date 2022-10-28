x=int(input())
word=["Hello" for i in range (x)]
length=[0 for i in range (x)]
for i in range (x):
    word[i]=input()    
    length[i]=len(word[i])
#for i in range (x):
    #if length[i]>10:
        #print(str(word[i][1])+str(length[i]-2)+str(word[i][-1]))
    #else:
        #print(word[i])
