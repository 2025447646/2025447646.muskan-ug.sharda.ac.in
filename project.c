#include<stdio.h>
#include<string.h>

struct user {
    char fullname[100];
    char username[100];
    char password[100];
};

typedef struct user account;

struct product {
    char name[100];
    int stock;
    float price;
};

typedef struct product inventory_item;

struct cart_item {
    char product_name[100];
    int quantity;
    float unit_price;
    float total_price;
};

typedef struct cart_item cart_product;

struct transaction {
    char username[100];
    char product_name[100];
    int quantity;
    float total_price;
};

typedef struct transaction sale_record;

// GLOBALS
inventory_item store[5];
int store_size = 5;

cart_product shopping_cart[100];
int cart_count = 0;

char current_user[100] = "";

// FILE FUNCTIONS
void initialize_inventory_file() {
    FILE *file = fopen("inventory.dat", "rb");

    if(file == NULL) {
        file = fopen("inventory.dat", "wb");

        inventory_item items[5] = {
            {"Gaming Laptop", 15, 1299.99},
            {"4K Monitor", 32, 399.99},
            {"Keyboard", 45, 149.99},
            {"Mouse", 78, 49.99},
            {"Headphones", 28, 299.99}
        };

        fwrite(items, sizeof(inventory_item), 5, file);
        fclose(file);
    } else {
        fclose(file);
    }
}

void load_inventory() {
    FILE *file = fopen("inventory.dat", "rb");
    if(file == NULL) return;

    fread(store, sizeof(inventory_item), 5, file);
    fclose(file);
}

void save_inventory() {
    FILE *file = fopen("inventory.dat", "wb");
    if(file == NULL) return;

    fwrite(store, sizeof(inventory_item), 5, file);
    fclose(file);
}

void save_transaction(char *username, char *product, int qty, float total) {
    FILE *file = fopen("transactions.dat", "ab");
    if(file == NULL) return;

    sale_record t;
    strcpy(t.username, username);
    strcpy(t.product_name, product);
    t.quantity = qty;
    t.total_price = total;

    fwrite(&t, sizeof(t), 1, file);
    fclose(file);
}

// USER
void register_user() {
    account new_user, temp;
    FILE *file;

    printf("Name: ");
    scanf(" %[^\n]", new_user.fullname);

    printf("Username: ");
    scanf("%s", new_user.username);

    printf("Password: ");
    scanf("%s", new_user.password);

    file = fopen("accounts.dat", "rb");
    if(file != NULL) {
        while(fread(&temp, sizeof(temp), 1, file)) {
            if(strcmp(temp.username, new_user.username) == 0) {
                printf("Username already exists!\n");
                fclose(file);
                return;
            }
        }
        fclose(file);
    }

    file = fopen("accounts.dat", "ab");
    fwrite(&new_user, sizeof(new_user), 1, file);
    fclose(file);

    printf("Registered Successfully!\n");
}

int login() {
    account user;
    char u[100], p[100];

    FILE *file = fopen("accounts.dat", "rb");
    if(file == NULL) {
        printf("No users found!\n");
        return 0;
    }

    printf("Username: ");
    scanf("%s", u);
    printf("Password: ");
    scanf("%s", p);

    while(fread(&user, sizeof(user), 1, file)) {
        if(strcmp(user.username, u) == 0 && strcmp(user.password, p) == 0) {
            strcpy(current_user, u);
            printf("Login Success!\n");
            fclose(file);
            return 1;
        }
    }

    fclose(file);
    printf("Invalid Login!\n");
    return 0;
}

// INVENTORY
void show_inventory() {
    printf("\nID | Name | Stock | Price\n");
    for(int i=0;i<5;i++) {
        printf("%d | %s | %d | %.2f\n", i+1, store[i].name, store[i].stock, store[i].price);
    }
}

// CART
void add_to_cart() {
    int id, qty;

    while(1) {
        show_inventory();

        printf("Enter ID (0 to stop): ");
        scanf("%d",&id);

        if(id == 0) break;

        if(id <1 || id >5) {
            printf("Invalid ID\n");
            continue;
        }

        printf("Quantity: ");
        scanf("%d",&qty);

        if(qty <=0 || qty > store[id-1].stock) {
            printf("Invalid quantity\n");
            continue;
        }

        if(cart_count >=100) {
            printf("Cart full!\n");
            return;
        }

        strcpy(shopping_cart[cart_count].product_name, store[id-1].name);
        shopping_cart[cart_count].quantity = qty;
        shopping_cart[cart_count].unit_price = store[id-1].price;
        shopping_cart[cart_count].total_price = qty * store[id-1].price;

        store[id-1].stock -= qty;

        cart_count++;   // ⭐ FIXED

        printf("Added to cart!\n");
    }
}

void view_cart() {
    float total = 0;

    if(cart_count == 0) {
        printf("Cart empty!\n");
        return;
    }

    for(int i=0;i<cart_count;i++) {
        printf("%s x%d = %.2f\n",
        shopping_cart[i].product_name,
        shopping_cart[i].quantity,
        shopping_cart[i].total_price);

        total += shopping_cart[i].total_price;
    }

    printf("Total = %.2f\n", total);
}

void checkout() {
    float total = 0;

    for(int i=0;i<cart_count;i++) {
        save_transaction(current_user,
        shopping_cart[i].product_name,
        shopping_cart[i].quantity,
        shopping_cart[i].total_price);

        total += shopping_cart[i].total_price;
    }

    printf("Final Bill = %.2f\n", total);

    save_inventory();
    cart_count = 0;
}

// MAIN
int main() {
    int ch;

    initialize_inventory_file();
    load_inventory();

    while(1) {
        if(strlen(current_user)==0) {
            printf("\n1.Register\n2.Login\n3.Exit\n");
            scanf("%d",&ch);

            if(ch==1) register_user();
            else if(ch==2) login();
            else return 0;
        }
        else {
            printf("\n1.Shop\n2.View Cart\n3.Checkout\n4.Logout\n");
            scanf("%d",&ch);

            if(ch==1) add_to_cart();
            else if(ch==2) view_cart();
            else if(ch==3) checkout();
            else if(ch==4) strcpy(current_user,"");
        }
    }
}