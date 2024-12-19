#include <stdio.h>

#define NUM_EMPLOYEES 10

// ساختار برای ذخیره اطلاعات کارمند
typedef struct {
    char name[50];
    char nationalID[15];
    float baseSalary;
    float bonus;
    float tax;
    float insurance;
    float netSalary;
} Employee;

int main() {
    Employee employees[NUM_EMPLOYEES];
    FILE *file;

    // دریافت اطلاعات کارمندان
    for (int i = 0; i < NUM_EMPLOYEES; i++) {
        printf("Enter details for employee %d:\n", i + 1);

        printf("Name: ");
        scanf(" %[^\n]", employees[i].name);

        printf("National ID: ");
        scanf(" %s", employees[i].nationalID);

        printf("Base Salary: ");
        scanf("%f", &employees[i].baseSalary);

        printf("Bonus: ");
        scanf("%f", &employees[i].bonus);

        printf("Tax: ");
        scanf("%f", &employees[i].tax);

        printf("Insurance: ");
        scanf("%f", &employees[i].insurance);

        // محاسبه حقوق خالص
        employees[i].netSalary = employees[i].baseSalary + employees[i].bonus - (employees[i].tax + employees[i].insurance);
    }

    // ذخیره اطلاعات در فایل
    file = fopen("salaries.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    fprintf(file, "Name\tNational ID\tBase Salary\tBonus\tTax\tInsurance\tNet Salary\n");
    for (int i = 0; i < NUM_EMPLOYEES; i++) {
        fprintf(file, "%s\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n",
                employees[i].name,
                employees[i].nationalID,
                employees[i].baseSalary,
                employees[i].bonus,
                employees[i].tax,
                employees[i].insurance,
                employees[i].netSalary);
    }
    fclose(file);

    // نمایش فیش حقوقی
    for (int i = 0; i < NUM_EMPLOYEES; i++) {
        printf("\n--- Payslip for Employee %d ---\n", i + 1);
        printf("Name: %s\n", employees[i].name);
        printf("National ID: %s\n", employees[i].nationalID);
        printf("Base Salary: %.2f\n", employees[i].baseSalary);
        printf("Bonus: %.2f\n", employees[i].bonus);
        printf("Tax: %.2f\n", employees[i].tax);
        printf("Insurance: %.2f\n", employees[i].insurance);
        printf("Net Salary: %.2f\n", employees[i].netSalary);
        printf("--------------------------\n");
    }

    printf("Employee data saved to 'salaries.txt'.\n");
    return 0;
}
