//End-Semester-Project.h

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>
  
//Operations on numbers
//Sum of digits
int sumOFDigits(int num) {
    int sum = 0,save = num ;

    while (num > 0) { 
        sum += num % 10; 
        num /= 10;       
    }
    num = save ;
    return sum;
}

// Reverse the digits of agiven number
int reverseNumber(int num ) {
    int reverse = 0 ,save = num ;
    while (num > 0 ){
        reverse=(num%10)+reverse*10 ;
        num=num/10 ;
    }
    num = save ;
    return reverse ;
}


// Palindrome
bool isPalindrome(int num){
    return num == reverseNumber(num);
}


// Prime
bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false;
    }
    return true;
}

//Greatest Common Divisor
int gcd(int a , int b ){
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

//Least Common Multiple
int lcm(int a ,int b) {
    if (a ==0||b==0) {
        return 0;
    }
    return (a*b / gcd(a,b));
}


//Factorial
long factorial(int num) {
    if (num < 0) {
        return -1 ;
    }
    long fact = 1 ;
    for(int i=1 ; i<=num ; i++){
        fact=fact*i ;
    }
    return fact ;
}


//Combination
int Combination(int n , int p ){
    return factorial(n)/(factorial(p)*factorial(n-p)) ;
}


//Even or odd
bool isEven(int num){
    if((num%2)==0){
     return true ;
    }else{
     return false ;
    }
}


//number of digits
int nd (int num ){
    if (num == 0){ 
        return 1;
    }
    int  nd ;
    while(num / 10 != 0){
        nd ++ ;
        num=num/10 ;
    }
 return nd ;
}



//Prime Factorization 
void primeFactors(int num) {
   if (num <= 1) {
     return;
    }
   int i;
   for(i=1 ; i<= sqrt(num) ; i++){
        while (num % i == 0) {
            printf("%d ", i);
            num /= i;
        }
    }

}


// armstrong number 
bool isArmstrong(int num){
int i,;
while(num>0){
    int save = num, sum = 0;
    int digits = nd(num) ;
    while (num > 0) {
        sum += pow(num % 10, digits);
        num /= 10;
    }
    return sum == save ;
}
}



//Fibonacci Sequence 
void fibonacciSeries(int n) {
int first = 0, second = 1, next ;
    for (int i =1;i<=n;i++) {
        if (i == 1) {
            printf("%d ", first);
        }
        if (i == 2) {
            printf("%d ", second) ;
        }

        next = first + second;
        first = second;
        second = next;
        printf("%d ", next) ;
    }
}

//Sum of Divisors 
int sumDivisors(int num){
    if (num <= 0) {
        return 0;
    }
    int sum ;
    for (int i=1 ; i<=sqrt(num) ; i++ ){
        if (num%i == 0 ){
            sum +=i ;
            if (i != num /i) {
                sum += num / i;
            }
        }
    }
    return sum ;
}


//Perfect Number
bool isPerfect(int num) {
    return (sumDivisors(num) - num )==num  ;
}


//Magic Number 
bool isMagic(int num){
  int save= num ;
  bool magic = false ;
  do{
    if ( sumOFDigits(num) == 1 ){
      magic = true ;
    }
    num = sumOFDigits(num) ;
  }while(num/10 != 0 ) ;
  num = save ;
return magic ;
}


//Automorphic Number
bool isAutomorphic(int num){
  bool Automorphic = false ;
  int nd = nd(num) ;
     if( sqr(num) % pow(10 , nd ) == num){
     Automorphic = true ;
    }
 return Automorphic ;
}










//Advanced operations on numbers
//Binary coversion
void toBinary(int num) {
    int Bin ;
    do {
        Bin= num%2+ 10*Bin ;
        num = num/2 ;
    }while((num/2) != 0) ;
}

//Narcissistic Number 
bool isNarcissistic(int num ){
 int save = num ;
 int nar = 0 ;
 bool isnar=false ;
 do {
     nar += pow (num%10,nd(num)) ;
     num = num/10 ;
    }while(num!=0 ) ;
 num =save ;
 if(num == nar){
     isnar=true ;
    }
 return isnar ;
}

//Square Root Calculation 
double sqrtApprox(int num){
    if (num < 0){
        return -1.0;
    }
    double x=num, y=1;
    int precision = 0.000001   ;


    while (fabs(x-y) > precision) {
        x =(x+y)/ 2 ;
        y =num/ x  ;
    }
    return x ;
}

//Exponentiation 
double power(int base, int exp) {
    if (base == 0 && exp <= 0) {
        return 0  ;
    }
    double power = 1;
    if (exp < 0) {
        base = 1 / base; 
        exp = -exp ;            
    }
    for (int i = 0; i < exp ; i++) {
        power *= base;
    }
    return power;
}


//Happy Number 
bool isHappy(int num) {
    while (num != 1 && num != 4) { 
        int sum = 0;
        while (num > 0) {
            sum + =(num% 10)*(num %10);
            num / =  10;
        }
        num =sum  ;
    }
    return num ==1  ;
}


//Abundant Number 
bool isAbundant(int num){
    if(sumDivisors(num)>num){
        return true ;
    }else{
        return false ;
    }
}



//Deficient Number 
bool isDeficient(int num){
    return !isAbundant ;
}



//Sum of Fibonacci Even Numbers
int sumEvenFibonacci(int n){
    int first = 0, second = 1, next , sum ;
    sum = 0 ;
    for (int i =1;i<=n;i++) {
        next = first + second;
        if(isEven(next)==true){
            sum += next ;
        }
        first = second;
        second = next;
    }
}


//Harshad Number 
bool isHarshad(int num){
    bool har=false ;
    if (num % sumOFDigits(num)==0){
        har = true ;
    }
    return har ;
}


//Catalan Number Calculation 
unsigned long catalanNumber(int n){
    return factorial(2 *n)/(factorial (n+1)*factorial  (n) )   ;
}


//Pascal Triangle 
void pascalTriangle(int n){
    for (int i=1 ; i<=n ; i++ ){
        for (int j =1 ; j<=i ; j++ ){
            printf ("%d", Combination(i,j)) ;
        }
        printf("\n");
    }

}



//Bell Number 
unsigned long bellNumber(int n){
    int y=0 ,x=1 ;
    for (int i=1 ; i<=n ; i++){
        y=0 ;
        for(int j=0 ; j<=i ; j++){
            y += Combination(i,j)*x ;
        }
         x = y ;
    }
    return x ;
}






//Kaprekar Number 
bool isKaprekar(int num){
 bool kap = false ;
 int ndnew=nd(num)/2 ;
 if(isEven(nd(num*num)) && (num*num/((int)pow(10,ndnew)) == num*num%  (int)pow(10,ndnew))){
    kap = true ;
 }
 return kap ;
}



//Smith Number 
bool isSmith(int num){

 if (isPrime(num)){
    return false ;
 }else{
     int i ,sum=0 ;
       for(i=1 ; i<= sqrt(num) ; i++){    
           if( num%i==0 && isPrime(i)==true ){
              sum += sumOFDigits(i) ;
           }  
        }
     if(sum==sumOFDigits(num)){
        return true ;
     }else{
        return false ;
     }
    }
}

//Sum of Prime Numbers 
int sumOfPrimes(int n){
    int sum ;
    for (int i=2 ; i<=n ; i ++){
        if(isPrime(i)){
            sum+=i ;
        }
    }
    return sum ;
}





/*Operations on strings*/



//Basic String Functions




//Calculate String Lenghth
int stringLength(char* str){
    int length = 0 ;
    while (str[length] != '\0' ){
        length++ ;
    }
    return length;
}

//Copy String 
void stringCopy(char* dest, const char* src){
    while (*src != '\0'){
        *dest = *src;
        dest++ ;
        src++ ;
    }
    *dest = '\0' ;
}


//Concatenate Strings 
void stringConcat(char* dest, const char* src){
    while (*dest != '\0') {
        dest++;
    }
    stringCopy(dest,src);
}

//Compare Strings
int stringCompare(const char* str1, const char* str2){
    while (*str1 && *str2   &&   *str1==*str2  ){
        str1++;
        str2++;
    }
    return (*str1-*str2)  ;
}

//Check if Empty 
bool isEmpty(char* str){
    return stringLength(str)==0   ; 
}

//Reverse a String 
void reverseString(char* str){
    int length = stringLength(str); 
     for (int i = 0; i < length / 2; i++) {
        char save = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = save;
    }
}

//Convert to Uppercase 
void toUpperCase(char* str){
    while (*str != '\0'){
          if (*str >= 'a' && *str <= 'z') { 
             *str = *str - ('a' - 'A');  
           }
     str++ ;
    }

}


//Convert to Lowercase 
void toLowerCase(char* str){
    while (*str != '\0'){
          if (*str >= 'A' && *str <= 'Z') { 
             *str = *str - ('A' - 'a');  
           }
     str++ ;
    }
}





//Intermedate String Functions

//Palindrome
bool isPalindrome(char* str){
    int len = stringLength(str)  ;
    for (int i = 0; i < len/2; i++) {
        if (str[i] !=str[len- i-1]) {
            return false  ;
        }
    }
    return true ;
}

//Count Vowels and Consonants 
void countVowelsConsonants ( char* str, int* vowels , int* consonants){
    *vowels = *consonants = 0;
    for (int i = 0; str[i]; i++) {
        char c = tolower(str[i])  ;
        if (c >= 'a' && c <= 'z') {
            if (c == 'a'||c=='e' ||c== 'i'||c  =='o'||c=='u')
                (*vowels) ++ ;
            else
                (*consonants) ++ ;
        }
    }
}

//Find Substring 
int findSubstring(const char* str, const char* sub){
    int lsub= stringLength(sub) ;
    int lstr= stringLength(str);
    if (lsub== 0||lstr < lsub)  {
        return -1;
    }
    for (int i = 0; i <= lstr - lsub; i++) {
        int j;
        for (j = 0; j < lsub; j++) {
            if (str[i + j] != sub[j]) {
                break;
            }
        }    
        if (j == lsub) {
            return i;
        }    
    }
    return -1 ;
}

//Remove Whitespaces 
void removeWhitespaces(char* str){
    int i = 0, j = 0;
    while (str[i]) {
        if (str[i] != ' ') {
            str[j++] = str[i];
        }
        i++;
    }
    str[j] = '\0';
}


//Count Words 
int countWords(char* str){
    int count = 0;
    bool inWord = false;
    while (*str) {
        if (*str != ' ' && !inWord) {
            inWord = true;
            count++;
        } else if (*str == ' ') {
            inWord = false;
        }
        str++;
    }
    return count;
}

//Remove Duplicate Characters 
void removeDuplicates(char* str){
    bool seen[256] = {false};
    int j = 0;
    for (int i = 0; str[i]; i++) {
        if (!seen[(unsigned char)str[i]]) {
            seen[(unsigned char)str[i]] = true;
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}



//Advanced String Functions


//String Compression 
void compressString(char* str, char* result) {
    int i = 0, j = 0;
    while (str[i]) {
        result[j++] =str[i];
        int count =1;
        while (str[i]==str[i+1]) {
            count++;
            i++;
        }
        if (count > 1) {
            char buffer[20];
            int len =sprintf(buffer,"%d",count);
            strcpy(&result[j], buffer);
            j +=len;
        }
        i++;
    }
    result[j] = '\0';
}








/*Operations on arrays*/
//Basic arrays functions




//Initialize Array 
void initializeArray(int arr[], int size, int value){
    for(int i=0;i<size;i++){
      arr[i] = value ;
    }
}

//print araay
void printArray(int arr[], int size){
    for(int i=0;i<size;i++){
      printf("%d",arr[i]) ;
    }
}


//Find Maximum 
int findMax(int arr[], int size){
    if(size == 0){
      return -9999  ; 
    } 
 int max = arr[0] ;
 for(int i=1;i<size;i++){
        if (arr[i]>max){
         max = arr[i];
        }
    }  
    return max ;
}

//Find Minimum 
int findMin(int arr[], int size){
    if(size == 0){
      return -9999 ; 
    } 
 int min = arr[0] ;
 for(int i=1;i<size;i++){
        if (arr[i]< min ){
         min = arr[i];
        }
    }  
    return min ;
}

//Calculate Sum 
int sumArray(int arr[], int size){
    int sum = 0 ;
    for (int i =0;i<size ; i++){
        sum+=arr[i] ;
    }
    return sum ;
}


//Calculate Average 
double averageArray(int arr[], int size){
    if(size == 0){
      return 0  ; 
    } 
    return (sumArray(arr,size)/(size-1));
}

//Check if Sorted 
bool isSorted(int arr[], int size){
    for (int i=0 ; i<size ; i ++ ){
        if (arr[i]>arr[i+1]){
            return false ;
        }
    }
    return true ;
}








//Intermediate Arry Functions 
//Reverse Array
void reverseArray(int arr[], int size){
    for(int i=0 ; i<=size/2 ; i++){
        swapArr( arr , i , size -1-i)
    } 
}

//Count Even and Odd Numbers 
void countEvenOdd(int arr[], int size, int* evenCount, int* oddCount){
    *oddCount=0 ;
    *evenCount=0 ;
    for (int i = 0 ;i<size ; i++ ){
        if (isEven(arr[i])){
            (*evenCount)=++ ;
        }else{
            (*oddCount)++ ;
        }
    }
}

//Find Second Largest 
int secondLargest(int arr[], int size){
    if(size < 2) {
        return -1 ;
    }
        
    int first = max(arr[0],arr[1]), second = min(arr[0],arr[1]);
    for(int i = 2; i < size; i++) {
        if(arr[i] > first) {
            second = first;
            first = arr[i];
        } else {
               if(arr[i] >second && arr[i] != first) {
                  second = arr[i];
                }
        }  
        return second; 
    }
}


//Find Frequency of Elements 
void elementFrequency(int arr[], int size){
    int count ;
    for (int i=0 ; i <size-1 ; i++){
        for (int j=i+1 ; j<size ; j++){   
           count ++ ;
           printf ("arr[ %i ] repeated %count time " , &i , &count) ;
        }
    }
}


//Remove Duplicates 
int removeDuplicates(int arr[], int size){
    if(size <= 1) {
        *return size;
    }
    
    int newSize = 1 ;
    for(int i = 1; i < size; i++) {
        if(arr[i] != arr[newSize-1]) {
            arr[newSize] = arr[i];
            newSize++;
        }
    }

    return newSize;
}

//Binary Search 
int binarySearch(int arr[], int size, int target){
    int low = 0 
    int high = size-1 ;

    while(low <= high) {
        int mid = low + (high - low)/2 ;

        if(arr[mid] == target) {
            return mid;
        } else {
               if(arr[mid] < target) {
                  low = mid +1;
              } else {
                  high = mid -1;
                }
        }
    }
    return -1;
}


//Linear Search 
int linearSearch(int arr[], int size, int target){
    for (int i=0 ; i<size ; i++){
        if(arr[i]==target){
            return i ;
        }
    }
    return -1 ;
}

//Left Shift Array 
void leftShift(int arr[], int size, int rotations){
    rotations %= size;
    while(rotations--) {
        int temp = arr[0];
        for(int i = 0; i < size-1; i++) {
            arr[i] = arr[i+1];
        }
        arr[size-1] = temp;
    }
}

//right Shift Array 
void rightShift(int arr[], int size, int rotations){
    rotations %= size;
    while(rotations--) {
        int temp = arr[size-1] ;
        for(int i = size-1; i > 0; i--) {
            arr[i] = arr[i-1];
        }
        arr[0] = temp ;
    }
}


//swapArr
void SwappArr(int arr , int* a, int* b){
    int temp=arr[a];
    arr[a]= arr[b] ;
    arr[b]=temp ;
}








//Sorting Algorithms

//Bubble Sort 
void bubbleSort(int arr[], int size){
    for(int i =0; i <size-1 ; i++) {
        for(int j=0; j <size - i-1;  j++) {
            if(arr[j] > arr[j+1])  {
                swapArr(arr, j, j+1 );
            }
        }
    }
}

//Selection Sort 
void selectionSort(int arr[], int size ){
    for(int i = 0; i < size-1; i++) {
        int min = i;

        for(int j = i+1 ; j < size; j++) {
            if(arr[j] < arr[min]) {
                min = j;
            }
        }

        swapArr(arr, i, min );

    }
}


//Insertion Sort 
void insertionSort(int arr[], int size){
    for (int i = 1; i < size ; i++ ) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j +1] = arr[j] ;
            j = j-1 ;
        }
        arr[j+1] = key ;
    }

}


