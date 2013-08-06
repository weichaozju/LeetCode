/*
 Author:     Weixian Zhou, ideazwx@gmail.com
 Date:       Jul 5, 2012
 Problem:    Median of Two Sorted Arrays
 Difficulty: medium
 Source:     http://www.leetcode.com/onlinejudge
 Notes:
 There are two sorted arrays A and B of size m and n respectively. Find the
 median of the two sorted arrays. The overall run time complexity should be
 O(log (m+n)).

 Solution:
 First compare the median of the two arrays, say Am and Bm, if Am is larger
 than Bm, then there are at least half of m + n elements that are less than
 Am. It means the overall median must less than or equal to Am. Thus the
 elements that larger than Am are eliminated.
 Repeat the above process until the number of eliminated elements are half
 of m + n;
 */
#include <vector>
#include <set>
#include <climits>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cmath>
#include <cstring>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int total = m + n;  
        if (total & 0x1)  
            return findKth(A, m, B, n, total / 2 + 1);  
        else  
            return (findKth(A, m, B, n, total / 2)  
                    + findKth(A, m, B, n, total / 2 + 1)) / 2; 
    }
    double findKth(int a[], int m, int b[], int n, int k)  
{  
    //always assume that m is equal or smaller than n  
    if (m > n)  
        return findKth(b, n, a, m, k);  
    if (m == 0)  
        return b[k - 1];  
    if (k == 1)  
        return min(a[0], b[0]);  
    //divide k into two parts  
    int pa = min(k / 2, m), pb = k - pa;  
    if (a[pa - 1] < b[pb - 1])  
        return findKth(a + pa, m - pa, b, n, k - pa);  
    else if (a[pa - 1] > b[pb - 1])  
        return findKth(a, m, b + pb, n - pb, k - pb);  
    else  
        return a[pa - 1];  
}
};
