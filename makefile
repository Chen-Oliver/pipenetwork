c:pipe_networking.c
	gcc server.c pipe_networking.c -o server
	gcc client.c pipe_networking.c -o client
