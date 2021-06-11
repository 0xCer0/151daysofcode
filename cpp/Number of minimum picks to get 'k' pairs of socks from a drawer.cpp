// A drawer contains socks of n different colours. The number of socks available of ith colour is given by a[i] where a is an array of n elements. Tony wants to take k pairs of socks out of the drawer. However, he cannot see the colour of the sock that he is picking. You have to tell what is the minimum number of socks Tony has to pick in one attempt from the drawer such that he can be absolutely sure, without seeing their colours, that he will have at least k matching pairs.

// Example :

// Input:
// N = 4, K = 6
// a[] = {3, 4, 5, 3}
// Output: 15
// Explanation: 
// All 15 socks have to be picked in order
// to obtain 6 pairs.

int p=0, sum=0;
for(int i=0;i<n;++i){
p+=a[i]/2;
if (a[i]%2==0)
sum+=(a[i]-2)/2;
else
sum+=(a[i]-1)/2;
}
if(p<k)
return -1;
if(sum>=k)
return 2*(k-1)+n+1;
else
return 2*sum +n +(k+sum);
}