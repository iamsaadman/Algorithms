#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void permute(string s, int left, int right)
{  
        for (int i = left; i <= right; i++)
        {
            swap(s[left], s[right]);
            permute(s, left + 1, right);
            swap(s[left], s[i]);
               cout<<s<<endl;
        }
 
}

int main()
{
    string s = "DSA";
    int size = s.size();

    permute(s, 0, size - 1);

    return 0;
}