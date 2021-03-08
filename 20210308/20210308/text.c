#define _CRT_SECURE_NO_WARNINGS

       《1》关于 定义宏 的 一些问题
    * #define 定义的变量 在编译时 实现的是替换 往往会造成一些问题

#define MAX_SIZE A+B
struct _Record_Struct
{
	unsigned char Env_Alarm_ID : 4;
	unsigned char Para1 : 2;
	unsigned char state;
	unsigned char avail : 1;
}*Env_Alarm_Record;

int  main()
{
	int A = 2;
	int B = 3;
	struct _Record_Struct *pointer = (struct _Record_Struct*)malloc
		(sizeof(struct _Record_Struct) * MAX_SIZE);
	printf("%d\n", sizeof(struct _Record_Struct) * MAX_SIZE); // 9
	
	
	/*
	说明：结构体向最长的char对齐，前两个位段元素一共4+2位，不足8位，
	合起来占1字节，最后一个单独1字节，一共3字节。另外，#define执行的是查找替换， 
	sizeof(struct _Record_Struct) * MAX_SIZE这个语句其实是3*2+3，结果为9，
	*/
	
	return 0;
}

//              <<2>>结构体指针 与 数组的结合用法
int main()
{
	unsigned char puc[4];
	struct tagPIM
	{
		unsigned char ucPim1;
		unsigned char ucData0 : 1;
		unsigned char ucData1 : 2;
		unsigned char ucData2 : 3;
	}*pstPimData;
	pstPimData = (struct tagPIM*)puc;
	memset(puc, 0, 4);
	pstPimData->ucPim1 = 2;
	pstPimData->ucData0 = 3;
	pstPimData->ucData1 = 4;
	pstPimData->ucData2 = 5;
	printf("%02x %02x %02x %02x\n", puc[0], puc[1], puc[2], puc[3]);
	return 0;
}
/*
puc是一个char数组，每次跳转一个字节，结构体不是，
它只有第一个元素单独享用一字节，其他三个元素一起共用一字节，
所以puc被结构体填充后，本身只有两个字节会被写入，后两个字节肯定是0，
，然后第一个字节是2就是2了，第二个字节比较麻烦，首先ucData0给了3其实是越界了
，1位的数字只能是0或1，所以11截断后只有1，同理ucData1给的4也是越界的，100截断后是00，
只有5的101是正常的。填充序列是类似小端的低地址在低位，
所以排列顺序是00 101 00 1。也就是0010 1001，即0x29，
*/