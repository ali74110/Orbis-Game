#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
////====================Do Not Change This!//==================
char c; //the input character
char joon=3,level=1,adder=0,attr=0,testmode=0;
int point=0,input_count = 0;
short int reset=0,x2=0,x2_2_2=0,x2_2=0,x4=0,x4_4_4=0,x4_4=0,stopflag=0,imhere=0,gameover=0;
 //your main() method will be implemented later

DWORD WINAPI keypress_callback( LPVOID lpParam ){
  while(1) {
	c = getch();
    if(c == 'q')  //press q to exit
      exit(0);
	input_count ++;
  }
  return 0;
}
void starter(){
  HANDLE thread = CreateThread(NULL, 0, keypress_callback, NULL, 0, NULL);
  return;
}
//=======================recallings===================================
void random (char disks[]);
void swup (char disks[]);
void print (char disks[]);
//1=======================functions===================================
void NiceDisplay(char disks[])
{
	int i,t;
	
}
//2===================================================================
void sleeper(){
	if(input_count<20){
	Sleep(200);
	level=1;
	}
	else if(input_count>19 && input_count<40){
		Sleep(100);
		level=2;
		}
	else if(input_count>39 && input_count<60){
		Sleep(70);
		level=3;
		}
	else if(input_count>59 && input_count<80){
		Sleep(50);
		level=4;
		}
	else{
		Sleep(40);
		level=5;
		}
}
//3===================================================================
void EmptyCheck (char disks[])
{
	int i=9,j,m;
	if(disks[0]==' ' && disks[1]==' ' && disks[2]==' ' && disks[3]==' ' && disks[4]==' ' && disks[5]==' ' && disks[6]==' ' && disks[7]==' ' && disks[8]==' ' && disks[9]==' '){
//		for(j=9;j<=5;j--){
		while(i!=5){
				srand(time(0));
    			m=rand()%30+1;
				if(m==1 || (m>10 && m<21) ){
					disks[i]='*';	
				}
				else if(m==2 || (m>20 && m<31)){
					disks[i]='#';
				}
				else if(m==3){
					disks[i]='$';
				}
				else if(m==4){
					disks[i]='+';
				}
				else if(m==5){
					disks[i]='2';
				}
				else if(m==6){
					disks[i]='4';
				}
				else if(m==7){
					disks[i]='?';
				}
				else if(m==8){
					disks[i]='|';
				}
				else if(m==9){
					disks[i]='~';
				}
				else if(m==10){
					disks[i]='=';
				}	
				imhere++;
				i--;
			}
			
		//	print(disks);

		//swup(disks);
	}
}
//4===================================================================
void CheckUnknown (char disks[]){
	int i,m,t;
	for(i=0;i<10;i++){
		if(disks[i]!=' '){
			t=i;
			break;	
		}
	}
	for(i=0;i<10;i++){
			if(disks[t]=='?'){
				srand(time(0)+(i*i));
    			m=rand()%30+1;
				if(m==0 || (m>10 && m<21) ){
					disks[t]='*';	
				}
				else if(m==2 || (m>20 && m<31)){
					disks[t]='#';
				}
				else if(m==3){
					disks[t]='$';
				}
				else if(m==4){
					disks[t]='+';
				}
				else if(m==5){
					disks[t]='2';
				}
				else if(m==6){
					disks[t]='4';
				}
				else if(m==7){
					disks[t]='?';
				}
				else if(m==8){
					disks[t]='|';
				}
				else if(m==9){
					disks[t]='~';
				}
				else if(m==10){
					disks[t]='=';
				}	
				break;
			}
		}
}
//5===================================================================
int calculator (char adder){
	if(x2>0){
		x2++;
		if(x2==4)
			x2=0;
		adder*=2;
		imhere++;
	}
	if(x2_2>0){
		x2_2++;
		if(x2_2==4)
			x2_2=0;
		adder*=2;
	}
	if(x2_2_2>0){
		x2_2_2++;
		if(x2_2_2==4)
			x2_2_2=0;
		adder*=2;
	}
	if(x4>0){
		x4++;
		if(x4==4)
			x4=0;
		adder*=4;
	}
	if(x4_4>0){
		x4_4++;
		if(x4_4==4)
			x4_4=0;
		adder*=4;
	}
	if(x4_4_4>0){
		x4_4_4++;
		if(x4_4_4==4)
			x4_4_4=0;
		adder*=4;
	}
	return adder;
}
//6===================================================================
void GamePlay(char disks[]){
	int k=input_count-1,t,i;
	while(1){
		if(k!=input_count){
			for(i=0;i<10;i++){
			if(disks[i]!=' '){
				t=i;
				break;	
			}
		}
			k++;
		if(c=='m'){
			c=' ';
			if(disks[t]=='#'){
				
				adder++;
				disks[t]=' ';
			}
//*****************************************
			else if(disks[t]=='*'){		
				adder--;	
				disks[t]=' ';
			}
//*****************************************	
			else if(disks[t]=='+'){
				joon++;
				if(joon==4)
				    joon=3;
				disks[t]=' ';
			}
//*****************************************
			else if(disks[t]=='$'){
				disks[t]=' ';
				for(i=0;i<10;i++){
					if(disks[i]!=' '){
						disks[i]='#';
					}
				}	
			}
//*****************************************
			else if(disks[t]=='2'){
				if(x2>0)
					x2_2=1;
				if(x2_2>0)
					x2_2_2=1;
				if(x2==0)	
					x2=1;
				disks[t]=' ';	
			}
//*****************************************			
			else if(disks[t]=='4'){
				if(x4>0)
					x2_2=1;
				if(x4_4>0)
					x4_4_4=1;
				if(x2==0)
					x4=1;
				disks[t]=' ';	
			}
//*****************************************
			else if(disks[t]=='|'){
				stopflag=1;
				disks[t]=' ';	
			}
//****************************************	
			else if(disks[t]=='='){
				if(attr>0)
					attr--;
				disks[t]=' ';	
			}
//*****************************************
			else if(disks[t]=='~'){
				attr++;
				disks[t]=' ';
			}	
		}
//*************************************************		
//*************************************************					
		else if(c=='n'){
			c=' ';
			if(disks[t]=='*'){
				adder++;
				disks[t]=' ';
			}
//*****************************************
			else if(disks[t]=='#'){	
				adder--;	
				disks[t]=' ';
			}
//*****************************************	
			else if(disks[t]=='+'){
				joon++;
				if(joon==4)
				    joon=3;
				disks[t]=' ';
			}
//*****************************************
			else if(disks[t]=='2'){
				if(x2>0)
					x2_2=1;
				if(x2_2>0)
					x2_2_2=1;
				if(x2==0)	
					x2=1;
				disks[t]=' ';	
			}
//*****************************************			
			else if(disks[t]=='4'){
				if(x4>0)
					x2_2=1;
				if(x4_4>0)
					x4_4_4=1;
				if(x2==0)
					x4=1;
				disks[t]=' ';	
			}
//*****************************************
			else if(disks[t]=='$'){
				disks[t]=' ';
				for(i=0;i<10;i++){
					if(disks[i]!=' '){
						disks[i]='*';
							
					}
				}	
			}
//*****************************************
			else if(disks[t]=='|'){
				stopflag=1;
				disks[t]=' ';	
			}
//****************************************	
			else if(disks[t]=='='){
				if(attr>0)
					attr--;
				disks[t]=' ';	
			}
//*****************************************
			else if(disks[t]=='~'){
				attr++;				
				disks[t]=' ';
			}
		}		
//*****************************************				
		else if(c=='s'){
		c=' ';	
		sleep(5);
		}
	}
	else
		break;
	}
point+=calculator(adder);
adder=0;
}
//7===================================================================
void attractive(char disks[]){
	int i;
	for(i=0;i<10;i++){
		if(disks[i]!=' '){
			if(disks[i]=='*' || disks[i]=='#'){
			disks[i]=' ';
			adder++;
			}
			else if(disks[i]=='+'){
				joon++;
				if(joon==4)
				    joon=3;
				disks[i]=' ';
			}
			else if(disks[i]=='$'){
				disks[i]=' ';
				for(i=0;i<10;i++){
					if(disks[i]!=' '){
						disks[i]='#';
					}
				}	
			}
			else if(disks[i]=='2'){
				if(x2>0)
					x2_2=1;
				if(x2_2>0)
					x2_2_2=1;
				if(x2==0)	
					x2=1;
				disks[i]=' ';	
			}
			else if(disks[i]=='4'){
				if(x4>0)
					x2_2=1;
				if(x4_4>0)
					x4_4_4=1;
				if(x2==0)
					x4=1;
				disks[i]=' ';	
			}
			else if(disks[i]=='='){
				attr--;
				disks[i]=' ';	
				break;
			}
			else if(disks[i]=='~'){
				attr++;
				disks[i]=' ';
			}
			else if(disks[i]=='|'){
				disks[i]=' ';	
			}
			point+=calculator(adder);
			adder=0;
            print(disks);
			Sleep(500);
		}
	}
}
//8===================================================================
void finish (char disks[]){
	if(disks[0]!=' ' && disks[1]!=' ' && disks[2]!=' ' && disks[3]!=' ' && disks[4]!=' ' && disks[5]!=' ' && disks[6]!=' ' && disks[7]!=' ' && disks[8]!=' ' && disks[9]!=' ' )	{
	joon--;
	printf("\nattempts:%d\n",joon);
	reset=1;
	input_count=1;
	}
	if(joon==0){
		print(disks);
		printf("\nGame Over\n");
		gameover=1;
		sleep(1);
	}
}
//9===================================================================
void random(char disks[]){
int i,m;
i=9;
		srand(time(0));
    	m=rand()%50+1;
		if(m==1 || (m>16 && m<24) ||(m>23 && m<30) ||(m>40 && m<46)){
			disks[i]='*';	
		}
		else if(m==2 || (m>29 && m<37)|| (m>10 && m<17) || (m>45 && m<51)){
			disks[i]='#';
		}
		else if(m==3 || m==37){
			disks[i]='$';
		}
		else if(m==4){
			disks[i]='+';
		}
		else if(m==5){
			disks[i]='2';
		}
		else if(m==6){
			disks[i]='4';
		}
		else if(m==7|| m==40){
			disks[i]='?';
		}
		else if(m==8){
			disks[i]='|';
		}
		else if(m==9){
			disks[i]='~';
		}
		else if(m==10 || m==38 || m==39 ){
			disks[i]='=';
		}
}
//10===================================================================
void swup(char disks[]){
	int i , d;
	for(i=0;i<10;i++)
		if(disks[i]!=' ')
			disks[i-1]=disks[i];
	disks[9]=' ';
}
//11===================================================================
void print(char disks[])
{
	system("cls");
	int i=0;
	printf("                    <<<<   Orbis   >>>>                \n");
	printf("    ___________________________________________________\n");
	for(i=0;i<10;++i){
		printf("     |                   *  ");
		printf("%c%c",disks[i],disks[i]);
		printf("  #                     |");
		printf("\n");	
	}
	printf("    ___________________________________________________\n");
	printf("      level=%d , attempts:%d , points:%d , Quit: press q\n",level,joon,point,imhere);
}
//112===================================================================
void runner(char disks[]){
	GamePlay(disks);
	CheckUnknown(disks);
	EmptyCheck(disks);
	print(disks);

	sleeper();
	GamePlay(disks);
	CheckUnknown(disks);
	EmptyCheck(disks);
	print(disks);
	
	sleeper();
	GamePlay(disks);
	CheckUnknown(disks);
	EmptyCheck(disks);
	print(disks);
	
	sleeper();
	GamePlay(disks);
	CheckUnknown(disks);
	EmptyCheck(disks);
	print(disks);
	
	sleeper();
	GamePlay(disks);
	CheckUnknown(disks);
	EmptyCheck(disks);
	print(disks);
}
//13===================================================================
void test(){
	system("cls");
	printf("\n\n                  <<<<   Orbis   >>>>\n");
	printf("               --> this is test mode <--  \n\n");
	printf("              please Enter Your Characters\n (type characters continualy then type spaces up to 10):\n");
	int i=9,j;
	char tdisks[10],m;
	while(i>=0 && tdisks[i+1]!='\r'){
		//scanf("%c",&tdisks[i]);
		tdisks[i]=getche();
		//if(m=='\r')
		//	break;
		i--;
	}
	for(j=0;j<i+1;j++)
		tdisks[j]=' ';
	starter();
	while(1){
		if(attr==0){
			sleep(1);
			GamePlay(tdisks);
			CheckUnknown(tdisks);
			print(tdisks);
		}
		else if(attr>0){
			sleep(1);
			GamePlay(tdisks);
			CheckUnknown(tdisks);
			attractive(tdisks);
			print(tdisks);
		}
		if(tdisks[0]==' ' && tdisks[1]==' ' && tdisks[2]==' ' && tdisks[3]==' ' && tdisks[4]==' ' && tdisks[5]==' ' && tdisks[6]==' ' && tdisks[7]==' ' && tdisks[8]==' ' && tdisks[9]==' ' )	{
			printf("\ntest Over\n");
			sleep(1);
			system("cls");
			printf("\nWait...\n");
			sleep(1);
			system("cls");
			break;
		}
	}
	
}
//14===================================================================
void menu(){
		while(1){
	int SelectedButton2,SelectedButton3,SelectedButton;
	aval:
	system("cls");
	printf("                Welcome to : \n");
	printf("            <<<<   Orbis   >>>>\n\n");
	printf("                 $ MENU $\n\n");
	printf("               1. test\n");
	printf("               2. Start\n");
	printf("               3. How To Play\n");
	printf("               4. Help\n");
	printf("               5. Last Score\n");
	printf("               6. Exit\n");
	printf("Enter a Number\n");
	shomare4:
	scanf("%d",&SelectedButton);
	
	if(SelectedButton==1){
		sleep(1);
		system("cls");
		printf("\nWait...\n");
		sleep(1);
		testmode=1;
		break;
	}
	else if(SelectedButton==2){
		system("cls");
		printf("\n\n\n\n\n                        --> 3 <--");
		sleep(1);
		system("cls");
		printf("\n\n\n\n\n                        --> 2 <--");
		sleep(1);
		system("cls");
		printf("\n\n\n\n\n                        --> 1 <--");
		sleep(1);
		break;
	}
	else if(SelectedButton==3){
		how:
		sleep(1);
		system("cls");
		printf("\n\n              <<<<   Orbis   >>>>\n");
		printf("\n\n\n\n              Right    : ' m ' Key\n");
		printf("              Left     : ' n ' Key\n");
		printf("              Pause 5s : ' s ' Key\n\n\n");
		printf(" Back : Enter b                         start : Enter s\n");
		scanf("%c",&SelectedButton2);
		if(SelectedButton2=='b')
			goto aval;
		else if(SelectedButton2=='s')
			break;
		else
			goto how;	
	}
	else if(SelectedButton==4){
		help:
		system("cls");
		printf("\n\n                <<<<   Orbis   >>>>\n");
		printf("\n        randomly from downside disks come and \n        you should send them to the right side.\n");
		printf("\n        *:by leveling up speed wil increase.\n");
		printf("\n                     < disks >");
		printf("\n              disk   |   : pause disk");
		printf("\n              disk   $   : all changer disk");
		printf("\n              disk   ?   : Unknown disk");
		printf("\n              disk   2   : x2 disk");
		printf("\n              disk   4   : x4 disk");
		printf("\n              disk   ~   : attractive disk");
		printf("\n              disk   =   : disattractive disk");
		printf("\n              disk   +   : plus attemps disk");
		printf("\n              disk * & # : Usual disks");
		printf("\n\n Back : Enter b                         start : Enter s\n");
		scanf("%c",&SelectedButton3);
		if(SelectedButton3=='b')
			goto aval;
		else if(SelectedButton3=='s')
			break;
		else
			goto help;
	}
	else if(SelectedButton==5){
		printf("No Records Yet           Let's Play! --> press 1\n\n");
		printf("Enter Another Number\n");
		goto shomare4;
	}
	else if(SelectedButton==6)
		exit(0);	
	system("cls");
	}
}
//15===================================================================
int main() {
	char disks[10]={ ' '  ,  ' '  ,  ' '  ,  ' '  ,  ' '  ,  ' '  ,  ' '  ,  ' '  ,  ' '  ,  ' ' };
	int i;
	home:
	menu();
	if(testmode==1){
		test();
		goto home;
	}
	starter();
	while (1){
		if(attr==0){
			swup(disks);
			random(disks);
			EmptyCheck(disks);
			if(reset==1){
				for(i=0;i<10;++i)
					disks[i]=' ';
				reset=0;
				level=1;
				continue;
			}
			runner(disks);
			int j=0;		
			while(stopflag==1){
				j++;
				runner(disks);
				if(j==3){
					j=0;
					stopflag=0;
					break;
				}
			}
		}
		else if(attr>0){
			swup(disks);
			random(disks);
			EmptyCheck(disks);
			print(disks);
			sleeper();
			CheckUnknown(disks);
			attractive(disks);
		}
		finish(disks);
		if(gameover==1){
			gameover=0;
			goto home;
		}
	}
}
//===================================================================
