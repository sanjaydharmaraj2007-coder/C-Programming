#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ITEMS 20
struct MenuItem {
 int id;
 char name[30];
 float price;
};
struct Order {
 int itemId;
 int quantity;
 float total;
};
int main() {
 struct MenuItem menu[] = {
 {1, "Veg Fried Rice", 120.0},
 {2, "Chicken Fried Rice", 150.0},
 {3, "Paneer Butter Masala", 180.0},
 {4, "Chicken 65", 160.0},
 {5, "Veg Noodles", 110.0},
 {6, "Parotta (2pcs)", 40.0},
 {7, "Meals (Veg)", 100.0},
 {8, "Meals (Non-Veg)", 130.0},
 {9, "Ice Cream", 60.0},
 {10,"Fresh Lime Juice", 40.0}
 };
 int n = sizeof(menu)/sizeof(menu[0]);
 struct Order orderList[MAX_ITEMS];
 int orderCount = 0, choice, qty;
 float subtotal = 0.0, gst, grandTotal;
 printf("\n==============================\n");
 printf(" HOTEL & RESTAURANT BILLING SYSTEM");
 printf("\n==============================\n");
 printf("\nMenu:\n");
 printf("-------------------------------------------\n");
 printf("No. Item Name\t\t\tPrice (Rs)\n");
 printf("-------------------------------------------\n");
 for(int i=0; i<n; i++)
 printf("%-3d %-25s %.2f\n", menu[i].id, menu[i].name, menu[i].price);
 printf("-------------------------------------------\n");
 printf("\nEnter number of different items ordered: ");
 scanf("%d", &orderCount);
 for(int i=0; i<orderCount; i++) {
 printf("\nEnter item number: ");
 scanf("%d", &choice);
 printf("Enter quantity: ");
 scanf("%d", &qty);
 if(choice >= 1 && choice <= n) {
 orderList[i].itemId = choice;
 orderList[i].quantity = qty;
 orderList[i].total = menu[choice-1].price * qty;
 subtotal += orderList[i].total;
 } else {
 printf("Invalid item number!\n");
 i--; // repeat iteration
 }
 }
 gst = subtotal * 0.05; // 5% GST
 grandTotal = subtotal + gst;
 // Print Bill
 printf("\n\n============= CUSTOMER BILL =============\n");
 printf("%-3s %-25s %-10s %-10s\n", "No.", "Item", "Qty", "Amount");
 printf("-------------------------------------------\n");
 for(int i=0; i<orderCount; i++) {
 int id = orderList[i].itemId - 1;
 printf("%-3d %-25s %-10d %-10.2f\n",
 menu[id].id, menu[id].name,
 orderList[i].quantity,
 orderList[i].total);
 }
 printf("-------------------------------------------\n");
 printf("Subtotal\t\t\t%.2f\n", subtotal);
 printf("GST (5%%)\t\t\t%.2f\n", gst);
 printf("Grand Total\t\t\t%.2f\n", grandTotal);
 printf("-------------------------------------------\n");
 printf("Thank you! Visit Again!\n");
 // Save to file (optional)
 FILE *fp = fopen("bill.txt", "a");
 if(fp != NULL) {
 fprintf(fp, "\n==== Customer Bill ====\n");
 for(int i=0; i<orderCount; i++) {
 int id = orderList[i].itemId - 1;
 fprintf(fp, "%s x %d = %.2f\n",
 menu[id].name, orderList[i].quantity, orderList[i].total);
 }
 fprintf(fp, "Subtotal: %.2f\nGST(5%%): %.2f\nGrand Total: %.2f\n", subtotal, gst, 
grandTotal);
 fprintf(fp, "------------------------\n");
 fclose(fp);
 } else {
 printf("Error saving bill file!\n");
 }
 return 0;
}