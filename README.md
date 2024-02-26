[x,y,s] for top 10 known primes p with s²=-1 (mod p) and p=x²+y² (all above 6million decimal digits)

## top10 primes "=1 (mod 4)" from [largest known primes list](https://t5k.org/primes/lists/all.txt)
[top10.gp](top10.gp)  
```
{[                   \\ https://t5k.org/primes/lists/all.txt    as of 2/25/2024
[-1,516693,1048576], \\  7e Phi(3,-516693^1048576)          11981518 L4561 2023
[-1,465859,1048576], \\  8  Phi(3,-465859^1048576)          11887192 L4561 2023
[10223,2,31172165],  \\ 11  10223*2^31172165+1               9383761 SB12  2016
[1,1963736,1048576], \\ 15  1963736^1048576+1                6598776 L4245 2022
[1,1951734,1048576], \\ 16  1951734^1048576+1                6595985 L5583 2022
[202705,2,21320516], \\ 17  202705*2^21320516+1              6418121 L5181 2021
[1,1059094,1048576], \\ 19  1059094^1048576+1                6317602 L4720 2018
[1,919444,1048576],  \\ 21  919444^1048576+1                 6253210 L4286 2017
[81,2,20498148],     \\ 22  81*2^20498148+1                  6170560 L4965 2023
[7,2,20267500]       \\ 23  7*2^20267500+1                   6101127 L4965 2022
]}
```

## validation

Not all 10 sum of two squares and sqrt(-1) (mod p) yet ...

[validate.gp](validate.gp), PARI/GP 
```
hermann@7950x:~/top10.sum_of_2_squares.primes$ gp -q < validate.gp 
P=readvec("top10.gp")[1]
  ***   last result: cpu time 385 ms, real time 413 ms.
S=readvec("sqrtm1.gp")[1]
  ***   last result: cpu time 81 ms, real time 89 ms.
11
XY=readvec("sos.gp")[1]
  ***   last result: cpu time 54 ms, real time 54 ms.
1
done, all asserts OK
hermann@7950x:~/top10.sum_of_2_squares.primes$ 
```

validate.py, Python with gmpy2:  
TODO

validate.js, Node with BigInt:  
TODO

validate.cc, C++ with libgmpxx:  
TODO
