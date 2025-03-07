class Solution {
public:
bool isPrime(int n) {
    if (n < 2) return false; // Numbers less than 2 are not prime
    if (n == 2 || n == 3) return true; // 2 and 3 are prime numbers
    if (n % 2 == 0 || n % 3 == 0) return false; // Eliminate even numbers and multiples of 3

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}
    vector<int> closestPrimes(int left, int right) {
        vector<int> primes;
        for(int i = left;i <= right;i++){
            if(isPrime(i))primes.push_back(i);
        }
        int minDif = 1e9,num1 = -1,num2 = -1;
        for(int i = 1;i < primes.size();i++){
            int temp = minDif;
            minDif = min(minDif,primes[i] - primes[i-1]);
            if(temp != minDif){
                num1 = primes[i-1];
                num2 = primes[i];
            }
        }
        return {num1,num2};
    }

};