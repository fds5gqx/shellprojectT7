#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

int getargs(char *cmd, char *argv[]);

int main ()
{ 
	char buf[256];
	char *argv[50];
	int narg;

	pid_t pid;

	while (1)
	{
 		printf("shell>");
		 fgets(buf,256,stdin);
		 narg = getargs(buf, argv);
		 pid=fork();

 	if (strncmp (buf, "exit",4) == 0)
 	{
  		exit(0);
 	}

	 if(pid==0)
     {
 	 execvp(argv[0],argv);
 	 perror("Error:");
 	 exit(0);
	 }

	 else if (pid>0)
	 {
 		 if(narg>=0)
  		 wait(NULL);
		 continue;
	  }

	 else
	 {
 		 perror("fork failed");
	 }

	}
	return 1;
}

int getargs(char * cmd, char *argv[])
{
	int i = 0;
	char c;
	char * token;
	int len=strlen(cmd);

	for(i=0;i<len;i++)
	{
		 if (cmd[i]=='\n')
			 cmd[i]=' ';
	}
	argv[0]=token=strtok(cmd," ");
	argv[1]=NULL;
	i=1;

	while (token!=NULL)
	{
		token=strtok(NULL," ");
		 if(token!=NULL&&strcmp(token,"&")==0)
		 {
 		 argv[i]=NULL;
 		 return i*(-1);
	 }
	 argv[i]=token;
	}
}

