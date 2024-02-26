print("P=readvec(\"top10.gp\")[1]");
P=readvec("top10.gp")[1];
##
print("conversion");
for(i=1,#P,p=P[i];e=p[2]^p[3];P[i]=if(p[1]==-1,e^2-e+1,p[1]*e+1));
##

print("S=readvec(\"sqrtm1.gp\")[1]");
S=readvec("sqrtm1.gp")[1];
##
print("validation");
for(i=1,#S,s=S[i];my(p=P[i]);print1(s^2%p==p-1););
##

print("XY=readvec(\"sos.gp\")[1]");
XY=readvec("sos.gp")[1];
##
print("validation");
for(i=1,#XY,xy=XY[i];[x,y]=xy;my(p=P[i]);print1(x^2+y^2==p););
##
