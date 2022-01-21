// https://www.interviewbit.com/problems/gcdcmpl/

/*

In the following C++ function, let n >= m.

    int gcd(int n, int m) {
            if (n%m ==0) return m;
            if (n < m) swap(n, m);
            while (m > 0) {
                n = n%m;
                swap(n, m);
            }
            return n;
    }

What is the time complexity of the above function assuming n > m?


*/


/*

If you take the example of n = fibo(N) and m = fibo(N-1), then at every step n = m + k, where k is fibo(N-2).

Proceed through the example and you’ll see after every iteration we move one Fibonacci number left.

If N is the number then the how many steps are needed to reach fibo(N).

When we take any two successive  (one after the other)  Fibonacci Numbers, their ratio is very close to the Golden Ratio (1.61803…). Thus number of steps to reach fibo(N) is log(1.61803…)N

*/