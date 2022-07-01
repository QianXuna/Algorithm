#include<stdio.h>
#include<math.h>
#include<time.h>

#define MAX 100000
#define N 100     /*N为多项式次数*/

double Poly_Traditional(double x,double a[])
{
  int i;
  double p = 0;
  for (i = 0;i<=N;i++)
    p += a[i]*pow(x,i);
  return p;
}

double Poly_Better(double x,double a[])
{
  int i;
  double p = a[N];
  for (i = N-1;i>=0;i--)
    p = a[i]+x*p;
  return p;
}

void leta(double a[])
{
  int i;
  a[0] = 1;
  for (i = 1;i<=N;i++)
    a[i] = 1.0/(double)i;
  return;
}

void CalTime(double x,double a[])
{
  clock_t begin,stop;
  int i;
  begin = clock();
  for (i = 0;i<MAX;i++)
    Poly_Traditional(x,a);
  stop = clock();
  printf("Poly_Traditional:%lf\n",(double)(stop-begin)/CLK_TCK);
  begin = clock();
  for (i = 0;i<MAX;i++)
    Poly_Better(x,a);
  stop = clock();
  printf("Poly_Better:%lf\n",(double)(stop-begin)/CLK_TCK);
}

int main()
{
  double a[N+1];     /*a为多项式系数数组*/
  double x = 1.1;
  leta(a);       /*初始化a数组*/
  CalTime(x,a);
  return 0;
}
