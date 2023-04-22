#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
char name;
void printparen(int i,int j,int n,int b[n][n])
{
	if(i==j)
	{	printf("%c",name++);
		return;
	}
	printf("(");
	printparen(i,b[i][j],n,b);
	printparen(b[i][j]+1,j,n,b);
	printf(")");
		
}
int MatrixChainOrder(int p[],int n)
{
	int m[n][n],b[n][n];
	int i,j,k,l,q;
	for(int i=1;i<n;i++)
		m[i][i]=0;
	for(l=2;l<n;l++)
	{	for(i=1;i<n-l+1;i++)
		{	j=i+l-1;
			m[i][j]=INT_MAX;
			
			for(k=i;k<j;k++)
			{	
				q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
				if(q<m[i][j])
				{
					m[i][j]=q;
					b[i][j]=k;
				}
			}
		}
	
	}
	name='A';
	printf("Optimal parenthesization is: \n");
	printparen(1,n-1,n,b);
	return m[1][n-1];	
}

int main()
{
	int n;
	printf("Enter the number of matrices \n");
	scanf("%d",&n);
	int arr[n+1];
	printf("Enter the dimensions of the matrices \n");
	for(int i=0;i<n+1;i++)
		scanf("%d",&arr[i]);
	printf("The minimum number of the matrix multiplications are: %d \n",MatrixChainOrder(arr,n+1));
	return 0;	
}

