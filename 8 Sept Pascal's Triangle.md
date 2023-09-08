# Problem type- 1
Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.


## Extreme brute force:

```
class Solution {
private:
    long  nCr(int n, int r){
```


 just like in fact(n)/ fact(r) * fact(n-r)
        fact(n-r) cancels most of fact(n) elements,
        so fact(r) also cancels some of them
        depending which is greater.
        for 10 C 3;
        10*9*8 /
        3! * 5!;
        we use 3! as r as 5! get's cancelled
        but for 10 C 5;
        10*9*8 /
        5! * 3!;
        we better consider (n-r)! as r because bigger one is r and it's being cancelled
        so whichever is smaller of the two we check nCr with that and other one is cancelled in num.

```
        if(r>n-r){
            r=n-r;
        }


        long long result=1;

```
  //FOR OPTIMIZATION PURPOSES WE FIRSTLY MULTIPLE EVERYTHING THEN DIVIDE IN SAME LOOP
            //TO AVAOID OVERFLOWS
//WATCH STRIVER'S FOR DETAILS

```
 for (int i = 0; i < r; ++i) {
            result *= (n - i);
            result /= (i + 1);
        }
        return result;
    }

public:
    vector<int> getRow(int rowIndex) {
            //row  is zero indexed
            //0th row has 1 elem
            //1st has two
            //rowIndex th row has rowIndex+1 elements;
        vector<int> ans;

        //nCr is applied when r and c are 1-indexed so formula is r-1 C c-1 but here
        //they already are 0 indexed so we do rCn

        for(int col=0;col<=rowIndex;col++){
           ans.push_back(nCr(rowIndex,col));
        }
            return ans;
    }
};
```




## Better Solution:

Now at let's say r=5, so we're at 6th row which has 6 elements.

![image](https://github.com/ayushichoudhary-19/3MonthDSA/assets/73214455/0546b6c1-7085-4492-bece-1abc162f359b)


So at each column of the given row, nCr is only adding one fraction more at each step.

1st and last column will always be one, so we need not worry about them.
**Notice** that at each step, some extra fraction is getting multipled and the DENOMINATOR of this is same as the column number of that position.

- So, observing the rows and columns, we can see that in extra multiplied fraction, deno is always col and numberator is always row-col. Eg. for col 1, ans=ans*(6-1)/1=5/1;
- Now, multiply further, for col=2: ans*=(6-2)/2=4/2...so on untill we get out of for loop that runs n times;

```
class Solution {
public:
    vector<int> getRow(int rowIndex) {
         vector<int> result;

        //let's make it 1-indexed
        int row=rowIndex+1;

        //first col of row is always 1
        long long ans=1;
        result.push_back(ans);

        // nth row has n+1 items so run the loop accordingly
         for(int col=1;col<row;col++){
             ans*=(row-col);
             ans/=col;
             result.push_back(ans);
         }
         return result;
    }
};
```


# Problem type- 2 (118. Pascal's Triangle : https://leetcode.com/problems/pascals-triangle/?envType=daily-question&envId=2023-09-08)
Given an integer numRows, return the first numRows of Pascal's triangle.
```
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;

       for(int row=1;row<=numRows;row++){
            vector<int> ans;
            ans.push_back(1);
            long long prod=1;
           for(int col=1;col<row;col++){
               prod=prod*(row-col);
               prod=prod/(col);
               ans.push_back(prod);
           }
           result.push_back(ans);
       }
       return result;
    }
};
```
