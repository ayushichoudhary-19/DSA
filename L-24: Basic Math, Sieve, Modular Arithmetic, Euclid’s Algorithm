//Count Primes on Leetcode: https://leetcode.com/problems/count-primes/  

//Brute Force
//Exceeds time on larger number
class Solution {
public:
    bool isprime(int num){
        for(int i=2;i<num;i++){
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

//Sieve
class Solution {
public:

    int countPrimes(int n) {
        int count=0;
        vector<bool> isprime(n+1,true);
//[T,T,T,T....]
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

//Optimized Sieve
//Now in the above code
