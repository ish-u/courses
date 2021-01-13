#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int main(int argc , char *argv[])
{
	if(argc != 3)
	{
		write(1,"error",strlen("error"));
		exit(-1);
	}
	else
	{
		char buff;
		int n = 0;
		int source_file = open(argv[1],O_RDONLY);
		if(source_file < 0)
		{
			write(1,"Can\'t Open Source File",strlen("Can\'t Open Source File"));
			exit(-1);
		}
		else
		{
			int destination_file = creat(argv[2],0641);
			if(destination_file < 0)
			{
				write(1,"Can't Open\\Create Destination File",strlen("Can't Open\\Create Destination File"));
				exit(-1);
			}
			else
			{
				while(read(source_file, &buff, 1))
				{
					write(destination_file, &buff,1);
				}
				close(source_file);
				close(destination_file);
				write(1,"Done\n",strlen("Done\n"));
			}
		}
	}
	return 0;
}
