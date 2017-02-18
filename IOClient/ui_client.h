#ifndef UI_CLIENT
#define UI_CLIENT

#include "logic_client.h"

//2.客户端登录
int ui_login(int sockfd);

//3.登录注册总界面
int ui_register_login(int sockfd);

//4.私聊界面
int ui_private_chat(int sockfd);

//5.群聊界面
int ui_group_chat(int sockfd);

//6.聊天主界面
int ui_mainchat(int sockfd, MESSAGE *message);

//7.主功能界面
int ui_main(int sockfd);

#endif // LOGIC_CLIENT_H
