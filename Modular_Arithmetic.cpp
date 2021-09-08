//define MOD in template

int modAdd( int a , int b )
{
    return ( a%MOD + b%MOD ) % MOD;
}

int modSubtract( int a , int b )
{
    return ( ( a%MOD - b%MOD ) + MOD )%MOD;
}

int modProduct( int a , int b )
{
    return ( a%MOD * b%MOD ) % MOD;
}

int powerMod( int a , int b )
{
    if(b==0)
        return 1;
 
    int x = powerMod(a,b/2);
 
    if(b%2==0) 
        return (x*x) % MOD;
    else
        return ( ((x*x) % MOD) * a ) % MOD;
}
 
int modInverse(int a)
{
    int x = powerMod( a , MOD-2 );
    return x;
}

int modDivide( int a , int b )
{
    return ( a%MOD * modInverse(b)%MOD ) % MOD;
}
