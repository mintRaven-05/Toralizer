#include "tor.h"

PROXY_PACKET *request(const char *dstip, const int dstport){
    PROXY_PACKET *req;
    req = malloc(packet_size);
    req -> vn = 4;
    req -> cd = 1;
    req -> dest_ip = inet_addr(dstip);
    req -> port = htons(dstport);
    strncpy(req -> user, USER, 4);
    return req;
}


int main(int argc, char *argv[]){

    char *host;
    int port, sock_des;
    PROXY_PACKET *req;
    PROXY_RESPONSE *res;
    char buffer[response_size];
    int success;
    struct sockaddr_in sock;

    if(argc < 3){
        fprintf(stderr, "Usage : %s <HOST> <PORT>\n", argv[0]);
        return -1;
    }

    host = argv[1];
    port = atoi(argv[2]);

    sock_des = socket(AF_INET, SOCK_STREAM, 0);
    
    if (sock_des < 0){
        perror("socket");
        return -1;
    }

    sock.sin_family = AF_INET;
    sock.sin_port = htons(PROXY_PORT);
    sock.sin_addr.s_addr = inet_addr(PROXY);

    if(connect(sock_des, (struct sockaddr *)&sock, sizeof(sock)) == -1){
        close(sock_des);
        perror("connect");
        return -1;
    }

    printf("|- Connecting to proxy server\n|- Please wait, this takes time\n");
    req = request(host, port);
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
    printf("response code stat: %d\n", success);
    if(!success){
        fprintf(stderr, "|-Switching connections, Status : %d\n", res -> cd);
        close(sock_des);
        free(req);
        return -1;
    }
    printf("|-successfully connected through the proxy to %s:%d\n", host, port);
    close(sock_des);
    free(req);
    return 0;
}