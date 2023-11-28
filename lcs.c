#include <stdio.h>

void lcs(char x[], char y[],int m,int n)
{
        int d[m][n];
        int tab[m][n];

        for(int i=0;i<m;i++)
        {
                tab[i][0]=0;
        }
        for(int j=0;j<n;j++)
        {
                tab[0][j]=0;
        }

        for(int i=1;i<m;i++)
        {
                for(int j=1;j<n;j++)
                {
                        if(x[i-1]==y[j-1])
                        {
                                tab[i][j]=tab[i-1][j-1]+1;
                        }
                        else if(tab[i-1][j]>=tab[i][j-1])
                        {
                                tab[i][j]=tab[i-1][j];
                        }
                        else
                        {
                                tab[i][j]=tab[i][j-1];
                        }
                }      
        }

        for(int i=0;i<m;i++)
        {
                for(int j=0;j<n;j++)
                {
                        printf("%d\t",tab[i][j]);
                } 
         printf("\n"); 
        }

        printf("\nlcs is %d\n",tab[m-1][n-1]);

        int index = tab[m-1][n-1];
        char lcsAlgo[index + 1];
        lcsAlgo[index] = '\0';

        int i = m-1, j = n-1;
        while (i > 0 && j > 0) 
        {
                if(x[i-1]==y[j-1]) 
                {
                        lcsAlgo[index-1] = x[i-1];
                        i--;
                        j--;
                        index--;
                }

                else if (tab[i-1][j]>tab[i][j-1])
                        i--;
                else
                        j--;
        }
        
        for(int k=0;k<index;j++)
        {
              printf("%c",lcsAlgo[k]);
        } 
        printf("\n"); 
}

int main()
{
        char x[]="abmde";
        char y[]="abcde";

        int m= sizeof(x);
        int n= sizeof(y);
        
        lcs(x,y,m,n);

        return 0;
}
