#include <stdio.h>
#define N 209 // The 1000th Fibonacci number has 209 decimal digits.

char fibo[1002][N];

void print_digits(char d[N])
{
  int i = 0;
  while (i < N && d[i] == 0)
    i++;
  if (i == N)
  {
    printf("%d", 0);
    return ;
  }
  while (i < N)
    printf("%d", (int)d[i++]); // "%d" instead of "%c"
}
// Add aa and bb and store the result in bb.
// aa is assumed to be always larger.
// store the result in res.
void add_digits(char aa[N], char bb[N], char res[N])
{
  int i = 0;
  int carry = 0;
  int j, s;
  while (aa[i++] == 0)
    ; // after loop, i is the first "non-zero" place
  for (j = N - 1; j >= i - 1; j--)
  { // the sum can have non-zero at (i-1)th place
    if ((s = carry + aa[j] + bb[j]) > 9)
    {
      res[j] = s - 10;
      carry = 1;
    }
    else
    {
      res[j] = s;
      carry = 0;
    }
  }
  if (carry)
    res[j] = carry;
}
int main()
{
  fibo[0][N - 1] = 1;
  fibo[1][N - 1] = 1;
  printf("f[%d]: ", 0);
  print_digits(fibo[0]);
  printf("\n");
  printf("f[%d]: ", 1);
  print_digits(fibo[1]);
  printf("\n");
  for (int i = 2; i <= 1000; ++i)
  {
    add_digits(fibo[i - 1], fibo[i - 2], fibo[i]);
    printf("f[%d]: ", i);
    print_digits(fibo[i]);
    printf("\n");
  }
  return (0);
}
