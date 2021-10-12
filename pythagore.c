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
    char *cote[3]= {"AB","BC"},q;
    int count,on=1,subon=1,len[2],bc;
    do
    {
        bc=1;
        count=0;
        do
        {
            printf("Tracer un triangle [o] ou [n] : ");
            scanf(" %c",&q);
            if(q=='o'){
                subon=0;
            }else if(q=='n'){
                on=0;
                subon=0;
            }else{
                printf("\n[o] ou [n] svp\n");
            }
        }while(subon==1);


        for(int i=0; i<2; i++)
        {
            printf("\nCote %s en cm : \n",cote[i]);
            scanf(" %i",&len[i]);
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
                if((len[0]/len[1])>=2){
                    count++;
                    if(count>=(len[0]/len[1]))
                    {
                        bc++;
                        count=0;
                    }
                }else{
                    count++;
                    if(count>4*(len[0]/len[1]))
                    {
                        bc+=4;
                        count=0;
                    }
                }
            }
        }
    }
    while(on==1);
}
