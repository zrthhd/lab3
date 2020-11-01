#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#define NUM_LENGTH 2

int getNum(int num)
{
	int pipefds[2];
	printf("Please enter a number: ");
	scanf("%d", &num);

	close(pipefds[1]);
	write(pipefds[1], num, NUM_LENGTH + 1); 

	read(pipefds[0], &num, NUM_LENGTH + 1);

}
int main(void)
{
	int pipefds[2];
	int buffer;
	int num;
	pipe(pipefds);
	pid_t pid = fork();
	if(pid == 0)
	{
		getNum(num);
		if(num %2 != 0)
		{
			printf("%d is a prime number. \n", num);
					
		}

		else
		{

			printf("%d is not a prime number. \n",num);
			
		}
		exit (EXIT_SUCCESS);
	}

	 if(pid > 0)
	{
		wait(NULL);

	}

	return EXIT_SUCCESS;
}

