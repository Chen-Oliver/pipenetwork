#include "pipe_networking.h"

int server_handshake(int *from_client){

  mkfifo(WKP,0644);
  printf("[SERVER]Created WKP\n");

  *from_client=open(WKP,O_RDONLY);
  printf("[SERVER]Connected to WKP\n");

  char clientmessage[MAX_BUFFER_SIZE];
  read(*from_client,clientmessage,MAX_BUFFER_SIZE);
  printf("[SERVER]Received private FIFO: %s\n",clientmessage);
  remove(WKP);

  int to_client = open(clientmessage,O_WRONLY);
  printf("[SERVER]Connected to private FIFO\n");
  write(to_client,init_server_msg,strlen(init_server_msg));

  read(*from_client,clientmessage,MAX_BUFFER_SIZE);
  printf("[SERVER]Received client response: %s\n",clientmessage);
  return to_client;
}
int client_handshake(int *to_server){

  char privateFIFO[MAX_BUFFER_SIZE];
  sprintf(privateFIFO,"%d",getpid());
  mkfifo(privateFIFO,0644);
  printf("[CLIENT]Created private FIFO:%s\n",privateFIFO);

  *to_server = open(WKP,O_WRONLY);
  write(*to_server,privateFIFO,sizeof(privateFIFO));
  printf("[CLIENT]Connected to WKP, sent private FIFO\n");

  int from_client = open(privateFIFO,O_RDONLY);
  printf("[CLIENT]Connected to private FIFO\n");

  char server_response[MAX_BUFFER_SIZE];
  read(from_client,server_response,MAX_BUFFER_SIZE);
  printf("[CLIENT]Received server response:%s\n",server_response);
  remove(privateFIFO);

  write(*to_server,init_client_msg,strlen(init_server_msg));
  return from_client;
}
