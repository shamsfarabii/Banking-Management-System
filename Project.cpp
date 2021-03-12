#include<bits/stdc++.h>
#include<conio.h>
#include<windows.h>
using namespace std;
#define MIN_BALANCE 5000
long account_Num = 11110 ;
char admin_id[] = "123456";
char admin_password[] = "312456";
class InsufficientFunds {};

/// class Part start ::: end 45 :::
class customer
{
public:
    char fname[200], lname[200];
    double balance;
    long accountNumber;
    char password[200];
};


typedef class customer DC;
DC store[2000];
int collectInfo()
{
    FILE *sign = fopen("customerDB.txt", "r");
    if (sign == 0)
    {
        printf("404 not found\n");
        return 1;
    }

    DC temp;
    int cnt = 0, j;

    while (fgets(temp.fname, sizeof temp.fname, sign) != NULL)
    {
        fscanf(sign, "%s", temp.lname);
        fscanf(sign, "%d", &temp.accountNumber);
        fscanf(sign, "%s", temp.password);
        fscanf(sign, "%lf\n", &temp.balance);
        /// Store ::
        strcpy(store[cnt].fname, temp.fname) ;
        strcpy(store[cnt].lname, temp.lname) ;
        store[cnt].accountNumber = temp.accountNumber ;
        store[cnt].balance = temp.balance ;
        strcpy(store[cnt].password, temp.password);
        /// Store Index ::
        cnt++;
    }

    fclose(sign);
    return cnt;
}
/// class part end ::: start 7 :::

///Adding Info to database ::: end 60 :::
void info_jog(DC addinfo)
{
    FILE *sign = fopen("customerDB.txt", "a");

    fprintf(sign, "%s\n", addinfo.fname);
    fprintf(sign, "%s\n", addinfo.lname);
    fprintf(sign, "%d\n", addinfo.accountNumber);
    fprintf(sign, "%s\n", addinfo.password);
    fprintf(sign, "%lf\n\n", addinfo.balance);

    fclose(sign);
}
/// Adding info shesh :3 ::: start 49::;

int accountvalue = collectInfo();


/// For enquiry :::
void Show_Specific_Account(int accNum, char p[])
{
    int ab = collectInfo();

    for (int i = 0; i < ab; i++)
    {
        if (store[i].accountNumber == accNum )
        {
            if (!strcmp(store[i].password, p))
            {
                system("COLOR 07");

                cout << endl << "Your Account Details\n" << endl;
                cout << "First Name : " << store[i].fname;
                cout << "Last Name : " << store[i].lname << endl;
                cout << "Account Number : " << store[i].accountNumber << endl;
                cout << "Balance : " << store[i].balance << endl ;
                cout << endl << endl;
            }
            else
            {
                cout << endl;
                system("COLOR 0C");
                cout << "INCORRECT PASSWORD!! Try again!" << endl << endl;
            }
        }
    }
}
///end/// For enquiry

///Add money to an individual account
void deposit(int ac_num, double balance, char p[])
{
    int ab = collectInfo();

    for (int i = 0; i < ab; i++)
    {
        if (store[i].accountNumber == ac_num)
        {
            if (!strcmp(store[i].password, p))
            {
                system("COLOR 0E");
                store[i].balance += balance;

                cout << endl;

                string s = store[i].fname;

                s[s.size() - 1] = ' ';

                cout << "Dear " << s << " " << store[i].lname << endl;

                cout << "Your new balance is " << store[i].balance << endl;

                cout << "Account number " << store[i].accountNumber << endl;

                cout << endl << "Amount is Deposited!" << endl;
            }

            else
            {
                cout << endl;
                system("COLOR 0C");
                cout << "INCORRECT PASSWORD!! Try again!" << endl << endl;
            }
        }
    }

    FILE *sign = fopen("customerDB.txt", "w");

    for (int i = 0; i < ab; i++)
    {
        fprintf(sign, "%s\n", store[i].fname);
        fprintf(sign, "%s\n", store[i].lname);
        fprintf(sign, "%d\n", store[i].accountNumber);
        fprintf(sign, "%s\n", store[i].password);
        fprintf(sign, "%lf\n\n", store[i].balance);
    }

    fclose(sign);
}
///end///Add money to a individual account

