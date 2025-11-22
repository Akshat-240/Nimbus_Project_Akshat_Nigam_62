#include <stdio.h>

void initProducts();
void addProduct();
void removeProduct();
void displayAllProducts();
void saveInventory();
void loadInventory();
void initCart();
void addToCart(int code, int qty);
void generateInvoice();

void showMenu();
void clearScreen();
void extrasMenu();

int main(){
    initProducts();
    initCart();
    loadInventory();

    int choice;

    do{
        clearScreen();
        showMenu();
        printf("Enter a Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addProduct(); break;
            case 2: removeProduct(); break;
            case 3: displayAllProducts(); break;

        case 4: {
            int code, qty;
            printf("Enter code: ");
            scanf("%d" , &code);
            printf("Enter qty: ");
            addToCart(code, qty);
            break;
        }
            case 5: generateInvoice(); break;
            case 6: saveInventory(); break;
            case 7: extrasMenu(); break;
            case 8: 
                    saveInventory();
                    printf("Goodbye.\n");
                    return 0;
            default:
            printf("Invalid.\n");


        }
        printf("Press Enter to continue...");
        getchar();
        getchar();
    } while(1);
    return 0;
}