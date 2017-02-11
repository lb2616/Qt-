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
