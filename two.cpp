#include <iostream>
using namespace std;

int nthTerm(int n)
{
    int a = 1;
    int b = 2;

    for (int i = 1; i < n; ++i)
    {
        a += 3;
        b *= 2;
    }

    return a * b;
}

int Sum_Series(int n)
{
    if (n == 1)
        return nthTerm(1);
    return nthTerm(n) + Sum_Series(n - 1);
}

int main()
{
    int N;
    cout << "Enter the value of N: ";
    cin >> N;

    int result = Sum_Series(N);
    cout << result << endl;

    return 0;
}
