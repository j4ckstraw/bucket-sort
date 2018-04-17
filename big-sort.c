#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #define SIZE 0x100000000
#define SIZE 0x10000
void info();

int main(int argc, char *argv[])
{
	// info();
	FILE *fp,*fp2;
	unsigned long long i,num,bucket[SIZE];
	memset(&bucket,0,sizeof(bucket));
	fp  = fopen("2t-file.txt","r");
	fp2 = fopen("sorted.txt","w");
	while(fscanf(fp,"%llu\n",&num)>0)  bucket[num]++;
	for(num = 0;num < SIZE;num++)
		for(i = bucket[num];i;i--)
			fprintf(fp2,"%llu\n",num);
	fclose(fp2);
	fclose(fp);
	return 0;
}

void info()
{
	// http://www.cplusplus.com/reference/climits/
	printf("Size of unsigned long long: %ld\n",sizeof(unsigned long long));
}
/*
# Memory Occupied
2T / 4 bytes = 500G
500G = 2^32 * 25 * 5 < 2^39
有500G个数字排序
unsigned long 	   4294967295 = 2^32 - 1
unsigned long long 18446744073709551615 = 2^64 - 1
unsigned long long 足够包含500G的大小

4 bytes 的空间 最大整型数字为 2^32 - 1
所以SIZE取 0x1 0000 0000 刚好

bucket 数组占用内存 8 * 2^32 = 32G

# File Size
原始文件2T
排序后2T
硬盘3T
好像有点不够用
但如果存下来bucket数组的话是可以的 
*/