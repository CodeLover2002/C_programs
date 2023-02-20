#include<stdio.h>

int main ()
{
	int n;                                    
	printf("Enter the number of elements: ");
	scanf("%d",&n);
	int arr[n],low=0,high=n,item,index=-1;
 	printf("Enter the array elements in sorted order: ");
 	
	for(int i =0;i<n;i++)
		scanf("%d",&arr[i]);
	printf("Enter the element to be searched: ");
	scanf("%d",&item);
    
	while (low<=high)
	{int mid  = (low + high)/2;
        
        if(arr[mid] == item)
	{
            printf("Found at index %d\n",mid);
            index=mid;
            break;
        }
	else if(arr[mid]>item)
                high = mid-1;
        else
		low = mid + 1;
         
        }
    if(index==-1)
    printf("Not found");
    
    return 0;
}