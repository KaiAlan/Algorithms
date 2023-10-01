#include <stdio.h>

int main() {

  int n, i, flag = 0;
  printf("Enter a positive integer: ");
  scanf("%d", &n);

  // Check if the entered number is 0 or 1 (special cases)
  if (n == 0 || n == 1)
    flag = 1; // Set the flag to indicate that the number is not prime

  // Loop to check for factors of the number
  for (i = 2; i <= n / 2; ++i) {
    // Check if n is divisible by i (i is a factor of n)
    if (n % i == 0) {
      flag = 1; // Set the flag to indicate that the number is not prime
      break;    // Break out of the loop as we have found a factor
    }
  }

  // Check the flag to determine if the number is prime or not
  if (flag == 0)
    printf("%d is a prime number.", n);      // If flag is 0, it's a prime number
  else
    printf("%d is not a prime number.", n);  // If flag is 1, it's not a prime number

  return 0;
}
