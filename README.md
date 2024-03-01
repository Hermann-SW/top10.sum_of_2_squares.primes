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
The enclosing angle brackets are for allowing PARI/GP "readvec()" multiline input only.  

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

## files

name|size|what
----|----|----
top10.gp|4KB|ith top10 prime
sqrtm1.gp|47MB|sqrt(-1) (mod p) for ith prime p
sos.gp|45MB|[x,y] for ith prime =x^2+y^2 (x>y>0)

## validation

[validate.gp](validate.gp), PARI/GP 
```
hermann@7950x:~/top10.sum_of_2_squares.primes$ gp -q < validate.gp 
P=readvec("top10.gp")[1]
  ***   last result: cpu time 0 ms, real time 0 ms.
conversion
  ***   last result: cpu time 355 ms, real time 376 ms.
S=readvec("sqrtm1.gp")[1]
  ***   last result: cpu time 346 ms, real time 394 ms.
validation
1111111111
  ***   last result: cpu time 1,643 ms, real time 1,660 ms.
XY=readvec("sos.gp")[1]
  ***   last result: cpu time 266 ms, real time 286 ms.
validation
1111111111
  ***   last result: cpu time 384 ms, real time 391 ms.
hermann@7950x:~/top10.sum_of_2_squares.primes$ 
```

validate.py, Python with gmpy2:  
TODO

validate.js, Node with BigInt:  
TODO

[validate.cc](validate.cc) ([Makefile](Makefile)), C++ with libgmpxx:  

```
hermann@7950x:~/top10.sum_of_2_squares.primes$ make clean
rm -f validate.cc.out
hermann@7950x:~/top10.sum_of_2_squares.primes$ make validate
g++ -O3 validate.cc -lgmpxx -lgmp -o validate.cc.out
./validate.cc.out
1111111111
1111111111
hermann@7950x:~/top10.sum_of_2_squares.primes$ time make validate 2>/dev/null 
./validate.cc.out

real	0m2.543s
user	0m2.405s
sys	0m0.138s
hermann@7950x:~/top10.sum_of_2_squares.primes$ 
```

## runtimes

Proth prime computations were done on AMD 7950X CPU Ubuntu 22.04 with
LLR 4.0.5 software of Jean Penné based on (x86 only) gwnum lib, with
16 threads forced onto 8C/16T chiplet0:  
http://jpenne.free.fr/index2.html  
Yves Gallot pointed out that no computation is needed for the 5 primes of form x^2+1:  
https://mersenneforum.org/showthread.php?p=651245#post651245  
mersenneforum.org @Neptune showed how to do the Phi(3,_) prime computations superfast:  
https://mersenneforum.org/showthread.php?p=651488#post651488  
```
? {
b=516693;
e=1048576;
p=polcyclo(3,-b^e);
s=b^(e*3/2);
[M,V]=halfgcd(s,p);
[x,y]=[V[2],M[2,1]];
}
? ##
  ***   last result: cpu time 347 ms, real time 347 ms.
? x^2+y^2==p
%19 = 1
? s^2%p==p-1
%20 = 1
? #digits(p)
%21 = 11981518
?
```

rank|description         |digits    |who  |year|runtime |comment
---:|:-------------------|---------:|----:|---:|-------:|------:
7e|Phi(3,-516693^1048576)|11,981,518|L4561|2023|347ms   |
 8|Phi(3,-465859^1048576)|11,887,192|L4561|2023|358ms   |
11|10223*2^31172165+1    |9,383,761 |SB12 |2016|6:33:01h|
15|1963736^1048576+1     |6,598,776 |L4245|2022|—       |x^2+1
16|1951734^1048576+1     |6,595,985 |L5583|2022|—       |x^2+1
17|202705*2^21320516+1   |6,418,121 |L5181|2021|4:09:02h|
19|1059094^1048576+1     |6,317,602 |L4720|2018|—       |x^2+1
21|919444^1048576+1      |6,253,210 |L4286|2017|—       |x^2+1
22|81*2^20498148+1       |6,170,560 |L4965|2023|—       |x^2+1
23|7*2^20267500+1        |6,101,127 |L4965|2022|1:59:20h|
