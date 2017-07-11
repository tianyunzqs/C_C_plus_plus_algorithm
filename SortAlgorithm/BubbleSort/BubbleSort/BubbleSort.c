/************************** 冒泡排序 **************************
函数名称：int bubbleSort(int a[], int n);
参    数：int a[]---待排序的数据
		  int len---待排序数据的个数，也即数组a的长度
功    能：完成冒泡排序
返 回 值：排序过程中发生交换的次数
基本思想：通过无序区中相邻记录关键字间的比较和位置的交换，
		  使关键字最小的记录如气泡一般逐渐往上“漂浮”，
          直至“水面”。
说    明：排序好的数据依然存放在数组a中
**************************************************************/
int BubbleSort(int a[], int len)
{  
	int i, j, temp, CompareNum=0;
    for(i=0; i<len-1; i++)  // 最多需len-1趟排序
        for(j=0; j<len-i-1; j++)  // 每趟排序最多需要len-i-1次比较
		{
            if(a[j] > a[j+1])  // 将较大的值放到后面
            {  
                temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
			CompareNum++;    // 比较次数加1
		}
	return CompareNum;
}  