//Merge Sort 
void merge(int arr[], int left, int mid, int right) {
    int size1 = mid - left + 1;
    int size2 = right - mid;
    int LEFT[size1], RIGHT[size2];

    // Copy subarrays
    for(int i = 0; i < size1; i++) {
        LEFT[i] = arr[left + i];
    }
    for(int j = 0; j < size2; j++) {
        RIGHT[j] = arr[mid + 1 + j];
    }

    // Merge
    int i = 0, j = 0, k = left;
    while(i < size1 && j < size2) {
        if(LEFT[i] <= RIGHT[j]) {
            arr[k++] = LEFT[i++];
        } else {
            arr[k++] = RIGHT[j++];
        }
    }

    // Copy remaining elements
    while(i < size1) arr[k++] = LEFT[i++];
    while(j < size2) arr[k++] = RIGHT[j++];
}

void mergeSort(int arr[], int left, int right) {
    if(left < right) {
        // Prevent overflow for large arrays
        int mid = left + (right - left) / 2; 
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}


//Quick Sort 
void quickSort(int arr[], int low, int high){

}




// ADVANCED ARRAY OPOERATION 


// FIND MISSING NUMBER 
int FindMissingNumber(int arr[],int size)
{
    int S,s,i ;
    S=((size+1) *(size+2))/2 ; // calculate the sum of numbers from 1 to n
    s=0; 
    for(i=0;i<size;i++)
    {
        s+=arr[i]; // calculate the sum of all numbers of the array 

    }
    return S-s ;
}


// FIND PAIRS WITH GIVEN SUM 

  void FindPairsWithSum(int arr[],int size,int sum)
{
    int i,j;
    for(i=0;i<size;i++)
    {
        for(j=i+1 ;j<size;j++)
        {
            if (arr[i]+arr[j]==sum)
            {
                printf("(%d,%d)\n",arr[i],arr[j]);
            }
        }
    }
}


// SUBARRAY WITH GIVEN SUM 

void findSubArrayWithSum(int arr[],int size,int sum)
{
    int begin,end , subsum,i ;
    for(begin=0;begin<size;begin++)
    {
        subsum=0;
        for( end=0 ;end<size;end++)
        {
            subsum+=arr[end]; // calculate the sum  subarrays
            if(subsum==sum)
            {
                for(i=begin;i<=end;i++)
                {
                  printf(" %d ",arr[i]); 
                }
                printf("\n");
            }
        }
    }


}


// REARRANGE POSITIVE AND NEGATIVE NUMBERS
void rearrangeAlternatePositiveNegative(int arr[],int size)
{
    int left=0,right=size-1,temp ;
    while(left<=right)
    {
        if(arr[left] < 0)
        {
        left++;
        }
        else 
        {
            if (arr[right]>=0)
            {
                right--;
            }
            else
            {
                temp=arr[left];
                arr[left]=arr[right];
                arr[right]=temp;
                left++;
                right--;

            }
        }
        

    }
}

//FIND MAJORITY ELEMENT
int findMajorityElement(int arr[] , int size)
{
    int i,j,c;
    for(i=0;i<size;i++)
    { c=0;
      
        for(j=0;j<size;j++)
        {
            if(arr[i]==arr[j])
            {
                c++;
            }
            if(c>(size/2))
            {
                return arr[i];
    
            }

        }
    }
    return -1;
}

// LONGEST INCREASING SUBSEQUENCE
int longestIncreasingSubsequence(int arr[], int size){
    if (size == 0) {
        return 0;
    }
    int i, longest=1,length=1 ;

    for(i=1;i<size;i++)
    {
        if(arr[i]>arr[i-1])
        {
            length++;
            if(length>longest)
            {
                longest = length;
            }
        }
        else 
        {
            length = 1;
        }
    }
    return longest;
}









/*Operations on matrices */


//Basic Matrix Functions
//Initialize Matrix 
void initializeMatrix(int rows, int cols, int matrix[rows][cols], int value){
   for (int i = 0; i < rows; i++) {
       for (int j = 0; j < cols; j++) {
         matrix[i][j] = value ;
        }
    }
}

//Print Matrix 
void printMatrix(int rows, int cols, int matrix[rows][cols]){
    for ( int i=0 ; i< rows ; i ++){
        for ( int j=0 ; j< cols ; j++){
            printf ("%4d" , matrix[i][j] ) ;
        }
        printf("\n") ;
    }
}

//Input Matrix 
void inputMatrix(int rows, int cols, int matrix[rows][cols]){
     for ( int i=0 ; i< rows ; i ++){
       for ( int j=0 ; j< cols ; j++){
         scanf ("%d" , &matrix[i][j]  ) ;
        }
    }  
}

//Matrix Arithmetic
//Matrix Addition 
void addMatrices(int rows, int cols, int mat1[rows][cols], int mat2[rows][cols], int result[rows][cols]){
 for ( int i=0 ; i< rows ; i ++){
       for ( int j=0 ; j< cols ; j++){
         result[i][j] = mat1[i][j] + mat2[i][j] ;     
        }
    }  
}

//Matrix Subtraction 
void subtractMatrices(int rows, int cols, int mat1[rows][cols], int mat2[rows][cols], int result[rows][cols]){
 for ( int i=0 ; i< rows ; i ++){
       for ( int j=0 ; j< cols ; j++){
         result[i][j] = mat1[i][j] - mat2[i][j] ;     
        }
    }  
}

//Matrix multiplication
void multiplyMatrices(int rows1, int cols1,int rows2 , int cols2 , int mat1[rows1][cols1], int mat2[rows2][cols2], int result[rows1][cols2]){


    if (cols1 != rows2) {
        printf("Error: Matrix dimensions incompatible for multiplication!\n");
        printf("Columns of first matrix (%d) must match rows of second matrix (%d)\n", cols1, rows2);
        return;
    }

    for (int i = 0; i < rows1; i++) {       
        for (int j = 0; j < cols2 ;j++)  {     
            result[i][j] = 0;                
            for (int k = 0; k < cols1;k++){
                result[i][j] +=mat1[i][k] *mat2[k][j] ;
            }
        }
    }
}


//Scalar Multiplication 
void scalarMultiplyMatrix(int rows, int cols, int matrix[rows][cols], int scalar){
     for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] *= scalar; 
        }
    }

}

