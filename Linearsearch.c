#include<stdio.h>
int main()
{int i,n,item,index =-1;
printf("Enter the number of elements: \n");
scanf("%d",&n);
int a[n];
printf("Enter the elements : \n");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
printf("Enter the item to be searched : \n");
scanf("%d",&item);
for(i=0;i<n;i++)
{	if(a[i]==item)
	{	index =i;
	break;
	}
}
if(index==-1)
printf("%d not found in array \n", item);
else
printf("%d found in array in index position %d \n", item,index);
return 0;
}
