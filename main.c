#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    int i;
	long unsigned int min_size=10;
    int itm[min_size];
    for (i=0; i<min_size; i++)
        itm[i]=0;
    FILE *fp = fopen(argv[1], "rt");
    if ( fp != NULL)
    {
		char str[255];
        unsigned int j=0;
        while(fscanf(fp, "%s", str)!=EOF)
        {
            if (!strcmp(str, "movr"))
            {
				j++;
				min_size++;
			}
            if (!strcmp(str, "movl"))
            {
				j--;
				min_size++;
			}
            if (!strcmp(str, "inc"))
            {
                ++itm[j];
                if (itm[j]==256)
                    itm[j]=0;
            }
            if (!strcmp(str, "dec"))
            {
                --itm[j];
                if (itm[j]==-1)
                    itm[j]=255;
            }
            if (!strcmp(str, "print"))
			{
				printf("%d\n", itm[j]);
				
			}
			if (!strcmp(str, "printc"))
			{
				printf("%c\n", itm[j]);
			}
            if (!strcmp(str, "get"))
			{
                scanf("%d", &itm[j]);
			}
            if (!strcmp(str, "begin"))
            {
                if (itm[j]==0)
                {
                    while (strcmp(str,"end"))
					{
						fgets(str, sizeof(str), fp);
					}
                }
                else
                {
					while (strcmp(str, "end"))
					{	
						fscanf(fp, "%s", str);
						while (itm[j]!=0)
						{
							if (!strcmp(str, "movr"))
							{
								j++;
								min_size++;
							}
							if (!strcmp(str, "movl"))
							{
								j--;
								min_size++;
							}
							if (!strcmp(str, "inc"))
							{
								++itm[j];
								if (itm[j]==256)
									itm[j]=0;
							}
							if (!strcmp(str, "dec"))
							{
								--itm[j];
								if (itm[j]==-1)
									itm[j]=255;
							}
							if (!strcmp(str, "print"))
								printf("%d\n", itm[j]);
							if (!strcmp(str, "printc"))
								printf("%c\n", itm[j]);
							if (!strcmp(str, "get"))
								scanf("%d", &itm[j]);
						}
					}
				}
			}
			else if (strcmp(str, "end"))
				continue;
		}
		fclose(fp);
		return 0;
    }
    else
    {
        printf("File does not open");
        return 0;
    }
}