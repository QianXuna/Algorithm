#include<stdio.h>

#define Swap1(x,y) {typeof(x) t;t = x;x = y;y = t;}
/*据网上说这种宏定义不太完备，当调用该宏函数时，大括号后面会多一个分号，不过也可以运行*/
#define Swap2(x,y) do{typeof(x) t;t = x;x = y;y = t;}while(0)
/*do...while(0)语句，巧妙地避免了这种情况，while(0)后刚好需要一个分号*/
#define ElementType int
/*任意指定数据类型*/
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
