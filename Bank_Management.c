#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>

int main_exit;
void menu();
struct date
{
    int month,day,year;
};
struct
{
    char name[100];
    int acc_no,age;
    char address[100];
    char NID[100];
    double phone;
    char acc_type[100];
    float amt;
    struct date dob;
    struct date deposit;
    struct date withdraw;
}

add,upd,check,rem,transaction;
float interest(float t,float amount,int rate)
{
    float SI;
    SI=(rate*t*amount)/100.0;
    return (SI);
}
int i,j;
void fordelay(int j)
{   int i,k;
    for(i=0;i<j;i++)
         k=i;
}
void red ()
{
  printf("\033[1;31m");
}
void white()
{
  printf("\033[1;37m");
}
void cyan()
{
  printf("\033[1;36m");
}


void new_acc()
{
    system("color B0");
    int choice;
    FILE *ptr;
    ptr=fopen("record.dat","a+");
    account_no:
    system("cls");

    printf("\n\n\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\t\t\t\t\xB2\xDB\xDB\xDB\xDB\t\t\t\t\t\t   \xDB\xDB\xDB\xDB\xB2");
    printf("\n\t\t\t\t\t       ADD RECORD for REGISTRATION");
    printf("\n\t\t\t\t\xB2\xDB\xDB\xDB\xDB\t\t\t\t\t\t   \xDB\xDB\xDB\xDB\xB2");
    printf("\n\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

    printf("\n\n\n\t\t\xB2\xDB Enter today's date(mm/dd/yyyy):");
    scanf("%d/%d/%d",&add.deposit.month,&add.deposit.day,&add.deposit.year);
    printf("\n\t\t\xB2\xDB Enter the account number:");
    scanf("%d",&check.acc_no);
    while(fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.NID,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        if (check.acc_no==add.acc_no)
            {
                printf("Account no. already in use!");
                fordelay(1000000000);
                goto account_no;
            }
    }
    add.acc_no=check.acc_no;
    printf("\n\t\t\xB2\xDB Enter the name:");
    scanf("%s",add.name);
    printf("\n\t\t\xB2\xDB Enter the date of birth(mm/dd/yyyy):");
    scanf("%d/%d/%d",&add.dob.month,&add.dob.day,&add.dob.year);
    printf("\n\t\t\xB2\xDB Enter the age:");
    scanf("%d",&add.age);
    printf("\n\t\t\xB2\xDB Enter the address:");
    scanf("%s",add.address);
    printf("\n\t\t\xB2\xDB Enter the NID number:");
    scanf("%s",add.NID);
    printf("\n\t\t\xB2\xDB Enter the phone number: ");
    scanf("%lf",&add.phone);
    printf("\n\t\t\xB2\xDB Enter the amount to deposit:$");
    scanf("%f",&add.amt);
    printf("\n\t\t\xB2\xDB\xDB Type of account:\n\t\t#Saving\n\t\t#Current\n\t\t#Fixed1(for 1 year)\n\t\t#Fixed2(for 2 years)\n\t\t#Fixed3(for 3 years)\n\n\t\tEnter your choice: ");
    scanf("%s",add.acc_type);
    fprintf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.NID,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
    fclose(ptr);
    printf("\n\t\t\xB2\xDB Account created successfully! \xDB\xB2");
    add_invalid:
    printf("\n\n\n\t\t\xB2\xB2 Enter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
        menu();
    else if(main_exit==0)
        close();
    else
        {
            printf("\nInvalid!\a");
            goto add_invalid;
        }
}


void edit(void)
{
    int choice,test=0;
    FILE *old,*newrec;
    system("color B");
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");

    printf("\n\n\t\t\t\t \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\t\t\t\t \xB2\xDB\xDB\xDB\xDB\t\t\t\t\t\t    \xDB\xDB\xDB\xDB\xB2");
    printf("\n\t\t\t\t\t\t    UPDATE INFORMATION");
    printf("\n\t\t\t\t \xB2\xDB\xDB\xDB\xDB\t\t\t\t\t\t    \xDB\xDB\xDB\xDB\xB2");
    printf("\n\t\t\t\t \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

    printf("\n\n\n\n\t\t\t\xB2\xB2 Enter the account no. of the customer whose info you want to change:");
    scanf("%d",&upd.acc_no);
    while(fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.NID,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        if (add.acc_no==upd.acc_no)
        {
            test=1;
            printf("\n\n\t\t\t\t\xB2\xB2 Which information do you want to change?\n\n\t\t\t\t1.Address\n\t\t\t\t2.Phone number\n\n\t\t\t\tEnter your choice: ");
            scanf("%d",&choice);
            //system("cls");
            if(choice==1)
                {
                   printf("\n\n\n\t\t\t\t\t\xB2 Enter the new address:");
                   scanf("%s",upd.address);
                   fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,upd.address,add.NID,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                   //system("cls");
                   printf("\n\n\n\n\t\t\t\t\t\tChanges saved!");
                }
            else if(choice==2)
                {
                    printf("\n\n\n\t\t\t\t\xB2 Enter the new phone number:");
                    scanf("%lf",&upd.phone);
                    fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.NID,upd.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                    //system("cls");
                    printf("\n\n\n\n\t\t\t\t\t\xB2 Changes saved!");
                }
        }
            else
               {
                  fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.NID,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
               }
    }
    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat","record.dat");
    if(test!=1)
        {
            system("cls");
            printf("\n\t\t\t\tRecord not found!!\a\a\a");
            edit_invalid:
              printf("\n\n\n\t\t\t\t\xB2\xB2 Enter your choice..\n\n\t\t\t\t0 to try again\n\t\t\t\t1 to return to main menu\n\t\t\t\t2 to account details\n\t\t\t\t3 to exit\n\n\t\t\t\t Enter: ");
              scanf("%d",&main_exit);
              system("cls");
                if (main_exit==0)
                {
                    edit();
                }
                    else if (main_exit==1)
                {
                    menu();
                }
                else if(main_exit==2)
                {
                    see();
                }
                else if(main_exit==3)
                {
                    close();
                }
                else
                {
                    printf("\n\n\t\t\t\t\tInvalid!\a");
                    goto edit_invalid;
                }
        }
    else
        {
           printf("\n\n\n\t\t\t\t\xB2\xB2 Enter your choice..\n\n\t\t\t\t0 to try again\n\t\t\t\t1 to return to main menu\n\t\t\t\t2 to account details\n\t\t\t\t3 to exit\n\n\t\t\t\t Enter: ");
           scanf("%d",&main_exit);
           system("cls");
            if (main_exit==0)
                {
                    edit();
                }
                    else if (main_exit==1)
                {
                    menu();
                }
                else if(main_exit==2)
                {
                    see();
                }
                else if(main_exit==3)
                {
                    close();
                }
        }
}


void transact(void)
{
    int choice,test=0;
    FILE *old,*newrec;
    system("color B0");
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");

    printf("\n\n\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\t\t\t\t\xB2\xDB\xDB\xDB\xDB\t\t\t\t\t\t   \xDB\xDB\xDB\xDB\xB2");
    printf("\n\t\t\t\t\t\t       TRANSECTION");
    printf("\n\t\t\t\t\xB2\xDB\xDB\xDB\xDB\t\t\t\t\t\t   \xDB\xDB\xDB\xDB\xB2");
    printf("\n\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

    printf("\n\n\n\t\t\t\t  \xB2 Enter the account no. of the customer: ");
    scanf("%d",&transaction.acc_no);
    while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.NID,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
   {
        if(add.acc_no==transaction.acc_no)
            {   test=1;
                if(strcmpi(add.acc_type,"fixed1")==0||strcmpi(add.acc_type,"fixed2")==0||strcmpi(add.acc_type,"fixed3")==0)
                {
                    printf("\t\t\a\a\a\n\nYOU CANNOT DEPOSIT OR WITHDRAW CASH IN FIXED ACCOUNTS!!!!!");
                    fordelay(1000000000);
                    system("cls");
                    menu();
                }
                printf("\n\n\n\t\t\t\t\xB2\xB2 Do you want to...\n\n\t\t\t\t1.Deposit\n\n\t\t\t\t2.Withdraw?\n\n\t\t\t\tEnter your choice: ");
                scanf("%d",&choice);
                if (choice==1)
                {
                    printf("\n\t\t\t\t\xB2 Enter the amount you want to deposit: $ ");
                    scanf("%f",&transaction.amt);
                    add.amt+=transaction.amt;

                    printf("\n\n\t\t\t\t\t\tLoading..");
                    for(i=0;i<=5;i++)
                      {
                          printf("\xB2");
                          fordelay(100000000);
                      }
                      system("cls");
                      fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.NID,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                      printf("\a");
                      printf("\n\n\n\n\t\t\t\t\t    \xDB Deposited successfully! \xDB");
                }
                else
                {
                    printf("\n\t\t\t\t\xB2 Enter the amount you want to withdraw: $ ");
                    scanf("%f",&transaction.amt);
                    add.amt-=transaction.amt;
                    printf("\n\n\t\t\t\t\t\tLoading..");
                    for(i=0;i<=5;i++)
                      {
                          printf("\xB2");
                          fordelay(100000000);
                      }
                    system("cls");
                    fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.NID,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                    printf("\a");
                    printf("\n\n\n\n\t\t\t\t\t    \xDB Withdrawn successfully! \xDB");
                }
            }
            else
            {
               fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.NID,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
            }
   }
   fclose(old);
   fclose(newrec);
   remove("record.dat");
   rename("new.dat","record.dat");
   if(test!=1)
   {
      printf("\n\n\t\tRecord not found!!");
      transact_invalid:
      printf("\n\n\n\n\t\t\t\t\t\xB2\xB2 Enter your choice..\n\n\t\t\t\t\t0 to try again\n\t\t\t\t\t1 to view account details\n\t\t\t\t\t2 to return to main menu\n\t\t\t\t\t3 to exit\n\t\t\t\t\tEnter your choice:");
      scanf("%d",&main_exit);
      system("cls");
      if (main_exit==0)
      {
          transact();
      }
      else if (main_exit==1)
      {
          see();
      }
      else if (main_exit==2)
      {
          menu();
      }
      else if (main_exit==3)
      {
          close();
      }
      else
      {
        printf("\n\n\t\t\tInvalid!");
        goto transact_invalid;
      }
   }
   else
   {
    printf("\n\n\n\n\t\t\t\t\t\xB2\xB2 Enter your choice..\n\n\t\t\t\t\t0 to try again\n\t\t\t\t\t1 to view account details\n\t\t\t\t\t2 to return to main menu\n\t\t\t\t\t3 to exit\n\t\t\t\t\tEnter your choice:");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==0)
      {
          transact();
      }
      else if (main_exit==1)
      {
          see();
      }
      else if (main_exit==2)
      {
          menu();
      }
      else if (main_exit==3)
      {
          close();
      }
   }
}


void see(void)
{
    FILE *ptr;
    int test=0,rate;
    int choice;
    float time;
    float intrst;
    system("color F0");
    ptr=fopen("record.dat","r");

    printf("\n\n\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\t\t\t\t\xB2\xDB\xDB\xDB\xDB\t\t\t\t\t\t   \xDB\xDB\xDB\xDB\xB2");
    printf("\n\t\t\t\t\t\t   FOR ACCOUNT DETAILS");
    printf("\n\t\t\t\t\xB2\xDB\xDB\xDB\xDB\t\t\t\t\t\t   \xDB\xDB\xDB\xDB\xB2");
    printf("\n\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

    printf("\n\n\n\t\t\t\t\xB2 Do you want to check by\n\n\t\t\t\t1.Account no\n\t\t\t\t2.Name\n\n\t\t\t\tEnter your choice:");
    scanf("%d",&choice);
    if (choice==1)
    {
        printf("\n\t\t\t\t\xB2 Enter the account number:");
        scanf("%d",&check.acc_no);
        while (fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.NID,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
        {
            if(add.acc_no==check.acc_no)
            {
                system("cls");
                test=1;
                printf("\n\n\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
                printf("\n\t\t\t\t\xB2\xDB\xDB\xDB\xDB\t\t\t\t\t\t   \xDB\xDB\xDB\xDB\xB2");
                printf("\n\t\t\t\t\t\t    ACCOUNT DETAILS");
                printf("\n\t\t\t\t\xB2\xDB\xDB\xDB\xDB\t\t\t\t\t\t   \xDB\xDB\xDB\xDB\xB2");
                printf("\n\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

                printf("\n\n\t\t\t\tAccount NO.:%d\n\t\t\t\tName:%s \n\t\t\t\tDOB:%d/%d/%d \n\t\t\t\tAge:%d \n\t\t\t\tAddress:%s \n\t\t\t\tNID No:%s \n\t\t\t\tPhone number:%.0lf \n\t\t\t\tType Of Account:%s \n\t\t\t\tAmount deposited:$ %.2f \n\t\t\t\tDate Of Deposit:%d/%d/%d\n\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.NID,add.phone,
                add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                if(strcmpi(add.acc_type,"fixed1")==0)
                    {
                        time=1.0;
                        rate=9;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\n\t\t\t\tYou will get $%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+1);
                    }
                else if(strcmpi(add.acc_type,"fixed2")==0)
                    {
                        time=2.0;
                        rate=11;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\n\t\t\t\tYou will get $.%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+2);
                    }
                else if(strcmpi(add.acc_type,"fixed3")==0)
                    {
                        time=3.0;
                        rate=13;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\n\t\t\t\tYou will get $.%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+3);
                    }
                 else if(strcmpi(add.acc_type,"saving")==0)
                    {
                        time=(1.0/12.0);
                        rate=8;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\n\t\t\t\tYou will get $.%.2f as interest on %d of every month",intrst,add.deposit.day);
                     }
                 else if(strcmpi(add.acc_type,"current")==0)
                    {
                        printf("\n\n\t\t\tYou will get no interest\a\a");
                    }
             }
        }
    }
    else if (choice==2)
    {
        printf("\n\t\t\t\tEnter the name:");
        scanf("%s",&check.name);
        while (fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.NID,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
        {
            if(strcmpi(add.name,check.name)==0)
            {
                system("cls");
                test=1;
                printf("\n\n\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
                printf("\n\t\t\t\t\xB2\xDB\xDB\xDB\xDB\t\t\t\t\t\t   \xDB\xDB\xDB\xDB\xB2");
                printf("\n\t\t\t\t\t\t    ACCOUNT DETAILS");
                printf("\n\t\t\t\t\xB2\xDB\xDB\xDB\xDB\t\t\t\t\t\t   \xDB\xDB\xDB\xDB\xB2");
                printf("\n\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

                printf("\n\n\t\t\t\tAccount No.:%d\n\t\t\t\tName:%s \n\t\t\t\tDOB:%d/%d/%d \n\t\t\t\tAge:%d \n\t\t\t\tAddress:%s \n\t\t\t\tNID No:%s \n\t\t\t\tPhone number:%.0lf \n\t\t\t\tType Of Account:%s \n\t\t\t\tAmount deposited:$%.2f \n\t\t\t\tDate Of Deposit:%d/%d/%d\n\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.NID,add.phone,
                add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                if(strcmpi(add.acc_type,"fixed1")==0)
                    {
                        time=1.0;
                        rate=9;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\n\t\t\t\tYou will get $.%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+1);
                    }
                else if(strcmpi(add.acc_type,"fixed2")==0)
                    {
                        time=2.0;
                        rate=11;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\n\t\t\t\tYou will get $.%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+2);
                    }
                else if(strcmpi(add.acc_type,"fixed3")==0)
                    {
                        time=3.0;
                        rate=13;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\n\t\t\tYou will get $.%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+3);
                    }
                 else if(strcmpi(add.acc_type,"saving")==0)
                    {
                        time=(1.0/12.0);
                        rate=8;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\n\t\t\t\tYou will get $.%.2f as interest on %d of every month",intrst,add.deposit.day);
                     }
                 else if(strcmpi(add.acc_type,"current")==0)
                     {
                        printf("\n\n\t\t\t\t\tYou will get no interest\a\a");
                     }
             }
        }
    }
     fclose(ptr);
     if(test!=1)
        {
         system("cls");
         printf("\a");
         printf("\n\t\t\t\t\tRecord not found!!\a\a\a");
         see_invalid:
         printf("\n\n\t\t\t\t\xB2\xB2 Enter 0 to try again,1 to return to main menu and 2 to exit:");
         scanf("%d",&main_exit);
         system("cls");
            if (main_exit==1)
                 {
                    menu();
                 }
            else if (main_exit==2)
                 {
                    close();
                 }
            else if(main_exit==0)
                 {
                    see();
                 }
            else
                 {
                    system("cls");
                    printf("\n\n\t\t\t\t\tInvalid!\a");
                    goto see_invalid;
                 }
        }
    else
        {
            printf("\n\n\t\t\t   \xB2\xB2 Enter 1 to go to the main menu, 2 to transection and 0 to exit:");
            scanf("%d",&main_exit);
        }
        if (main_exit==1)
        {
            system("cls");
            menu();
        }
        else if (main_exit==2)
        {
            system("cls");
            transact();
        }
        else
        {
            system("cls");
            close();
        }
}


void erase(void)
{
    FILE *old,*newrec;
    int test=0;
    system("color F0");
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");

    printf("\n\n\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\t\t\t\t\xB2\xDB\xDB\xDB\xDB\t\t\t\t\t\t   \xDB\xDB\xDB\xDB\xB2");
    printf("\n\t\t\t\t\t\t      Delete Account");
    printf("\n\t\t\t\t\xB2\xDB\xDB\xDB\xDB\t\t\t\t\t\t   \xDB\xDB\xDB\xDB\xB2");
    printf("\n\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

    printf("\n\n\n\n\t\t\t     \xB2\xDB\xDB Enter the account no. of the customer you want to delete:");
    scanf("%d",&rem.acc_no);
    while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.NID,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
   {
        if(add.acc_no!=rem.acc_no)
        {
            fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.NID,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
        }
        else
        {
            test++;
            printf("\a");
            //system("cls");
            printf("\n\n\t\t\t\t\tRecord deleted successfully!\n");
        }
   }
   fclose(old);
   fclose(newrec);
   remove("record.dat");
   rename("new.dat","record.dat");
   if(test==0)
        {
            //system("cls");
            printf("\n\n\t\t\t\t\tRecord not found!!\a\a\a");
            erase_invalid:
              printf("\n\n\t\t\xB2\xB2 Enter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);
              system("cls");
                 if (main_exit==1)
                 {
                     menu();
                 }
                 else if (main_exit==2)
                 {
                    close();
                 }
                 else if(main_exit==0)
                 {
                    erase();
                 }
                 else
                 {
                    printf("\nInvalid!\a");
                    goto erase_invalid;
                 }
        }
   else
        {
           printf("\n\n\t\t\t\t\xB2\xB2 Enter 1 to go to the main menu and 0 to exit:");
           scanf("%d",&main_exit);
           system("cls");
           if (main_exit==1)
            {
               menu();
            }
           else
            {
               close();
            }
        }
}


void view_list()
{
    FILE *view;
    view=fopen("record.dat","r");
    int test=0;
    system("color B0");
    system("cls");

    printf("\n\n\t\t\t\t \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\t\t\t\t \xB2\xDB\xDB\xDB\xDB\t\t\t\t\t\t    \xDB\xDB\xDB\xDB\xB2");
    printf("\n\t\t\t\t\t        ALL CUSTOMER'S INFORMATION");
    printf("\n\t\t\t\t \xB2\xDB\xDB\xDB\xDB\t\t\t\t\t\t    \xDB\xDB\xDB\xDB\xB2");
    printf("\n\t\t\t\t \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\n\t\t  ACC. NO.\t\t\tNAME\t\t\tADDRESS\t\t\t   PHONE\n");

    while(fscanf(view,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.NID,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
       {
           printf("\n\t\t%10d\t\t   %10s\t\t    %10s\t\t\t%0.0lf",add.acc_no,add.name,add.address,add.phone);
           test++;
       }
    fclose(view);
    if (test==0)
        {
            system("cls");
            printf("\n\n\t\t\t\t\tNO RECORDS!!\n");
        }
     view_list_invalid:
     printf("\n\n\n\t\t\t\t  \xB2\xB2 Enter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else if(main_exit==0)
            close();
        else
        {
            printf("\nInvalid!\a");
            goto view_list_invalid;
        }
}

void close(void)
{
    system("color F0");
    printf("\n\n\n\t\t\t    \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
    printf("\n\t\t\t    \xDB      \t\t\t\t\t\t  \xDB");
    printf("\n\t\t\t    \xDB          This C Project is developed by...      \t  \xDB");
    printf("\n\t\t\t    \xDB      \t\t\t\t\t\t  \xDB");
    printf("\n\t\t\t    \xDB  [ Team 9-Intake 47-Section 2--Dept. of CSE BUBT ]  \xDB");
    printf("\n\t\t\t    \xDB      \t\t\t\t\t\t  \xDB");
    printf("\n\t\t\t    \xDB    1. Md Ashikur Islam      -\tId-20215103086    \xDB");
    printf("\n\t\t\t    \xDB      \t\t\t\t\t\t  \xDB");
    printf("\n\t\t\t    \xDB    2. Tahmid Jawwad         -\tId-20215103096    \xDB");
    printf("\n\t\t\t    \xDB      \t\t\t\t\t\t  \xDB");
    printf("\n\t\t\t    \xDB    3. Md Ariful Islam Rifat -\tId-20215103099    \xDB");
    printf("\n\t\t\t    \xDB      \t\t\t\t\t\t  \xDB");
    printf("\n\t\t\t    \xDB      \t\t\t\t\t\t  \xDB");
    printf("\n\t\t\t    \xDB            <THANKS FOR USING THIS SYSTEM>           \xDB");
    printf("\n\t\t\t    \xDB             \t\t\t\t\t  \xDB");
    printf("\n\t\t\t    \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
getch();
}

void menu(void)
{
    int choice;
    system("cls");
    system("color 0B");

printf("\n\n\t\t   \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
printf("\n\t\t   \xB2\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB2\xB2 WELCOME TO \xB2\xB2\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB2");
printf("\n\t\t   \xB2\xDB\xDB\t\t\t\t\t\t\t\t\t        \xDB\xDB\xB2");
printf("\n\t\t   \xB2\xDB\xDB\t\t\t\t\t\t\t\t\t\t\xDB\xDB\xB2");
printf("\n\t\t   \xB2\xDB\xDB\t\t\t     \xDB\xDB\xDB\xDB   \xDB\xDB\xDB\xDB\xDB  \xDB\xDB\xDB\xDB \xDB\xDB  \xDB\xDB  \xDB\t\t\t\xDB\xDB\xB2");
printf("\n\t\t   \xB2\xDB\xDB\t\t\t     \xDB\xDB \xDB\xDB  \xDB\xDB \xDB\xDB  \xDB\xDB \xDB \xDB\xDB  \xDB\xDB \xDB\t\t\t\xDB\xDB\xB2");
printf("\n\t\t   \xB2\xDB\xDB\t\t\t     \xDB\xDB\xDB\xDB\xDB  \xDB\xDB\xDB\xDB\xDB  \xDB\xDB \xDB \xDB\xDB  \xDB\xDB\xDB\t\t\t        \xDB\xDB\xB2");
printf("\n\t\t   \xB2\xDB\xDB\t\t\t     \xDB\xDB \xDB\xDB  \xDB\xDB \xDB\xDB  \xDB\xDB \xDB \xDB\xDB  \xDB\xDB \xDB\t\t\t\xDB\xDB\xB2");
printf("\n\t\t   \xB2\xDB\xDB\t\t\t     \xDB\xDB\xDB\xDB   \xDB\xDB \xDB\xDB  \xDB\xDB \xDB\xDB\xDB\xDB  \xDB\xDB  \xDB\t\t\t\xDB\xDB\xB2");
printf("\n\t\t   \xB2\xDB\xDB\t\t\t\t\t\t\t\t\t\t\xDB\xDB\xB2");
printf("\n\t\t   \xB2\xDB\xDB\t\t\t\t\t\t\t\t\t        \xDB\xDB\xB2");
printf("\n\t\t   \xB2\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB2\xB2 BANK MAIN MENU \xB2\xB2\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB2");
printf("\n\t\t   \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");

    white();
    time_t now;
    time(&now);
    printf("\n\n\t\t\t\t\t       %s",ctime(&now));

    printf("\n\t\t\t\t\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
    printf("\n\t\t\t\t\xDB                                                      \xDB\n");
    printf("\t\t\t\t\xDB   \xDB 1.Create new account\t\t\t       \xDB");
    printf("\n\t\t\t\t\xDB\t\t\t\t\t\t       \xDB");
    printf("\n\t\t\t\t\xDB   \xDB 2.Update information of existing account\t       \xDB");
    printf("\n\t\t\t\t\xDB\t\t\t\t\t\t       \xDB");
    printf("\n\t\t\t\t\xDB   \xDB 3.For Transactions\t\t\t       \xDB");
    printf("\n\t\t\t\t\xDB\t\t\t\t\t\t       \xDB");
    printf("\n\t\t\t\t\xDB   \xDB 4.Check the details of account\t\t       \xDB");
    printf("\n\t\t\t\t\xDB\t\t\t\t\t\t       \xDB");
    printf("\n\t\t\t\t\xDB   \xDB 5.Removing existing account\t\t       \xDB");
    printf("\n\t\t\t\t\xDB\t\t\t\t\t\t       \xDB");
    printf("\n\t\t\t\t\xDB   \xDB 6.View customer's list\t\t\t       \xDB");
    printf("\n\t\t\t\t\xDB\t\t\t\t\t\t       \xDB");
    printf("\n\t\t\t\t\xDB   \xDB 7.Exit\t\t\t\t\t       \xDB");
    printf("\n\t\t\t\t\xDB\t\t\t\t\t\t       \xDB");
    printf("\n\t\t\t\t\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");

    printf("\n\n\t\t\t\t\t\t\xB2\xDB\xDB Enter your choice: ");

    scanf("%d",&choice);
    system("cls");
    switch(choice)
    {
        case 1:
            new_acc();
            break;
        case 2:
            edit();
            break;
        case 3:
            transact();
            break;
        case 4:
            see();
            break;
        case 5:
            erase();
            break;
        case 6:
            view_list();
            break;
        case 7:
            close();
            break;
        default:
            red ();
            printf("\n\n\n\t\t\t\tPlease enter 1 to 7\n\n");
            printf("\n\t\t\t\tPress any key");
            getch();
            menu();
    }
}


void Password(void)
{
    char ch,pass[20],user[20],username[20]="admin",password[20]="2020";
    int i=0;
    system("color F0");
    printf("\n\n\t\t\t     \xB2\xDB\xDB\xDB\xDB Please enter the Username and Password to login...\xDB\xDB\xDB\xDB\xB2");
    printf("\n\n\t\t\t\t\t\t\xB2\xDB\xDB\xDB Username : ");
    scanf("%s",user);

    printf("\n\t\t\t\t\t\t\xB2\xDB\xDB\xDB Password : ");
    while(ch!=13)
    {
      ch=getch();
      if(ch!=13 && ch!=8)
       {
          putch('*');
          pass[i] = ch;
          i++;
       }
       else if(ch==8)
       {
           if(i>0)
           {
               i--;
               printf("\b \b");
           }
       }
    }
    pass[i] = '\0';

    if (strcmp(username,user)==0 && strcmp(password,pass)==0)
        {
            printf("\n\n\t\t\t\t\t   \xDB Username & Password Match! \xDB\n\n\t\t\t\t\t\t   LOADING..");
            for(i=0;i<=6;i++)
             {
                fordelay(100000000);
                printf("\xDB");
             }
                system("cls");
                menu();
        }
    else
        {
            printf("\a");
            printf("\n\n\t\t\t\t\tWrong Username or Password!!");
            login_try:
            printf("\n\n\t\t\t\t\tEnter 1 to try again and 0 to exit: ");
            scanf("%d",&main_exit);
            if (main_exit==1)
                    {
                        system("cls");
                        main();
                    }
            else if (main_exit==0)
                    {
                        system("cls");
                        close();
                    }
            else
                    {
                        printf("\n\n\t\t\t\tInvalid!");
                        fordelay(1000000000);
                        system("cls");
                        goto login_try;
                    }
        }

        getch();
}


int main()
{
system("color F0");

printf("\n\t\t                   \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
printf("\n\t\t                   \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
printf("\n\t\t           \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB2 WELCOME TO \xB2\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
printf("\n\t\t           \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB2 BANK \xB2\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
printf("\n\t\t \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB2 MANAGEMENT  SYSTEM \xB2\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
printf("\n\t\t \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
printf("\n\t\t   \xB2\xDB\xDB\xDB\xDB \xDB\xDB\xDB\xDB \xDB\xDB\xDB\xDB \xDB\xDB\xDB\xDB     \t\t\t\t       \xDB\xDB\xDB\xDB \xDB\xDB\xDB\xDB \xDB\xDB\xDB\xDB \xDB\xDB\xDB\xDB\xB2");
printf("\n\t\t   \xB2\xDB\xDB\xDB   \xDB\xB2   \xDB\xB2   \xDB\xB2     \t\t\t\t\t\xB2\xDB   \xB2\xDB   \xB2\xDB   \xDB\xDB\xDB\xB2");
printf("\n\t\t   \xB2\xDB\xDB\xDB   \xDB\xB2   \xDB\xB2   \xDB\xB2       \xDB\xDB\xDB\xDB   \xDB\xDB\xDB\xDB\xDB  \xDB\xDB\xDB\xDB \xDB\xDB  \xDB\xDB  \xDB\t\xB2\xDB   \xB2\xDB   \xB2\xDB   \xDB\xDB\xDB\xB2");
printf("\n\t\t   \xB2\xDB\xDB\xDB   \xDB\xB2   \xDB\xB2   \xDB\xB2       \xDB\xDB \xDB\xDB  \xDB\xDB \xDB\xDB  \xDB\xDB \xDB \xDB\xDB  \xDB\xDB \xDB\t\xB2\xDB   \xB2\xDB   \xB2\xDB   \xDB\xDB\xDB\xB2");
printf("\n\t\t   \xB2\xDB\xDB\xDB   \xDB\xB2   \xDB\xB2   \xDB\xB2       \xDB\xDB\xDB\xDB\xDB  \xDB\xDB\xDB\xDB\xDB  \xDB\xDB \xDB \xDB\xDB  \xDB\xDB\xDB\t\t\xB2\xDB   \xB2\xDB   \xB2\xDB   \xDB\xDB\xDB\xB2");
printf("\n\t\t   \xB2\xDB\xDB\xDB   \xDB\xB2   \xDB\xB2   \xDB\xB2       \xDB\xDB \xDB\xDB  \xDB\xDB \xDB\xDB  \xDB\xDB \xDB \xDB\xDB  \xDB\xDB \xDB\t\xB2\xDB   \xB2\xDB   \xB2\xDB   \xDB\xDB\xDB\xB2");
printf("\n\t\t   \xB2\xDB\xDB\xDB   \xDB\xB2   \xDB\xB2   \xDB\xB2       \xDB\xDB\xDB\xDB   \xDB\xDB \xDB\xDB  \xDB\xDB \xDB\xDB\xDB\xDB  \xDB\xDB  \xDB\t\xB2\xDB   \xB2\xDB   \xB2\xDB   \xDB\xDB\xDB\xB2");
printf("\n\t\t   \xB2\xDB\xDB\xDB   \xDB\xB2   \xDB\xB2   \xDB\xB2      \t\t\t\t\t\xB2\xDB   \xB2\xDB   \xB2\xDB   \xDB\xDB\xDB\xB2");
printf("\n\t\t   \xB2\xDB\xDB\xDB\xDB \xDB\xDB\xDB\xDB \xDB\xDB\xDB\xDB \xDB\xDB\xDB\xDB     \t\t\t\t       \xDB\xDB\xDB\xDB \xDB\xDB\xDB\xDB \xDB\xDB\xDB\xDB \xDB\xDB\xDB\xDB\xB2");
printf("\n\t\t   \xB2\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB2");
printf("\n\t\t  \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
printf("\n\t\t \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");

Password();
getch();
}
