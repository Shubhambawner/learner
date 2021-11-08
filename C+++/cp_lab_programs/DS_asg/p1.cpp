//insertion, deletion.
//sort: quick, merge, bubble, insertion.
//search: binary, sequetial. 

#include<iostream> 
using namespace std;

void takeArray(int arr[],int n){
    int j=0;
    cout<<"type array of "<<n<<" space separated integers & press enter\t";
    while (n>j)
    {
        cin>>arr[j];j++;
    }
    
}

void printArray(int arr[], int size){
    int i=0;
    while(size>i){
        cout<<arr[i]<<",\t";i++;
    }
    cout<<"\n";
}

int* arrCopy(int hrr[],int arr[],int n){
    while (n-->0)
    {
        hrr[n] = arr[n];
        //cout<<"acp.."<<n<<'\n';
    } 
    return hrr;  
}

int* ArrInsert( int arr[],int index,int element,int n){
    
    if (index>=n)
    {
        cout<<"Index out of range error\n";
        return arr;
    }
    
    for (int i = n; i >= index+1 ; i--)
    {
        arr[i]=arr[i-1];
    }
    arr[index] = element;
    
    return arr;
}
int* ArrDelete( int arr[],int index,int n){
    if (index>=n)
    {
        cout<<"Index out of range error\n";
        return arr;
    }
    
    for (int i = index; i < n ; i++)
    {
        arr[i]=arr[i+1];
    }
    
    return arr;
    
}

int ArrSearch(int arr[], int element,int n){
    int i = 0;
    while (arr[i]!=element)
    {
        i++;
    }
    if(i==n){
        cout<<"not found\n";
        return -1;
    }else{
        return i;
    }
}

int rBinarySearch(int arr[], int start, int end, int element){
    int mid = (start+end)/2;

    if(start==end && element!=arr[mid]){
        cout<<"not found";
        return -1;
    }

    if(element==arr[mid]){
        return mid;
    }else if(element<arr[mid]){
        return rBinarySearch(arr,start,mid-1,element);cout<<start<<'\t'<<mid<<'\n';
    }else if(element>arr[mid]){
        return rBinarySearch(arr,mid+1,end,element);cout<<start<<'\t'<<mid<<'\n';
    }
    return -1;
}
int ArrBinarySearch(int arr[], int element,int n){
    return rBinarySearch(arr, 0, n-1,element);
}

int* Swap(int arr[], int n){
    printArray(arr,5);
    arr[n] = (arr[n]+arr[n+1]);
    arr[n+1] = arr[n] - arr[n+1];
    arr[n] = arr[n] - arr[n+1];
    printArray(arr,5);
    
    return arr;
}
int* bSort(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-i; j++)
        {
            if (arr[j]>arr[j+1])
            {
                Swap(arr,j);
            }
            
        }
        
    }
    return arr;
}

int* iSort(int arr[], int n){

    if (n==1 )
    {
        return arr;
    }
    
    for (int i = 1; i < n; i++)
    {
        int j = i-1, t = arr[i];
        while (arr[j]>t  && j>=0)
        {
            Swap(arr,j);
            j--;
        }        
    }
    return arr;
}

int* merge(int arr[], int start, int end,int n, int brr[]){
    int mid = (start+end)/2;
    int ai=start, bi=mid + 1;
    //cout<<"__merging: \n";
    printArray(arr,n);
    for (int i = 0; i < start; i++)
    {
        arr[i] = brr[i];
    }
    for (int i = end+1; i <= n; i++)
    {
        arr[i] = brr[i];
    }
    //cout<<"b4 entering merger: \n";
    printArray(arr,n);
    for (int i = start; i <= end ; i++)
    {
        if ((brr[ai]>=brr[bi] && ai<=mid && bi<=end) || ai>mid)
        {
            arr[i]=brr[bi];
            //cout<<brr[bi]<<" from b part inserted(\t"<<bi<<'\n';
            bi++;
        }else if(ai<=mid && bi<=end || bi>end&&bi<=n ){
            arr[i]=brr[ai];
            //cout<<brr[ai]<<" from a part inserted(\t"<<ai<<'\n';
            ai++;
        }
        printArray(arr,n);
    }
    
    
    cout<<"finaly we get: \t";
    printArray(arr,n);
    return arr;
    
}
int* mergeSort(int arr[], int start, int end, int n){
    cout<<"\tmergeCall\t"<<start<<'\t'<<(start+end)/2<<'\t'<<end<<'\n';
    
    if(start+1==end){
        if(arr[start]<arr[end]){
            cout<<"no swap\n";
            return arr;
        }else{
            Swap(arr,start);
            cout<<"swap\n";
            return arr;
        }
    }
    
    if(start==end){
        return arr;
    }
    
    mergeSort(arr, start, (start+end)/2, n);
    mergeSort(arr, (start+end)/2+1, end, n);
    int brr[n] = {0};
    arrCopy(brr,arr,n);
    cout<<"merge takes:\n";
    printArray(arr,n);
    merge( arr
    ,start, end, n,brr
    );
    
    return arr;
}
int* mSort(int arr[], int n){
    mergeSort(arr, 0, n-1, n);
    return arr;
}



