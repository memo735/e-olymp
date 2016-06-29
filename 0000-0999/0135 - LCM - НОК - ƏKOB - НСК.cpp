#include <stdio.h>
#define Q 10000  // система счисления
#define N 100000
 
typedef int DIGIT;
int count[101];
DIGIT a[N], b[N];
int alen, blen;
 
// вывод конечного результата
void Print(DIGIT *a, int n)
{
   int i;
   for (i = n - 1; i >=0 ; i--) printf("%d", a[i]);
   printf("\n");
}
 
// нахождение максимальных степеней простых чисел
void Count(unsigned int n)
{
  unsigned int i;
  int a[101] = {0};
  i = 2;
  while (n != 1)
  {
      if (n % i == 0)
      {
          a[i]++;
          n = n/ i;
      }
      else
          if (i*i > n) i = n;
          else i++;
  }
  for (i = 1; i < 101; i++)
     if (a[i] > count[i]) count[i] = a[i];
}
 
// сумма (длинная арифметика, числа перевернуты)
void Sum(DIGIT *a, int *alen, DIGIT *b, int *blen)
{
   DIGIT ost, buf;
   int i;
   i = ost = 0;
   while (i < *alen && i < *blen)
   {
       buf = (a[i] + b[i] + ost) / Q;
       a[i] = (a[i] + b[i] + ost) % Q;
       ost = buf;
       i++;
   }
   while (i < *alen)
   {
      buf = (a[i] + ost) / Q;
      a[i] = (a[i] + ost) % Q;
      ost = buf;
      i++;
   }
   while (i < *blen)
   {
      buf = (b[i] + ost) / Q;
      a[i] = (b[i] + ost) % Q;
      ost = buf;
      i++;
   }
   if (ost) a[i++] = ost;
   *alen = i;
}
 
// произведение (длинная арифметика, числа перевернуты)
void Product(DIGIT *a, int *alen, DIGIT *b, int blen)
{
   int i, j, buflen, prodlen = 0;
   DIGIT prod[N] = {0}, buf[N], ost;
   for (i = 0; i < blen; i++)
   {
      for (j = 0; j < i; j++) buf[j] = 0;
      ost = 0;
      for (j = 0; j < *alen; j++)
      {
         buf[i + j] = (a[j] * b[i] + ost) % Q;
         ost = (a[j] * b[i] + ost) / Q;
      }
      buflen = i + j;
      if (ost) buf[buflen++] = ost;
      Sum(prod, &prodlen, buf, &buflen);
   }
   for (i = 0; i < prodlen; i++) a[i] = prod[i];
   *alen = prodlen;
}
 
// перевод числа в массив в перевенутом виде
void ToArray(long x, DIGIT *a, int *n)
{
   int i = 0;
   do
   {
       a[i++] = x % Q;
       x = x/ Q;
   }
   while (x);
   *n = i;
}
 
 
int main()
{
  unsigned int n, i, j;
  unsigned int A[21];
 
  scanf("%u", &n);
  for (i = 0; i < n; i++)
  {
     scanf("%u", &A[i]);
     Count(A[i]);
  }
  ToArray(1, a, &alen);
  for (i = 1; i < 101; i++)
  {
     ToArray(i, b, &blen);
     for(j = 0; j < count[i]; j++) Product(a, &alen, b, blen);
  }
 
  Print(a, alen);
  return 0;
}
