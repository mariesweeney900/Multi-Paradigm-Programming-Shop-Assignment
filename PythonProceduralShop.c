
#Code compiled online at https://www.jdoodle.com/c-online-compiler/#
#Code adapted from https://learnonline.gmit.ie/pluginfile.php/136452/mod_resource/content/0/shop.c
#https://www.urbanpro.com/c-language/why-we-use-include-stdio-h
#stdio.h is the header file for standard input and output. This is useful for getting the input from the user(Keyboard) and output result text to the monitor(screen). With out this header file, 
#one can not display the results to the users on the screen or cannot input the values through the keyboard

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#https://www.tutorialspoint.com/cprogramming/c_structures.htm
#Structure is user data type in C that permits to aligh data types of different kinds.
struct Product{
	char* name;
	double cost;
};

struct ProductStore {
	struct Product prod;
	int amount;
};

struct Shop {
	double money;
	struct ProductStore store[20];
	int index;
};

struct Customer{
	char* name;
	double maxbudget;
	struct ProductStore shopList[10];
	int index;
};

#https://www.thoughtco.com/definition-of-void-958182
#Void is used as a function return type, it identifies that the function does not return a value
void printProduct(struct Product p)
{
	printf("PRODUCT NAME: %s \nPRODUCT COST: %.2f\n", p.name, p.cost);
	printf("----------------\n");
};


void printCustomer(struct Customer c)
{
	printf("CUSTOMER NAME: %s \nCUSTOMER MAXBUDGET: %.2f\n", c.name, c.maxbudget);
	printf("----------------\n");
	for(int i=0; i<c.index; i++)
	{
	printProduct(c.shopList[i].prod);
	printf("%s ORDERS %d OF ABOVE PRODUCT\n", c.name,c.shopList[i].amount);
	double cost = c.shopList[i].amount * c.shopList[i].prod.cost;
	printf("The cost to %s will be %.2f\n", c.name, cost);
	}
}	

struct Shop createAndStoreShop()
{
	//struct Shop shop = { 200 };
	FILE * fp;
	char * line = NULL;
	size_t len = 0;
	ssize_t read;

	fp = fopen("/uploads/stock.csv", "r");
	if (fp == NULL)
		exit(EXIT_FAILURE);

	read = getline(&line, &len, fp);	
	float money = atof(line);
	// printf("money in shop is %.2f\n", money);
	
	struct Shop shop = { money };

	while ((read = getline(&line, &len, fp)) != -1){
		//printf("%s IS A LINE", line);
		char *n = strtok(line,",");
		char *p= strtok(NULL, ",");
		char *q = strtok(NULL, ",");
		int amount = atoi(q);
		double cost = atof(p);
		char *name = malloc(sizeof(char) * 50);
		strcpy(name, n);
		struct Product prod = { name,cost };
		struct ProductStore storeitemType = { prod, amount};
		shop.store[shop.index++] = storeitemType;
		//printf("NAME OF PRODUCT %s, COST %.2f, AMOUNT %d\n", name, cost, amount);
	}
	//printProduct(shop.store[0].prod);
	
	return shop;
}

void printShop(struct Shop s)
{
	printf("Shop has %.2f in money\n", s.money);
	for (int i = 0; i < s.index; i++)
	{
		printProduct(s.store[i].prod);
		printf("The shop has %d of the above\n", s.store[i].amount);
	}
}

int main(void)
{
//	struct Customer paul = {"Paul", 100.0};
	
//	struct Product coke={"Can Coke", 1.10};
//	struct Product bread={"Bread", 0.7};
	
//	printProduct(coke);

//	struct ProductStore cokeStore = {coke, 20};
//	struct ProductStore breadStore = {bread, 2};
//	dominic.shopList[paul.index++] = cokeStore;
//	dominic.shopList[paul.index++] = breadStore;
//	printCustomer(paul);
//	printf("The shop has %d of the product %s\n", cokeStore.amount, cokeStore.prod.name);

	struct Shop shop = createAndStoreShop();
	printShop(shop);

	return 0;
}


Shop has 0.00 in money
PRODUCT NAME: Bread 
PRODUCT COST: 0.70
----------------
The shop has 30 of the above
PRODUCT NAME: Spaghetti 
PRODUCT COST: 1.20
----------------
The shop has 100 of the above
PRODUCT NAME: Tomato Sauce 
PRODUCT COST: 0.80
----------------
The shop has 100 of the above
PRODUCT NAME: Big Bags 
PRODUCT COST: 2.50
----------------
The shop has 4 of the above
