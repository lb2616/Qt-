#include "data_client.h"
//将fgets函数多存入的一个\n处理掉
void you_hua(char *p)
{
	while(*p != '\0')
	{	
		if(*p == '\n')
		{
		 	*p ='\0';
		 	break;
		}	
		p++;
	}
}

//模拟与服务器连接函数,动态打印>>
void dynamic_print()
{
	int i = 3;
	while(i)
	{
		printf(L_CYAN" >> >> "NONE);
		fflush(stdout);
		i--;
		usleep(500000);
	}
	printf("\n\n");
}

//处理键盘输入字符的函数，返回值为int型的
int input_digit(char left, char right)
{
    char ch[50];
    char li;
    int flag = 0;
    do
    {
        fgets(ch,49,stdin);
        you_hua(ch);
        flag = strlen(ch);
        li = ch[0];
        setbuf(stdin, NULL);/*清空键盘缓冲区里的无用字符*/
        if(!(li >= left && li <= right))
            printf("\033[;31m您输入的操作选项有误，请重新输入!!\033[0m\n");
    }
    while(!(li >= left && li <= right));
    return li - '0';
}



//处理客户端发来的群聊的请求
void deal_with_group_chat()
{

}


/***************************************************
  函数名:cutStr
  功能:将字符串str在字符c处分割，前后两段
  分别赋给left和right，left最大长度为n，str最大
  长度为max
  传入参数:char str[],char left[], int n, char right[],int max, char c
  返回值:无
 ***************************************************/
void cutStr(char str[], char left[], int n, char right[], int max, char c)
{
    int i,k,j;
    for(i = 0 ; i < n ;i++)
    {
        if(c == str[i])                             //c为str的分割符
            break;
    }
    if(i == n)
    {
        i = -1;
    }
    else
    {
        memset(left,0,strlen(left));
        for(k = 0 ; k < i ; k++)
        {
            left[k] = str[k];         //c左边的字符串赋给left[]
        }
    }

    left[i] = '\0';

    for(j = i+1 ; j < max; j++)
    {
        if(str[j] == '\0')
            break;
        right[j-i-1] = str[j];     //c右边的字符串给right[]
    }
    if(j < max)
    {
        right[j-i-1] = '\0';
    }
    else
    {
        right[max] = '\0';
    }
}
