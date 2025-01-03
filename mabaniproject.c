#include <stdio.h>
#include <string.h>

#define MAX_USERS 100

typedef struct {
    char national_code[11];
    char first_name[50];
    char last_name[50];
} User;

User users[MAX_USERS];
int user_count = 0;

void add_user(const char *national_code, const char *first_name, const char *last_name) {
    if (user_count < MAX_USERS) {
        strcpy(users[user_count].national_code, national_code);
        strcpy(users[user_count].first_name, first_name);
        strcpy(users[user_count].last_name, last_name);
        user_count++;
    }
}

User* find_user(const char *national_code) {
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].national_code, national_code) == 0) {
            return &users[i];
        }
    }
    return NULL;
}

int main() {
    char first_name[50], last_name[50], national_code[11];

    while (user_count < MAX_USERS) {
        printf("نام: ");
        scanf("%s", first_name);
        printf("نام خانوادگی: ");
        scanf("%s", last_name);
        printf("کد ملی: ");
        scanf("%s", national_code);
        add_user(national_code, first_name, last_name);

        char choice[4];
        printf("آیا ادامه می‌دهید؟ (بله/خیر): ");
        scanf("%s", choice);
        if (strcmp(choice, "خیر") == 0) break;
    }

    printf("\nکد ملی برای جستجو: ");
    scanf("%s", national_code);
    
    User* user = find_user(national_code);
    if (user) {
        printf("مشخصات: کد ملی: %s, نام: %s, نام خانوادگی: %s\n", user->national_code, user->first_name, user->last_name);
    } else {
        printf("کاربری پیدا نشد.\n");
    }

    return 0;
}