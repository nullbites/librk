#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <strings.h>
#include "get_socket.h"

int get_socket(char *HOST, int PORT);
int get_socket(char *HOST, int PORT)
{
    int sockfd;
    struct sockaddr_in serveraddr;
    struct hostent *server;

    /* socket: create the socket */
    sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    if (sockfd < 0)  
        perror("ERROR opening socket");

    /* gethostbyname: get the server's DNS entry */
    server = gethostbyname(HOST);
    if (server == NULL)
        perror("ERROR, no such host");

    /* build the server's Internet address */
    bzero((char *) &serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
      (char *)&serveraddr.sin_addr.s_addr, (unsigned long)server->h_length);
    serveraddr.sin_port = htons(PORT);

    /* connect: create a connection with the server */
    if (connect(sockfd, (void *)&serveraddr, sizeof(serveraddr)) < 0)  
      perror("ERROR connecting");

    return sockfd;
}
