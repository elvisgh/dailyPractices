#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main()
{
    int server_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(123);
    bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr));

    struct sockaddr_in client_addr;
    socklen_t client_addr_size = sizeof(client_addr);
    int client_sock = accept(server_socket, (struct sockaddr*)&client_addr, &client_addr_size);
    
    char str[] = "hello";
    while(true)
    {
    	write(client_sock, str, sizeof(str));
    }

    close(client_sock);
    close(server_socket);
    return 0;
}