///Withdraw :::>
void withdraw(int accNum, double balance, char p[])
{
    int ab = collectInfo();
    for (int i = 0 ; i < ab ; i++)
    {
        if (store[i].accountNumber == accNum)
        {
            if (!strcmp(store[i].password, p))
            {
                double temp = store[i].balance - balance ;

                if (temp < 500.000)
                {
                    cout << "Dear Sir.You don't have enough money to withdraw. Try again later!" << endl ;
                }
                else
                {
                    system("COLOR 07");
                    cout << endl;

                    store[i].balance = temp ;

                    string s = store[i].fname;

                    s[s.size() - 1] = ' ';

                    cout << "Dear " << s << " " << store[i].lname << endl;

                    cout << "Your new balance is " << store[i].balance << endl;

                    cout << "Account number " << store[i].accountNumber << endl;
                    cout << endl << "Amount Withdrawn!" << endl;
                }
            }
            else
            {
                cout << endl;
                system("COLOR 0C");
                cout << "INCORRECT PASSWORD!! Try again!" << endl << endl;
            }
        }
        FILE *sign = fopen("customerDB.txt", "w");

        for (int i = 0 ; i < ab ; i++)
        {
            fprintf(sign, "%s\n", store[i].fname);
            fprintf(sign, "%s\n", store[i].lname);
            fprintf(sign, "%d\n", store[i].accountNumber);
            fprintf(sign, "%s\n", store[i].password);
            fprintf(sign, "%lf\n\n", store[i].balance);
        }
        fclose(sign);

    }
}

/// end withdraw ::::


//Account close

void close_ac(int input, char p[])
{
    int ab = collectInfo();

    FILE *sign = fopen("customerDB.txt", "w");

    for (int i = 0; i < ab ; i++)
    {
        if (!strcmp(store[i].password, p))
        {
            if (store[i].accountNumber != input)
            {
                fprintf(sign, "%s\n", store[i].fname);
                fprintf(sign, "%s\n", store[i].lname);
                fprintf(sign, "%d\n", store[i].accountNumber);
                fprintf(sign, "%s\n", store[i].password);
                fprintf(sign, "%lf\n\n", store[i].balance);
            }
        }
        else
        {
            cout << endl;
            system("COLOR 0C");
            cout << "INCORRECT PASSWORD!! Try again!" << endl << endl;
        }
    }

    fclose(sign);
}

///end//Account close

int admin_approval(char id[], char password[])
{
    if (strcmp(id,admin_id) || strcmp(password,admin_password))
        return 0 ;
    else return 1;
}


void bkash()
{
    string url = "https://www.bkash.com/user";
    ShellExecute(NULL, "open", url.c_str(), NULL, NULL, SW_SHOWNORMAL);
    Sleep(3000);

}

int is_present(long aNUM)
{
    int ab = collectInfo();
    for (int i = 0 ; i < ab ; i++)
    {
        if (store[i].accountNumber == aNUM)
        {
            return 1 ;
        }
    }
    return 0 ;

}

void show_deposit(long AN)
{
    int ab = collectInfo();
    for (int i = 0 ; i < ab ; i++)
    {
        if (store[i].accountNumber == AN)
        {
            double temp_amount  = store[i].balance - 500.00;
            cout << "Available balance for Withdrawal : " ;
            cout <<setprecision(2)<< fixed <<temp_amount << endl ;
            cout << endl;
        }
    }
}

