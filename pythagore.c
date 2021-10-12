#include <stdio.h>
#include <math.h>
#ifdef __unix__
# include <unistd.h>
#elif defined _WIN32
# include <windows.h>
#define sleep(x) Sleep(10 * (x))
#endif
int main(void)
{
    int len[2];
    int bc;
    char *cote[3]= {"AB","BC"};
    int count;
    do
    {
        bc=1;
        count=0;
        for(int i=0; i<2; i++)
        {
            printf("Cote %s en cm (0 pour sortir): \n",cote[i]);
            scanf(" %i",&len[i]);
            if(len[i]==0)
            {
                return 0;
            }
        }
        printf("hypothenuse[CA] = %f\n", sqrt(len[0]*len[0]+len[1]*len[1]));
        for(int i=0; i<len[0]; i++)
        {
            for(int j=0; j<bc; j++)
            {
                //sleep(1);
                printf("#");
            }
            printf("\n");
            if(len[1]>=len[0])
            {
                bc+=(len[1]/len[0]);
            }
            else
            {
                count++;
                if(count>=(len[0]/len[1])){
                    bc++;
                    count=0;
                }
            }
        }
    }
    while(1);

}
