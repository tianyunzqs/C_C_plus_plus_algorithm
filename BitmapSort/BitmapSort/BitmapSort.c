//位图排序法，时空高效的至高境界
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
 
 #define BITSPERWORD 32
 #define SHIFT 5
 #define MASK 0x1F
 #define N 10000000
 #define M 20
 int a[1 + N/BITSPERWORD];
 
void set(int i){
    a[i >> SHIFT] |= (1<<(i & MASK));
}
void clr(int i){
    a[i >> SHIFT] &= ~(1<<(i & MASK));
}
int test(int i){
    return a[i >> SHIFT] & (1<<(i & MASK));
}

int myRand()   /* 产生一个0~1之间的随机数 */
{
  int num;
  num = rand() % 10000000;
  return num;
}
int main(void) {

	//printf("%d\n", 2>>5);

    int i,j,count=0;
    int arr[M];    
    for (i = 0; i < N; i++)
        clr(i);
	//注意这个随机数种子不能放在产生随机数myRand()函数中，否则每次调用都会产生几乎同一个随机数
    srand( (unsigned)time( NULL ) );
    printf("The count of array is %d:\n",M);
    for (j = 0; j < M; j++)    //供简单的正确性测试
	{        
		arr[j]=myRand();            //注意，输入的数不能重复     //否则当只输入一次
		printf("%d\t",arr[j]);
    }
   
    for (j = 0; j < M; j++)    //供简单的正确性测试
        set(arr[j]);    
   
    printf("\nAfter Sorted:\n");
    for (i = 0; i < N; i++) 	
        if (test(i)) 
		{
			printf("%d\t", i);
			count++;
		}    
    //打印出排序后的数字个数，如果有重复数字作为输入，则排序后数字的个数会比排序前少。
	printf("\nAfter sorted count is %d\n",count);
} 