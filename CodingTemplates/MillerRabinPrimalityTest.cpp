#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

// Utility function to do modular exponentiation.
// It returns (x^y) % p
int power(int x, unsigned int y, int p)
{
    int res = 1;      // Initialize result
    x = x % p;  // Update x if it is more than or
                // equal to p
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}

bool miillerTest(int d, int n)
{
    int a = 2 + rand() % (n - 4);
    int x = power(a, d, n);
    if (x == 1  || x == n-1)
       return true;
    while (d != n-1)
    {
        x = (x * x) % n;
        d *= 2;
        if (x == 1)      return false;
        if (x == n-1)    return true;
    }
    return false;
}

// Primality test controller function
bool isPrime(int n, int k)
{
    if (n <= 1 || n == 4)  return false;
    if (n <= 3) return true;
    int d = n - 1;
    while (d % 2 == 0) d /= 2;
    for (int i = 0; i < k; i++) if (miillerTest(d, n) == false) return false;
    return true;
}




// main function for demo
int main()
{
    int k = 4;  // Number of iterations
    cout << "All primes smaller than 100: \n";
    for (int n = 1; n < 100; n++)
       if (isPrime(n, k))
          cout << n << " ";
    return 0;
}
