a=input().split()
 
a=list(a)
 
lena=len(a)
 
i=0
 
max=0
 
min=99999
 
while i<lena:
            
            num=len(a[i])
            
            if max<num:
                        max=num
                        flagmax=i
                        
            if min>num:
                        min=num
                        flagmin=i
                        
            i+=1
 
print(a[flagmax])
 
print(a[flagmin])