// 3.删除法求质数 -- 爱拉托逊斯筛法
// "删除法求质数" in English is "Sieve of Eratosthenes". It refers to 
// an algorithm used to find all prime numbers up to a given limit by iteratively 
// marking the multiples of each prime number as composite (i.e., "deleting" them).
//Sieve of Eratosthenes  
// In mathematics, the Sieve of Eratosthenes is a simple, ancient algorithm for finding 
// all prime numbers up to a specified integer. It is the predecessor to the modern Sieve of Atkin, 
// which is faster but more complex. It was created by Eratosthenes, 
// an ancient Greek mathematician. Wheel factorization is often applied on the list of 
// integers to be checked for primality, before Sieve of Eratosthenes is used, to increase the speed.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// static void printArray(int arr[], int n) {
//     for (int i = 0; i < n; i++) {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");
// }
static void sieve_Eratosthenes()
{
    int i, j;
    bool prime_num[1000 + 1]; // 创建一个布尔数组，初始化为 true
    for (int i = 0; i <= 1000; i++) 
        prime_num[i] = true;
    prime_num[0] = prime_num[1] = false; // 0 和 1 不是质数
    printf("Prime numbers up to %d are:\n", 1000);

    for (i = 2; i*i <=1000; i++) {
        if (prime_num[i]) 
        {
            for (j = i*i; j <= 1001; j += i) // 如果 p 是质数，则标记 p 的倍数为合数composite number
                prime_num[j] = false;        // 把下标值index作为数字本身
        }
    }

    for(i=2; i<1001;i++)
    {
        if(prime_num[i])
            printf("%d, ",i);
    }
    printf("\n");
    return;
}
int main()
{
    sieve_Eratosthenes();
    exit(0);
}
/*
deepseek给的质数：
2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 
37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 
101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 
199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 
317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 
443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 
577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 
709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 
853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 
991, 997

sieve method with array:
2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31,
37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97,
101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197,
199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313,
317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439,
443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571,
577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701,
709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839,
853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983,
991, 997,
*/