# Count Primes 
Leetcode: https://leetcode.com/problems/count-primes/  

**Brute Force**
Exceeds time on a larger number

**Time Complexity** : O(N*N)

```
class Solution {
public:
    bool isprime(int num){
       A for(int i=2;i<num;i++){
            if(num%i==0){
                return false;
            }
        }
        return true;
    }
    int countPrimes(int n) {
        int count=0;
        for(int i=2;i<n;i++){
            if(isprime(i)){
                count++;
            }
        }
    return count;
    }
};
```

# Sieve

**Time Complexity** : O(N* log(log N))
as good as O(N)

```
class Solution {
public:

    int countPrimes(int n) {
        int count=0;
        vector<bool> isprime(n+1,true);
    
    // isprime(n+1,true);
    // [T,T,T,T....]
    // 0 1 2 3 4 ....n 

        isprime[0]=isprime[1]=false;

        for(int i=2;i<n;i++){
            if(isprime[i]){
            
        //j's are multiples of i. first multiple of i is 2*i ,
        //so initialize j=2*i and then after this comes the next multiple which is j+i 
        //e.g. i=3 not first multiple of 3 is 3*2=6 , upcoming multiples are 6+3=9, 9+3=12..so on
        // thus, j that is each multiple is incremented by +i.
        //we set all multiples of a prime i to false, according to Sieve.
        
                for(int j=2*i;j<n;j=j+i)
                {
                    isprime[j]=false;
                }
                count++;
            }
        }
    return count;
    }
};
```

# Find GCD of Array
https://leetcode.com/problems/find-greatest-common-divisor-of-array/

**Euler's Formula**
```
class Solution {
public:
    int gcd(int a, int b){
        if(a==0){
            return b;
        }
        if(b==0){
            return a;
        }
        if(a>b)
        return gcd(a-b,b);
        else
        return gcd(a,b-a);
    }

    int findGCD(vector<int>& nums) {
        int n = nums.size();
        int smallest = nums[0];
        int largest = nums[0];

        for (int i = 1; i < n; ++i) {
            smallest = min(smallest, nums[i]);
            largest = max(largest, nums[i]);
        }
        return gcd(smallest,largest);
    }
};
```