//Matrix Properties and Checks
//Check if Square Matrix 
bool isSquareMatrix( int rows, int cols){
    return (rows == cols) ;
}

//Check if Identity Matrix 
bool isIdentityMatrix(int size, int matrix[size][size]) {
    for (int i = 0; i < size; i++) {
        if (matrix[i][i] != 1) {
            return false;
        }
    }
    return isDiagonalMatrix(size, matrix);  
}

//Check if Diagonal Matrix 
bool isDiagonalMatrix(int size, int matrix[size][size]){
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i!= j && matrix[i][j]!= 0){
                return false;
            }
        }
    }
    return true;      
}

//Check if Symmetric Matrix 
bool isSymmetricMatrix(int size, int matrix[size][size]){
    for ( int i  =0 ; i<size ; i++){
        int j = i ;
        int k=0 ;
        int l=size-1 ;
        while (k!=i && l!=i ){
            if (matrix[i+l][j] != matrix[i-k][j] ){
                return false ;
            }
            if (k!= i ){
                k++ ;
            }
            if (l!=i){
                l-- ;
            }
        }
    }
    return true ;
}

//Check if Upper Triangular Matrix 
bool isUpperTriangular(int size, int matrix[size][size]){
    for ( int i  = 0 ; i<size ; i++){
        int j = i ;
        int k=1 ;
        while (k!=i){
            if (matrix [i-k][i]!=0){
                return false ;
            }
            k++ ;
        }
    }
    return true ;
}






