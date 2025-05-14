#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int sockfd;
    struct sockaddr_in server_addr;

    // 1. Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return 1;
    }

    // 2. Set server address details
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);  // server port
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr); // localhost IP

    // 3. Connect to server
    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sockfd);
        return 1;
    }

    printf("Connected to the server!\n");

    // ... proceed with send()/recv() or write()/read()

    close(sockfd);
    return 0;
}