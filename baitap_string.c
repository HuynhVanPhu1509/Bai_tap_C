#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int _Atoi(char *str)
{ 
	char buffer[32] = { 0 };
	strcpy(buffer, str);
	int val = 0;
	int index = 0;
	while (str[index] > 47 && str[index] < 58)
	{
		buffer[index] = buffer[index] - 48;
		index++;
	}
	index--;
	for (int i = index; i >= 0; i--)
	{
		val += (long)buffer[index - i] * pow(10, i);
	}
	return val;
}
double _Atof(char *str)
{
	char buffer[32] = { 0 };
	strcpy(buffer, str);
	double val = 0;
	int index = 0;
	while (str[index] > 47 && str[index] < 58 || str[index] == 46)
	{
		buffer[index] = buffer[index] - 48;
		index++;
	}
	index = 0;
	while (buffer[index] != -2)
	{
		index++;
	}
	index--;
	for (int i = index; i >= 0; i--)
	{
		val += (double)buffer[index - i] * pow(10, i);
	}
	index += 2;
	int index1 = index;
	while (buffer[index] >= 0 && buffer[index] <= 9)
	{
		val += (double)buffer[index] / (pow(10, index + 1 - index1));
		index++;
	}
	return val;
}
double _Strtod(const char *str, char **endptr)
{
	double val = 0;
	int index = 0;
	if (str[0] < 48 && str[0] > 57) return '\0';
	if (str[0] != '\0') 
	{
		while (str[index] > 47 && str[index] < 58 || str[index] == 46)
		{
			index++;
		}
		val = _Atof(str);
		*endptr = &str[index];
	}
	else val='\0';
	return val;
}
float _Strtof(char *str, char **endptr)
{
	float val = 0;
	int index = 0;
	if (str[index] != '\0')
	{
		while (str[index] > 47 && str[index] < 58 || str[index] == 46)
		{
			index++;
		}
		val = (float)_Atof(str);
		if (str[index] != '\0')
		{
			index++;
			*endptr = &str[index];
		}
	}
	return val;
}
void _Itoa(int Value, char *buffer, int _Radix)
{
	int index = 0;
	int temp = 0;
	switch (_Radix)
	{
	case 10:
		temp = 0;
		while (Value > 0)
		{
			buffer[index] = (Value % 10)+48;
			Value = Value / 10;
			index++;
		}
		if (index % 2 == 0)
		{
			for (int i = 0; i < (index / 2); i++)
			{
				temp = buffer[i];
				buffer[i] = buffer[index - i - 1];
				buffer[index - i - 1] = temp;
			}
		}
		else
		{
			for (int i = 0; i < (index / 2)+1; i++)
			{
				temp = buffer[i];
				buffer[i] = buffer[index - i - 1];
				buffer[index - i - 1] = temp;
			}
		}
		break;
	case 16:
		temp = 0;
		while (Value > 0)
		{
			temp = Value % 16;
			if (temp < 10) buffer[index] = temp + 48;
			else if (temp == 10) buffer[index] = 'a';
			else if (temp == 11)  buffer[index] = 'b';
			else if (temp == 12)  buffer[index] = 'c';
			else if (temp == 13)  buffer[index] = 'd';
			else if (temp == 14)  buffer[index] = 'e';
			else buffer[index] = 'f';
			Value /= 16;
			index++;
		}
		if (index % 2 == 0)
		{
			for (int i = 0; i < (index / 2); i++)
			{
				temp = buffer[i];
				buffer[i] = buffer[index - i - 1];
				buffer[index - i - 1] = temp;
			}
		}
		else
		{
			for (int i = 0; i < (index / 2) + 1; i++)
			{
				temp = buffer[i];
				buffer[i] = buffer[index - i - 1];
				buffer[index - i - 1] = temp;
			}
		}
		break;
	case 2:
		while (Value > 0)
		{
			buffer[index] = (Value % 2)+48;
			Value = Value / 2;
			index++;
		}
		if (index % 2 == 0)
		{
			for (int i = 0; i < (index / 2); i++)
			{
				temp = buffer[i];
				buffer[i] = buffer[index - i - 1];
				buffer[index - i - 1] = temp;
			}
		}
		else
		{
			for (int i = 0; i < (index / 2) + 1; i++)
			{
				temp = buffer[i];
				buffer[i] = buffer[index - i - 1];
				buffer[index - i - 1] = temp;
			}
		}
		break;
	default:
		break;
	}
}
char* _Strtok(char str[], char* keyseach)
{
	(char)str;
	int index = 0;
	while (str[index] != '\0')
	{
		if (str[index] == keyseach)
		{
			str[index] = NULL;
			return &str[index-index];
		}
		index++;
	} 
}
int main()
{
	char *str = "1345.23864";
	char *str1 = "134534";
	char str2[] = "Hello! we are learn strtok";
	char *str4 = "123456.783 xin chao cac ban";
	char *str5 = "56.98 45.98";
	int ret = _Atoi(str1);
	printf("chuoi sau khi chuyen sang so nguyen: %d\r\n", ret);
	float ret_f =(float) _Atof(str);
	printf("chuoi sau khi chuyen sang so thuc: %f\r\n", ret_f);
	double val = 0;
	char* ptr = '\0';
	val = _Strtod(str4, &ptr);
	printf("phan so: %f, phan chuoi: %s\r\n", val,ptr);
	char *ptr2 = '\0';
	float val1 = _Strtof(str5, &ptr2);
	float val2 = _Strtof(ptr2, NULL);
	printf("phan so thu 1: %f, phan so thu 2: %f\r\n", val1, val2);
	char buffer[32] = { 0 };
	_Itoa(3453871, buffer, 16);
	printf("so thuc chuyen sang mang co so 16: %s\r\n", buffer);
	_Itoa(3453871, buffer, 10);
	printf("so thuc chuyen sang mang co so 10: %s\r\n", buffer);
	_Itoa(3453871, buffer, 2);
	printf("so thuc chuyen sang mang co so 2: %s\r\n", buffer);
	char *token = _Strtok(str2, ' ');
	while (token != NULL)
	{
		printf("%s\r\n", token);
		token = _Strtok(NULL, ' ');
	}
	return 0;
}