#include "./libs/tor.h"

PROXY_PACKET *request(struct sockaddr_in *sock2){
    PROXY_PACKET *req;
    req = malloc(packet_size);
    req -> vn = 4;
    req -> cd = 1;
    req -> dest_ip = sock2->sin_addr.s_addr;
    req -> port = sock2->sin_port;
    strncpy(req -> user, USER, 4);
    return req;
}


int connect(int sockfd, const struct sockaddr *sock2,socklen_t addrlen){

    int sock_des;
    PROXY_PACKET *req;
    PROXY_RESPONSE *res;
    char buffer[response_size];
    int success;
    struct sockaddr_in sock;
    int (*con_ptr)(int , const struct sockaddr*,socklen_t);
   
    con_ptr = dlsym(RTLD_NEXT, "connect");

    sock_des = socket(AF_INET, SOCK_STREAM, 0);
    
    if (sock_des < 0){
        perror("socket");
        return -1;
    }

    sock.sin_family = AF_INET;
    sock.sin_port = htons(PROXY_PORT);
    sock.sin_addr.s_addr = inet_addr(PROXY);

    if(con_ptr(sock_des, (struct sockaddr *)&sock, sizeof(sock)) == -1){
        close(sock_des);
        perror("connect");
        return -1;
    }

    printf("Connecting to proxy server\n|- Please wait, this takes time\n");
    req = request((struct sockaddr_in *)sock2);
    write(sock_des, req, packet_size);
    memset(buffer, 0, response_size);

    if(read(sock_des, buffer, response_size) < 1){
        perror("read");
        free(req);
        close(sock_des);
        return -1;
    }

    res = (PROXY_RESPONSE *)buffer;
    success = (res -> cd == 90);
    printf("|- response code stat: %d\n", success);
    if(!success){
        fprintf(stderr, "|- Switching connections, status : %d\n", res -> cd);
        close(sock_des);
        free(req);
        return -1;
    }
    printf("|- successfully connected through the proxy\n");
    dup2(sock_des, sockfd);
    free(req);
    return 0;
}