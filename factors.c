#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <gmp.h>
#include <sys/types.h>
#include <sys/stat.h>

#define Size 1000000

int sieve(int stat)
{
    bool prime[Size];
    static int primes[Size];
    static int n_primes;
    static int current;

    if (stat == 0)
    {
        n_primes = 0;
        current = 0;
        memset(prime, true, sizeof(prime));

        for (int p= 2; p * p < Size; p++)
            if (prime[p] == true)
                for (int i = p * p; i <= Size; i += p)
                    prime[i] = false;

        for (int p = 2; p < Size; p++)
            if (prime[p])
            {
                primes[n_primes] = p;
                n_primes += 1;
            }
    }
    else if (stat == 1)
    {
        current++;
        if (current - 1 < n_primes)
            return (-1);
    }
    else
        current = 0;
}