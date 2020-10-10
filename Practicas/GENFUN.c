#include "stdio.h" 
#include"GENFUN.h" 
#include"string.h" 
void main( void  ) 
{ 
	printf("Testing  Genfun_vCapsoff\n"); 
	uint8 au8BufferTest[12] = "HElLO WOrLd"; 
	printf("Buffer before function%s\n",au8BufferTest ); 
	Genfun_vCapsoff(&au8BufferTest[0],12); 
	printf("Buffer after function%s\n",au8BufferTest ); 
} 
void Genfun_vCapsoff (uint8 *pu8Src, uint8 u8SizeOfflist) 
{ 
	while( u8Sizeofflist !=0 ) 
	{ 
		if(*pu8Src>=ASCII_LOW_THRESHHOLD_CAPSON_TO_OFF && *pu8Src<=ASCII_HIGH_THRESHHOLD_CAPSON_TO_OFF) 
		{ 
			*pu8Src+=ASCII_CONVERTION_FACTOR; 
		} 
		else 
		{ 
			/*Nothing to do */ 
		} 
		pu8Src++; 
	    u8Sizeofflist --; 
	} 
} 
/* Segundo problema*/ 
void main(void) 
{ 
	printf("Testing Genfun_vCapsOn\n"); 
	uint8 au8BufferTest[12] = "HElLO WOrLd"; 
	printf("Buffer before function%s\n",au8BufferTest ); 
	Genfun_vCapsoff(&au8BufferTest[0],12); 
	printf("Buffer after function%s\n",au8BufferTest ); 
} 
void void Genfun_vCapsOn (uint8 *pu8Src, uint8 u8SizeOfflist) 
{ 
	while( u8Sizeofflist!=0) 
	{ 
		if(*pu8Src>=ASCII_High_THRESHHOLD_CAPSON_TO_On && *pu8Srcz=ASCII_Low_THRESHHOLD_CAPSON_TO_On) 
		{ 
			*pu8Src-=ASCII_CONVERTION_FACTOR; 
		} 
		else 
		{ 
			/*Nothing to do */ 
		} 
		pu8Src++; 
		u8Sizeofflist -- ; 
	} 
} 
/*Tercer problema */ 
int main() 
{ 
	char *pu8Src= " COMO ESTA LA RAZA EL DIA DE HOY?"; 
	char u8Target = "A"; 
	char *Busqueda= NULL; 
	int i= 0; 
	uint8 GENFUN_u8GetOccurence(*pu8Src,u8Target); 
	GENFUN_u8GetOccurence =(strstr(*pu8Src,u8Target)); 
	while(GENFUN_u8GetOccurence !=NULL) 
	{ 
		i++; 
		GENFUN_u8GetOccurence =strstr(Busqueda+1,u8Target); 
	} 
	printf("Total de coincidencias%i\n",i); 
	if(Busqueda!=NULL) 
	{ 
		printf("Se encontro el target %s\n",u8Target) 
	} 
	else 
	{ 
		printf("No se encontro el target %s\n",u8Target); 
	} 
 
} 
char* uint8 GENFUN_u8GetOccurence (uint8 *pu8Src, uint8 u8Target, uint8 u8SizeOfList) 
{ 
	int i; 
 
	else  
	{ 
		i=0; 
		c= u8Target [0]; 
		while(u8Sizeofflist [i]  !=0) 
		{ 
			if(*pu8Src[i]==c) 
			{ 
				if(strncomp(*pu8Src[i],&u8Target, u8Sizeofflist)==0) 
				{ 
					return &u8Target [i];  
				} 
			} 
			i++; 
		} 
		return NULL; 
	} 
 
} 
 
 
/*Cuarto problema*/ 

char uint8 GENFUN_u8GetAverage (uint8 *pu8Src, uint8 u8SizeOfList)

void main()
{
	char uint8 GENFUN_u8GetAverage (uint8 *pu8Src, uint8 u8SizeOfList);
	int uint8,*pu8Src,sum=0,i;
	float avg;
	clrscr();
	printf("\nHOW MANY NUMBERS: ");
	scanf("%d",&uint8);
	pu8Src=(int *) malloc(uint8*2);
	if(pu8Src==NULL)
	{
		printf("\nMEMORY ALLOCATION UNSUCCCESSFUL");
		exit();
	}
	for(i=0;i<uint8;i++)
	{
		printf("\nENTER NUMBER %d: ",i+1);
		scanf("%d",(pu8Src+i));
	}
	for(i=0;i<uint8;i++)
		sum=sum+*(pu8Src+i);
	avg=(float)sum/n;
	printf("\nTHE AVERAGE OF THE NUMBERS IS %0.2f",avg);
	getch();
}

/*Quinta Funcion*/
int main() 
{ 
    char str[50] = "GeeksForGeeks is for programming geeks."; 
    printf("\nBefore memset(): %s\n", str); 
  
    // Fill 8 characters starting from str[13] with '.' 
    memset(str + 13, '.', 8*sizeof(char)); 
  
    printf("After memset():  %s", str); 
    return 0; 
} 

void printArray(int arr[], int n) 
{ 
   for (int i=0; i<n; i++) 
      printf("%d ", arr[i]); 
} 
  
int main() 
{ 
    int n = 10; 
    int arr[n]; 
  
    // Fill whole array with 0. 
    memset(arr, 0, n*sizeof(arr[0])); 
    printf("Array after memset()\n"); 
    printArray(arr, n); 
  
    return 0; 
} 


/*sexto programa*/
int main(int argc, const char * argv[])
{
    /* Create a place to store our results */
    int result;

    /* Create two arrays to hold our data */
    char original[50];
    char newcopy[50];

    /* Copy a string into the original array */
    strcpy(original, "C memcpy at TechOnTheNet.com");

    /* Copy the first 24 characters of the original
     array into the newcopy array */
    result = memcpy(newcopy, original, 24);

    /* Set the character at position 24 to a null (char 0)
     in the newcopy array to ensure the string is terminated
     (This is important since memcpy does not initialize memory
     and printf expects a null at the end of a string) */
    newcopy[24] = 0;

    /* Display the contents of the new copy */
    printf("%s\n", newcopy);

    return 0;
}

/*septimo programa*/
void sort(int n, int* ptr) 
{ 
    int i, j, t; 
  
    // Sort the numbers using pointers 
    for (i = 0; i < n; i++) { 
  
        for (j = i + 1; j < n; j++) { 
  
            if (*(ptr + j) < *(ptr + i)) { 
  
                t = *(ptr + i); 
                *(ptr + i) = *(ptr + j); 
                *(ptr + j) = t; 
            } 
        } 
    } 
  
    // print the numbers 
    for (i = 0; i < n; i++) 
        printf("%d ", *(ptr + i)); 
} 
  
// Driver code 
int main() 
{ 
    int n = 5; 
    int arr[] = { 0, 23, 14, 12, 9 }; 
  
    sort(n, arr); 
  
    return 0; 
} 