int* quickSort(int arr[], int n, int start, int end,int pivot){
    cout<<"qsort\t"<<start<<" to "<<end<<" pivot: "<<arr[pivot]<<'\n';
    
    int s[n] ={0}, si=0;
    int b[n] ={0}, bi=0;
    int p = arr[pivot];
    
    
    if(start==end){
        return arr;
    }

    bool equalFlag = false;

    for (int i = start; i <= end; i++)
    {
        if (arr[i]<p)
        {
            if (arr[i]==p && !equalFlag)
            {
                equalFlag=true;
            }else{
                s[si]=arr[i];
                si++;
            }
        }else{
            if (arr[i]==p && !equalFlag)
            {
                equalFlag=true;
            }else{
                b[bi]=arr[i];
                bi++;
            }
            
            
        }
        
    }
    
    int ms=0,mb=0;
    for (int i = start; i < start+si  ; i++)
    {
        arr[i]=s[ms];ms++;
    }
    arr[start+ms]=p;

    for (int i = start+si+1; i <= end; i++)
    {
        arr[i]=b[mb];mb++;
    }
    printArray(s,n);
    printArray(b,n);
    printArray(arr,n);

    
    if(si>=1)
    quickSort(arr,n,start,start+si-1,start+si-1);
    
    if(bi>=1)
    quickSort(arr,n,start+si,end,end);
    

    
    return arr;

}
int* qSort(int arr[], int n){

    printArray(arr,n);
    quickSort(arr,n,0,n-1,n-1);//n-1 as end pivoted
    return arr;
}

void stop(){
    int a;cin>>a;
}

int main()
{
    cout<<"array length = 5\n" ;
    int n=5;
    //cin>>n;
    int arr[5];
    
    takeArray(arr, n); //C++ array head pass by reference!! head pointer is a pointer itself! 
    //int *hrr = arr; //array name is like a pointer to array, but not exactly a pointer!!
    
    int index,element;
    cout<<"type index to insert at\t";
    cin>>index;
    cout<<"type element to insert at\t";
    cin>>element;
    ArrInsert( arr,index,element, n);
    printArray(arr, ++n);
    
    cout<<"type index to delete\t";
    cin>>index;
    ArrDelete(arr,index,n);
    printArray(arr, --n);

    cout<<"type element to search for\t";
    cin>>element;
    cout<<"found at(iff there) :\t"<<ArrSearch(arr,element,n);

    cout<<'\n';
    int hrr[ n ]={0};
    arrCopy(hrr, arr, n);

    
    cout<<"Sorting the array: insertion\t";printArray(arr, n);cout<<'\n';
    iSort(arr, n);
    printArray(arr, n);arrCopy(arr, hrr, n);

    cout<<"Sorting the array: bubble\t";printArray(arr, n);cout<<'\n';
    bSort(arr, n);
    printArray(arr, n);arrCopy(arr, hrr, n);

    cout<<"Sorting the array: merge\t";printArray(arr, n);cout<<'\n';
    mSort(arr, n);
    printArray(arr, n);
    //arrCopy(arr, hrr, n);//<--------------this line here gives unKnown error!!
    //cout<<"asdkjlasdjjljasdlhj\n"<<hrr[4]<<"00000000000000";
    
    
    cout<<"Sorting the array: quick\t";printArray(arr, n);cout<<'\n';
    qSort(arr, n);
    printArray(arr, n);
    
    cout<<"type element to perform Binary search for\t";
    cin>>element;
    cout<<"found at :\t"<<ArrBinarySearch(arr,element,n)<<'\n';
    
    
    stop();
}
