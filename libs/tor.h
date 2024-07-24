#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <dlfcn.h>

#define PROXY "127.0.0.1"
#define PROXY_PORT 9050
#define packet_size sizeof(PROXY_PACKET)
#define response_size sizeof(PROXY_RESPONSE)
#define USER "tor"

typedef unsigned char int8;
typedef unsigned short int int16;
typedef unsigned int int32;

typedef struct REQUEST{
    int8 vn;
    int8 cd;
    int16 port;
    int32 dest_ip;
    unsigned char user[4];
}PROXY_PACKET;

typedef struct RESPONSE{
    int8 vn;
    int8 cd;
    int16 _;
    int32 __;
}PROXY_RESPONSE;


PROXY_PACKET *request(struct sockaddr_in*);
int connect(int , const struct sockaddr*,socklen_t);

