import random

p=509
q=431
n=p*q

a=int(input('input a : '))

def enc (A,R,M):
    return (A*p+2*R+M)%n

def dec(C):
    return (C%p)%2


for m1 in range(2):
    for m2 in range(2):
        for m3 in range(2):
            print('m1 = ',m1,' m2 = ',m2,'m3 = ',m3)
            for r in range(1,10):
                print('r = ',r)
                c1=enc(a,r,m1)
                c2=enc(a,r,m2)
                c1_2=(c1+c2)%n
                c1_2_=enc(a,r,m1^m2)
                print('Enc(m1) = ',c1,', Enc(m2) =',c2,', Enc(m1)+Enc(m2) mod n = ',c1_2,', Enc(m1+m2) = ',c1_2_)

                d1=dec(c1_2)
                d2=dec(c1_2_)
                print('Dec(Enc(m1)+Enc(m2)) = ', d1, ', Dec(Enc(m1+m2)) = ',d2)


                c1=enc(a,r,m1)
                c2=enc(a,r,m2)
                c1_2=(c1*c2)%n
                c1_2_=enc(a,r,m1*m2)
                print('Enc(m1) = ',c1,', Enc(m2) =',c2,', Enc(m1)*Enc(m2) mod n = ',c1_2,', Enc(m1*m2) = ',c1_2_)

                d1=dec(c1_2)
                d2=dec(c1_2_)
                print('Dec(Enc(m1)*Enc(m2)) = ', d1, ', Dec(Enc(m1+m2)) = ',d2)

                
                c1=enc(a,r,m1)
                c2=enc(a,r,m2)
                c3=enc(a,r,m3)
                c1_2_3=(c1*c2*c3)%n
                c1_2_3_=enc(a,r,m1*m2*m3)
                print('Enc(m1) = ',c1,', Enc(m2) =',c2,', Enc(m1)*Enc(m2)*Enc(m3) mod n = ',c1_2_3,', Enc(m1*m2*m3) = ',c1_2_3_)

                d1=dec(c1_2_3)
                d2=dec(c1_2_3_)
                print('Dec(Enc(m1)*Enc(m2)*Enc(m3)) = ', d1, ', Dec(Enc(m1*m2*m3)) = ',d2)
