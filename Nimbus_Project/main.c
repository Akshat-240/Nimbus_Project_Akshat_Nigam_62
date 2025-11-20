#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//structure
typedef struct {
    int code;
    char name[50];
    float price;
    int quantity;
} Product;

//global inventory

Product **products = NULL;
int num_products = 0;
int max_products = 100;

//Intialize inventory
void initProducts() {
    products = malloc(max_products * sizeof(Product *));
    num_products = 0;
}

// Resize product array
void resizeProducts() {
    max_products *= 2;
    products = realloc(products, max_products * sizeof(Product *));
}

// Add product
void addProduct() {
    if (num_products >= max_products)
        resizeProducts();

    products[num_products] = malloc(sizeof(Product));

    printf("Enter code: ");
    scanf("%d", &products[num_products]->code);

    for (int i = 0; i < num_products; i++) {
        if (products[i]->code == products[num_products]->code) {
            printf("Duplicate code.\n");
            free(products[num_products]);
            return;
        }
    }

    printf("Enter name: ");
    scanf(" %[^\n]", products[num_products]->name);

    printf("Enter price: ");
    scanf("%f", &products[num_products]->price);

    printf("Enter quantity: ");
    scanf("%d", &products[num_products]->quantity);

    num_products++;
    printf("Product added.\n");
}

int findProductIndex(int code) {
    for (int i = 0; i< numproducts; i++){
        if(products[i]->code == code){
            return i;
        }
    }
    return -1;
}

void removeProdect(){
    int code;
    printf("Enter code to remove; ");
    scanf("%d", &code);

    int idx = findProductIndex(code);
    if(idx == -1) {
        printf("Not Found.\n");
        return;
    }

    free(products[idx]);

    for(int i = idx; i < num_products-1; i++)
    products[i] = products[i+1];

    num_products--;
    printf("Removed.\n");

}

void displayAllProducts() {
    if(num_products == 0){
        printf("Empty inventory.\n");
        return;
    }
    printf("%-5s %-20s %-10s %-8s\n", "Code", "Name", "Price", "Qty");

    for(int i = 0; i < num_products; i++) {
        printf("%-5d %-20s %-10.2f %-8d\n",
            products[i]->code,
            products[i]->name,
            products[i]->price,
            products[i]->quantity);
    }
}

