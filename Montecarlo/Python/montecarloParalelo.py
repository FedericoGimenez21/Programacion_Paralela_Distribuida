import random
from multiprocessing import Pool, cpu_count
from math import sqrt
from timeit import default_timer as timer
import os

def pi_part(n):
    print(n)

    count = 0

    for i in range(int(n)):

        x=  random.uniform(0, 1)
        y = random.uniform(0, 1)

        d=sqrt((x*x)+(y*y))

        if d <= 1:
            count += 1

    return count


def main():

    start = timer()

    np = cpu_count()
    print(f'You have {np} cores')

    n = 1000000
    
    part_count = [n/np for i in range(np)]
    

    with Pool(processes=np) as pool:
        start2 = timer()
        count = pool.map(pi_part, part_count)
        pi_est = sum(count) / (n * 1.0) * 4

        end = timer()

        print(f'elapsed time paralelo: {end - start2}')
        print(f'π estimate: {pi_est}')
    print(f'elapsed time  total: {end - start}')
        

if __name__=='__main__':
    main()