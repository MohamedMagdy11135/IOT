#include<stdio.h>
#include<winsock2.h>  // to use socket APIs

#pragma comment(lib, "ws2_32.lib")  //winsock library compiler command

int main()
{
    //Socket Windows intialization

   WSADATA wsa;
   SOCKET s, c;


   struct sockaddr_in addrport;
   struct sockaddr_in server;
   struct sockaddr_in clientAddr ;

   printf("\nIntialising Winsock...");
   if(WSAStartup(MAKEWORD(2,2),&wsa) != 0)
   {
       printf("Failed. Error Code : %d", WSAGetLastError());
       return 1;
   }

   printf("Intialised.\n");

   //Creat Socket
   //int sockid = socket(damily, type, protocol);
   if((s = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
   {
       printf("Could not Creat socket : %d", WSAGetLastError());
   }

   printf("Socket Created.\n");

   addrport.sin_family = AF_INET; // Address Family IPv4
   addrport.sin_port = htons(100); //port of htp
   addrport.sin_addr.s_addr = INADDR_ANY; //IP of the server Ex. here Google

    int status = bind(s, (struct sockaddr *) &addrport ,sizeof(addrport));
    printf("%d", status);

    int size=sizeof(clientAddr);
    char recv_buf[2000] = "";
    char message [500] = "Welcome Mohamed Magdy";

        int status_1 = listen(s, 3);

while(1)
{
        c = accept(s,(struct sockaddr *)&clientAddr ,&size);

        recv(c, recv_buf, sizeof(recv_buf), 0);
        puts(recv_buf);

        send(c, message, strlen(message), 0);
}
    return 0;
}