//Matrix Operations


//Transpose Matrix 
void transposeMatrix(int rows, int cols, int matrix[rows][cols], int result[cols][rows]){
   for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

//Determinant of a Matrix 
int determinantMatrix(int size, int matrix[size][size]){
    int det = 0 ;
    int smatrix[size - 1][size- 1]; 
    if (size == 1) {
        return matrix[0][0];
    }

    if (size == 2) {
        return (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
    }

    int submatrix[size-1][size-1] ;
    int det = 0 ;
    int sign = 1 ;


    for (int col = 0; col < size ; col++) {
        int  l ;
        for (int i = 0 ;i<size ; i++){
           if (i==col){
             l++ ;
            }
            for (int j=1 ; j<size ; j++){           
             submatrix[i][j-1]=matrix[l][j] ; 
            }
            l++ ;   
        }

        det += sign * matrix[0][col] * determinantMatrix(size- 1, submatrix) ;
        sign *= -1 ;  
    }

    return det;
}

void adjointMatrix(int size, int matrix[size][size], int adjoint[size][size]) ;

//Inverse of a Matrix 
void inverseMatrix(int size, int matrix[size][size], int result[size][size]){
    
    double det = determinant(size, matrix);
    if (det == 0) {
        printf("The inverse does not exist.");
        return ;
    }else{
        adjointMatrix (size , matrix , result ) ;
        for ( int i ; i<size ; i++){
            for ( int j ; j<size ;j++){
                result[i][j]/=det ;
            }
        }
    }

}



//Matrix Power 
void matrixPower(int size, int matrix[size][size], int power, int result[size][size]){
    if (power == 0) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
               if (i == j) {         
                    result[i][j] = 1; 
             }else {            
                  result[i][j] = 0; 
                }
            }
        }
        return;
    }


    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = matrix[i][j] ;
        }
    }


    int temp[size][size] ;
    for (int p = 1; p < power; p++) {
        multiplyMatrices (size, size, result, size, size, matrix, temp ) ;
        
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                result[i][j] = temp[i][j];
            }
        }

    }
}



