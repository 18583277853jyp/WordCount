#include <stdio.h>
#include <stdlib.h>
#include<String.h>
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
int main(int argc, char* argv[])
{
    //检查参数个数是否正确
    if (argc != 3)
    {	
        printf("输入格式有误\n", argv[0]);
        exit(1);
    }

    //打开输入文件
    FILE* fp = fopen(argv[2], "r");
    if (fp == NULL)
    {	// 
        printf("不能打开文件 %s\n", argv[2]);
        exit(2);
    }

    //根据参数选择统计模式
    if (strcmp(argv[1], "-c") == 0) //统计字符数
    {
        int count = 0; //记录字符数
        char ch; //存储读取的字符				getc()FILE* 指针指向的文件中读取 1 个字符 ,
        while ((ch = getc(fp)) != EOF )//循环读取文件中的每个字符，直到到达文件末尾
        {
            count++; //每读取一个字符，就增加一次计数
        }
        count--;///减去结尾 
        printf("字符数: %d\n", count); //输出结果
    }

    else if (strcmp(argv[1], "-w") == 0) //统计单词数
    {
    int num=0;//单词数 
	int a=0;//a将' '和','前的所有字符归为一个单词
	int b=0;//b将空格和','后的字符归为一个单词 
	int flag=0;  //作为一个标志位，用来判断该字符的前一个字符是否是逗号还是空格
	char word;   //取出对应位置的字符，用Word去得到它的值
    word = fgetc(fp);   //当读取一个字符后，下次读取前会自动后移到一个字节开始读

	if(word == 32 || word == 44)//用来判断首字符是否是空格还是逗号
	{
		     flag=1;
			 num--;
			 b--;
	}
	//feof()是检测流上的文件结束符的函数，如果文件结束，则返回非0值，否则返回0;
	while(feof(fp)==0)
    {	
        if(flag == 0 && (word == 32 || word == 44))//判断该字符是否为逗号或空格，若是则它之前的所有字符归为一个单词，单词数加一
		{
			 num++;
             flag = 1;
             a++;
        }
        //Ascii码32对应空格，44对应‘，’ 
        else if( (word != 32 && word != 44) && flag==1) 
        {
            num++;
            flag = 0;
			b++;
        }
		else
		{	//如果字符前不是空格或逗号， 
		    num=num;
		}
		word = fgetc(fp);   //当读取一个字符后，下次读取前会自动后移到一个字节开始读
    }
	
	if(flag==1)//用来判断末尾字符是否为逗号还是空格,不增加 
	{
	    num=a;
	}
	// rewind()将文件内部的位置的指针重新指向一个流（ 数据流/文件）的开头
    rewind(fp);
	if(a==b)//用来判断中间是否有被重复计算了的单词数目
	{
	num=num/2+1;
	}
	printf("单词数 %d\n",num);
    }
    else //无效的参数
    {
        printf("Invalid parameter: %s\n", argv[1]);
        exit(3);
    }

    //关闭输入文件
    fclose(fp);

    return 0;
}
