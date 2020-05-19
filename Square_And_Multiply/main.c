#include <stdio.h>
#include <stdlib.h>

long long int pow(long long int x, long long int h, long long int n)
{
    long long int r=x;
	int bin[32];
	int i=0;
	while(h>0) {
		if(h%2) bin[i]=1;
		else bin[i]=0;
		h=h/2;
		i++;
	}
	i--;
	while(i>0) {
		r=(r*r)%n;
		if(bin[--i]) r=(r*x)%n;
	}
	return r;
}

long long int gcd(long long int a, long long int b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

int main()
{
	long long int p,q,n,pn,e,d;

	long long int i,j;

	long long int m=7273;  //HI
	long long int c;
	long long int m_;
	scanf("%lld %lld", &p, &q);

	n=p*q;
	pn=(p-1)*(q-1);

	for(i=2; i<30; i++) {
        if(gcd(i,pn)==1) e=i;
        else continue;

        for(j=2; j<pn; j++) {
            if((e*j)%pn==1) {
                d=j;
                break;
            }
        }
        c=pow(m,e,n);
        m_=pow(c,d,n);
        printf("\ne = %lld, d = %lld\n",e,d);
        printf("m = %lld, c = %lld, m_ = %lld\n", m,c,m_);
	}

	return 0;
}
