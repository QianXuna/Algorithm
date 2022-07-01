#include<stdio.h>
#include<time.h>
#include<math.h>
#include<unistd.h>
double fff[4],sss[4];
void PrintN1(int N)
{
  int i;
    for (i = 1;i<=N;i++)
        printf("%d\n",i);
  return;
}

void PrintN2(int N)
{
	if (N){
        PrintN2(N-1);
        printf("%d\n",N);
    }
  return;
}

void CalTime(int N,int i)
{
    clock_t start,end;
    start= clock();PrintN1(N);end= clock();
    fff[i] = (double)(end-start)/CLK_TCK;
    start= clock();PrintN2(N);end= clock();
    sss[i] = (double)(end-start)/CLK_TCK;
}

int main()
{
  int N;
  int i;

  for (i = 0;i<=2;i++){
    N = pow(10,i+2);
    CalTime(N,i);
  }
  printf("Ñ­»·\t\tµÝ¹é\n");
  for (i = 0;i<=2;i++){
    printf("%lf\t%lf\n",fff[i],sss[i]);
  }

  system("pause");
  return 0;
}
