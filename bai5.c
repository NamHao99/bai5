#include <stdio.h>
#include <string.h>


enum type{
	CLOTHING,
	SHOES,
	ELECTRONICS,
 };
union info
{
	float size;
	float weight;
};
struct data
{
	char nameproduct[20];
	float price;
	enum type CSE;
	union info SW;

	
};
int main(){
	int num;
	
	printf("Input number of products:");
	scanf("%d", &num);
	struct data storedata[num];
	for (int i = 0; i < num; i++)
	{
		printf("\nEnter information for product %d:\n", i+1 );

        printf("Name: ");
        scanf("%s", storedata[i].nameproduct);

        printf("Price: ");
        scanf("%f", &storedata[i].price);

	int typeValue;
		printf("Type (0: Clothing, 1: Shoes, 2: Electronics): ");
		scanf("%d", &typeValue);

	if (typeValue >= CLOTHING && typeValue <= ELECTRONICS) {
    	storedata[i].CSE = typeValue;
	 	if (storedata[i].CSE == CLOTHING || storedata[i].CSE == SHOES) {
            printf("Size: ");
            scanf("%f", &storedata[i].SW.size);
            } else if (storedata[i].CSE == ELECTRONICS) {
            printf("Weight: ");
            scanf("%f", &storedata[i].SW.weight);
            }
	} else{
	while (typeValue < 0 || typeValue > 2) {
    	printf("Invalid value!! Please enter a valid type (0: Clothing, 1: Shoes, 2: Electronics): ");
    	scanf("%d", &typeValue);
		if (storedata[i].CSE == CLOTHING || storedata[i].CSE == SHOES) {
            printf("Size: ");
            scanf("%f", &storedata[i].SW.size);
            } else if (storedata[i].CSE == ELECTRONICS) {
            printf("Weight: ");
            scanf("%f", &storedata[i].SW.weight);
            }
    }
	}
	}
	 char searchName[50];
    printf("\nEnter the name of the product to search: ");
    scanf("%s", searchName);

    for (int i = 0; i < num; i++) {
        if (strcmp(searchName, storedata[i].nameproduct) == 0) {
            printf("\nProduct found!\n");
            printf("Name: %s\n", storedata[i].nameproduct);
            printf("Price: %f\n", storedata[i].price);
            if (storedata[i].CSE == CLOTHING) {
				printf("Type: CLOTHING");
                printf("Size: %f\n", storedata[i].SW.size);
            } else if (storedata[i].CSE == ELECTRONICS) {
				printf("Type: ELECTRONICS\n");
                printf("Weight: %f\n", storedata[i].SW.weight);
            } else if ( storedata[i].CSE == SHOES){
				printf("Type: SHOES");
				printf("Size: %f\n", storedata[i].SW.size);
			}
        }
    }

}