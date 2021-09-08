
//------------------------------------------------------------------------------------------------------
//ALL THE SUBSETS OF AN ARRAY
    
	//array name -> a[n] , size of array -> n
 
	int m=pow(2,n);
	for(int i=1 ; i<=m-1 ; i++)
	{
		int copyi = i;
		int j=0;
		while(copyi>0) 
		{
			int bit = copyi%2;      // binary of the number
			copyi /=  2;            //
 
 
			if(bit==1)              //                      
				cout<<a[j]<<" ";    //print the corresponding elements of the array                   
 
			j++;
		}
		cout<<"\n";
	}
 
//--------------------------------------------------------------------------------------------------------
//BINARY OF A NUMBER
 
	//number -> x
 
	int copyx = x;
	vector <int> binary;
	while(copyx>0)
	{
		int bit = copyx%2;
		copyx /= 2;
 
		binary.pb(bit);
	}
 
	// the vector contains the reverse of the binary so it needs to be reversed
	reverse(binary.begin() , binary.end());
 
	for(auto i=binary.begin() ; i!=binary.end() ; i++)
		cout<<*i<<" ";
 
//---------------------------------------------------------------------------------------------------------
//SIEVE OF ERATOSTHENES
 
	// finds all the primes numbers till n
	// all primes are given the value true and start from 2,3,5,7.......
 
	vector<bool> v(n,true);      // n -> number till we need to find the primes               
 	for(int i=2 ; i*i <= n ; i++)
 	{
 		if(v[i])
 		{
 			for(int j=i*i ; j<=n ; j+=i)
 				v[j] = false;
 		}
 	}
 
//---------------------------------------------------------------------------------------------------------
//POWER FUNCTION
 
 	//returns a^n
 
int pow(int a , int n)
{
	if(n==0)
		return 1;
	else if(n%2==0)
		return pow(a*a,n/2);
	else
		return pow(a*a,n/2)*a;
}
 
//----------------------------------------------------------------------------------------------------------
//POWER FUNCTION MOD X
 
	//returns (a^n)%x;
 
int pow(int a , int n , int x)
{
	if(n==0)
		return 1;
	else if(n%2==0)
		return pow( (a*a)%x , n/2 , x ) % x;
	else
		return ( pow( (a*a)%x , n/2 , x ) * a ) % x;
}
 
//-----------------------------------------------------------------------------------------------------------
//MERGE SORT
 
	// transforms the original array as we are passing array by value
 
void merge_sort (int a[] , int first , int last)
{
	if(first>=last)
		return;
 
	int mid = (first+last)/2;
 
	merge_sort(a , first , mid);
	merge_sort(a , mid+1 , last);
 
	int left[mid-first+1] , right[last-mid];
 
	for(int i=first ; i<= mid ; i++)
		left[i-first] = a[i];
 
	for(int i=mid+1 ; i<=last ; i++)
		right[i-mid-1] = a[i];
 
	int ptr1 = 0 , ptr2 = 0;
	int i = first;
 
	while(ptr1 < mid-first+1 and ptr2 < last-mid)
	{
		if(left[ptr1] <= right[ptr2])
		{
			a[i] = left[ptr1];
			ptr1++;
		}
		else
		{
			a[i] = right[ptr2];
			ptr2++;
		}
		
		i++;
	}
 
	while(ptr1 < mid-first+1)
	{
		a[i] = left[ptr1];
		ptr1++;
		i++;
	}
 
	while(ptr2 < last-mid)
	{
		a[i] = right[ptr2];
		ptr2++;
		i++;
	}
}
 
//-----------------------------------------------------------------------------------------------------------
//PERMUTATIONS OF AN ARRAY
 
void findPermutations(int a[], int n)
{
    sort(a, a + n);
 
    cout << "Possible permutations are:\n";
    do {
        for(int i=0 ; i<n ; i++)
        	cout << a[i] << "  ";
        cout << endl;
    } while (next_permutation(a, a + n));
}
 
//-----------------------------------------------------------------------------------------------------------
//SPARSE TABLE
 
//this vector is declared globally
vector <vector<int>> st;
 
void build_sparse_table(int a[] , int n)
{
	//first row of sparse table as it is the same array as subarray is 1
	vector <int> firstline;
	for(int i=0 ; i<n ; i++)
		firstline.pb(a[i]);
	st.pb(firstline);
 
	int y = 2;
	int counter=1;
 
	while(y<=n){
		vector <int> x;
 
		for(int i=0 ; i<=n-y ; i++)
			x.pb( st[counter-1][i] + st[counter-1][i+y/2] );
 
		st.pb(x);
 
		y *= 2;
		counter++;
	}
}
	//suppose we want the range query of subarray of length l starting from index i
	//then 
	//		int logi = log2(l);
	//		st[logi][i] , st[logi][ i+l-pow(2,logi) ]
 
//-----------------------------------------------------------------------------------------------------------
// SEGMENT TREE 
 
//start_index , end_index , q_start , q_end follows 0 based indexing
 
// BUILD
void build_segment_tree(int tree[] , int a[] , int tree_ind , int start_index , int end_index)
{
	if(start_index > end_index)
		return;
 
	if(start_index == end_index){
		tree[tree_ind] = a[start_index];
		return;
	}
 
	int mid = (start_index+end_index)/2;
 
	build_segment_tree(tree , a , 2*tree_ind , start_index , mid);
	build_segment_tree(tree , a , 2*tree_ind+1 , mid+1 , end_index);
 
	tree[tree_ind] = tree[2*tree_ind] + tree[2*tree_ind+1] ;
}
 
//QUERY - returns the sum of the subarray starting from qstart to qend
int query(int tree[] , int tree_ind , int start_index , int end_index , int q_start , int q_end)
{
	if(q_start <= start_index and q_end >= end_index)
		return tree[tree_ind];
 
	if(q_end < start_index or q_start > end_index)
		return 0;
 
	int mid = (start_index+end_index)/2;
 
	int left_half = query(tree , 2*tree_ind , start_index , mid , q_start , q_end);
	int right_half = query(tree , 2*tree_ind+1 , mid+1 , end_index, q_start , q_end);
 
	return __gcd(left_half,right_half);
}
 
//---------------------------------------------------------------------------------------------------------------
// nCr by fermants theorem
	
	// needs fact[n] array storing factorial of each number
	// calculate it beforehand 
int powerMod( int a , int b)
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
 
int nCrMODp(int n , int i) 
{
    int x = ( ( ( ( fact[n] % MOD ) * ( modInverse(fact[i]) % MOD ) ) % MOD ) * ( modInverse(fact[n-i]) % MOD ) ) % MOD;
    return x; 
}

//---------------------------------------------------------------------------------------------------------------
//MODULAR ARITHMETIC

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

int powerMod( int a , int b)
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
//---------------------------------------------------------------------------------------------------------------
