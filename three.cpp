#include <iostream>
using namespace std;


int countBits(int N) {
    int count = 0;
    while (N > 0) {
        N = N / 2; 
        count++;
    }
    return count;
}


bool isBinaryPalindrome(int N) {
    if (N == 0) return true;  
    
    int numBits = countBits(N);
    int left = 0, right = numBits - 1;
    
    while (left < right) {
  
        int leftBit = (N / powerOfTwo(left)) % 2;
        int rightBit = (N / powerOfTwo(right)) % 2;
        
        if (leftBit != rightBit) {
            return false; 
        }
        
        left++;
        right--;
    }
    
    return true; 
}


int powerOfTwo(int k) {
    int result = 1;
    for (int i = 0; i < k; ++i) {
        result *= 2;
    }
    return result;
}

int main() {
    int N;
    cout << "Enter the number N: ";
    cin >> N;
    
    if (isBinaryPalindrome(N)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}
