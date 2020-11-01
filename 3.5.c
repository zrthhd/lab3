#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#define NUM_LENGTH 2

int getNum(int num)
{
	int pipefds[2];
/*	int num;*/
	printf("Please enter a number: ");
	scanf("%d", &num);

/*	close(pipefds[0]);
	write(pipefds[1], num, NUM_LENGTH + 1); */

	write(pipefds[1], &num, NUM_LENGTH + 1);
	close(pipefds[1]);
	read(pipefds[0], &num, NUM_LENGTH + 1);
	close(pipefds[0]);
	return &num;
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
		exit (EXIT_SUCCESS);
	}

	else if(pid > 0)
	{
		wait(NULL);

		getNum(num);
	/*	close(pipefds[1]);
		read(pipefds[0], buffer, NUM_LENGTH + 1);*/ 
		int i, flag = 0;

	/*	int num = 0 ;*/
		for (int i = 2; i <= num / 2; ++i)
 		{

        			if (num % i == 0) 
				{
            				flag = 1;
            				break;
        			}
    

				if (num == 1) 
				{
        				printf("1 is neither prime nor composite.");
  				}
    				else 
				{
        				if (flag == 0)
            				printf("%d is a prime number.", num);
        				else
           				printf("%d is not a prime number.", num);
    				}
		}


		

	/*	close(pipefds[0]);*/
	}

	return EXIT_SUCCESS;
}

