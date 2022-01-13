# include <stdio.h>
# include <string.h>
 
int main( )
{
    int xyz;
    printf("Customer registry warranty details");
    printf("press 1 for adding detail,2for viewing details : ");
    scanf("%d",&xyz);
    if(xyz==1){
        FILE *filePointer ;
     
        char custName[50],prod[50],mobno[50],mrp[20],dop[10];
        printf("MRP :");
        scanf("%s",&mrp);
        printf("Product: ");
        scanf("%s",prod);
        printf("Customer Name: ");
        scanf("%s",custName);
        printf("Mobile Number: ");
        scanf("%s",mobno);
        printf("Date Of Purchase: ");
        scanf("%s",dop);

        filePointer = fopen("Pranav.txt", "a") ;
        

        if ( filePointer == NULL )
        {
            printf( "file failed to open." ) ;
        }
        else
        {
            
            printf("The file is now opened.\n") ;
            

            if ( strlen ( custName ) > 0 )
            {
                
                fputs(custName, filePointer) ;
                fputs(" ", filePointer) ;

            }
            if( strlen ( prod ) > 0){

                fputs(prod, filePointer) ;
                fputs(" ", filePointer) ;
            } 
            if( strlen (mobno) == 10){
                fputs(mobno, filePointer) ;
                fputs(" ", filePointer) ;
            }
            else {
                printf("Invalid Mobile Number");
                printf("retype mobile number");
                scanf("%s",mobno);
                fputs(mobno, filePointer) ;
                fputs(" ", filePointer) ;
            }
            fputs(dop, filePointer) ;
            fputs("\n", filePointer) ;
            if( strlen (mrp) > 0){
                fputs(mrp, filePointer) ;
                fputs("\n", filePointer) ;
            }
            fclose(filePointer) ;
            
            printf("Data successfully written in file");
            printf("The file is now closed.") ;
        }
    }
    if(xyz==2){
        FILE *filePointer ;
        char dataToBeRead[50];
        filePointer = fopen("pranav.txt", "r") ;
        if ( filePointer == NULL )
        {
            printf( "file failed to open." ) ;
        }
        else
        {
            
            printf("\nThe file is now opened.\n") ;
            while( fgets ( dataToBeRead, 50, filePointer ) != NULL )
            {
            
                printf( "%s" , dataToBeRead ) ;
            }
            fclose(filePointer) ;
            
            printf("\nData successfully read from file\n");
            printf("The file is now closed.") ;
        }
    }
    return 0;       
}
