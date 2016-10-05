m=input("Enter a number to be checked for primality: ")
x=m-1
n=2
k=0
while (x/n==float(x)/float(n)):
    k=k+1
    x=x/n
a=2
b0=(a ** x)%m
if (b0==1 | b0==-1):
    print m+" is a prime number"
b=(b0 ** 2)%m
while(1):
    b=(b ** 2)%m
    if (b==1):
        print "Not a prime number"
        break
    elif (b==m-1):
        print "A prime number"
        break
    else:
        continue
