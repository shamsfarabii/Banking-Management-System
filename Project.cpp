#include<bits/stdc++.h>
using namespace std;
#define MIN_BALANCE 5000
long account_Num = 11110 ;


class InsufficientFunds {};

/// Struct Part start ::: end 45 :::
struct customer
{
    char fname[200], lname[200];
    double balance;
    long accountNumber;
};


typedef struct customer DC;
DC store[2000];
int collectInfo()
{
    FILE *sign = fopen("customerDB.txt", "r");
    if(sign==0)
    {
        printf("404 not found\n");
        return 1;
    }
    DC temp;
    int cnt=0, j;
    while(fgets(temp.fname, sizeof temp.fname, sign) != NULL)
    {
        fscanf(sign, "%s", temp.lname);
        fscanf(sign, "%d", &temp.accountNumber);
        fscanf(sign, "%lf\n", &temp.balance);
        /// Store ::
        strcpy(store[cnt].fname, temp.fname) ;
        strcpy(store[cnt].lname, temp.lname) ;
        store[cnt].accountNumber = temp.accountNumber ;
        store[cnt].balance = temp.balance ;
        /// Store Index ::
        cnt++;
    }
    fclose(sign);
    return cnt;
}
/// Struct part end ::: start 7 :::

///Adding Info to database ::: end 60 :::
void info_jog(DC addinfo)
{
    FILE *sign = fopen("customerDB.txt", "a");

    fprintf(sign, "%s\n", addinfo.fname);
    fprintf(sign, "%s\n", addinfo.lname);
    fprintf(sign, "%d\n", addinfo.accountNumber);
    fprintf(sign, "%lf\n\n", addinfo.balance);

    fclose(sign);
}
/// Adding info shesh :3 ::: start 49::;








int main()
{
    int choice;
    int input_AN;
    bool flag = true;
    string fname,lname,blank;
    double balance;
    int accountvalue = collectInfo();
    DC addinfo;

    cout << accountvalue << endl;
    for(int i=0; i<accountvalue; i++)
    {
        cout << store[i].fname;// << endl ;
        cout << store[i].lname << endl;
        cout << store[i].accountNumber<< endl;
        cout << store[i].balance<<endl ;
        //cout << store
    }

    cout<<"||***Banking System***||"<<endl;

    while(1)
    {
        cout<<"\nSelect one option below ";
        cout<<"\n1 : Open an Account";
        cout<<"\n2 : Balance Enquiry";
        cout<<"\n3 : Deposit";
        cout<<"\n4 : Withdrawal";
        cout<<"\n5 : Close an Account";
        cout<<"\n6 : Show All Accounts";
        cout<<"\n7 : Quit" << endl;
        cout<<"\nEnter your choice: ";
        cin>>choice;
        switch(choice)
        {

        case 1:
            cout<<"Enter First Name: ";
            cin>>addinfo.fname;
            cout<<"Enter Last Name: ";
            cin>>addinfo.lname;
            cout<<"Enter initial Balance: ";
            cin>>balance;
            while(balance < MIN_BALANCE)
            {
                system("COLOR 0C");
                cout << '\n' << "Sorry you have to deposit minimum amount of Taka 5000 to open an account\n"<<endl ;
                cout<<"Enter initial Balance: ";
                cin>>balance;

            }
            system("COLOR 07");
            if(accountvalue && flag)
            {
                flag = 0 ;
                account_Num = 1+ store[accountvalue-1].accountNumber   ;
            }
            ///  else account_Num = 11110;
            addinfo.accountNumber = account_Num;
            cout<<endl<<"Congratulations! Dear "<<addinfo.fname<<" "<<addinfo.lname<< ", Your account is Created .\n\n"<<endl;
            cout << "Your Account Number is " << account_Num << endl ;

            account_Num++;
            addinfo.balance = balance;
            info_jog(addinfo);
            break;

        case 2:
            cout<<"Enter Account Number:";
            cin>>input_AN;
            cout<<endl<<"Your Account Details"<<endl;
            break;

        case 3:
            cout<<"Enter Account Number:";
            cin>>input_AN;
            cout<<"Enter Balance:";
            cin>>balance;
            //acc=b.Deposit(accountNumber, balance);
            cout<<endl<<"Amount is Deposited"<<endl;
            //cout<<acc;
            break;

        case 4:
            cout<<"Enter Account Number:";
            cin>>input_AN;
            cout<<"Enter Balance:";
            cin>>balance;
            //acc=b.Withdraw(accountNumber, balance);
            cout<<endl<<"Amount Withdrawn"<<endl;
            //cout<<acc;
            break;

        case 5:
            cout<<"Enter Account Number:";
            cin>>input_AN;
            //b.CloseAccount(accountNumber);
            cout<<endl<<"Account is Closed"<<endl;
        //cout<<acc;

        case 6:
            //b.ShowAllAccounts();
            break;

        default:
            cout<<"\nTHANKS FOR USING OUR SERVICE\n#Created by C201001 C201010 C201031" << endl;
            cin >> blank;
            exit(0);
        }

    }
    //while(choice!=7);

    cin >> blank;
    return 0;
}