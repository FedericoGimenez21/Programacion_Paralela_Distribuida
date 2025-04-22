import random

import math 
from timeit import default_timer as timer
start = timer()
niter = 1000000
circle_point=0

for i in range(0,niter):

  x=random.uniform(0, 1)
  y=random.uniform(0, 1)

  #distancia
  d=math.sqrt((x*x)+(y*y))
  if d<=1:
    circle_point+=1

resultado=(circle_point/niter)*4
end = timer()

print(f'elapsed time: {end - start}')
print("Valor de pi: ",resultado)
  