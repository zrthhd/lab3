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
	return num;

}
int main(void)
{
	int pipefds[2];
	int num = 0;
	pipe(pipefds);
	pid_t pid = fork();
	if(pid == 0)
	{
		int flag;
		int test = getNum(num);
		printf("Entered number:%d\n", test);
		for(int i=2; i <= test/2; ++i){
			if(test % i == 0)
			{
				flag = 1;
				break;
			}
		}
		if(test == 1)
		{
			printf("%d is neither a prime or composite. \n", test);
					
		}

		else
		{
			if(flag == 0)

			printf("%d is a prime number. \n",test);

			else

			printf("%d is not a prime number. \n",test);
			
		}
		exit (EXIT_SUCCESS);
	}

	 if(pid > 0)
	{
		wait(NULL);

	}

	return EXIT_SUCCESS;
}

