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
	
	
	while(isspace(str[i])) i++;		//跳过空字符
	
	sign = (str[i] == '-')? -1:1;	//判断正负

	while(!isdigit(str[i])) i++;	//跳过非数字字符
	
	while(isdigit(*(str + i )) && str)						 //遇到数字字符开始转换
		{
			result = result * 10 + *(str + i ) - '0';  //将字符转换为整数
			
			str++;
		
		}
	
	return sign * result;

}

