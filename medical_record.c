#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*  Medicine Details */
struct medicine
{
	char name[64];
	char description[128];
	char manf_date[16];
	char expiry_date[16]; 
	float price;
	int quantity;
	int deleted;
};



/*  open the file for reading */
void read_from_file(struct medicine* medical_record, char* filename, int* medicine_count){	
	FILE *fptr;

    fptr = fopen(filename, "r");

    if (fptr) {

    	/*  read medicine details line by line till end of file */
	    while(1){
	        
	        // read name
	        fscanf(fptr, "%[^\n]%*c", medical_record[*medicine_count].name);

			// read description
		
	        fscanf(fptr, "%[^\n]%*c", medical_record[*medicine_count].description);

	        // read manufacturing date
	       
	       fscanf(fptr, "%[^\n]%*c", medical_record[*medicine_count].manf_date);

	        // read expiry date
	       
	      fscanf(fptr, "%[^\n]%*c", medical_record[*medicine_count].expiry_date);

	        // read price
	        fscanf(fptr, "%f\n", &medical_record[*medicine_count].price);
	        
	        // read quantity

	        if(fscanf(fptr, "%d\n", &medical_record[*medicine_count].quantity)!=EOF){
	        	medical_record[*medicine_count].deleted = 0;
	        	(*medicine_count)++;
        	}

	        else{
	        	break;
	        }
	    }
	    fclose(fptr);

	}
	else{
		printf("Cannot open file \n");
        exit(0);
	}
}



void display_medical_record(struct medicine* medical_record, int medicine_count){
	int i, count;

	printf("\n********************  Start Of Medical Record   ********************\n\n");

	for(i=0, count=1; i < medicine_count; i++){

		if(medical_record[i].deleted==1)
			continue;
		
		printf("\n\t\tMedicine %d\n", count++);
		
		printf("Name\t\t\t: %s\n",medical_record[i].name);
		printf("Description\t\t: %s\n",medical_record[i].description);
		printf("Manufacturing Date\t: %s\n",medical_record[i].manf_date);
		printf("Expiry Date\t\t: %s\n",medical_record[i].expiry_date);
		printf("Price\t\t\t: %f\n",medical_record[i].price);
		printf("Quantity\t\t: %d\n",medical_record[i].quantity);			
	}

	printf("\n\n********************  End Of Medical Record   ********************\n\n");
}



void add_medicine(struct medicine* medical_record, int* medicine_count)
{

	if(*medicine_count==100){
		printf("\n\nMedical Record Full\n\n");
	}
	else{
		printf("\nPlease Enter Name\n");
		// read name
	
	    scanf("\n%[^\n]%*c", medical_record[*medicine_count].name);

	    printf("\nPlease Enter Description\n");
		// read description
	

	    scanf("%[^\n]%*c", medical_record[*medicine_count].description);

	    printf("\nPlease Enter Manufacturing Date\n");
	    // read manufacturing date
	 
	    scanf("%[^\n]%*c", medical_record[*medicine_count].manf_date);

	    printf("\nPlease Enter Expiry Date\n");
	    // read expiry date
	 
	   scanf("%[^\n]%*c", medical_record[*medicine_count].expiry_date);

	    printf("\nPlease Enter Price\n");
	    // read price
	    scanf("%f", &medical_record[*medicine_count].price);
	    
	    printf("\nPlease Enter Quantity\n");
	    // read quantity
	    scanf("%d", &medical_record[*medicine_count].quantity);
	    medical_record[*medicine_count].deleted = 0;
	    (*medicine_count)++;

	    printf("\n\nMedicine Added\n\n");
	}
}



void search_medicine(struct medicine* medical_record, int medicine_count)
{
	char name[64];
	
	printf("\n\nPlease Enter Name\n\n");
	// read name

      scanf("\n%[^\n]%*c", name);

    while(medicine_count >= 0)
	{
    	
    	if(medical_record[medicine_count].deleted==1)
    	{
    		medicine_count--;
			continue;
		}
    	
    	if(stricmp(name, medical_record[medicine_count].name) == 0)
           {
    		printf("\n\t\tMedicine Details\n");

	    	printf("Name\t\t\t: %s\n",medical_record[medicine_count].name);
			printf("Description\t\t: %s\n",medical_record[medicine_count].description);
			printf("Manufacturing Date\t: %s\n",medical_record[medicine_count].manf_date);
			printf("Expiry Date\t\t: %s\n",medical_record[medicine_count].expiry_date);
			printf("Price\t\t\t: %f\n",medical_record[medicine_count].price);
			printf("Quantity\t\t: %d\n",medical_record[medicine_count].quantity);
    		
    		break;
    	}
    	medicine_count--;
    }
    if(medicine_count<0){
    	printf("\n\nNo Medicine Found\n\n");
    }
}



