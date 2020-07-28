/*Problem Description

Given a positive integer A, the task is to count the total number of set bits in the binary representation of all the numbers from 1 to A.

Return the count modulo 109 + 7.



Problem Constraints
1 <= A <= 109



Input Format
First and only argument is an integer A.



Output Format
Return an integer denoting the ( Total number of set bits in the binary representation of all the numbers from 1 to A )modulo 109 + 7.



Example Input
Input 1:

 A = 3
Input 2:

 A = 1


Example Output
Output 1:

 4
Output 2:

 1


Example Explanation
Explanation 1:

 DECIMAL    BINARY  SET BIT COUNT
    1          01        1
    2          10        1
    3          11        2
 1 + 1 + 2 = 4 
 Answer = 4 % 1000000007 = 4
Explanation 2:

 A = 1
  DECIMAL    BINARY  SET BIT COUNT
    1          01        1
 Answer = 1 % 1000000007 = 1*/
 
 #define MOD 1000000007
    #define ll long long int
    ll leftmost (ll n) {    //function to find the leftmost set bit
        int pos = 0;
        while(n > 1)  {
            pos++;
            n = n >> 1;
        }
        return pos;
    }
    ll countBits (ll n)  {
        if(n == 0)    return 0; //if the number is 0 return 0
        ll m = leftmost(n);
        if(n == ((1 << (m + 1)) - 1))   return ((m + 1)*(1 << m));  //if number is of form 2^b-1 return directly
        n = n - (1 << m);   //if not all bits are set
        return (n + 1) + (m * ( 1 << (m - 1))) + countBits(n);  //recursively calling for the rest of the bits
    }
    int Solution::solve(int n) {
        ll result = countBits(n);
        return result%MOD;
    }
