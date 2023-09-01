# Count Ways To Reach The N-th Stairs
**Code Studio:** https://www.codingninjas.com/studio/problems/count-ways-to-reach-nth-stairs_798650?utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_10&leftPanelTab=0 

We use **Recursion**. However, this problem can be solved by the concept of Dynamic programming more efficiently, which is why only a few test cases pass and rest give TLE. 

Recursive solution:

```
#include <bits/stdc++.h> 
int countDistinctWays(int nStairs) {
    int ways=0;
    //base cases
    if(nStairs==-1){
        return 0;
    }
    if(nStairs==0){
        //0th that is first stare pe jaane ka 1 tareeka jo ki hai take 1 step. 1 way so +1;
        return 1;
    }

    ways=ways+countDistinctWays(nStairs-1) + countDistinctWays(nStairs-2);
    return ways;
}

```