void delete_medicine(struct medicine* medical_record, int medicine_count)
{
	char name[64];
	
	printf("\n\nPlease Enter Name\n\n");
	// read name

    scanf("\n%[^\n]%*c", name);

    while(medicine_count >= 0)
	{
    	
    	if(medical_record[medicine_count].deleted==1)
    	{
    		medicine_count--;
			continue;
		}
		
    	if(stricmp(name, medical_record[medicine_count].name) == 0){

    		printf("\n\t\tMedicine Deleted\n");

			medical_record[medicine_count].deleted = 1;
 
    		break;
    	}
    	medicine_count--;
    }
    if(medicine_count<0){
    	printf("\n\nNo Medicine Found\n\n");
    }
}

void update_medicine(struct medicine* medical_record, int medicine_count)
{
	char name[64];
	float price;
	int quantity;
	
	printf("\n\nPlease Enter Name\n\n");
	scanf("\n%[^\n]%*c", name);
	printf("\n\nPlease Enter Price\n\n");
	scanf("\n%f",&price);
	printf("\n\nPlease Enter no of Tablets\n\n");
	scanf("\n%d", &quantity);
	
	while(medicine_count>=0)
	{
		if(medical_record[medicine_count].deleted==1)
    	{
    		medicine_count--;
			continue;
		}
	    	if(stricmp(name, medical_record[medicine_count].name) == 0)
			{
				medical_record[medicine_count].price=price;
				medical_record[medicine_count].quantity=quantity;
				
					printf("\n\t\tMedicine Details\n");

	    	printf("Name\t\t\t: %s\n",medical_record[medicine_count].name);
			printf("Description\t\t: %s\n",medical_record[medicine_count].description);
			printf("Manufacturing Date\t: %s\n",medical_record[medicine_count].manf_date);
			printf("Expiry Date\t\t: %s\n",medical_record[medicine_count].expiry_date);
			printf("Price\t\t\t: %f\n",medical_record[medicine_count].price);
			printf("Quantity\t\t: %d\n",medical_record[medicine_count].quantity);
           	
			printf("\n\n\t\t\tMedicine Is Updated\n");
			   	
    		break;
				
		}
		medicine_count--;	
	}
	if(medicine_count<0)
	{
	   printf("\n\nNo Medicine Found");
}
	
}


void bill(struct medicine*medical_record, int medicine_count)

   {
	float total=0;
	char name[64];
	char coustumer_name[60];
	char date[40];
	int tablets;
	float price;
    char mobile_number[60];
	
	printf("Please Enter Name Of Tablet\n\n");
	scanf("\n%[^\n]%*c", name);
	
	printf("Please Enter Mobile Number\n\n");
	scanf("\n%[^\n]%*c", &mobile_number);
	
	printf("\nPlease Enter Coustumer Name\n\n");
	scanf("\n%[^\n]%*c",coustumer_name);
	
	printf("\nPlease Enter Date\n\n");
	scanf("\n%[^\n]%*c",date);
	
	printf("\nPlease Enter Tablets\n\n");
	scanf("%d",&tablets);
	
	while(medicine_count>=0)
	{
		
		if(medical_record[medicine_count].deleted==1)
    	{
    		medicine_count--;
			continue;
		}
		
		if(stricmp(name, medical_record[medicine_count].name) == 0)
		{
			total=total+tablets*medical_record[medicine_count].price;

	printf("\n********************  Bill   ********************\n\n");
			
			printf("Coustumer Name\t: %s\n",coustumer_name);
			printf("Mobile Number\t: %s\n",mobile_number);
			printf("Name Of Medicine: %s\n",medical_record[medicine_count].name);
			printf("Date\t\t: %s\n",date);
			printf("Total Cost\t: %f\n",total);
	
	 printf("\n*******************  Thankyou   *******************\n\n");
			
			break;
		}
		medicine_count--;
		
		
	}
	if(medicine_count<0)
	{
	    printf("\n\nNo Medicine Found");	
	}

	
}



int main()
{
	
	int input;

    char filename[100];

    struct medicine medical_record[100];
    int medicine_count = 0;

    printf("\n\n\t\t\t\t\t\t\t\tMEDICINE RECORD MANAGEMENT SYSTEM\n\n");

    printf("Enter the filename to be opened \n");
    scanf("%s", filename);
    
    // Read Medical Record
   read_from_file(medical_record, filename, &medicine_count);

    while(1){
    	printf("\n\nChoose Below Options\n\n");
    	printf("1. Display Medical Record\n");
    	printf("2. Add Medicine\n");
    	printf("3. Search Medicine\n");
    	printf("4. Delete Medicine\n");
    	printf("5. Update Medicine\n");
    	printf("6. Create Bill\n");
    	printf("7. Exit Program\n");
    	
    	scanf("%d",&input);

    	switch(input){
    		
    		case 1:
    			display_medical_record(medical_record, medicine_count);
    			break;

    		case 2:
    			add_medicine(medical_record, &medicine_count);
    			break;
    		
    		case 3:
    			search_medicine(medical_record, medicine_count);
    			break;

    		case 4:
    			delete_medicine(medical_record, medicine_count);
    			break;
    		
    		case 5:
    			update_medicine(medical_record, medicine_count);
    			break;
    		
			case 6:
				bill(medical_record, medicine_count);
				break;
					
    		case 7:
    			printf("\n\nProgram Terminating\n\n");
    			return 0;
    	}

    }
}
