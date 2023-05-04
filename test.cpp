#include <iostream>
#include <openssl/bn.h>

void generatePrimeRandomNumber(int bytes_number);

int main()
{
    int option;
    std::cout << "1. Generate random prime number\n";
    std::cout << "4. Exit\n";
    while(1) {
        std::cout << "Enter option: ";
        std::cin >> option;
        switch(option) {
            case 1:
            int bytes_number;
            std::cout << "Enter number of bytes: ";
            std::cin >> bytes_number;
            std::cout << "Generate prime random number with " << bytes_number << " bytes long\n";
            generatePrimeRandomNumber(bytes_number);
            break;
            case 4:
            return 0;
        }
    }
    
    
    return 0;
}

void generatePrimeRandomNumber(int bytes_number) {
    BIGNUM *primeNumber = BN_new();
    BN_generate_prime_ex(primeNumber, bytes_number * 8, 1, NULL, NULL, NULL);
    char *primeNumber_str = BN_bn2dec(primeNumber);
    std::cout << "random prime number with " << bytes_number << ": " << primeNumber_str << std::endl;
}