//Advanced Matrix Functions

//Minor of a matrix
int Minor( int a , int b ,int size, int matrix[][size], int minor[][size-1]){
    int mini = 0;
    for(int i = 0; i <size; i++) {
        if(i ==row) {
            continue;
        }
        int minj = 0;
        for(int j = 0; j < size; j++) {
            if(j == col) {
                continue;
            }

            minor[mini][minj] = matrix[i][j];
            minj++;
        }

        mini++;
    }
}



//Cofactor Matrix 
void cofactorMatrix(int size, int matrix[size][size], int cofactor[size][size]){
    int minor[size-1][size-1];
    for(int i = 0; i < size;i++){
        for(int j = 0; j < size;j++){
            getMinor(size,matrix,i,j,minor);
            int sign;
            if ((i + j) % 2 == 0) { 
                sign = 1 ;
         } else {                 
                sign = -1 ;
            }
            cofactor[i][j] = sign* determinantMatrix(size-1 , minor)  ;
        }
    }
}

//Adjoint Matrix 
void adjointMatrix(int size, int matrix[size][size], int adjoint[size][size]){
    int cofactor[size][size] ;  
    cofactorMatrix ( size , matrix , cofactor);
    transposeMatrix(size , size , cofactor , adjoint ) ;
}



//LU Decomposition 
void luDecomposition (int size, double matrix[size][size], double lower[size][size], double upper[size][size]){

    for(int i = 0; i < size; i++) {

        for(int k = i; k < size; k++) {
            double sum = 0;
            for(int j = 0; j < i; j++){
                sum += lower[i][j] * upper[j][k] ;
            }
            upper[i][k] =matrix[i][k] -sum ;
        }


        for(int k = i; k < size; k++) {

            if(i == k) {
                lower[i][i] = 1;
            } else {
                double sum = 0;
                for(int j = 0; j < i; j++) {
                    sum += lower[k][j] * upper[j][i] ;
                }
                lower[k][i] = (matrix[k][i] - sum) /upper[i][i]   ;
            }

        }
    }
}







