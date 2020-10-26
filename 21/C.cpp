#include <vector>
#include <string>
#include <iostream>


class Checker
{
    private:
        const unsigned int n = 60000000;
        const unsigned int primes[3] = {19, 23, 29};
        std::vector<bool> table;

        unsigned long long int hashfun(std::string s, unsigned int p)
        {
            unsigned long long int hash = 0;
            for (auto c: s) {
                hash += c - 'a' + 1;
                hash *= p;
            }
            return hash;
        }
    public:
        Checker() : table(n) {}
        void Add(const std::string& s)
        {
            for (int i = 0; i < 3; ++i) {
                table[hashfun(s, primes[i]) % n] = true;
            }
        }
        bool Exists(const std::string& s)
        {
            bool is_exist = true;
            for (int i = 0; i < 3; ++i) {
                if (table[hashfun(s, primes[i]) % n] == false)
                    is_exist = false;
            }
            return is_exist;
        }
};


// int main()
// {
//     Checker obj;
//     obj.Add("a");
//     obj.Add("Hello Hell!");
//     std::cout << obj.Exists("a") << ' ' << obj.Exists("aa") << ' ' << obj.Exists("Hello Hell!");

//     return 0;
// }