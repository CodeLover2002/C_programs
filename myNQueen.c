#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int a[30],count=0;
int place(int pos)
{
    for(int i=1; i<pos;i++)
    {    if((a[i]==a[pos])||(abs(a[i]-a[pos])==abs(i-pos)))
            return 0;
    }
    return 1;
    
}
void printsol(int n)
{   
    count ++;
    printf("Solution %d\n",count);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i]==j)
                printf("%d",j);
        }
    }
    printf("\n");
}
void queen(int n)
{
    int k=1;
    a[k]=0;
    while(k!=0)
    {
        a[k]=a[k]+1;
        while(a[k]<=n && !place(k))
        {
            a[k]++;
        }
        if(a[k]<=n)
        {
            if(k==n)
                printsol(k);
            else
            {
                k++;
                a[k]=0;
            }
        }
        else
        k--;    
    
    }
    
}
int main()
{
    int n;
    printf("Enter the number of queens: \n");
    scanf("%d",&n);
    queen(n);
    printf("Total number of solutions are: %d \n",count);

}