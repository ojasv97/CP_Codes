import numpy as np
import seaborn as sns
# number of simulations
n=10000
x1=np.random.uniform(low=-1,high=1, size=n)
x2=np.random.uniform(low=-1,high=1, size=n)
z=np.sqrt((x1**2)+(x2**2))
print(4*sum(z<=1)/n)
inout=np.where(z<=1,'in','out')
sns.scatterplot(x1,x2,hue=inout,legend=False)