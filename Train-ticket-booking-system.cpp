#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
int trainlist11(int,int,char *,char *,int,int,int,int);
int trainlist12(int,int,char *,char *,int,int,int,int);
int trainlist21(int,int,char *,char *,int,int,int,int);
int trainlist22(int,int,char *,char *,int,int,int,int);
int route1(int,int);
int route2(int,int);
int finalticket(char *,char *,char *,char *,char *,int,int,int,int);
int mrand();
int mrand()
{
    srand(time(NULL));
    int random = rand();
    random=random*9458+random;
    return random;
}
int finalticket(char *train, char *brs, char *ars, char *brt, char *art, int bkm, int akm, int d, int m)
{
	int i=1;
	int cl;
	int pno;
	int km=bkm-akm;
	int fare;
	if(km<0)
	{
		km=km*(-1);
	}
	system("cls");
	while(i)
	{
		printf("SELECT CLASS OF TRAVEL\n1.AC 1ST CLASS(1A)\n2.AC 2 TIER(2A)\n3.AC 3 TIER(3A)\n4.SLEEPER CLASS (SL) : \n");
		scanf("%d",&cl);
		if(cl==0||cl>4||cl<0)
		{
			i=1;
			printf("ENTER A VALID VALUE");
		}
		else
		{
			i=0;
			printf("YOU HAVE SELECTED : ");
			switch(cl)
			{
				case 1:
					printf("FIRST CLASS");
					break;
				case 2:
					printf("AC 2 TIER");
					break;
				case 3:
					printf("AC 3 TIER");
					break;
				case 4:
					printf("SLEEPER CLASS");
					break;    
			}
			printf("\nPRESS 0 TO PROCEED OR 1 TO RE-ENTER : ");
			scanf("%d",&i);
		}
	}
	i=1;
	while(i)
	{
		printf("ENTER TOTAL NUMBER OF PASSENGERS(MAX=6) : ");
		scanf("%d",&pno);
		if(pno==0||pno<0||pno>6)
		{
			i=1;
			printf("PLEASE ENTER A VALID VALUE\n");
		}
		else
		{
			printf("YOU HAVE ENTERED %d PASSENGERS\n PLEASE ENTER 0 TO PROCEED OR 1 TO RE-ENTER : ",pno);
			scanf("%d",&i);
		}
	}
	char pname[pno + 1][25];
    char ps[pno + 1];
    int page[pno + 1];
	int v=0;
	int w=0;
    for (i = 1; i <= pno; i++) 
	{
        printf("ENTER NAME, SEX (M/F), AGE FOR PASSENGER %d : ", i);
        scanf(" %24[^\n] %c %d", &pname[i], &ps[i], &page[i]);
        printf("\n");
        if ((ps[i] != 'M' && ps[i] != 'F' && ps[i]!='m' && ps[i]!='f')||page[i]<0||page[i]>100) 
		{
		    printf("ENTER A VALID VALUE \n");
            i--; 
    	}
		else
        {	
        	int g;
        	printf("YOU HAVE ENTERED THE FOLLOWING DETAILS FOR PASSENGER %d \n %s \t %c \t %d\n",i,pname[i],ps[i],page[i]);
			printf("ENTER 0 TO CONFIRM OR 1 TO RE-ENTER : ");
			scanf("%d",&g);
			if(g!=0)
			{
				i--;	
			}	
		}
    }
    int j;
    for(i=1;i<=pno;i++)
    {   
		if(ps[i]>=97&&ps[i]<=123)
        {
        	ps[i]=ps[i]-32;
		}
    	for(j=0;j<25;j++)
    	{
    		if(pname[i][j]>=97&&pname[i][j]<=123)
    		{
    			pname[i][j]=pname[i][j]-32;
			}
		}
	}
	
    printf("THE FINAL TICKET LIST IS GIVEN BELOW\n");
    for(i=1;i<=pno;i++)
    {
    	printf("%d . %-20s \t %c \t %d\n",i,pname[i],ps[i],page[i]);
	}
	int z;
	printf("PLEASE ENTER 1 TO PROCEED : ");
	scanf("%d",&z);
	if(z==1)
	{
		printf("PLEASE WAIT WHILE YOUR TICKET IS BEING GENERATED\n\n\n\n");
		system("cls");
		printf("*************************************************************************\n");
		printf("-----------HAPPY JOURNEY----------|--------INDIAN RAILWAYS---------------\n");
		printf("*************************************************************************\n");
		printf("------------------JOURNEY CUM RESERVATION TICKET-------------------------\n");
		printf("*************************************************************************\n");
		int pn1,pn2;
		pn1=(mrand())%100;
		pn2=(mrand()*7)%10000000;
		if(pn1<10)
		{
			pn1=pn1+10;
		}
		if(pn2<1000000)
		{
			pn2=pn2+1000000;
		}
		printf("PNR NO : 4%d-%d\n",pn1,pn2);
		printf("DATE OF JOURNEY : %d - %d\n",d,m);
		printf("TRAIN NAME AND NUMBER : %s\nBOARDING STATION : %s\nBOARDING TIME : %s\nARRIVAL STATION : %s\nARRIVAL TIME : %s\n",train,brs,brt,ars,art);
		printf("DISTANCE : %d KM\n",km);
		printf("CLASS : ");
			switch(cl)
			{
				case 1:
					printf("FIRST CLASS\n");
					break;
				case 2:
					printf("AC 2 TIER\n");
					break;
				case 3:
					printf("AC 3 TIER\n");
					break;
				case 4:
					printf("SLEEPER CLASS\n");
					break;    
			}
		int sc=mrand();
		int sn=mrand()*7;
		switch(cl)
		{
			case 1:
				sc=1;
				sn=sn%6;
				break;
			case 2:
				sc=sc%3;
				sn=sn%41;
				break;
			case 3:
				sc=sc%6;
				sn=sn%66;
				break;
			case 4:
				sc=sc%13;
				sn=sn%74;
				break;
		}	
			if(sc==0)
			{
				sc=1;
			}
			if(sn==0)
			{
				sn=1;
			}
		printf("-------------------------PASSENGER DETAILS-------------------------------\n");
		printf("   PASSENGER NAME\t\tSEX \t AGE \tCOACH \tSEAT \tBERTH\n");
	    for(i=1;i<=pno;i++)
	    {
	    	printf("%d . %-25s \t %c \t %d\t",i,pname[i],ps[i],page[i]);
	    	switch(cl)
	    	{
	    		case 1:
	    			printf("H-%d\t",sc);
	    			printf("%d\t",sn+i-1);
	    			if((sn+i-1)%2==1)
	    			{
	    				printf("LB\n");
					}
					else if((sn+i-1)%2==0)
					{
	    				printf("UB\n");
					}
	    			break;
	    		case 2:
	    			printf("A-%d\t",sc);
	    			printf("%d\t",sn+i-1);
	    			if((sn+i-1)%6==1||(sn+i-1)%6==3)
	    			{
	    				printf("LB\n");
					}
					else if((sn+i-1)%6==2||(sn+i-1)%6==4)
					{
	    				printf("UB\n");
					}
					else if((sn+i-1)%6==5)
					{
	    				printf("SL\n");
					}
					else if((sn+i-1)%6==0)
					{
	    				printf("SU\n");
					}
	    			break;
	    		case 3:
	    			printf("B-%d\t",sc);
	    			printf("%d\t",sn+i-1);
	    			if((sn+i-1)%8==1||(sn+i-1)%8==4)
	    			{
	    				printf("LB\n");
					}
					else if((sn+i-1)%8==2||(sn+i-1)%8==5)
					{
	    				printf("MB\n");
					}
					else if((sn+i-1)%8==3||(sn+i-1)%8==6)
					{
	    				printf("UB\n");
					}
					else if((sn+i-1)%8==7)
					{
	    				printf("SL\n");
					}
					else if((sn+i-1)%8==0)
					{
	    				printf("SU\n");
					}
	    			break;
	    		case 4:
	    			printf("S-%d\t",sc);
	    			printf("%d\t",sn+i-1);
	    			if((sn+i-1)%8==1||(sn+i-1)%8==4)
	    			{
	    				printf("LB\n");
					}
					else if((sn+i-1)%8==2||(sn+i-1)%8==5)
					{
	    				printf("MB\n");
					}
					else if((sn+i-1)%8==3||(sn+i-1)%8==6)
					{
	    				printf("UB\n");
					}
					else if((sn+i-1)%8==7)
					{
	    				printf("SL\n");
					}
					else if((sn+i-1)%8==0)
					{
	    				printf("SU\n");
					}
	    			break;
			}
		}
		printf("------------------------------------------------------------------------------\n");
		printf("*********WISH YOU A SAFE AND SECURE JOURNEY!!! - INDIAN RAILWAYS*********\n");
		printf("THIS TICKET IS SUBJECT TO RAILWAYS ACT 1989 AND OTHER RULES\n\tTHIS TICKET IS NON TRANSFERRABLE\n\tTHIS TICKET IS VALID ONLY WITH GOVT. ISSUED PHOTO IDENTITY CARD\n\tTRAVELLING WITHOUT TICKET ORIGINAL TICKET IS CONSIDERED AS TICKETLESS AND FINES ARE APPLICABLE ACCORDINGLY\n");
		printf("------------------------------------------------------------------------------\n");
		printf("****REAL TIME DATA SOURCE REFERENCE WEBSITES : www.indianrail.gov.in****\n");
		printf("------------------------------------------------------------------------------\n");
		printf("NOTE : THIS CODE LOGIC IS MADE ENTIRELY WITHOUT CHATGPT AND MADE ENTIRELY BY HUMANS\n");
		printf("------------------------------------------------------------------------------\n");
	}
}
int route1(int d, int m)
{
	int i;
	i=1;
	int stn11,stn12;
	char *brp,*arp;
	char stnlist[10][25]={"","PGT\t-\tPALAKKAD","PTJ\t-\tPODANUR","CBE\t-\tCOIMBATORE MAIN","TUP\t-\tTIRUPPUR","ED\t-\tERODE","SA\t-\tSALEM","KPD\t-\tKATPADI(VELLORE)","AJJ\t-\tARAKKONAM","MAS\t-\tCHENNAI CENTRAL\n"};
	int km[10]={0,0,48,54,105,155,214,423,484,559};
	int bkm,akm;
	printf("LIST OF STATIONS\n");
	printf("1.PGT\t-\tPALAKKAD\n2.PTJ\t-\tPODANUR\n3.CBE\t-\tCOIMBATORE MAIN\n4.TUP\t-\tTIRUPPUR\n5.ED\t-\tERODE\n6.SA\t-\tSALEM\n7.KPD\t-\tKATPADI(VELLORE)\n8.AJJ\t-\tARAKKONAM\n9.MAS\t-\tCHENNAI CENTRAL\n");
	while(i)
	{
		printf("\nENTER BOARDING POINT SERIAL NO : ");
		scanf("%d",&stn11);
		{
			if(stn11<0||stn11>9||stn11==0)
			{
				i=1;
				printf("PLEASE ENTER A VALID VALUE");
			}
			else
			{
				i=0;
				printf("\n YOUR BOARDING POINT IS \t\t%s\t KM %d\t",&stnlist[stn11],km[stn11]);
				printf("\n PLEASE ENTER 0 TO PROCEED OR 1 TO RE-ENTER : ");
				scanf("%d",&i);
			}
		}
	}
	i=1;
	while(i)
	{
		printf("\nENTER ARRIVAL POINT SERIAL NO : ");
		scanf("%d",&stn12);
		{
			if(stn12<0||stn12>9||stn12==0)
			{
				i=1;
				printf("PLEASE ENTER A VALID VALUE");
			}
			else if(stn11==stn12)
			{
				i=1;
				printf("PLEASE ENTER A VALID INPUT(ERR : BRD PNT!=ARR PNT)");
			}
			else
			{
				i=0;
				printf("\n YOUR ARRIVAL POINT IS  \t\t%s\t KM %d\t",&stnlist[stn12],km[stn12]);
				printf("\n PLEASE ENTER 0 TO PROCEED OR 1 TO RE-ENTER : ");
				scanf("%d",&i);
			}
		}
	}	
	brp=&stnlist[stn11][0];
	arp=&stnlist[stn12][0];
	bkm=km[stn11];
	akm=km[stn12];
	system("cls");
	if(stn11<stn12)
	{
		trainlist11(stn11,stn12,brp,arp,bkm,akm,d,m);
	}
	else
	{
		trainlist12(stn11,stn12,brp,arp,bkm,akm,d,m);
	}
}
int route2(int d, int m)
{
	int i;
	i=1;
	int stn21,stn22;
	char *brp,*arp;
	int bkm,akm;
	char stnlist[13][25]={"","CAPE\t-\tKANNIYAKUMARI","NCJ\t-\tNAGERCOIL","TEN\t-\tTIRUNELVELI","CVP\t-\tKOVILPATTI","VPT\t-\tVIRUDHUNAGAR","MDU\t-\tMADURAI","DG\t-\tDINDIGUL","TPJ\t-\tTIRUCHCHIRAPPALLI","VM\t-\tVILLUPPURAM","CGL\t-\tCHENGLPATTU","TBM\t-\tTAMBARAM","MS\t-\tCHENNAI EGMORE\n"};
	int km[13]={0,0,16,89,154,202,245,311,405,583,686,716,741};
	printf("LIST OF STATIONS\n");
	printf("\n1.CAPE\t-\tKANNIYAKUMARI\n2.NCJ\t-\tNAGERCOIL\n3.TEN\t-\tTIRUNELVELI\n4.CVP\t-\tKOVILPATTI\n5.VPT\t-\tVIRUDHUNAGAR\n6.MDU\t-\tMADURAI\n7.DG\t-\tDINDIGUL\n8.TPJ\t-\tTIRUCHCHIRAPPALLI\n9.VM\t-\tVILLUPPURAM\n10.CGL\t-\tCHENGLPATTU\n11.TBM\t-\tTAMBARAM\n12.MS\t-\tCHENNAI EGMORE\n");
	while(i)
	{
		printf("\nENTER BOARDING POINT SERIAL NO : ");
		scanf("%d",&stn21);
		{
			if(stn21<0||stn21>12||stn21==0)
			{
				i=1;
				printf("PLEASE ENTER A VALID VALUE");
			}
			else
			{
				i=0;
				printf("\n YOUR BOARDING POINT IS \t\t%s\t KM %d\t",&stnlist[stn21],km[stn21]);
				printf("\n PLEASE ENTER 0 TO PROCEED OR 1 TO RE-ENTER : ");
				scanf("%d",&i);
			}
		}
	}
	i=1;
	while(i)
	{
		printf("\nENTER ARRIVAL POINT SERIAL NO : ");
		scanf("%d",&stn22);
		{
			if(stn22<0||stn22>12||stn22==0)
			{
				i=1;
				printf("PLEASE ENTER A VALID VALUE");

			}
			else if(stn21==stn22)
			{
				i=1;
				printf("PLEASE ENTER A VALID INPUT(ERR : BRD PNT!=ARR PNT)");
			}
			else
			{
				i=0;
				printf("\n YOUR ARRIVAL POINT IS  \t\t%s\t KM %d\t",&stnlist[stn22],km[stn22]);
				printf("\n PLEASE ENTER 0 TO PROCEED OR 1 TO RE-ENTER : ");
				scanf("%d",&i);
			}
		}
	}	
	brp=&stnlist[stn21][0];
	arp=&stnlist[stn22][0];
	bkm=km[stn21];
	akm=km[stn22];
	system("cls");
	if(stn21<stn22)
	{
		trainlist21(stn21,stn22,brp,arp,bkm,akm,d,m);
	}
	else
	{
		trainlist22(stn21,stn22,brp,arp,bkm,akm,d,m);
	}
}
int trainlist11(int brd,int arr,char *brn,char *arn,int bkm,int akm,int d,int m)
{
	char tname[15][30]={"","12696\tTVC MAS SF EXP","22208\tTVC MAS SF EXP","22638\tWEST COAST SF EXP","13352\tALLP DHN EXP","12512\tRAPTISAGAR SF EXP","22640\tALLP MAS EXP","12624\tTVC MAS MAIL","12682\tCBE MAS SF EXP","12672\tNILGIRI EXP","12674\tCHERAN EXP","22652 PGT MAS SF EXP","12625\tTVC NDLS KERALA SF EXP"};
	int check[15]={0};
	int sel;
	char brt[15][1][6];
	char art[15][1][6];
	int index = 0;
	int c=1;
	int k=1;
	int i;
	char valtr[15][30];
	int tno[15][10] = {
		{},
        {0, 1, 0, 3, 4, 5, 6, 7, 8, 9},
        {0, 1, 0, 3, 0, 5, 6, 7, 0, 9},
        {0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
        {0, 1, 0, 3, 4, 5, 6, 7, 8, 0},
        {0, 1, 0, 3, 4, 5, 6, 7, 0, 9},
        {0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
        {0, 1, 0, 3, 0, 5, 6, 7, 0, 9},
        {0, 0, 0, 3, 4, 5, 6, 7, 8, 9},
        {0, 0, 0, 3, 4, 5, 6, 7, 8, 9},
        {0, 0, 0, 3, 4, 5, 6, 7, 8, 9},
        {0, 1, 0, 0, 0, 0, 6, 7, 8, 9},
        {0, 1, 0, 3, 4, 5, 6, 7, 0, 0}
    };
    char time[15][10][6]=
	{
		{},
    	{"","00:40","  :  ","02:00","02:45","03:40","04:35","07:40","08:30","10:00"},
    	{"","01:20","  :  ","02:45","  :  ","04:20","05:10","08:00","  :  ","10:25"},
    	{"","06:00","07:10","07:25","08:10","09:05","10:10","13:20","14:15","15:50"},
    	{"","10:35","  :  ","12:20","13:10","14:00","15:00","18:35","19:35","  :  "},
    	{"","13:50","  :  ","15:25","16:10","17:05","18:00","20:55","  :  ","23:35"},
    	{"","19:50","21:20","21:35","22:20","23:10","00:05","03:05","03:55","05:15"},
    	{"","22:20","  :  ","23:45","  :  ","01:20","02:15","05:10","  :  ","07:45"},
    	{"","  :  ","  :  ","23:30","00:12","00:55","01:50","05:00","06:00","07:35"},
    	{"","  :  ","  :  ","22:25","23:10","23:55","00:55","03:50","04:40","06:25"},
    	{"","  :  ","  :  ","22:50","23:35","00:25","01:20","04:30","05:20","07:00"},
    	{"","16:10","  :  ","  :  ","  :  ","  :  ","22:40","01:45","02:35","04:05"},
    	{"","19:15","  :  ","20:55","21:45","22:35","23:35","03:00","  :  ","  :  "}
	};
for (int i = 1; i <= 13; i++) {
        for (int j = 1; j <= 11; j++) {
            if (tno[i][j] == brd) {
                check[i]++; 
                strcpy(brt[k][0],time[i][j]);
            }
            if (tno[i][j] == arr) {
                check[i]++;
                strcpy(art[k][0], time[i][j]);
                if (check[i] == 2) {
                    int index = 0;
                    while (tname[i][index] != '\0' && index < 29) {
                        valtr[c][index] = tname[i][index];
                        index++;
                    }
                    valtr[c][index] = '\0';
                    c++;
                    k++;
                }
            }
        }
    }
    for (int i = 1; i < c; i++) {
        printf("\n%d.%s", i, valtr[i]);
        printf("\n BRD STN : %s - BRD TIME : %s", brn, brt[i][0]);
        printf("\n ARR STN : %s - ARR TIME : %s ", arn, art[i][0]);
	}
	i=1;
	while(i)
	{
		printf("\nPLEASE ENTER A CHOICE FROM THE ABOVE LIST : ");
		scanf("%d",&sel);
		if(sel==0||sel<0||sel>c-1)
		{
			i=1;
			printf("PLEASE ENTER AN VALID VALUE");
		}
		else
		{
			printf("YOU HAVE SELECTED OPTION %d. \n PLEASE VERIFY THE BELOW PARTICULARS AND FINALIZE THE CHOICE\n",sel);
			printf("\n-----------------------------------------------------------------------------\n");
			printf("%s\n%s\t%s\n%s\t%s",valtr[sel],brn,brt[sel][0],arn,art[sel][0]);
			printf("\n-----------------------------------------------------------------------------");
			printf("\nPRESS 0 TO CONFIRM AND 1 TO RE-ENTER : ");
			scanf("%d",&i);
		}
	}
	char *t,*bt,*at;
	t=&valtr[sel][0];
	bt=&brt[sel][0][0];
	at=&art[sel][0][0];
	finalticket(t,brn,arn,bt,at,bkm,akm,d,m);
}
int trainlist12(int brd,int arr,char *brn,char *arn,int bkm,int akm,int d,int m)
{
	char tname[13][30]={"","12695\tMAS TVC SF EXP","22207\tMAS TVC SF EXP","22637\tWEST COAST SF EXP","13351\tDHN ALLP EXP","12511\tRAPTISAGAR SF EXP","22639\tMAS ALLP EXP","12623\tMAS TVC MAIL","12681\tMAS CBE SF EXP","12671\tNILGIRI EXP","12673\tCHERAN EXP","22651\tMAS PGT SF EXP","12626\tNDLS TVC KERALA SF EXP"};
	int check[13]={0};
	char brt[13][1][6];
	char art[13][1][6];
	int index = 0;
	int c=1;
	int k=1;
	int i,sel;
	char valtr[13][30];
	int tno[13][10] = {
		{},
        {0, 1, 0, 3, 4, 5, 6, 7, 8, 9},
        {0, 1, 0, 3, 0, 5, 6, 7, 0, 9},
        {0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
        {0, 1, 0, 3, 4, 5, 6, 7, 8, 0},
        {0, 1, 0, 3, 4, 5, 6, 7, 0, 9},
        {0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
        {0, 1, 0, 3, 0, 5, 6, 7, 0, 9},
        {0, 0, 0, 3, 4, 5, 6, 7, 8, 9},
        {0, 0, 0, 3, 4, 5, 6, 7, 8, 9},
        {0, 0, 0, 3, 4, 5, 6, 7, 8, 9},
        {0, 1, 0, 0, 0, 0, 6, 7, 8, 9},
        {0, 1, 0, 3, 4, 5, 6, 7, 0, 0}
    };    
	char time[13][10][6]={
    	{},
    	{"","00:30","  :  ","23:15","21:55","21:10","20:05","17:10","16:20","15:20"},
    	{"","00:10","  :  ","23:00","  :  ","21:30","20:30","17:40","  :  ","16:00"},
    	{"","22:55","21:45","21:30","20:35","19:50","18:40","15:25","14:20","13:25"},
    	{"","10:00","  :  ","08:35","07:30","06:45","05:25","01:30","00:40","23:40"},
    	{"","08:00","  :  ","06:50","05:45","05:00","03:55","01:10","  :  ","23:10"},
    	{"","05:20","04:30","04:15","03:20","02:35","01:35","22:45","21:50","20:55"},
    	{"","03:55","  :  ","02:40","  :  ","01:10","00:10","21:30","  :  ","19:45"},
    	{"","  :  ","  :  ","06:30","05:00","04:15","03:20","00:15","23:25","22:30"},
    	{"","  :  ","  :  ","05:20","03:45","03:00","01:50","22:55","22:05","21:05"},
    	{"","  :  ","  :  ","06:00","04:35","03:50","02:50","23:55","22:55","22:00"},
    	{"","09:30","  :  ","  :  ","  :  ","  :  ","02:40","23:40","22:45","21:40"},
    	{"","13:55","  :  ","12:30","11:40","10:55","09:45","06:50","  :  ","  :  "}
	};
	for(int i=1;i<=13;i++)
	{
		for(int j=1;j<=10;j++)
		{
			if(tno[i][j]==arr)
			{
				check[i]++;
				strcpy(art[k][0], time[i][j]);
			}
			if(tno[i][j]==brd)
			{
				check[i]++;
				strcpy(brt[k][0],time[i][j]);
				if(check[i]==2)
		        {	
					int index = 0;
		        	while (tname[i][index] != '\0' && index < 29) 
					{
						valtr[c][index] = tname[i][index];
		                index++;
		            }
		        valtr[c][index] = '\0'; 
				c++;
				k++;
				}
			}
		}
	}
	
	for(int i=1;i<c;i++)
	{		
		printf("\n%d.%s", i, valtr[i]);
        printf("\n BRD STN %s - BRD TIME %s ", brn, brt[i][0]);
        printf("\n ARR STN %s - ARR TIME %s ", arn, art[i][0]);
	}
	
	i=1;
	while(i)
	{
		printf("\nPLEASE ENTER A CHOICE FROM THE ABOVE LIST : ");
		scanf("%d",&sel);
		if(sel==0||sel<0||sel>c-1)
		{
			i=1;
			printf("PLEASE ENTER AN VALID VALUE");
		}
		else
		{
			printf("YOU HAVE SELECTED OPTION %d. \n PLEASE VERIFY THE BELOW PARTICULARS AND FINALIZE THE CHOICE\n",sel);
			printf("\n-----------------------------------------------------------------------------\n");
			printf("%s\n%s\t%s\n%s\t%s",valtr[sel],brn,brt[sel][0],arn,art[sel][0]);
			printf("\n-----------------------------------------------------------------------------");
			printf("\nPRESS 0 TO CONFIRM AND 1 TO RE-ENTER : ");
			scanf("%d",&i);
		}
	}
	
	i=1;
	while(i)
	{
		printf("\nPLEASE ENTER A CHOICE FROM THE ABOVE LIST : ");
		scanf("%d",&sel);
		if(sel==0||sel<0||sel>c-1)
		{
			i=1;
			printf("PLEASE ENTER AN VALID VALUE");
		}
		else
		{
			printf("YOU HAVE SELECTED OPTION %d. \n PLEASE VERIFY THE BELOW PARTICULARS AND FINALIZE THE CHOICE\n",sel);
			printf("\n-----------------------------------------------------------------------------\n");
			printf("%s\n%s\t%s\n%s\t%s",valtr[sel],brn,brt[sel][0],arn,art[sel][0]);
			printf("\n-----------------------------------------------------------------------------");
			printf("\nPRESS 0 TO CONFIRM AND 1 TO RE-ENTER : ");
			scanf("%d",&i);
		}
	}
	char *t,*bt,*at;
	t=&valtr[sel][0];
	bt=&brt[sel][0][0];
	at=&art[sel][0][0];
	finalticket(t,brn,arn,bt,at,bkm,akm,d,m);
}
int trainlist21(int brd,int arr,char *brn,char *arn,int bkm,int akm,int d,int m)
{
	char tname[15][45]={"","12634\tCAPE MS SF EXP","12632\tTEN MS NELLAI SF EXP","12694\tTN MS PEARL CITY SF EXP","12662\tSCT MS POTHIGAI SF EXP","12638\tMDU MS PANDIAN SF EXP","20682\t SCT MS SILAMBU SF EXP","16352\tNCJ CSMT EXP VIA CGL","12641\tCAPE NDLS TIRUKKURAL SF EXP","16354\tNCJ KCG EXP","16787\tTEN SVDK EXP","20636\tQLN MS ANANTHAPURI SF EXP","22658\tNCJ TBM TRI WKLY SF EXP","12668\tNCJ MS WEEKLY","22662\tRMM MS SETHU SF EXP"};
	int check[15]={0};
	int sel;
	char brt[15][1][6];
	char art[15][1][6];
	int index = 0;
	int c=1;
	int k=1;
	int i;
	char valtr[15][30];
	int tno[15][13] = {
		{},
        {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12},//12634
        {0, 0, 0, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12},//12632
        {0, 0, 0, 0, 4, 5, 6, 7, 8, 9, 10, 11, 12},//12694
        {0, 0, 0, 0, 0, 5, 6, 7, 8, 9, 10, 11, 12},//12662
        {0, 0, 0, 0, 0, 0, 6, 7, 8, 9, 10, 11, 12},//12638
        {0, 0, 0, 0, 0, 5, 0, 0, 8, 9, 10, 11, 12},//20682
        {0, 0, 2, 3, 4, 5, 6, 7, 8, 9, 10, 00, 00},//16352
        {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12},//12641
        {0, 0, 2, 3, 4, 5, 6, 7, 8, 0, 00, 00, 00},//16354
        {0, 0, 0, 3, 4, 5, 6, 7, 8, 0, 00, 00, 00},//16787
        {0, 0, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12},//20635
        {0, 0, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 00},//22657
        {0, 0, 2, 3, 0, 5, 6, 7, 8, 9, 10, 00, 12},//12667
        {0, 0, 0, 0, 0, 0, 0, 0, 8, 9, 10, 11, 12}//22661
    };
    char time[15][13][6]=
	{
		{},
    	{"","17:50","18:15","19:35","20:26","21:10","22:10","23:05","00:35","03:25","04:55","05:25","06:30"},
    	{"","  :  ","  :  ","20:05","20:55","21:37","22:25","23:25","01:00","03:55","05:25","05:55","07:00"},
    	{"","  :  ","  :  ","  :  ","21:27","22:10","23:05","00:15","01:35","04:40","06:10","06:40","07:35"},
    	{"","  :  ","  :  ","  :  ","  :  ","20:40","21:35","22:35","23:55","02:50","04:20","04:50","05:40"},
    	{"","  :  ","  :  ","  :  ","  :  ","  :  ","21:20","22:20","23:45","02:30","03:50","04:20","05:10"},
    	{"","  :  ","  :  ","  :  ","  :  ","19:10","  :  ","  :  ","23:35","02:05","03:25","03:55","04:55"},
    	{"","  :  ","06:15","08:00","08:50","09:35","11:00","12:00","13:30","16:15","18:30","  :  ","  :  "},
    	{"","19:10","19:35","21:50","22:42","23:25","00:55","01:55","03:10","05:45","07:10","07:40","08:45"},
    	{"","  :  ","09:15","10 20","11:15","12:05","13:15","14:10","15:20","  :  ","  :  ","  :  ","  :  "},
    	{"","  :  ","  :  ","17:35","18:30","19:20","20:45","21:50","23:10","  :  ","  :  ","  :  ","  :  "},
    	{"","  :  ","17:27","19:05","19:59","20:52","21:55","22:50","00:20","03:05","04:45","05:15","06:10"},
    	{"","  :  ","16:30","18:00","18:45","19:30","21:05","22:05","23:20","01:55","03:15","04:10","  :  "},
    	{"","  :  ","16:30","18:00","  :  ","19:30","21:05","22:05","23:20","01:55","03:15","  :  ","04:35"},
    	{"","  :  ","  :  ","  :  ","  :  ","  :  ","  :  ","  :  ","01:25","04:15","05:35","06:05","07:10"}
	};
for (int i = 1; i <= 15; i++) {
        for (int j = 1; j <= 12; j++) {
            if (tno[i][j] == brd) {
                check[i]++; 
                strcpy(brt[k][0],time[i][j]);
            }
            if (tno[i][j] == arr) {
                check[i]++;
                strcpy(art[k][0], time[i][j]);
                if (check[i] == 2) {
                    int index = 0;
                    while (tname[i][index] != '\0' && index < 29) {
                        valtr[c][index] = tname[i][index];
                        index++;
                    }
                    valtr[c][index] = '\0';
                    c++;
                    k++;
                }
            }
        }
    }
    for (int i = 1; i <c; i++) {
        printf("\n%d.%s", i, valtr[i]);
        printf("\n BRD STN : %s - BRD TIME : %s", brn, brt[i][0]);
        printf("\n ARR STN : %s - ARR TIME : %s ", arn, art[i][0]);
	}
	i=1;
	while(i)
	{
		printf("\nPLEASE ENTER A CHOICE FROM THE ABOVE LIST : ");
		scanf("%d",&sel);
		if(sel==0||sel<0||sel>c-1)
		{
			i=1;
			printf("PLEASE ENTER AN VALID VALUE");
		}
		else
		{
			printf("YOU HAVE SELECTED OPTION %d. \n PLEASE VERIFY THE BELOW PARTICULARS AND FINALIZE THE CHOICE\n",sel);
			printf("\n-----------------------------------------------------------------------------\n");
			printf("%s\n%s\t%s\n%s\t%s",valtr[sel],brn,brt[sel][0],arn,art[sel][0]);
			printf("\n-----------------------------------------------------------------------------");
			printf("\nPRESS 0 TO CONFIRM AND 1 TO RE-ENTER : ");
			scanf("%d",&i);
		}
	}
	char *t,*bt,*at;
	t=&valtr[sel][0];
	bt=&brt[sel][0][0];
	at=&art[sel][0][0];
	finalticket(t,brn,arn,bt,at,bkm,akm,d,m);
}
int trainlist22(int brd,int arr,char *brn,char *arn,int bkm,int akm,int d,int m)
{
	char tname[15][35]={"","12633\tMS CAPE SF EXP","12631\tMS TEN NELLAI SF EXP","12693\tMS TN PEARL CITY SF EXP","12661\tMS SCT POTHIGAI SF EXP","12637\tMS MDU PANDIAN SF EXP","20681\tMS SCT SILAMBU SF EXP","16351\tCSMT NCJ EXP VIA CGL","12642\tNDLS CAPE TIRUKKURAL SF EXP","16353\tKCG NCJ EXP","16788\tTEN SVDK EXP","20635\tMS QLN ANANTHAPURI SF EXP","22657\tTBM NCJ TRI WKLY SF EXP","12667\tMS NCJ WEEKLY","22661\tRMM MS SETHU SF EXP"};
	int check[15]={0};
	char brt[15][1][6];
	char art[15][1][6];
	int index = 0;
	int c=1;
	int k=1;
	int i,sel;
	char valtr[15][30];
	int tno[15][13] = {
		{},
        {0, 1, 2, 3, 0, 5, 6, 7, 8, 9, 10, 11, 12},//12634
        {0, 0, 0, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12},//12632
        {0, 0, 0, 0, 4, 5, 6, 7, 8, 9, 10, 11, 12},//12694
        {0, 0, 0, 0, 0, 5, 6, 7, 8, 9, 10, 11, 12},//12662
        {0, 0, 0, 0, 0, 0, 6, 7, 8, 9, 10, 11, 12},//12638
        {0, 0, 0, 0, 0, 5, 0, 0, 8, 9, 10, 11, 12},//20682
        {0, 0, 2, 3, 4, 5, 6, 7, 8, 9, 10, 00, 00},//16352
        {0, 1, 2, 3, 0, 5, 6, 7, 8, 9, 10, 11, 12},//12641
        {0, 0, 2, 3, 4, 5, 6, 7, 8, 0, 00, 00, 00},//16354
        {0, 0, 0, 3, 4, 5, 6, 7, 8, 0, 00, 00, 00},//16787
        {0, 0, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12},//20635
        {0, 0, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 00},//22657
        {0, 0, 2, 3, 0, 5, 6, 7, 8, 9, 10, 00, 12},//12667
        {0, 0, 0, 0, 0, 0, 0, 0, 8, 9, 10, 11, 12}//22661
    };
    char time[15][13][6]=
	{
		{},
    	{"","05:35","05:00","03:25","  :  ","01:37","01:00","23:40","22:30","20:00","18:20","17:50","17:20"},
    	{"","  :  ","  :  ","06:40","05:06","04:26","03:50","02:40","01:30","22:50","21:10","20:40","20:10"},
    	{"","  :  ","  :  ","  :  ","04:28","03:50","03:10","02:10","00:50","22:15","20:30","20:00","19:30"},
    	{"","  :  ","  :  ","  :  ","  :  ","04:50","04:10","03:00","01:55","23:15","21:40","21:10","20:40"},
    	{"","  :  ","  :  ","  :  ","  :  ","  :  ","05:25","03:55","02:50","00:10","22:40","22:10","21:40"},
    	{"","  :  ","  :  ","  :  ","  :  ","05:20","  :  ","  :  ","01:50","23:00","21:25","20:55","20:25"},
    	{"","  :  ","07:10","05:25","03:50","03:12","02:35","01:35","00:30","21:35","19:35","  :  ","  :  "},
    	{"","04:40","03:35","02:25","  :  ","00:25","23:50","22:35","21:30","18:55","17:20","16:50","16:20"},
    	{"","  :  ","20:30","18:15","16:30","15:50","15:10","13:50","12:40","  :  ","  :  ","  :  ","  :  "},
    	{"","  :  ","  :  ","18:45","16:30","15:50","15:10","13:50","12:40","  :  ","  :  ","  :  ","  :  "},
    	{"","  :  ","07:43","06:10","04:52","04:12","03:25","02:20","01:05","22:30","20:50","20:20","19:50"},
    	{"","  :  ","07:10","05:25","03:50","03:12","02:35","01:35","00:30","21:35","20:00","19:30","  :  "},
    	{"","  :  ","07:10","05:25","03:50","03:12","02:35","01:35","00:30","21:35","20:00","  :  ","18:55"},
    	{"","  :  ","  :  ","  :  ","  :  ","  :  ","  :  ","  :  ","23:25","20:25","18:45","18:15","17:45"}
	};
	for(int i=1;i<=15;i++)
	{
		for(int j=1;j<=15;j++)
		{
			if(tno[i][j]==arr)
			{
				check[i]++;
				strcpy(art[k][0], time[i][j]);
			}
			if(tno[i][j]==brd)
			{
				check[i]++;
				strcpy(brt[k][0],time[i][j]);
				if(check[i]==2)
		        {	
					int index = 0;
		        	while (tname[i][index] != '\0' && index < 29) 
					{
						valtr[c][index] = tname[i][index];
		                index++;
		            }
		        valtr[c][index] = '\0'; 
				c++;
				k++;
				}
			}
		}
	}
	for(int i=1;i<c;i++)
	{		
		printf("\n%d.%s", i, valtr[i]);
        printf("\n BRD STN %s - BRD TIME %s ", brn, brt[i][0]);
        printf("\n ARR STN %s - ARR TIME %s ", arn, art[i][0]);
	}
	
	i=1;
	while(i)
	{
		printf("\nPLEASE ENTER A CHOICE FROM THE ABOVE LIST : ");
		scanf("%d",&sel);
		if(sel==0||sel<0||sel>c-1)
		{
			i=1;
			printf("PLEASE ENTER AN VALID VALUE : ");
		}
		else
		{
			printf("YOU HAVE SELECTED OPTION %d. \n PLEASE VERIFY THE BELOW PARTICULARS AND FINALIZE THE CHOICE\n",sel);
			printf("\n-----------------------------------------------------------------------------\n");
			printf("%s\n%s\t%s\n%s\t%s",valtr[sel],brn,brt[sel][0],arn,art[sel][0]);
			printf("\n-----------------------------------------------------------------------------");
			printf("\nPRESS 0 TO CONFIRM AND 1 TO RE-ENTER : ");
			scanf("%d",&i);
		}
	}
	char *t,*bt,*at;
	t=&valtr[sel][0];
	bt=&brt[sel][0][0];
	at=&art[sel][0][0];
	finalticket(t,brn,arn,bt,at,bkm,akm,d,m);
}
int main()
{
	int r,i;
	i=1;
	int d,m;
	printf("*****************************************************************\n");
	printf("--------WELCOME TO INDIAN RAILWAYS TICKET BOOKING SYSTEM---------\n");
	printf("*****************************************************************\n");
	printf("Please select any one of the route given below\n");
	printf("1.PGT-MAS (PALAKKAD TO CHENNAI CENTRAL)      (VIA PTJ-CBE-TUP-ED-SA-KPD-AJJ)\n");
	printf("2.CAPE-MS (KANNIYAKUMARI TO CHENNAI EGMORE)  (VIA NCJ-TEN-CVP-VPT-MDU-DG-TPJ-VM-CGL-TBM-MS)\n");
	while(i)
	{
		printf("\nPLEASE ENTER YOUR CHOICE : ");
		scanf("\n%d",&r);
		if(r==1)
		{
			i=0;
			printf("YOU HAVE SELECTED ROUTE \nPGT-MAS (PALAKKAD TO CHENNAI CENTRAL)      (VIA PTJ-CBE-TUP-ED-SA-KPD-AJJ)\n PRESS 0 TO PROCEED OR 1 TO RE-ENTER : ");
			scanf("%d",&i);
		}
		if(r==2)
		{
			i=0;
			printf("YOU HAVE SELECTED ROUTE \nCAPE-MS (KANNIYAKUMARI TO CHENNAI EGMORE)  (VIA NCJ-TEN-CVP-VPT-MDU-DG-TPJ-VRI-VM-CGL-TBM-MS)\n PRESS 0 TO PROCEED OR 1 TO RE-ENTER : ");
			scanf("%d",&i);
		}
		if(r!=1 && r!=2)
		{
			printf("PLEASE ENTER A VALID VALUE");
		}
	}
		
	i=1;
	while(i)
	{
		printf("\nENTER THE DATE AND MONTH OF JOURNEY (DD-MM FORMAT) : ");
		scanf("%d%d",&d,&m);
		if(d==0||d>31||d<0)
		{
			printf("PLEASE ENTER A VALID VALUE\n");
			i=1;
		}
		else if(d==31&&(m!=1&&m!=3&&m!=5&&m!=7&&m!=8&&m!=10&&m!=12))
		{
			printf("PLEASE ENTER A VALID VALUE\n");
			i=1;
		}
		else if(d>28&&m==2)
		{
			printf("PLEASE ENTER A VALID VALUE\n");
			i=1;
		}
		else if(m==0||m<0||m>12)
		{
			printf("PLEASE ENTER A VALID VALUE\n");
			i=1;
		}
		else
		{
			printf("YOU HAVE ENTERED %d AS DATE AND %d AS MONTH \nPRESS 0 TO CONFIRM OR 1 TO RE-ENTER : ",d,m);
			i=0;
			scanf("%d",&i);	
		}
	}
	system("cls");
	if(r==1)
	{
		route1(d,m);
	}
	if(r==2)
	{
		route2(d,m);
	}
}
