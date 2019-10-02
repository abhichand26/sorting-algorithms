#include<stdio.h>
#include<stdlib.h>
#define M 50

void printArray(int A[], int n)
{
	int i;
  	printf("\nSorted Array : ");
	for(i=1;i<n;i++)
		printf("%d  ",A[i]);
	printf("\n");
}

void swap(int *x,int *y)
{
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}

void InsertionSort(int A[],int n)
{
	int i,j,x;
	for(i=2;i<n;i++)
	{
		x=A[i];
		j=i-1;
		while(j>=1&&x<A[j])
		{
			A[j+1]=A[j];
			j--;
		}
		A[j+1]=x;
	}
}

void SelectionSort(int A[],int n)
{
	int i,j,min;
	for(i=1;i<n;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(A[j]<A[min])
				min=j;
		}
		swap(&A[min],&A[i]);
	}
}

void Merge(int L[],int n1,int R[],int n2,int A[])
{
	int i=0,j=0,k=0;
	while(i<n1&&j<n2)
	{
		if(L[i]<=R[j])
		{
			A[k]=L[i];
			i++;
		}
		else
		{
			A[k]=R[j];
			j++;
		}
		k++;
	}
	while(i<n1)
	{
		A[k]=L[i];
		k++;
		i++;
	}
	while(j<n2)
	{
		A[k]=R[j];
		k++;
		j++;
	}
}

void MergeSort(int A[],int n)
{
	if(n<2)
		return;
	int i,mid=n/2;
	int *L=(int *)malloc(mid*sizeof(int));
	int *R=(int *)malloc((n-mid)*sizeof(int));
	//int L[mid],R[n-mid];
	for(i=0;i<mid;i++)
		L[i]=A[i];
	for(i=mid;i<n;i++)
		R[i-mid]=A[i];
	
	MergeSort(L,mid);
	MergeSort(R,n-mid);
	
	Merge(L,mid,R,n-mid,A);
	free(L);
	free(R);
		
}

int partition(int A[],int beg,int end)
{
	int i,pivot=A[end],p=beg;
	for(i=beg;i<end;i++)
	{
		if(A[i]<=pivot)
		{
			swap(&A[i],&A[p]);
			p++;
		}
	}
	swap(&A[end],&A[p]);
	return p;
}

void QuickSort(int []A,int beg,int end)
{
	int q;
	if(beg>=end)
		return;
	q=partition(A,beg,end);
	QuickSort(A,beg,q-1);
	QuickSort(A,q+1,end);
	
}

void maxHeapify(int A[],int n,int i)
{
	int x,max,l,r;  //temp variable, maximum value, left child & right child indexes
	x=A[i];
	
	while(2*i<=n)
	{
		l=2*i;
		r=l+1;
		if(r<=n && A[r]>A[l])
			max=r;
		else
			max=l;
		
		if(x<A[max])
		{
			A[i]=A[max];
			i=max;
		}
		else
			break;
	}
	A[i]=x;
}

void buildHeap(int A[],int n)
{
	int i;
	for(i=n/2;i>0;i--)
		maxHeapify(A,n,i);
}

void HeapSort(int A[],int n)
{
	int i;
	buildHeap(A,n);
	for(i=n;i>=2;i--)
	{
		swap(&A[1],&A[i]);
		maxHeapify(A,i-1,1);
	}	
}

int main()
{
	int i,n,*A,sel;
	char ch;
	do
	{
		printf("Enter the size of Array : ");
		scanf("%d",&n);
		//n++;
		A=(int *)malloc(n*sizeof(int));
		printf("Enter the elements of Array to sort :\n");
		for(i=0;i<n;i++)
		scanf("%d",&A[i]);
	
		printf("Select the type of sorting:\n");
		printf("1-Insertion Sort\n");
		printf("2-Selection Sort\n");
		printf("3-Merge Sort\n");
		printf("4-Quick Sort\n");
		printf("5-Heap Sort\n");
		printf("6-Exit\n");
		printf("Enter your choice:");
		scanf("%d",&sel);
		
		
		switch(sel)
 		{
			case 1:
  				InsertionSort(A,n);
				printArray(A,n);
  				break;
			case 2:
  				SelectionSort(A,n);
				printArray(A,n);
  				break;
			case 3:
  				MergeSort(A,n);
				printArray(A,n);
  				break;
			case 4:
				QuickSort(A,0,n-1);
				printArray(A,n);
  				break;
			case 5:
  				HeapSort(A,n);
				printArray(A,n);
				break;
			case 6:
				return 0;
			default:
  				printf("That is not a valid selection!\n");
  		}
		printf("\nTo continue enter (Y/y):");
  		fflush(stdin);
  		scanf("%c",&ch);	
	}while(ch=='Y'||ch=='y');

	return 0;
}

