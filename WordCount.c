#include <stdio.h>
#include <stdlib.h>
#include<String.h>
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
int main(int argc, char* argv[])
{
    //�����������Ƿ���ȷ
    if (argc != 3)
    {	
        printf("�����ʽ����\n", argv[0]);
        exit(1);
    }

    //�������ļ�
    FILE* fp = fopen(argv[2], "r");
    if (fp == NULL)
    {	// 
        printf("���ܴ��ļ� %s\n", argv[2]);
        exit(2);
    }

    //���ݲ���ѡ��ͳ��ģʽ
    if (strcmp(argv[1], "-c") == 0) //ͳ���ַ���
    {
        int count = 0; //��¼�ַ���
        char ch; //�洢��ȡ���ַ�				getc()FILE* ָ��ָ����ļ��ж�ȡ 1 ���ַ� ,
        while ((ch = getc(fp)) != EOF )//ѭ����ȡ�ļ��е�ÿ���ַ���ֱ�������ļ�ĩβ
        {
            count++; //ÿ��ȡһ���ַ���������һ�μ���
        }
        count--;///��ȥ��β 
        printf("�ַ���: %d\n", count); //������
    }

    else if (strcmp(argv[1], "-w") == 0) //ͳ�Ƶ�����
    {
    int num=0;//������ 
	int a=0;//a��' '��','ǰ�������ַ���Ϊһ������
	int b=0;//b���ո��','����ַ���Ϊһ������ 
	int flag=0;  //��Ϊһ����־λ�������жϸ��ַ���ǰһ���ַ��Ƿ��Ƕ��Ż��ǿո�
	char word;   //ȡ����Ӧλ�õ��ַ�����Wordȥ�õ�����ֵ
    word = fgetc(fp);   //����ȡһ���ַ����´ζ�ȡǰ���Զ����Ƶ�һ���ֽڿ�ʼ��

	if(word == 32 || word == 44)//�����ж����ַ��Ƿ��ǿո��Ƕ���
	{
		     flag=1;
			 num--;
			 b--;
	}
	//feof()�Ǽ�����ϵ��ļ��������ĺ���������ļ��������򷵻ط�0ֵ�����򷵻�0;
	while(feof(fp)==0)
    {	
        if(flag == 0 && (word == 32 || word == 44))//�жϸ��ַ��Ƿ�Ϊ���Ż�ո���������֮ǰ�������ַ���Ϊһ�����ʣ���������һ
		{
			 num++;
             flag = 1;
             a++;
        }
        //Ascii��32��Ӧ�ո�44��Ӧ������ 
        else if( (word != 32 && word != 44) && flag==1) 
        {
            num++;
            flag = 0;
			b++;
        }
		else
		{	//����ַ�ǰ���ǿո�򶺺ţ� 
		    num=num;
		}
		word = fgetc(fp);   //����ȡһ���ַ����´ζ�ȡǰ���Զ����Ƶ�һ���ֽڿ�ʼ��
    }
	
	if(flag==1)//�����ж�ĩβ�ַ��Ƿ�Ϊ���Ż��ǿո�,������ 
	{
	    num=a;
	}
	// rewind()���ļ��ڲ���λ�õ�ָ������ָ��һ������ ������/�ļ����Ŀ�ͷ
    rewind(fp);
	if(a==b)//�����ж��м��Ƿ��б��ظ������˵ĵ�����Ŀ
	{
	num=num/2+1;
	}
	printf("������ %d\n",num);
    }
    else //��Ч�Ĳ���
    {
        printf("Invalid parameter: %s\n", argv[1]);
        exit(3);
    }

    //�ر������ļ�
    fclose(fp);

    return 0;
}
