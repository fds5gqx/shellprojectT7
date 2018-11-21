#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
	char str[10];
	while(1){
		gets(str);
		if(strcmp(str,"exit")==1)
			break;
	}
	return 0;
}

	
