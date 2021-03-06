#include "pipe_networking.h"

void process( char * s );

int main() {

  int to_client, from_client;
  char buffer[MAX_BUFFER_SIZE];

  to_client = server_handshake( &from_client );

  read( from_client, buffer, sizeof(buffer) );
  printf("[SERVER] Received message: %s\n", buffer);
  process( buffer );
  write( to_client, buffer, sizeof(buffer));

  return 0;
}




void process( char * s ) {

  while ( *s ) {
    *s = (*s - 'a' + 13) % 26 + 'a';
    s++;
  }
}
