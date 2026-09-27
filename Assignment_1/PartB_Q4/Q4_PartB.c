/*
    Programming Fundamentals Theory 
    Question 4 Part B
    Syed Sajid Ali
*/
#include <stdio.h>

int main() {
    
    int quantity;
    double price_per_item, discount_percentage, tax_percentage;
    printf("Enter quantity: ");
    scanf("%d", &quantity);
    printf("Enter price per item: ");
    scanf("%lf", &price_per_item);
    printf("Enter discount percentage: ");
    scanf("%lf", &discount_percentage);
    printf("Enter tax percentage: ");
    scanf("%lf", &tax_percentage);

    if ((quantity > 0 && quantity <= 100) && (price_per_item > 0 && price_per_item <= 1000)&&(discount_percentage >= 0 && discount_percentage <= 100) &&(tax_percentage >= 0 && tax_percentage <= 100)) {
        double sub_total = quantity * price_per_item;
        double discount_amount = (sub_total * discount_percentage)/ 100.0;
        double after_discount = sub_total - discount_amount;
        double tax_amount = (after_discount * tax_percentage) /100.0;
        double final_bill = after_discount + tax_amount;
            printf("Sub Total: %.2lf\n", sub_total);
            printf("Discount Amount: %.2lf\n", discount_amount);
            printf("Tax Amount: %.2lf\n", tax_amount);
            printf("Final Bill: %.2lf\n", final_bill);

    } 
    else {
        printf("Invalid input. Please enter valid values.\n");
    }


    return 0;
}