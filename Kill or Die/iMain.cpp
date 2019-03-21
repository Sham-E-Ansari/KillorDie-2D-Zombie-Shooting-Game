# include "iGraphics.h"
int x=50,y=100,start=0,z=0,playerNum=0;
int mode=0,namelen,count_down=5,countTime;
int name_box_col1,name_box_col2,name_box_col3,time_out=0 ;
char tempName[100];
int bullet_x=x+100,bullet_y=y+160,bullet_time,bullet_mode=0;
int mouse_pos_x,mouse_pos_y;
int rand1=0,rand2=0,rand3=0;
int z1_flag=0,z2_flag=0,man1_flag=0,man2_flag=0;
int total_time=121,game_time;
char shoting_time[100]="120";
int option_pos_x,option_pos_y;
int z1_x=1300,z1_y=400,z1_time;
int z2_x=1300,z2_y=200,z2_time;
int man1_x=1300,man1_y=100,man1_time;
int man2_x=1300,man2_y=300,man2_time;
int count=0,z1_pos=0,z2_pos=0,man1_pos=0,man2_pos=0;
char score[1000]="0";
char countdown[10]="5";
int op_1_c1=64,op_1_c2=128,op_1_c3=128;
int op_2_c1=64,op_2_c2=128,op_2_c3=128;
int op_3_c1=64,op_3_c2=128,op_3_c3=128;
int op_4_c1=64,op_4_c2=128,op_4_c3=128;
int op_5_c1=64,op_5_c2=128,op_5_c3=128;
int op_6_c1=64,op_6_c2=128,op_6_c3=128;
int bulletflag = 12;
struct playerNameScore{
	char name[50];
	int score;
}player[1000000],temp;

