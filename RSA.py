def gcd(a, b):
    if b==0: return a
    return gcd(b,a%b)


p, q = map(int, input('input p,q : ').split())
n=p*q;
m=7273;  #HI = 72 73
pn=(p-1)*(q-1);
for k in range(2,30):
    if gcd(k,pn)==1: e=k;
    else: continue;
    
    for x in range(2,pn):
        if (e*x)%pn==1:
            d=x;
            break;
    
    c=pow(m,e,n)
    m_=pow(c,d,n)
    print("\ne = ",e," d = ",d)
    print("m = ",m," c = ",c," m_ = ",m_)
