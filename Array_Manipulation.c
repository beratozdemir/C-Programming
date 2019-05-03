#include <stdio.h>
#include <stdlib.h>
 
typedef struct array {
    int data;
    struct array *forward;
} array1;
 
array1 *new, *first = NULL, *temporary, *deletetemporary;
 
void menu();
void add(int);
void listele();
void wait();
int search(int);
int delete(int);
void clearscreen();
 
int main() {
 
    while (1) {
        clearscreen();
        menu();
    }
    return 0;
}
 
void add(int number) {
 
    //Liste bos ise
    if (first == NULL) {
        first = (array1*) malloc(sizeof (array1));
        first->data = number;
        first->forward = NULL;
    } else {
        //Girilen sayi ilk sayidan kucuk ise
        if ((first->data) > (number)) {
            new = (array1*) malloc(sizeof (array1));
            new->data = number;
            new->forward = first;
            first = new;
        } else {
            temporary = first;
            new = (array1*) malloc(sizeof (array1));
            new->data = number;
            while (temporary != NULL) {
                //gecici elemaninin sonraki null ise ve son elemandan buyukse
                if (temporary->forward == NULL && (temporary->data) <= (number)) {
                    new->forward = NULL;
                    temporary->forward = new;
                    break;
                }
                //Araya Ekleme
                if ((temporary->forward->data) > (number)) {
                    new->forward = temporary->forward;
                    temporary->forward = new;
                    break;
                }
                temporary = temporary->forward;
            }
        }
    }
}
 
void listele() {
    //liste bos ise
    if (first == NULL) {
        printf("Empty List\n");
    } else {
        //ilk degeri kaybetmemek icin gecici kullanildi
        temporary = first;
        while (temporary != NULL) {
            printf("%d\n", temporary->data);
            temporary = temporary->forward;
        }
    }
    wait();
}
 
void menu() {
    int choose, number, rank, control;
 
    printf("1-Add number to Array\n");
    printf("2-Show into Array\n");
    printf("3-Search in the Array\n");
    printf("4-Delete element from Array\n");
    printf("5-Exit\n");
 
    scanf("%d", &choose);
 
    switch (choose) {
        case 1:
            clearscreen();
            printf("Enter to number: ");
            scanf("%d", &number);
            add(number);
            wait();
            break;
        case 2:
            clearscreen();
            listele();
            break;
        case 3:
            clearscreen();
            if (first == NULL) {
                printf("Empty List!\n");
                wait();
                break;
            }
            printf("Enter to number: ");
            scanf("%d", &number);
            rank = search(number);
            if (rank == -1)
                printf("A number not found!\n");
            else
                printf("Number %d is the %d. element of the list\n", number, rank);
            wait();
            break;
        case 4:
            clearscreen();
            if(first == NULL){
                printf("Empty List!\n");
                wait();
                break;
            }
            printf("Enter to number: ");
            scanf("%d", &number);
            control = delete(number);
            if (control == -1)
                printf("Empty List!\n");
            else if (control == 0)
                printf("%d A list not found!\n", number);
            else
                printf("%d deleted\n", number);
            wait();
 
            break;
        case 5:
            clearscreen();
            printf("Exit Succesful!\n");
            exit(0);
            break;
        default:
            clearscreen();
            printf("Wrong Choose\n");
            wait();
    }
}
 
int search(int number) {
    int counter = 0;
    temporary = first;
    while (temporary != NULL) {
        counter++;
        if (temporary->data == number)
            return counter;
        temporary = temporary->forward;
    }
    return -1;
}
 
int delete(int number) {
    if (first == NULL)
        return -1;
    else if (first->data == number) {
        deletetemporary = first;
        first = first->forward;
        free(deletetemporary);
        return 1;
    } else {
        temporary = first;
        while (temporary->forward != NULL) {
            if (temporary->forward->data == number) {
                deletetemporary = temporary->forward;
                temporary->forward = deletetemporary->forward;
                free(deletetemporary);
                return 1;
            }
            temporary = temporary->forward;
        }
 
    }
    return 0;
}
 
//Kendi Yazdigimiz Ozel bekleme fonksiyonu
void wait() {
    char temp;
    printf("Please, enter any key to continue\n");
 
    //klavyeden okuma atlamasinin onune gecmek icin 2 kere yazildi
    temp = getchar();
    temp = getchar();
    clearscreen(); 
} 
void clearscreen() {
    system("clear");
}
