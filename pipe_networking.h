#define MAX_BUFFER_SIZE 300
#define init_server_msg "received private FIFO"
#define init_client_msg "ok, good"
#define WKP "mario"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int server_handshake(int *);
int client_handshake(int *);
