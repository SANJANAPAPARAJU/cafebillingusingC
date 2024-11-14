//program on customer billing system
#include<stdio.h>
#include<string.h>
struct customer{
	int quantity;
	int product;
	float price;
};
void disp(void);
int main()
{  int opt,n,i,j;
float subtotal,total;
float discount,a_paid,a_due=0;
char name[20];
char str[20];
int date,month,year,hours,minutes;
unsigned long int phone_no;
	struct customer c[n];
	FILE *fp=NULL;
	fp=fopen("customer_data1.txt","a+");
	if(fp==NULL)
{
	printf("\n ERROR!! TRY AGAIN");
	return 0;
}
printf("\t\tANURAG CAFE\t\t\t");
disp();
printf("\n 1.Make a bill \n 2.exit\n");
//enter 1 or 2
scanf("%d",&opt);
switch(opt)
{
	case 1:
		{printf("\n enter code:1.pizza(200),2.burger(150),3.fries(100),4.coke(150),5.coffee(150),6.hot chocolate(150),7.frappicino(300)"); 
		printf("\n enter date,month,year:");
		scanf("%d%d%d",&date,&month,&year);
		printf("\n enter time(hours,min):");
		scanf("%d%d",&hours,&minutes);
		printf("\n enter name of the customer:");
		scanf("%s",name);
		printf("\n enter phone no:");
		scanf("%lu",&phone_no);
		printf("\n how many items are ordered?:");
		scanf("%d",&n);
		subtotal=0;
		for(i=0;i<n;i++)
		{ 
			printf("\n enter %d item name:",i+1);
			scanf("%d",&c[i].product);
			if((c[i].product==1)||(c[i].product==2)||(c[i].product==3)||(c[i].product)==4||(c[i].product==5)||(c[i].product==6)||(c[i].product==7))
			{
		     printf("\n quantity:");
			}
			else
			{printf("\n product not available!");
			}//printf("\nquantity:");
			scanf("%d",&c[i].quantity);
			if((c[i].product==2)||(c[i].product==4)||(c[i].product==5)||(c[i].product==6))
			{ 
			c[i].price=150;
				subtotal+=c[i].price*c[i].quantity;
		    }
			else if(c[i].product==1)
			{
			c[i].price=200;
			subtotal+=c[i].price*c[i].quantity;
            }
			else if(c[i].product==3)
			{
				c[i].price=100;
				subtotal+=c[i].price*c[i].quantity;
			}
			else
			{
				c[i].price=300;
				subtotal+=c[i].price*c[i].quantity;
			}
		}
			printf("\n enter discount price");
			scanf("%f",&discount);
			total=subtotal-discount;
	        printf("\n total:%.2f",total);
			printf("\n enter paid amount:");
			scanf("%f",&a_paid);
			a_due+=total-a_paid;
			if(a_due==0)
			{
			printf("\n no due.");
			}
			else
			printf("\n %.2f is due.",a_due);
		printf("\n\n\n\n");
		disp();
		printf("\n\t\t\t\t ANURAG CAFE\t\t\t\t");
		disp();
		printf("\n customer name: %s",name);
		strcpy(str,"customer details");
		fprintf(fp,"%s\n\n",str);
		fputs(name,fp);
		strcpy(str,"phonenumber\n");
			fprintf(fp,"\n%s:",str);
		printf("\n PH.No:%lu\n",phone_no);
		fprintf(fp,"%lu\n",phone_no);
		strcpy(str,"D-M-Y");
		printf("\n date:%d-%d-%d",date,month,year);
		fprintf(fp,"%s:",str);
		fprintf(fp,"%d ",date);
		fprintf(fp,"%d ",month);		
		fprintf(fp,"%d\n",year);
		printf("\n time:%d:%d",hours,minutes);
		strcpy(str,"hours:minutes");
		fprintf(fp,"%s\t",str);
		fprintf(fp,"%d:",hours);
		fprintf(fp,"%d\n",minutes);
		disp();
		printf("\n\titems\t\t\tQuantity\t\t\ttotal");
}		disp();
		for(i=0;i<n;i++)
	{
		if((c[i].product==2)||(c[i].product==4)||(c[i].product==5)||(c[i].product==6))
			{ 
			c[i].price=150;
			}
			else if(c[i].product==1)
			{
			c[i].price=200;
			}
			else if(c[i].product==3)
			{
				c[i].price=100;
			}
			else
			{
				c[i].price=300;
			}
		printf("\n%d",c[i].product);
		strcpy(str,"product");
		fprintf(fp,"%s\t",str);
		fprintf(fp,"%d\n",c[i].product);
		printf("\t\t\t\t\%d\t\t\t\%.2f",c[i].quantity,c[i].price);
		strcpy(str,"qua");
		fprintf(fp,"%s\t",str);
		fprintf(fp,"%d\n",c[i].quantity);
		strcpy(str,"price");
		fprintf(fp,"%s\t",str);
		fprintf(fp,"%.2f\n",c[i].price);
	}	disp();
		printf("\nsubtotal\t\t\t\t:%.2f",subtotal);
		strcpy(str,"subtotal");
		fprintf(fp,"%s\t",str);
		fprintf(fp,"%.2f\n",subtotal);
		printf("\ndiscount\t\t\t\t:-%.2f",discount);
		strcpy(str,"discount");
		fprintf(fp,"%s\t",str);
		fprintf(fp,"%.2f\n","discount");
		disp();
		total=subtotal-discount;
		printf("\ntotal\t\t\t\t\t:%.2f",total);
		strcpy(str,"total");
		fprintf(fp,"%s\t",str);
		fprintf(fp,"%.2f\n",total);
		printf("\namount paid\t\t\t:%.2f",a_paid);
		strcpy(str,"amount_paid");
		fprintf(fp,"%s\t",str);
		fprintf(fp,"%.2f\n",a_paid);
		printf("\namount due\t\t\t:%.2f",a_due);
		strcpy(str,"a_due");
			fprintf(fp,"%s\t",str);
		fprintf(fp,"%.2f\n",a_due);
	break;
	case 2:
		{
		return 0;
		}
}return 0;
}
void disp(void)
{
	printf("\n------------------------------------------------------------------");
}

