#include<stdio.h>
#include<math.h>
#include<stdlib.h>


int construct_tree(int arr[] , int ss , int se , int *st , int sindex)
{
	if(ss == se) 
	{
		st[sindex] = arr[ss] ; 
		return arr[ss] ; 
	}

	int mid = ss + (se - ss)/2 ; 

	st[sindex] = construct_tree(arr , ss, mid ,st , 2*sindex+1) + construct_tree(arr ,mid+1 , se , st, 2*sindex+2) ; 
	return st[sindex] ; 
}


int *segment_tree(int arr[] , int n )
{
	int x = (int)(ceil(log2(n))) ;

	int max_size = 2*(int)pow(2,x) - 1 ; 

	int *st = (int*)malloc(max_size*sizeof(int)) ; 

	construct_tree(arr , 0 , n-1 , st , 0) ; 

	return st ; 
}

int update_in_tree(int *st , int ss, int se , int i , int diff , int sindex)
{
	if (i < ss || i > se) 
        return 0 ; 
	if( i == ss and i == se){
		st[sindex] = st[sindex] + diff;
		return 0; 
	}
    // if (se != ss) 
    // {
    	int mid = ss + (se - ss)/2 ;
    	update_in_tree(st , ss, mid , i , diff , 2*sindex+1) ;
    	update_in_tree(st , mid + 1 , se ,i , diff , 2*sindex+2) ;

    // }
	st[sindex] = st[2*sindex + 1] + st[2*sindex + 2];
}


int update(int arr[] , int *st , int n  ,int i , int new_val)
{
	if (i < 0 || i > n-1) 
    { 
        printf("Invalid Input"); 
        return 0 ; 
    } 

    int diff = new_val - arr[i] ; 

    arr[i] = new_val ; 
    update_in_tree(st , 0 , n-1 , i , diff , 0) ;  
}


int query(int *st , int sindex , int m)
{
	if(st[sindex] < m)
	{
		return 0 ; 
	} 

	while(sindex < sizeof(st)/sizeof(st[0]))
	{
		if(st[sindex] >= m)
		{
			sindex = 2*sindex +1 ; 
			
			if(st[sindex] < m)
			{
				m = m - st[sindex] ; 
				sindex = sindex + 1 ;  
			}
			else
			{
				continue ; 
			}
		}
	}

	return sindex ; 

}


int main()
{	
	int arr[] = {1, 1, 1, 1, 1, 1} ; 
	int n = sizeof(arr)/sizeof(arr[0]) ; 
	
	int *st = segment_tree(arr , n) ;
	for(int i = 0; i <= 15; i++){
		printf("%d ",st[i]);
	}
	printf("\n");

	update(arr , st , n , 2 , 0 ) ; 
	
	for(int i = 0; i <= 15; i++){
		printf("%d ",st[i]);
	}
	printf("\n");
	// printf("%d" , query(st , 0, 3)) ; 
}