int main()
{
    int choice;
    int input_AN;
    bool flag = true;
    string fname, lname, blank;
    double balance;
    //char in_pw [200];
    DC addinfo;
    system("COLOR 07");


    cout << "||***Banking System***||\n" << endl;


    while (1)
    {
        cout << "#Select one option below#\n";
        cout << "1 : Open an Account\n";
        cout << "2 : Balance Enquiry\n";
        cout << "3 : Deposit\n";
        cout << "4 : Withdrawal\n";
        cout << "5 : Close an Account\n";
        cout << "6 : Link your account with Bkash\n";
        cout << "7 : Quit\n\n";
        cout << "Enter your choice --> ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter First Name: ";
            cin >> addinfo.fname;
            cout << "Enter Last Name: ";
            cin >> addinfo.lname;
            cout << "Enter initial Balance: ";
            cin >> balance;
            while (balance < MIN_BALANCE)
            {
                system("COLOR 0C");
                cout << '\n' << "Sorry you have to deposit minimum amount of Taka 5000 to open an account\n" << endl ;
                cout << "Enter initial Balance: ";
                cin >> balance;

            }
            system("COLOR 07");

            cout << "Enter a 6 digit password : " ;

            // Odrissho Password :3
            int i;
            for ( i = 0; i < 10; i++)
            {
                addinfo.password[i] = _getch();
                if (addinfo.password[i] == 13) break;
                _putch('*');

            }
            addinfo.password[i] = '\0';
            // Jaduuuu Shesh :3

            if (accountvalue && flag)
            {
                flag = 0 ;
                account_Num = 1 + store[accountvalue - 1].accountNumber   ;
            }
            addinfo.accountNumber = account_Num;
            cout << endl << "Congratulations! Dear " << addinfo.fname << " " << addinfo.lname << ", Your account is Created .\n\n" << endl;
            cout << "Your Account Number is " << account_Num << endl ;
            cout << endl;

            account_Num++;
            addinfo.balance = balance;
            info_jog(addinfo);
            break;

        case 2:
            char in_pw[10];

            cout << "Enter Account Number:";
            cin >> input_AN;
            if(is_present(input_AN))
            {
                cout << "Enter your 6 digit password : ";
                // Odrissho Password :3
                i;
                for (i = 0; i < 10; i++)
                {
                    in_pw[i] = _getch();
                    if(in_pw[i] == 13) break;
                    _putch('*');

                }
                in_pw[i] = '\0' ;
                // Jaduuuu Shesh :3


                Show_Specific_Account(input_AN, in_pw);
                //system("COLOR 07");
                cout << endl;
                break;
            }
            else
            {
                system("COLOR 0C");
                cout << "Your account does not exist . Try again with valid account number\n" << endl;

            }
            break;

        case 3:
            cout << "Enter Account Number:";
            cin >> input_AN;
            if(is_present(input_AN))
            {
                cout << "Enter your 6 digit password : " ;

                /// Odrissho Password :3
                in_pw[10];
                i;
                for (i = 0; i < 10; i++)
                {
                    in_pw[i] = _getch();
                    if(in_pw[i] == 13) break;
                    _putch('*');

                }
                in_pw[i] = '\0' ;
                /// Jaduuuu Shesh :3

                cout << endl;
                cout << "Waiting for ADMIN approval " ;
                Sleep(1000);
                cout << ".";
                Sleep(1000);
                cout << ".";
                Sleep(1000);
                cout << ".";
                cout << endl;
                cout << "Enter Admin-id : " ;

                /// Odrissho Password :3
                char ad_id[10];
                i;
                for (i = 0; i < 10; i++)
                {
                    ad_id[i] = _getch();
                    if(ad_id[i] == 13) break;
                    _putch('*');

                }
                ad_id[i] = '\0' ;
                /// Jaduuuu Shesh :3
                cout << endl;
                cout << "Enter Admin-password : ";

                /// Odrissho Password :3
                char ad_pass[10];
                i;
                for (i = 0; i < 10; i++)
                {
                    ad_pass[i] = _getch();
                    if(ad_pass[i] == 13) break;
                    _putch('*');

                }
                ad_pass[i] = '\0' ;
                /// Jaduuuu Shesh :3

                cout << endl;

                if(admin_approval(ad_id, ad_pass))
                {
                    cout << "Enter Balance:";
                    cin >> balance;
                    deposit(input_AN, balance, in_pw);
                    cout << endl;
                }
                else
                {
                    cout << endl;
                    system("COLOR 0C");
                    cout << "Admin authentication failed. Try again later \n"<< endl ;
                }
                break;
            }
            else
            {
                system("COLOR 0C");
                cout << "Your account does not exist . Try again with valid account number\n" << endl;
            }
            break;

        case 4:
            cout << "Enter Account Number:";
            cin >> input_AN;
            if(is_present(input_AN))
            {
                cout << "Enter your 6 digit password : " ;

                // Odrissho Password :3
                in_pw[10];
                i;
                for (i = 0; i < 10; i++)
                {
                    in_pw[i] = _getch();
                    if(in_pw[i] == 13) break;
                    _putch('*');

                }
                in_pw[i] = '\0' ;
                // Jaduuuu Shesh :3

                cout << endl;

                show_deposit(input_AN);

                cout << "Enter Balance:";
                cin >> balance;
                withdraw(input_AN, balance, in_pw);
                //system("COLOR 07");
                cout << endl;
                break;
            }
            else
            {
                system("COLOR 0C");
                cout << "Your account does not exist . Try again with valid account number\n" << endl;

            }
            break;

        case 5:
            cout << "Enter Account Number:";
            cin >> input_AN;
            if(is_present(input_AN))
            {
                cout << "Enter your 6 digit password : " ;
                // Odrissho Password :3
                in_pw[10];
                i;
                for (i = 0; i < 10; i++)
                {
                    in_pw[i] = _getch();
                    if(in_pw[i] == 13) break;
                    _putch('*');

                }
                in_pw[i] = '\0' ;
                //Jaduuuu Shesh :3

                close_ac(input_AN, in_pw);
                cout << endl << "Account is Closed" << endl;
                //system("COLOR 07");
                cout << endl;
                break;
            }

            else
            {
                system("COLOR 0C");
                cout << "Your account does not exist . Try again with valid account number\n" << endl;
            }
            break;

        case 6:
            system("COLOR 0E");
            cout << "Now Directing to Bkash for account linking process : " ;
            Sleep(0700) ;
            cout << "." ;
            Sleep(0700) ;
            cout << "." ;
            Sleep(0700) ;
            cout << "." ;
            Sleep(0700) ;
            cout << "." ;
            Sleep(0700) ;
            cout << "." ;
            bkash();
            cout << endl;
            cout << endl;
            break;

        default:
            cout << "\nTHANKS FOR USING OUR SERVICE\n#Created by C201001 C201010 C201031" << endl;
            cin >> blank;
            exit(0);
        }

    }
    cin >> blank;
    return 0;
}
