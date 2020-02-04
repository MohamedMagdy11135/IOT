#include <stdio.h>
#include <winsock2.h>

#pragma comment(lib,"ws2_32.lib")//winsock liberary bdal ely 3amaltelha include fe

int main(int argc, char *argv[])
{
    /*-----------------------Special init for Windows----------------------------------------*/
    WSADATA wsa;
    SOCKET s;//soket desc low fe EM int
    struct sockaddr_in server;

    printf("\ninitialising Winsock....");
    if(WSAStartup(MAKEWORD(2,2),&wsa) !=0)
    {
        printf("Failed Error Code :&d",WSAGetLastError());
        return 1;//mean that code return error
    }
    printf("Initialised.\n");
    /*---------------------------------------------------------------------------------------*/
    //create socket
    if((s = socket(AF_INET , SOCK_STREAM ,0)) == INVALID_SOCKET)
    {
        printf("Cloud not create socket : %d", WSAGetLastError());
    }
    printf("socket created\n");
    /*-------------------------------------creat socket--------------------------*/
    server.sin_family = AF_INET;//Address family ipv4
    server.sin_port = htons(100);//80 port of HTTP
    server.sin_addr.s_addr = inet_addr("192.168.3.12");
    while(1){
    int x = connect(s,(struct sockaddr *)&server,sizeof(server));
   // printf("hi");
   // printf("%d",x);
    char massage[50] ="HI I am mohamed magdy";                                        //"GET /  HTTP/1.1\r\n\r\n"; //condidt of request<>(get) (url after /) (\r\n)<>(Enter)
    char recv_buf[2000]="";
    send(s,massage,strlen(massage),0);
    long long i;
    while(i!=50){i++;}
    recv(s,recv_buf,2000,0);
    puts(recv_buf);

}
closesocket(s);
}
