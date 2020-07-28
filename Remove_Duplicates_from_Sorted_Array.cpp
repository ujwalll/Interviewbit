/*
Given a sorted array, remove the duplicates in place such that each element appears only once and return the new length.

Note that even though we want you to return the new length, make sure to change the original array as well in place

Do not allocate extra space for another array, you must do this in place with constant memory.

 Example:
Given input array A = [1,1,2],
Your function should return length = 2, and A is now [1,2]. 

*/
int Solution::removeDuplicates(vector<int>& a) {
    // int n=a.size();
    int x=1,cur=a[0];
    for(int i=1;i<a.size();i++){
       if(a[i]!=cur){
           cur=a[i];
           a[x]=cur;
           x++;
       }
    }
    a.erase(a.begin()+x,a.end());
    return a.size();
}

