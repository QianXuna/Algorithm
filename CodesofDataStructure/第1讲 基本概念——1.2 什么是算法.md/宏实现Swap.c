#include<stdio.h>

#define Swap1(x,y) {typeof(x) t;t = x;x = y;y = t;}
/*������˵���ֺ궨�岻̫�걸�������øú꺯��ʱ�������ź�����һ���ֺţ�����Ҳ��������*/
#define Swap2(x,y) do{typeof(x) t;t = x;x = y;y = t;}while(0)
/*do...while(0)��䣬����ر��������������while(0)��պ���Ҫһ���ֺ�*/
#define ElementType int
/*����ָ����������*/
void test(ElementType x,ElementType y)
{
    Swap2(x,y);
    printf("%d\n%d\n",x,y);
}
int main()
{
  int x = 1,y = 2;
  test(x,y);
  return 0;
}