//Special Matrix Operations



//Find Trace of a Matrix 
int traceMatrix(int size, int matrix[size][size]){
    int trace =0  ;
    for(int i = 0 ; i < size ; i++) {
        trace +=  matrix[i][i] ;
    }
    return trace ;
}


//Rotate Matrix 90 Degrees 
void rotateMatrix90 (int size, int matrix[size][size]){
    int tempMatrix[size][size] ;
    for ( int i = 0 ; i<size ; i++){
        for ( int j=0 ; j<size ; j++){
            tempMatrix[i][j] = matrix[size-1 -j][i] ;
        }
    }
    for ( int i = 0 ; i<size ; i++){
        for ( int j ; j<size ; j++){
            matrix[i][j]= tempMatrix[i][j] ;
        }
    }
}


//Find Eigenvalues
void findEigenvalues(int size, double matrix[size][size], double eigenvalues[size]) {

}



//Optional parts
//Caeser cipher 
char rightShiftChar(char c, int shift) {
    if (c >= 'a' && c <= 'z') {
        return ((c - 'a' + shift) % 26 + 'a'); 
    } else if (c >= 'A' && c <= 'Z') {
        return ((c - 'A' + shift) % 26 + 'A');
    return c; 
    }
}

void caesarCipher(char *text, int shift) {
    void caesarCipherRecursive(char *text, int shift, int index) {
        if (text[index] == '\0') {
            return; 
        }

        text[index] = rightShiftChar(text[index], shift); 
        caesarCipherRecursive(text, shift, index + 1); 
        }

    caesarCipherRecursive(text, shift, 0); 
}



void substitutionCipher(char *text, const char *key) {

    if (strlen(key)!= 26) {
        return;
    }

    for (int i = 0; i < 26; i++) {
        if (!isalpha(key[i])) {
            return ;
        }

        for (int j = i+1 ; j < 26; j++) {
            if (tolower(key[i]) == tolower(key[j])){
               return ;
            }
        }
    }


    for (int i = 0; text[i]; i++) {
       if (isalpha(text[i])) {
           if (islower(text[i])) {
              int index =text[i]-'a';
              text[i] = tolower(key[index])  ;
           }else{
              int index =text[i]-'A';
              text[i] = toupper(key[index]) ;
            }
       }
    }

}


void xorCipher(char *text, const char *key) {
    char bestkey = 0 ;
    int highestcount = 0 ;

    for (int key = 0; key < 256; key++) {
        int count = 0;
        
        for (int i = 0; ciphertext[i]; i++) {
            char decrypted = ciphertext[i] ^ key;
            
 
            if ((decrypted >= 'A' && decrypted <= 'Z') ||(decrypted >= 'a' && decrypted <= 'z') ||decrypted == ' ') {
                count++;
            }
        }


        if (count > highestcount) {
            highestcount = count;
            bestkey = key;
        }

    }

    return bestkey;
}