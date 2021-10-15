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
    char *cote[2]= {"AB","BC"},q;
    int on=1,subon=1;
    float len[2],hor=1;
    do
    {
        hor=1;
        do
        {
            printf("Tracer un triangle [o] ou [n] : ");
            scanf(" %c",&q);
            if(q=='o')
            {
                subon=0;
            }
            else if(q=='n')
            {
                on=0;
                subon=0;
            }
            else
            {
                printf("\n[o] ou [n] svp\n");
            }
        }
        while(subon==1);


        for(int i=0; i<2; i++)
        {
            printf("\nCote %s en cm : \n",cote[i]);
            scanf(" %f",&len[i]);
        }
        printf("hypothenuse[CA] = %f\n", sqrt(len[0]*len[0]+len[1]*len[1]));
        float dist=1;
        for(float i=0; i<len[0]; i++)
        {
            if(len[0]>=len[1])
            {
                for(float j=0; j<len[1]; j++)
                {

                    if(j<dist)
                    {
                        //sleep(1);
                        printf("#");
                    }
                    else
                    {
                        printf(" ");
                    }
                }
            }else{
                for(float j=0; j<hor; j++)
                {
                    //sleep(1);
                    printf("#");
                }
                hor+=(len[1]/len[0])+(len[1]/(len[0]*len[0]));
            }
            printf("\n");
            dist += len[1]/len[0];
        }
    }
    while(on==1);
}
