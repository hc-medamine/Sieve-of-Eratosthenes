//simple program to implement Sieve of Eratosthenes algorithm
#include <vector>
#include <algorithm>
#include <iostream>

void init_primes(std::vector<int> &primes,int &val)
{
    primes.clear(); //! -Alf, crucial functionality fix.
    for(int i=2; i<=val; ++i)
        {
            primes.push_back(i);
        }
}

void sieve(std::vector<int> &primes)
{
    for (int i=2; i<=primes.size(); ++i)
        {
            const auto it=remove_if(primes.begin(),
                                    primes.end(),
                                    [i](int x) -> bool { return (x > i && x % i == 0);}
                                    );
            primes.erase(it,primes.end());
        }
}

void print(std::vector<int> &primes)
{
    std::cout<<"=> ";
    for(const auto x : primes)
        std::cout<<x<<", ";
    std::cout<<"\n"; //! -Alf, cosmetic: removed side effect of prompting here.
}
main()
{
    std::vector<int> primes;
    int val {0};

    while((std::cout<<"=> ",std::cin>>val)) //! Alf, added prompting here.
        {
            init_primes(primes,val);
            sieve(primes);
            print(primes);
      }
    return 0;
}
