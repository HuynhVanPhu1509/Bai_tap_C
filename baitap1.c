#include<stdio.h>
typedef enum
{
	Khac_nhau,
	Giong_nhau
}Sosanh_t;
Sosanh_t StrStr(char *Str1, char *Str2)
{
	Sosanh_t result=0;
	int index=0;
	while(Str1[index]!=0)
	{
		if(Str1[index]==Str2[index]) result=Giong_nhau;
		else 
		{
			result=Khac_nhau;
			break;
		}
		index++;
	}
	return result;
}
int main()
{
	char *str1="xin chao cac ban";
	char *str2="xin Chao cac ban";
	char *str3="xin chao cac ban";
	char * str4="hello";
    Sosanh_t ret=StrStr(str1,str4);
    if(ret==0) printf("hai chuoi khac nhau\r\n");
	else printf("hai chuoi giong nhau\r\n");
	return 0;
}