#define _CRT_SECURE_NO_WARNINGS

       ��1������ ����� �� һЩ����
    * #define ����ı��� �ڱ���ʱ ʵ�ֵ����滻 ���������һЩ����

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
	˵�����ṹ�������char���룬ǰ����λ��Ԫ��һ��4+2λ������8λ��
	������ռ1�ֽڣ����һ������1�ֽڣ�һ��3�ֽڡ����⣬#defineִ�е��ǲ����滻�� 
	sizeof(struct _Record_Struct) * MAX_SIZE��������ʵ��3*2+3�����Ϊ9��
	*/
	
	return 0;
}

//              <<2>>�ṹ��ָ�� �� ����Ľ���÷�
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
puc��һ��char���飬ÿ����תһ���ֽڣ��ṹ�岻�ǣ�
��ֻ�е�һ��Ԫ�ص�������һ�ֽڣ���������Ԫ��һ����һ�ֽڣ�
����puc���ṹ�����󣬱���ֻ�������ֽڻᱻд�룬�������ֽڿ϶���0��
��Ȼ���һ���ֽ���2����2�ˣ��ڶ����ֽڱȽ��鷳������ucData0����3��ʵ��Խ����
��1λ������ֻ����0��1������11�ضϺ�ֻ��1��ͬ��ucData1����4Ҳ��Խ��ģ�100�ضϺ���00��
ֻ��5��101�������ġ��������������С�˵ĵ͵�ַ�ڵ�λ��
��������˳����00 101 00 1��Ҳ����0010 1001����0x29��
*/