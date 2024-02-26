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


Above format is for avoiding difficult parsing in languages other than PARI/GP only.  
For PARI/GP unchanged entries from list of largest known primes directly work:
```
$ gp -q
? Phi(x,y)=polcyclo(x,y);
? P=readvec("top10.2.gp")[1];
? ##
  ***   last result: cpu time 463 ms, real time 501 ms.
? #P
10
? #digits(P[1])
11981518
? 

$ cat top10.2.gp 
{[ \\ https://t5k.org/primes/lists/all.txt as of 2/25/2024
Phi(3,-516693^1048576), \\  7e         11981518 L4561 2023
Phi(3,-465859^1048576), \\  8          11887192 L4561 2023
10223*2^31172165+1,     \\ 11           9383761 SB12  2016
1963736^1048576+1,      \\ 15           6598776 L4245 2022
1951734^1048576+1,      \\ 16           6595985 L5583 2022
202705*2^21320516+1,    \\ 17           6418121 L5181 2021
1059094^1048576+1,      \\ 19           6317602 L4720 2018
919444^1048576+1,       \\ 21           6253210 L4286 2017
81*2^20498148+1,        \\ 22           6170560 L4965 2023
7*2^20267500+1          \\ 23           6101127 L4965 2022
]}
$
```

## validation

Not all 10 sum of two squares and sqrt(-1) (mod p) yet ...

[validate.gp](validate.gp), PARI/GP 
```
hermann@7950x:~/top10.sum_of_2_squares.primes$ gp -q < validate.gp 
P=readvec("top10.gp")[1]
  ***   last result: cpu time 0 ms, real time 0 ms.
conversion
  ***   last result: cpu time 389 ms, real time 414 ms.
S=readvec("sqrtm1.gp")[1]
  ***   last result: cpu time 80 ms, real time 88 ms.
validation
1__1______
  ***   last result: cpu time 366 ms, real time 378 ms.
XY=readvec("sos.gp")[1]
  ***   last result: cpu time 54 ms, real time 54 ms.
validation
1_________
  ***   last result: cpu time 72 ms, real time 80 ms.
hermann@7950x:~/top10.sum_of_2_squares.primes$ 
```

validate.py, Python with gmpy2:  
TODO

validate.js, Node with BigInt:  
TODO

validate.cc, C++ with libgmpxx:  
TODO