void reload()
{
	if(bulletflag==12)
	{
		iShowBMPWOBGWP(10,10,"bullets.bmp",16777215);
		iShowBMPWOBGWP(20,10,"bullets.bmp",16777215);
		iShowBMPWOBGWP(30,10,"bullets.bmp",16777215);
		iShowBMPWOBGWP(40,10,"bullets.bmp",16777215);
		iShowBMPWOBGWP(50,10,"bullets.bmp",16777215);
		iShowBMPWOBGWP(60,10,"bullets.bmp",16777215);
		iShowBMPWOBGWP(70,10,"bullets.bmp",16777215);
		iShowBMPWOBGWP(80,10,"bullets.bmp",16777215);
		iShowBMPWOBGWP(90,10,"bullets.bmp",16777215);
		iShowBMPWOBGWP(100,10,"bullets.bmp",16777215);
		iShowBMPWOBGWP(110,10,"bullets.bmp",16777215);
		iShowBMPWOBGWP(120,10,"bullets.bmp",16777215);

	}



}
void HomePage()
{
		iShowBMP(0,0,"Home.bmp");
		iSetColor(op_1_c1,op_1_c2,op_1_c3);
		iFilledRectangle(130,340,220,32);
		iSetColor(255,0,0);
		iText(190,350, "Start Game", GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(op_2_c1,op_2_c2,op_2_c3);
		iFilledRectangle(130,270,220,32);
		iSetColor(255,0,0);
		iText(180,280, "How To Play", GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(op_3_c1,op_3_c2,op_3_c3);
		iFilledRectangle(130,200,220,32);
		iSetColor(255,0,0);
		iText(180,210, "High Scores", GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(op_4_c1,op_4_c2,op_4_c3);
		iFilledRectangle(130,130,220,32);
		iSetColor(255,0,0);
		iText(190,140, "Exit Game", GLUT_BITMAP_TIMES_ROMAN_24);
}

void nameBox()
{
	iSetColor(name_box_col1,name_box_col2,name_box_col3);
	iText(320,400,"Enter Your Name",GLUT_BITMAP_TIMES_ROMAN_24);
	iRectangle(250,350,300,30);
	iSetColor(100,100,100);
	iText(230, 300, "Click to activate the box, enter to finish.");
}

void gameWindow()
{
	FILE *fp;
	int hscore=0;
	char highScore[100];
	char name[100];
	
	fp=fopen("finalscore.txt","r");
	fscanf(fp,"%s %d",&name,&hscore);
	sprintf(highScore,"%d",hscore);
	fclose(fp);
	
	iShowBMP(0,0,"bg.bmp");
	iShowBMPWOBGWP(bullet_x,bullet_y,"bullet.bmp",16777215);
	iShowBMPWOBGWP(x,y,"ss.bmp",16777215);
	//iShowBMPWOBGWP(z1_x,z1_y,"zom1.1.bmp",000000);
	//iShowBMPWOBGWP(z2_x,z2_y,"zom2.1.bmp",000000);
	iSetColor(255,255,255);
	iText(580,680,"Time: ",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(640,680,shoting_time,GLUT_BITMAP_TIMES_ROMAN_24);
	iText(1085,680,"Score: ",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(1150,680,score,GLUT_BITMAP_TIMES_ROMAN_24);
	iText(50,680,"High Score: ",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(180,680,highScore,GLUT_BITMAP_TIMES_ROMAN_24);
	
}

void timeOut()
{
	iShowBMP(0,0,"bg.bmp");
	iSetColor(255,255,255);
	iText(580,680,"Time: ",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(640,680,shoting_time,GLUT_BITMAP_TIMES_ROMAN_24);
	iText(1085,680,"Score: ",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(1150,682,score,GLUT_BITMAP_TIMES_ROMAN_24);
	iText(640,360,"Time Out",GLUT_BITMAP_TIMES_ROMAN_24);
}

void shooterPosition(int x1, int y1)
{
	if(y1>200)
	{
		y1=200;
	}
	if(x1>200)
	{
		x=200;
	}
}

void highscorePage()
{
	FILE *fp;
	int i,y=350,val;
	char name[100],score[100];
	iShowBMP(0,0,"highscore.bmp");
	iSetColor(op_5_c1,op_5_c2,op_5_c3);
	iFilledRectangle(1160,50,100,40);
	iSetColor(255,0,0);
	iText(1180,60,"BACK",GLUT_BITMAP_TIMES_ROMAN_24);
	fp=fopen("finalscore.txt","r");
	if((fscanf(fp,"%s %d",&name,&val))==EOF)
	{
		iSetColor(255,255,255);
		iText(250,450,"You Are 1st Player",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else
	{
		iSetColor(255,255,255);
		if(playerNum>5)
		{
			for(i=0;i<5;i++)
			{
				//while((fscanf(fp,"%s %d",&name,&val))!=EOF)
				//{
					fscanf(fp,"%s %d",&name,&val);
					sprintf(score,"%d",val);
					iText(100,y,name,GLUT_BITMAP_TIMES_ROMAN_24);
					iText(550,y,score,GLUT_BITMAP_TIMES_ROMAN_24);
					y-=50;
				//}
			}
		}
		else
		{
			for(i=0;i<playerNum;i++)
			{
				//while((fscanf(fp,"%s %d",&name,&val))!=EOF)
				//{
					fscanf(fp,"%s %d",&name,&val);
					sprintf(score,"%d",val);
					iText(100,y,name,GLUT_BITMAP_TIMES_ROMAN_24);
					iText(550,y,score,GLUT_BITMAP_TIMES_ROMAN_24);
					y-=50;
				//}
			}
		}
	}
	fclose(fp);
}

void instruction()
{
	iShowBMP(0,0,"instruction.bmp");
	iSetColor(op_6_c1,op_6_c2,op_6_c3);
	iFilledRectangle(1160,50,100,40);
	iSetColor(255,0,0);
	iText(1180,60,"BACK",GLUT_BITMAP_TIMES_ROMAN_24);
}

void iDraw()
{
	iClear();
	if(start==0)
	{
		HomePage();
		
	}
	else if(start==1)
	{
		int i=0;
		iShowBMP(0,0,"bg.bmp");
		iSetColor(255,255,255);
		iText(640,360,countdown,GLUT_BITMAP_TIMES_ROMAN_24);
	}
	
	/*if(start==1)
	{
		iShowBMP(0,0,"Home.bmp");
		nameBox();
		if(mode == 1)
		{
			iSetColor(255, 255, 255);
			iText(255,360,tempName);
		}
	}*/
	else if(start==2)
	{
		gameWindow();
		if(rand1==0)
		{
			if(z1_flag==0){iShowBMPWOBGWP(z1_x,z1_y,"zom1.1.bmp",000000);}
			else if(z1_flag==1){iShowBMPWOBGWP(z1_x,z1_y,"zom1.2.bmp",000000);}
			else if(z1_flag==2){iShowBMPWOBGWP(z1_x,z1_y,"zom1.2.bmp",000000);}
			else if(z1_flag==3){iShowBMPWOBGWP(z1_x,z1_y,"zom1.3.bmp",000000);}
			else if(z1_flag==4){iShowBMPWOBGWP(z1_x,z1_y,"zom1.3.bmp",000000);}
			else if(z1_flag==5){iShowBMPWOBGWP(z1_x,z1_y,"zom1.1.bmp",000000);}
		}
		else if(rand1==1)
		{
			if(z1_flag==0){iShowBMPWOBGWP(z1_x,z1_y,"zom2.1.bmp",000000);}
			else if(z1_flag==1){iShowBMPWOBGWP(z1_x,z1_y,"zom2.2.bmp",000000);}
			else if(z1_flag==2){iShowBMPWOBGWP(z1_x,z1_y,"zom2.3.bmp",000000);}
			else if(z1_flag==3){iShowBMPWOBGWP(z1_x,z1_y,"zom2.4.bmp",000000);}
			else if(z1_flag==4){iShowBMPWOBGWP(z1_x,z1_y,"zom2.5.bmp",000000);}
			else if(z1_flag==5){iShowBMPWOBGWP(z1_x,z1_y,"zom2.6.bmp",000000);}
		}
		else if(rand1==2)
		{
			if(z1_flag==0){iShowBMPWOBGWP(z1_x,z1_y,"zom1.1.bmp",000000);}
			else if(z1_flag==1){iShowBMPWOBGWP(z1_x,z1_y,"zom1.2.bmp",000000);}
			else if(z1_flag==2){iShowBMPWOBGWP(z1_x,z1_y,"zom1.2.bmp",000000);}
			else if(z1_flag==3){iShowBMPWOBGWP(z1_x,z1_y,"zom1.3.bmp",000000);}
			else if(z1_flag==4){iShowBMPWOBGWP(z1_x,z1_y,"zom1.3.bmp",000000);}
			else if(z1_flag==5){iShowBMPWOBGWP(z1_x,z1_y,"zom1.1.bmp",000000);}
		}
		if(rand2==0)
		{
			if(z2_flag==0){iShowBMPWOBGWP(z2_x,z2_y,"zom2.1.bmp",000000);}
			else if(z2_flag==1){iShowBMPWOBGWP(z2_x,z2_y,"zom2.2.bmp",000000);}
			else if(z2_flag==2){iShowBMPWOBGWP(z2_x,z2_y,"zom2.3.bmp",000000);}
			else if(z2_flag==3){iShowBMPWOBGWP(z2_x,z2_y,"zom2.4.bmp",000000);}
			else if(z2_flag==4){iShowBMPWOBGWP(z2_x,z2_y,"zom2.5.bmp",000000);}
			else if(z2_flag==5){iShowBMPWOBGWP(z2_x,z2_y,"zom2.6.bmp",000000);}
		}
		else if(rand2==1)
		{
			if(z2_flag==0){iShowBMPWOBGWP(z2_x,z2_y,"zom1.1.bmp",000000);}
			else if(z2_flag==1){iShowBMPWOBGWP(z2_x,z2_y,"zom1.2.bmp",000000);}
			else if(z2_flag==2){iShowBMPWOBGWP(z2_x,z2_y,"zom1.2.bmp",000000);}
			else if(z2_flag==3){iShowBMPWOBGWP(z2_x,z2_y,"zom1.3.bmp",000000);}
			else if(z2_flag==4){iShowBMPWOBGWP(z2_x,z2_y,"zom1.3.bmp",000000);}
			else if(z2_flag==5){iShowBMPWOBGWP(z2_x,z2_y,"zom1.1.bmp",000000);}
		}
		else if(rand2==2)
		{
			if(z2_flag==0){iShowBMPWOBGWP(z2_x,z2_y,"zom2.1.bmp",000000);}
			else if(z2_flag==1){iShowBMPWOBGWP(z2_x,z2_y,"zom2.2.bmp",000000);}
			else if(z2_flag==2){iShowBMPWOBGWP(z2_x,z2_y,"zom2.3.bmp",000000);}
			else if(z2_flag==3){iShowBMPWOBGWP(z2_x,z2_y,"zom2.4.bmp",000000);}
			else if(z2_flag==4){iShowBMPWOBGWP(z2_x,z2_y,"zom2.5.bmp",000000);}
			else if(z2_flag==5){iShowBMPWOBGWP(z2_x,z2_y,"zom2.6.bmp",000000);}
		}
		if(man1_flag==0){iShowBMPWOBGWP(man1_x,man1_y,"man1.1.bmp",000000);}
		else if(man1_flag==1){iShowBMPWOBGWP(man1_x,man1_y,"man1.3.bmp",000000);}
		else if(man1_flag==2){iShowBMPWOBGWP(man1_x,man1_y,"man1.3.bmp",000000);}
		else if(man1_flag==3){iShowBMPWOBGWP(man1_x,man1_y,"man1.4.bmp",000000);}
		else if(man1_flag==4){iShowBMPWOBGWP(man1_x,man1_y,"man1.4.bmp",000000);}
		else if(man1_flag==5){iShowBMPWOBGWP(man1_x,man1_y,"man1.5.bmp",000000);}

		if(man2_flag==0){iShowBMPWOBGWP(man2_x,man2_y,"man1.1.bmp",000000);}
		else if(man2_flag==1){iShowBMPWOBGWP(man2_x,man2_y,"man1.3.bmp",000000);}
		else if(man2_flag==2){iShowBMPWOBGWP(man2_x,man2_y,"man1.3.bmp",000000);}
		else if(man2_flag==3){iShowBMPWOBGWP(man2_x,man2_y,"man1.4.bmp",000000);}
		else if(man2_flag==4){iShowBMPWOBGWP(man2_x,man2_y,"man1.4.bmp",000000);}
		else if(man2_flag==5){iShowBMPWOBGWP(man2_x,man2_y,"man1.5.bmp",000000);}
	}
	else if(start==3)
	{
		timeOut();
		nameBox();
		if(mode == 1)
		{
			iSetColor(255, 255, 255);
			iText(255,360,tempName);
		}
	}
	
	else if(start==4)
	{
		instruction();
	}

	else if(start==5)
	{
		highscorePage();
	}
	
}

void iPassiveMouseMove(int mx,int my)
{
	x=mx; y=my;
	if(mx>=130 && mx<=350 && my>=340 && my<=372 &&start==0)
		{op_1_c1=128;op_1_c2=128;op_1_c3=128;PlaySound("mClick",NULL,SND_ASYNC);}
	else
		{op_1_c1=64;op_1_c2=128;op_1_c3=128;}

	if(mx>=130 && mx<=350 && my>=270 && my<=302 &&start==0)
		{op_2_c1=128;op_2_c2=128;op_2_c3=128;PlaySound("mClick",NULL,SND_ASYNC);}
	else
		{op_2_c1=64;op_2_c2=128;op_2_c3=128;}

	if(mx>=130 && mx<=350 && my>=200 && my<=232 &&start==0)
		{op_3_c1=128;op_3_c2=128;op_3_c3=128;PlaySound("mClick",NULL,SND_ASYNC);}
	else
		{op_3_c1=64;op_3_c2=128;op_3_c3=128;}

	if(mx>=130 && mx<=350 && my>=130 && my<=162 &&start==0)
		{op_4_c1=128;op_4_c2=128;op_4_c3=128;PlaySound("mClick",NULL,SND_ASYNC);}
	else
		{op_4_c1=64;op_4_c2=128;op_4_c3=128;}
	if(mx>=1160 && mx<=1260 && my>=48 && my<=88 &&start==4)
		{op_6_c1=128;op_6_c2=128;op_6_c3=128;PlaySound("mClick",NULL,SND_ASYNC);}
	else
		{op_6_c1=64;op_6_c2=128;op_6_c3=128;}

	if(mx>=1160 && mx<=1260 && my>=48 && my<=88 &&start==5)
		{op_5_c1=128;op_5_c2=128;op_5_c3=128;PlaySound("mClick",NULL,SND_ASYNC);}
	else
		{op_5_c1=64;op_5_c2=128;op_5_c3=128;}

	if(x>200)
		x=200;
	if(y>300)
		y=300;
	if(y<50)
		y=50;
	bullet_x=x+100;
	bullet_y=y+160;
}

void iMouseMove(int mx, int my)
{
	
}

void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if(mx>=52 && mx<=450 && my>=332 && my<=390 &&start==0)
			{
				start=1; 
				PlaySound("ctd",NULL,SND_ASYNC);
				iResumeTimer(countTime);
			}
		else if(mx>=252 && mx<=548 && my>=348 && my<=378 && start==3)
			{
				mode=1;
				name_box_col1=255; name_box_col2=255; name_box_col3=255;
			}
		if(bullet_time)
			{
				iResumeTimer(bullet_time);
				PlaySound("bulletSound",NULL,SND_ASYNC);
				bulletflag--;
			}
		if(mx>=130 && mx<=350 && my>=270 && my<=302 &&start==0)
			{
				start=4;
			}
		else if(mx>=130 && mx<=350 && my>=210 && my<=282 &&start==0)
			{
				start=5;
			}
		else if(mx>=1162 && mx<=1258 && my>=52 && my<=98 &&start==4)
			{
				start=0;
			}
		else if(mx>=1162 && mx<=1258 && my>=52 && my<=98 &&start==5)
			{
				start=0;
			}
		else if(mx>=132 && mx<=350 && my>=132 && my<=160 && start==0)
		{
			exit(0);
		}
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN && start == 2)
	{
		bulletflag = 12;
	}
}

void intialAllVar()
{
	int i;
	mode = 0; 
	total_time=121; 
	count_down=5; 
	start=0;
	man1_x=1300;man1_y=100;
	man2_x=1300;man2_y=300;
	man1_flag=0;man2_flag=0;
	z1_flag=0;z2_flag=0;
	z1_x=1300;z1_y=400;
	z2_x=1300;z2_y=200;
	x=50;y=100;
	iPauseTimer(z1_time);
	iPauseTimer(z2_time);
	iPauseTimer(countTime);
	iPauseTimer(bullet_time);
	iPauseTimer(game_time);
	count=0;
	z1_pos=0;z2_pos=0;
	strcpy(score,"0");
	strcpy(countdown,"5");
	for(i = 0; i < namelen; i++)
		tempName[i] = 0;
	namelen = 0;
}

void writeAfterSort(int n)
{
	int i;
	FILE *fp;
	fp=fopen("finalscore.txt","w");
	if(n>5)
	{
		for(i=0;i<5;i++)
		{
			fprintf(fp,"%s\t%d\n",player[i].name,player[i].score);
		}
	}
	else
	{
		for(i=0;i<n;i++)
		{
			fprintf(fp,"%s\t%d\n",player[i].name,player[i].score);
		}
	}
	fclose(fp);
}

void scoreSort()
{
	FILE *fp;
	int i=0,j,k;
	fp=fopen("playerNameList.txt","r");
	while((fscanf(fp,"%s %d",&player[i].name,&player[i].score))!=EOF)
		i++;
	playerNum=i;
	fclose(fp);
	for(j=0;j<(i-1);j++)
	{
		for(k=j+1;k<i;k++)
		{
			if(player[k].score>player[j].score)
			{
				temp=player[j];
				player[j]=player[k];
				player[k]=temp;
			}
		}
	}
	writeAfterSort(i);
}

void iKeyboard(unsigned char key)
{
	FILE *fp;
	if(mode == 1)
	{
		if(key == '\r')
		{
			name_box_col1=100; name_box_col2=100; name_box_col3=100;
			//strcpy(player[playerNum].name, tempName);
			fp = fopen("playerNameList.txt","a");
				fprintf(fp,"%s\t%d\n",tempName,count);
			fclose(fp);
			playerNum++;
			intialAllVar();
			scoreSort();
			//iResumeTimer(z1_time);
			//iResumeTimer(z2_time);
		}
		else if(key == 8)
		{
			namelen--;
			tempName[namelen] = 0;
		}
		else
		{
			
			tempName[namelen] = key;
			namelen++;
			
		}
	}
}

void iSpecialKeyboard(unsigned char key)
{
	if(key == GLUT_KEY_END)
	{
		exit(0);	
	}
}

void showTime()
{
	total_time--;
	sprintf(shoting_time,"%d",total_time);
	if(total_time==0) 
	{
		iPauseTimer(game_time);
		iPauseTimer(z1_time);
		iPauseTimer(z2_time);
		iPauseTimer(man1_time);
		iPauseTimer(man2_time);
		iPauseTimer(bullet_time);
		bullet_mode=0;
		start=3;
	}
}

void bullet()
{
	bullet_x+=150;
	if(bullet_x>1280) 
		{
			bullet_mode=1;
			bullet_x=x+100;
			bullet_y=y+160;
			iPauseTimer(bullet_time);
		}
}

void z1Change()
{
	z1_x-=1;
	int f=0;
	if(bullet_x>(z1_x+10) && bullet_x<(z1_x+100) && bullet_y>z1_y && bullet_y<(z1_y+200))
		{
			count++;
			sprintf(score,"%d",count);
			z1_x=1300;z1_y=400;
			if(z1_pos==0)
				{z1_y=300;z1_pos=1;}
			else
				{z1_y=400;z1_pos=0;}
			 bullet_x=x+100;bullet_y=y+160;
			 iPauseTimer(bullet_time);
			 rand1=rand()%3;
			 //rand2=rand()%3;
		}
	if(z1_x<0)
		{z1_x=1300;rand1=rand()%3;}
	z1_flag++;
	if(z1_flag>5)
		z1_flag=0;
}

void z2Change()
{
	z2_x-=1;
	if(bullet_x>(z2_x+10) && bullet_x<(z2_x+100) && bullet_y>z2_y && bullet_y<(z2_y+200))
		{
			count++;
			sprintf(score,"%d",count);
			//player[playerNum].score=count;
			z2_x=1300;
			if(z2_pos==0)
				{z2_pos=1;z2_y=100;}
			else
				{z2_pos=0;z2_y=200;}
			 bullet_x=x+100;bullet_y=y+160;
			 iPauseTimer(bullet_time);
			 //rand1=rand()%3;
			 rand2=rand()%3;
		}
	if(z2_x<0)
		{z2_x=1300;rand2=rand()%3;}
	z2_flag++;
	if(z2_flag>5)
		z2_flag=0;
}

void manChange1()
{
	man1_x-=5;
	if(bullet_x>(man1_x+10) && bullet_x<(man1_x+150) && bullet_y>man1_y && bullet_y<(man1_y+150))
	{
		total_time-=5;
		count-=2;
		if(count<0)
		{strcpy(score,"0");count=0;}
		else
			sprintf(score,"%d",count);
		bullet_x=x+100;bullet_y=y+160;
		man1_x=1300;
		man1_pos++;
		if(man1_pos>2)
			man1_pos=0;
		if(total_time<=0) 
		{
			iPauseTimer(game_time);
			iPauseTimer(z1_time);
			iPauseTimer(z2_time);
			iPauseTimer(man1_time);
			iPauseTimer(bullet_time);
			bullet_mode=0;
			start=3;
		}
		
	}
	man1_flag++;
	if(man1_x<0)
	{
		man1_x=1300;
		man1_pos++;
		if(man1_pos>2)
			man1_pos=0;
	}
	if(man1_flag>5)
		man1_flag=0;
	if(man1_pos==0)
		man1_y=100;
	else if(man1_pos==1)
		man1_y=200;
	else if(man1_pos==2)
		man1_y=300;
}

void manChange2()
{
	man2_x-=5;
	if(bullet_x>(man2_x+10) && bullet_x<(man2_x+150) && bullet_y>man2_y && bullet_y<(man2_y+150))
	{
		total_time-=5;
		count-=2;
		if(count<0)
		{strcpy(score,"0");count=0;}
		else
			sprintf(score,"%d",count);
		bullet_x=x+100;bullet_y=y+160;
		man2_x=1300;
		man2_pos++;
		if(man2_pos>2)
			man2_pos=0;
		if(total_time<=0) 
		{
			iPauseTimer(game_time);
			iPauseTimer(z1_time);
			iPauseTimer(z2_time);
			iPauseTimer(man1_time);
			iPauseTimer(man2_time);
			iPauseTimer(bullet_time);
			bullet_mode=0;
			start=3;
		}
		
	}
	man2_flag++;
	if(man2_x<0)
	{
		man2_x=1300;
		man2_pos++;
		if(man2_pos>2)
			man2_pos=0;
	}
	if(man2_flag>5)
		man2_flag=0;
	if(man2_pos==0)
		man2_y=300;
	else if(man2_pos==1)
		man2_y=100;
	else if(man2_pos==2)
		man2_y=200;
}
void countDown()
{
	if(count_down==0)
		{
			start=2; bullet_mode=1;
			iResumeTimer(game_time);
			iResumeTimer(z1_time);
			iResumeTimer(z2_time);
			iResumeTimer(man1_time);
			iResumeTimer(man2_time);
		}
	sprintf(countdown,"%d",count_down);
	count_down--;
	
}

int main()
{
	game_time=iSetTimer(500,showTime);
	z1_time=iSetTimer(10,z1Change);
	z2_time=iSetTimer(10,z2Change);
	man1_time=iSetTimer(50,manChange1);
	man2_time=iSetTimer(50,manChange2);
	countTime=iSetTimer(1000,countDown);
	bullet_time=iSetTimer(10,bullet);
	iPauseTimer(z1_time);
	iPauseTimer(z2_time);
	iPauseTimer(man1_time);
	iPauseTimer(man2_time);
	iPauseTimer(countTime);
	iPauseTimer(bullet_time);
	iPauseTimer(game_time);
	namelen = 0;
	tempName[0]= 0;
	name_box_col1=100; name_box_col2=100; name_box_col3=100;
	iInitialize(1280, 720, "Kill or Die");
	return 0;
}	