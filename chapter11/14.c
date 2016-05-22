#include <stdio.h>
int myatoi(const char *str);

int main(void)
{
	char *str1 = "   23";
	char *str2 = " -23";
	
	printf("%d\n",myatoi(str1));	
	printf("%d\n",myatoi(str2));	
	printf("%d\n",myatoi("-16"));

	return 0;
}

int myatoi(const char *str)
{
	int result = 0;
	int i = 0;
	int sign;
	
	
	while(isspace(str[i])) i++;		//�������ַ�
	
	sign = (str[i] == '-')? -1:1;	//�ж�����

	while(!isdigit(str[i])) i++;	//�����������ַ�
	
	while(isdigit(*(str + i )) && str)						 //���������ַ���ʼת��
		{
			result = result * 10 + *(str + i ) - '0';  //���ַ�ת��Ϊ����
			
			str++;
		
		}
	
	return sign * result;

}

