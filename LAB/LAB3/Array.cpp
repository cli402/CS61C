class Solution{
	public:
	int removeDuplicate(int A[],int n){
		if(n==0){
			return 0;
		}
		int index=0;
		for(int i =0;i<n;i++){
			if(A[index]!=A[i]){
				A[++index]=A[i];
			}
		}
		return index+1;
	}
};


//keep tracking of the index 
class Solution{
public:
	int removeDuplicate(int A[],int n){
		if (n<=2){
			return n;
		}
		int index=2;
		for (int i=2;i<n;i++){
			if(A[index-2]!=A[i]){
				A[index]=A[i];
				index++;
			}
		}
		return index;
	}
}；

//get the boundary of the 
class Solution{
public:
	int search(int A[],int n,int target){
		int right=0,left=n;
		while(right!=left){
		int mid=（right+left）/2;
		if(A[mid]==target){
			return mid;
		}
		if(A[mid]=>A[left]){
			if(A[mid]>target && A[left] <= target){
				right=mid;
			}
			else{
				left=mid+1;
			}
		}
		else{
			if(A[mid]<target && target <=A[right-1]){
				left=mid+1;
			}
			else{
				right=mid;
			}
		}
	}
	return -1;
}
};

//the extension version
class Solution{
public:
	int search(int A[],int n,int target){
		int right=0,left=n;
		while(right!=left){
		int mid=（right+left）/2;
		if(A[mid]==target){
			return mid;
		}
		if(A[mid]>A[left]){
			if(A[mid]>target && A[left] <= target){
				right=mid;
			}
			else{
				left=mid+1;
			}
		}
		else if (A[mid]<A[left]{
			if(A[mid]<target && target <=A[right-1]){
				left=mid+1;
			}
			else{
				right=mid;
			}
		}
		else{
			left++;
		}
	}
	return -1;
}
};

//
class Solution{
public:
	int find_kth(int a[], int b[], int size_a, int size_b, int k){
        /* to maintain uniformaty, we will assume that size_a is smaller than size_b
                else we will swap array in call :) */
        if(size_a > size_b)
                return find_kth(b, a, size_b, size_a, k);
        /* Now case when size of smaller array is 0 i.e there is no elemt in one array*/
        if(size_a == 0)
                return b[k-1]; // due to zero based index
        /* case where K ==1 that means we have hit limit */
        if(k ==1)
                return min(a[0], b[0]);
 
        /* Now the divide and conquer part */
 
        int i =  min(size_a, k/2) ; // K should be less than the size of array  
        int j =  min(size_b, k/2) ; // K should be less than the size of array  
 
        if(a[i-1] > b[j-1])
                // Now we need to find only K-j th element
                return find_kth(a, b+j, i, size_b -j, k-j);
        else
                return find_kth(a+i, b, size_a-i, j,  k-i);
 
        return -1;
}
 
int  find_median(int a[], int b[], int size_a, int size_b){
        int left  =  (size_a + size_b +1)       >>1;
        int right =  (size_a + size_b +2)       >>1;
 
        return ((find_kth(a,b, size_a,size_b, left) +
                         find_kth(a,b, size_a,size_b, right))/2);
}
};


//
