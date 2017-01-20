#include "ui_client.h"

//1.客户注册
int ui_register(int fd)
{
    system("clear");
    MESSAGE Client;
    char passwd[100];
    printf("==================注册界面========================\n\n");   
inputnameerr:    
    printf("请输入用户名:");
    fgets(Client.name,30,stdin);
    you_hua(Client.name);
    if (!check_input_name(Client.name))
    {
        goto inputnameerr;
    }    
inputpwderr:    
    printf("请输入密码  :");
    fgets(Client.msg,30,stdin);
    you_hua(Client.msg);
    printf("请确认密码  :");
    fgets(passwd,30,stdin);
    you_hua(passwd);
    if (!check_register_pwd(Client.msg, passwd))
    {
        goto inputpwderr;
    }
    printf("\n-----------------------------------\n");
    strcpy(Client.flag,"注册"); 
    printf("正在连接服务器，请稍等");
    dynamic_print();
    write(fd,&Client,sizeof(Client));      //向服务器发送信息，请求注册
    return 1;
}

//2.客户端登录
int ui_login(int sockfd)
{ 
    MESSAGE Client;
//	system("clear");
    printf("==================登录界面========================\n\n");
    do {
        printf("\t帐号或者用户名：");
        fgets(Client.name, 30, stdin);
        you_hua(Client.name);
    }while(!check_input_name(Client.name));
//    setbuf(stdin, NULL);
    do {
        printf("\t密          码：");
        fgets(Client.msg, 30, stdin);
        you_hua(Client.msg);
    }while(!check_input_pwd(Client.msg));
    printf("-----------------------------------\n");
//    pnum0=Client.pnum;                            //用全局变量保存登录者的帐号
    strcpy(Client.flag,"登录");
    printf("正在连接服务器，请稍等.\n");
    write(sockfd,&Client,sizeof(Client));        //向服务器发送信息，请求登录
    return 1;
}

//3.登录注册总界面
int ui_register_login(int sockfd)
{
    int iChoice;
    do
    {
        //system("clear");
        printf("===============欢迎进入聊天室==============\n");
        printf("\t1.登录                \n");
        printf("\t2.注册                \n");
        printf("\t0.退出                \n");
        printf("-------------------------------\n");
        printf("请选择:");
        scanf(" %d",&iChoice);//getchar();
        setbuf(stdin,NULL);
    }while((iChoice != 1) && (iChoice != 2) && (iChoice != 0));
    switch(iChoice)
    {
        case 1:
            ui_login(sockfd);
            break;
        case 2:
            ui_register(sockfd);
            break;
        case 0:
            //Exit(sockfd);
            break;
    }
    return iChoice;
}

//4.私聊界面
int ui_private_chat(int sockfd )
{
    return 1;
}

//5.群聊界面
int ui_group_chat(int sockfd)
{
    MESSAGE Client;
    memset(&Client, 0, sizeof(Client));
    while(1)
    {

        write(sockfd, &Client, sizeof(Client));
    }
    return 1;
}

//6.聊天主界面
int ui_mainchat(int sockfd)
{
    int iChoice;
    printf("===============聊天选项==============\n");
    printf("\t1.私聊\n");
    printf("\t2.群聊\n");
    printf("\t3.查看聊天记录\n");
    printf("\t4.查看在线人数\n");
    printf("\t5.文件传输下载\n");
    printf("\t0.返回\n");
    printf("=====================================\n");
    printf("\t请选择:");
    iChoice = input_digit('0', '5');
    switch(iChoice)
    {
        case 1:
            ui_private_chat(sockfd);
            break;
        case 2:
            ui_group_chat(sockfd);
            break;
        case 3:
        //    Record(sockfd);
            break;
        case 4:
        //    Record(sockfd);
            break;
        case 5:
        //    Record(sockfd);
            break;
        case 0:
            ui_main(sockfd);
            break;
    }
    return 1;
}

//7.主功能界面
int ui_main(int sockfd)
{
    return 1;
}

int Exit(int sockfd)
{
    MESSAGE Client;
    strcpy(Client.flag,"退出");
//	Client.pnum = pnum0;
    write(sockfd,&Client,sizeof(Client));
    close(sockfd);
    exit(0);
}

