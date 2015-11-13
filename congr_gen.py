import matplotlib.pyplot as plt

a=1103515245
c=12345
m=2**31
x=0
N=10000
def congruential():
    global x
    for j in range(N):
        x=(a*x+c) % m;
        yield x
        
y=list()
gen=congruential()
for i in range(N):   
    y.append(gen.next())
x_data=range(N)

print y
plt.hist(y)
plt.show()
