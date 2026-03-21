#include<iostream>
using namespace std;
#include <bits/stdc++.h>
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
    int m = needle.length();

    // If needle is longer than haystack, it's impossible to find
    if (m > n) return -1;

    // We only need to loop up to (n - m)
    for (int i = 0; i <= n - m; i++) {
        // Check if the substring starting at i matches needle
        if (haystack.substr(i, m) == needle) {
            return i;
        }
    }

    return -1;
    }
};
