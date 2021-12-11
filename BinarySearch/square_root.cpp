int searchRoot(int x) {
	if(x < 2)return x;
	int start = 2;
	int end = x/2;
	while(start <= end){
		long long int mid = start + (end - start)/2;
		if(mid * mid > x)end = mid-1;
		else if(mid * mid < x)start = mid+1;
		else return mid;
	}
	return end;
    // add your logic here
}