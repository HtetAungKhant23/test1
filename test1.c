#include<stdio.h>

typedef struct user
{

    int id;
    char name[20];
    char password[20];
//    int age;
//    char location[20];

} user;

void addData()
{
    user *u;
    FILE *fptr;
    int n, i;

    printf("\nEnter how many users you want: ");
    scanf("%d",&n);

    u = (user*)calloc(n, sizeof(user));
    fptr = fopen("file.txt","a");

    for(i=0; i<n; i++)
    {
        printf("\nEnter User ID: ");
        scanf("%d",&u[i]);

        fflush(stdin);

        printf("Enter User Name: ");
        scanf(" %[^\n]s",u[i].name);
        printf("Enter Password: ");
        scanf("%s",u[i].password);
//       printf("Enter Age: ");
//       scanf("%d",u[i].age);

//       fflush(stdin);

//       printf("Enter Location: ");
//       scanf(" %[^\n]s",u[i].location);

        fwrite(&u[i],sizeof(user),1,fptr);
    }

    fclose(fptr);
}

void display()
{
    user u1;
    FILE *fptr;
    fptr = fopen("file.txt","r");
    while(fread(&u1,sizeof(user),1,fptr))
    {
        printf("\n%-5d%-20s%-20s",u1.id,u1.name,u1.password);

    }
    printf("\n");

    fclose(fptr);
}

void findData()
{
    user u1;
    FILE *fptr;
    int id, found;
    fptr = fopen("file.txt","r");
    printf("\nEnter user ID to find: ");
    scanf("%d",&id);
    while(fread(&u1,sizeof(user),1,fptr))
    {
        if(u1.id == id)
        {
            found=1;
            printf("\n%-5d%-20s%-20s",u1.id,u1.name,u1.password);
        }
    }
    printf("\n");
    if(!found)
    {
        printf("\nUser not found\n");
    }

    fclose(fptr);
}

void updateData()
{
    user u1;
    FILE *fptr, *fptr1;
    int id, found;
    fptr = fopen("file.txt","r");
    fptr1 = fopen("update.txt","w");
    printf("\nEnter user ID to update: ");
    scanf("%d",&id);
    while(fread(&u1,sizeof(user),1,fptr))
    {
        if(u1.id == id)
        {
            found=1;
            fflush(stdin);

            printf("Enter New User Name: ");
            scanf(" %[^\n]s",u1.name);
            printf("Enter New Password: ");
            scanf("%s",u1.password);
            //       printf("Enter New Age: ");
            //       scanf("%d",u1.age);

            //       fflush(stdin);

            //       printf("Enter New Location: ");
            //       scanf(" %[^\n]s",u1.location);
        }
        fwrite(&u1,sizeof(user),1,fptr1);
    }
    fclose(fptr);
    fclose(fptr1);
    if(found)
    {
        fptr1 = fopen("update.txt","r");
        fptr = fopen("file.txt","w");

        while(fread(&u1,sizeof(user),1,fptr1))
        {
            fwrite(&u1,sizeof(user),1,fptr);
        }


        fclose(fptr);
        fclose(fptr1);

    }
    else
    {
        printf("\nUser not found\n");
    }

}


int main()
{

    int choice;
    do
    {
        printf("\n1.ADD USER DATA\n");
        printf("2.DISPLAY USER DATA\n");
        printf("3.FIND USER DATA\n");
        printf("4.UPDATE USER DATA\n");
        printf("0.EXIT\n\n");

        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            addData();
            printf("------------------------------------------\n");
            break;
        case 2:
            display();
            printf("------------------------------------------\n");
            break;
        case 3:
            findData();
            printf("------------------------------------------\n");
            break;
        case 4:
            updateData();
            printf("------------------------------------------\n");
            break;
        case 0;
            printf("\nThanks for enjoy with us\n");
            break;
        default:
            printf("\nInvalid Input\n");
            break;
        }



    }
    while(choice!=0);


    return 0;
}
