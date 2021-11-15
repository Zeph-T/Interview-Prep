bool solve(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    int n1 = a.size();
    int n2 = b.size();
    if(abs(n1 - n2) > 1)return false;
    int count = 0;
    while(p1<n1 and p2<n2){
        if(a[p1] == b[p2]){ // if the chars are the same, no need to delete or replace or insert any string
            p1++;
            p2++;
        }else{
            if(count == 1)return false; 
            if(n1 > n2)p1++; // if the first string len is greater than the second string, we ignore the char in the first string, else second string
            else if(n1 < n2)p2++;
            else{
                p1++; // this is the case for replace
                p2++;
            }
            count++;
        }
    }
    if(p1 < n1 or p2<n2)count++; // if any pointers didnot reach the end, that means there is some letters that did not get accessed , so count++;
    return count<=1; // return if the edit distance is less than or equal to 1
}