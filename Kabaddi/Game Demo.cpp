#include <stdio.h>
#include <math.h>
#include <graphics.h>
#include <windows.h>

int ax[6]={0, 295, 265, 235, 265, 295}, ay[6]={0, 120, 250, 380, 510, 640}; //Co-ordinates for the first team.
int r=35;                                                                   //Dictates distance from center to edge.
int axd[6]={0, 295, 265, 235, 265, 295}, ayd[6]={0, 120, 250, 380, 510, 640}; //Default co-ordinates for the first team.
int bx[6]={0, 1055, 1085, 1105, 1085, 1055}, by[6]={0, 120, 250, 380, 510, 640}; //Co-ordinates for the second team.
int bxd[6]={0, 1055, 1085, 1105, 1085, 1055}, byd[6]={0, 120, 250, 380, 510, 640}; //Default co-ordinates for the second team.
int i=1, j=1, i_other, j_other, v; //i & j dictate current player for Team 1 and Team 2 respectively.
int noteli[6]={0, 1, 1, 1, 1, 1}, notelim[6]={0, 1, 1, 1, 1, 1}; //'0' dictates the player has been eliminated, '1' dictates they haven't.
int energya[6]={0, 100, 120, 140, 80, 60}, energyb[6]={0, 1250, 1300, 1280, 1240, 1220}; //Energy end & start co-ordinates respectively for Team 1 & Team 2.
int energyad[6]={0, 100, 120, 140, 80, 60}, energybd[6]={0, 1250, 1300, 1280, 1240, 1220}; // Default energy co-ordinates.
int roundcount, loop, cl2; //Variables used for counting rounds and checking if one player has been eliminated.
int mmkey=1; //Main menu variable.
int g, h;
int pp1=0, pp2=0; //Scores' variables.
char c; //Input variable.
int once; //A.I. variable.
char ppc1[100], ppc2[100], rounds[100]; //Integer to string for display.


void energy1(int& i)
{
    setcolor(WHITE);
    rectangle(20, 40, energya[i], 60);  //Draws the white outline for Team 1's energy bar.
    setfillstyle(SOLID_FILL, GREEN);
    floodfill(21, 50, WHITE);           //Fills up the energy bar in green.
}
void energy2(int& j)
{
    setcolor(WHITE);
    rectangle(energyb[j], 40, 1341, 60);
    setfillstyle(SOLID_FILL, GREEN);
    floodfill(energyb[j]+1, 41, WHITE);
}

void player1_score()
{
    sprintf(ppc1, "%d", pp1);   //Converts Team 1's score from integer to a string.
    setcolor(WHITE);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 0);
    outtextxy(50, 10, ppc1);    //Prints the string(points) in the graphics window.
}

void player2_score()
{
    sprintf(ppc2, "%d", pp2);
    setcolor(WHITE);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 0);
    outtextxy(1290, 10, ppc2);
}

void midline()
{
    readimagefile("midline.jpg", 684, 0, 700, 848); //Draws the midline.
}

void points1()
{
    setcolor(WHITE);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 0);
    outtextxy(20, 10, "1P");                //To indicate whom the score belongs to.
    player1_score();                        //Prints the score.
}

void points2()
{
    setcolor(WHITE);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 0);
    outtextxy(1331, 10, "2P");
    player2_score();
}

void round()
{
    setcolor(WHITE);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 0);
    outtextxy(650, 8, "ROUND");                 //To show which round is underway.
    sprintf(rounds, "%d", roundcount);          //Converts the round number to a string for display.
    outtextxy(710, 9, rounds);                  //Shows the current ongoing round.
}

void draw_team1(int& i)
{
    points1();      //Prints the points portion.
    round();        //Prints the round portion.
    r=35;
    int m=1;
    while(m<=5)
    {
        readimagefile("kabadi1.gif", ax[m]-r, ay[m]-r, ax[m]+r, ay[m]+r);   //Draws each team member separately.
        m++;
    }
    energy1(i);     //Draws the energy bar for each member periodically.
}

void draw_team2(int& j)
{
    points2();
    r=35;
    int n=1;
    while(n<=5)
    {
        readimagefile("kabadi2.gif", bx[n]-r, by[n]-r, bx[n]+r, by[n]+r);
        n++;
        if(n==6)
        {
            break;
        }
    }
    energy2(j);
}

void indicators(int&i, int& j)
{
    readimagefile("pointer1.gif", ax[i]-r, ay[i]-r-r, ax[i]+r, ay[i]-r);    //Draws a pointer to indicate which player Team 1 is controlling.
    readimagefile("pointer2.gif", bx[j]-r, by[j]-r-r, bx[j]+r, by[j]-r);    //Draws a pointer to indicate which player Team 2 is controlling.
}

void indicatorsolo(int&i)
{
    readimagefile("pointer1.gif", ax[i]-r, ay[i]-r-r, ax[i]+r, ay[i]-r);    //Draws the pointer only for Team 1, during single player.
}

void song()     //Plays different background music for each round.
{
    if(roundcount==1)
    {
        mciSendString("play gravity.wav", NULL, 0, NULL);
    }
    else if(roundcount==2)
    {
        mciSendString("play batsy.wav", NULL, 0, NULL);
    }
    else if(roundcount==3)
    {
        mciSendString("play thunder.wav", NULL, 0, NULL);
    }
    else if(roundcount==4)
    {
        mciSendString("play dbz.wav", NULL, 0, NULL);
    }
    else if(roundcount==5)
    {
        mciSendString("play who.wav", NULL, 0, NULL);
    }
    else if(roundcount==6)
    {
        mciSendString("play emh.wav", NULL, 0, NULL);
    }
    else if(roundcount==7)
    {
        mciSendString("play awake.wav", NULL, 0, NULL);
    }
    else if(roundcount==8)
    {
        mciSendString("play dark.wav", NULL, 0, NULL);
    }
    else if(roundcount==9)
    {
        mciSendString("play medal.wav", NULL, 0, NULL);
    }
    else if(roundcount==10)
    {
        mciSendString("play fairy.wav", NULL, 0, NULL);
    }
}

void song_end() //Stops the current background music.
{
    if(roundcount==1)
    {
        mciSendString("stop gravity.wav", NULL, 0, NULL);
    }
    else if(roundcount==2)
    {
        mciSendString("stop batsy.wav", NULL, 0, NULL);
    }
    else if(roundcount==3)
    {
        mciSendString("stop thunder.wav", NULL, 0, NULL);
    }
    else if(roundcount==4)
    {
        mciSendString("stop dbz.wav", NULL, 0, NULL);
    }
    else if(roundcount==5)
    {
        mciSendString("stop who.wav", NULL, 0, NULL);
    }
    else if(roundcount==6)
    {
        mciSendString("stop emh.wav", NULL, 0, NULL);
    }
    else if(roundcount==7)
    {
        mciSendString("stop awake.wav", NULL, 0, NULL);
    }
    else if(roundcount==8)
    {
        mciSendString("stop dark.wav", NULL, 0, NULL);
    }
    else if(roundcount==9)
    {
        mciSendString("stop medal.wav", NULL, 0, NULL);
    }
    else if(roundcount==10)
    {
        mciSendString("stop fairy.wav", NULL, 0, NULL);
    }
}

void field()
{
    readimagefile("FieldPNGIF.jpg", 0, 0, 1380, 750);       //Draws the field.
}

void energy1_clear()
{
    readimagefile("EnergyFiller1.jpg", 20, 40, 150, 60);    //Colors up the whole energy bar with the color of the field. Used to remove white borderlines.
}

void energy2_clear()
{
    readimagefile("EnergyFiller1.jpg", 1200, 40, 1341, 60);
}

void enter_name()
{
    cleardevice();
    readimagefile("name.jpg", 0, 0, 1380, 750);
    char n[1000];
    int in, po=250;
    in=0;
    do
    {
        if(n[in-1]=='\n')break;
        if(in==25)
        {
            break;
        }
        n[in]=(char)getch();
        if(n[in]==8 || n[in]==127)
        {
            readimagefile("menufiller.jpg", po-40, 350, po, 400);
            in--;
            n[in]='\0';
            po-=35;
            continue;
        }
        if(n[in]=='a' || n[in]=='A')readimagefile("a.jpg", po, 350, po+30, 400);
        else if(n[in]=='b' || n[in]=='B')readimagefile("b.jpg", po, 350, po+30, 400);
        else if(n[in]=='c' || n[in]=='C')readimagefile("c.jpg", po, 350, po+30, 400);
        else if(n[in]=='d' || n[in]=='D')readimagefile("d.jpg", po, 350, po+30, 400);
        else if(n[in]=='e' || n[in]=='E')readimagefile("e.jpg", po, 350, po+30, 400);
        else if(n[in]=='f' || n[in]=='F')readimagefile("f.jpg", po, 350, po+30, 400);
        else if(n[in]=='g' || n[in]=='G')readimagefile("g.jpg", po, 350, po+30, 400);
        else if(n[in]=='h' || n[in]=='H')readimagefile("h.jpg", po, 350, po+30, 400);
        else if(n[in]=='i' || n[in]=='I')readimagefile("i.jpg", po, 350, po+30, 400);
        else if(n[in]=='j' || n[in]=='J')readimagefile("j.jpg", po, 350, po+30, 400);
        else if(n[in]=='k' || n[in]=='K')readimagefile("k.jpg", po, 350, po+30, 400);
        else if(n[in]=='l' || n[in]=='L')readimagefile("l.jpg", po, 350, po+30, 400);
        else if(n[in]=='m' || n[in]=='M')readimagefile("m.jpg", po, 350, po+30, 400);
        else if(n[in]=='n' || n[in]=='N')readimagefile("n.jpg", po, 350, po+30, 400);
        else if(n[in]=='o' || n[in]=='O')readimagefile("o.jpg", po, 350, po+30, 400);
        else if(n[in]=='p' || n[in]=='P')readimagefile("p.jpg", po, 350, po+30, 400);
        else if(n[in]=='q' || n[in]=='Q')readimagefile("q.jpg", po, 350, po+30, 400);
        else if(n[in]=='r' || n[in]=='R')readimagefile("r.jpg", po, 350, po+30, 400);
        else if(n[in]=='s' || n[in]=='S')readimagefile("s.jpg", po, 350, po+30, 400);
        else if(n[in]=='t' || n[in]=='T')readimagefile("t.jpg", po, 350, po+30, 400);
        else if(n[in]=='u' || n[in]=='U')readimagefile("u.jpg", po, 350, po+30, 400);
        else if(n[in]=='v' || n[in]=='V')readimagefile("v.jpg", po, 350, po+30, 400);
        else if(n[in]=='w' || n[in]=='W')readimagefile("w.jpg", po, 350, po+30, 400);
        else if(n[in]=='x' || n[in]=='X')readimagefile("x.jpg", po, 350, po+30, 400);
        else if(n[in]=='y' || n[in]=='Y')readimagefile("y.jpg", po, 350, po+30, 400);
        else if(n[in]=='z' || n[in]=='Z')readimagefile("z.jpg", po, 350, po+30, 400);
        else if(n[in]==' ')readimagefile("menufiller.jpg", po, 350, po+30, 400);
        else if(n[in]=='0')readimagefile("0.jpg", po, 350, po+30, 400);
        else if(n[in]=='1')readimagefile("1.jpg", po, 350, po+30, 400);
        else if(n[in]=='2')readimagefile("2.jpg", po, 350, po+30, 400);
        else if(n[in]=='3')readimagefile("3.jpg", po, 350, po+30, 400);
        else if(n[in]=='4')readimagefile("4.jpg", po, 350, po+30, 400);
        else if(n[in]=='5')readimagefile("5.jpg", po, 350, po+30, 400);
        else if(n[in]=='6')readimagefile("6.jpg", po, 350, po+30, 400);
        else if(n[in]=='7')readimagefile("7.jpg", po, 350, po+30, 400);
        else if(n[in]=='8')readimagefile("8.jpg", po, 350, po+30, 400);
        else if(n[in]=='9')readimagefile("9.jpg", po, 350, po+30, 400);
        else if(n[in]==13)break;
        if(n[in]>=97 && n[in]<=122)n[in]-=32;
        in++;
        po+=35;
    }
    while(n[in]!=13 || n[in-1]!='\n');
    n[in]='\n';
    n[in+1]='\0';
    FILE* lead;
    lead=fopen("leaderboard.txt", "a");
    fprintf(lead, n);
    printf("%s", n);
    delay(750);
    cleardevice();
}

void players_move()
{
            int cv, ct=5;
            c=(char)getch();        //Takes a character input.
            i_other=i;
            j_other=j;
            if(c=='a' || c=='A')    //Shifts co-ordinates left, varies from player to player. Erases the last location, and draws again at new location.
            {
                readimagefile("EnergyFiller1.jpg", ax[i]-r, ay[i]-(r*2), ax[i]+r, ay[i]+r);
                if(i==1)
                {
                    ax[i]-=50;
                }
                else if(i==2)
                {
                    ax[i]-=35;
                }
                else if(i==3)
                {
                    ax[i]-=70;
                }
                else if(i==4)
                {
                    ax[i]-=85;
                }
                else
                {
                    ax[i]-=50;
                }
                if(ax[i]-r<=20)
                {
                    ax[i]+=100;
                }
                readimagefile("kabadi1.gif", ax[i]-r, ay[i]-r, ax[i]+r, ay[i]+r);
                indicators(i, j);
                i=i_other;
            }
            if(c=='d' || c=='D')    //Shifts co-ordinates right, varies from player to player. Erases the last location, and draws again at new location.
            {

                readimagefile("EnergyFiller1.jpg", ax[i]-r, ay[i]-(r*2), ax[i]+r, ay[i]+r);
                if(i==1)
                {
                    ax[i]+=50;
                }
                else if(i==2)
                {
                    ax[i]+=35;
                }
                else if(i==3)
                {
                    ax[i]+=70;
                }
                else if(i==4)
                {
                    ax[i]+=85;
                }
                else
                {
                    ax[i]+=50;
                }
                if(ax[i]+r>=1380)
                {
                    ax[i]-=100;
                }
                if(roundcount%2==0)
                {
                    if(ax[i]+r>=690)
                    {
                        ax[i]=680-r;
                    }
                }
                readimagefile("kabadi1.gif", ax[i]-r, ay[i]-r, ax[i]+r, ay[i]+r);
                indicators(i, j);

                i=i_other;
            }
            if(c=='w' || c=='W')    //Shifts co-ordinates up, varies from player to player. Erases the last location, and draws again at new location.
            {

                readimagefile("EnergyFiller1.jpg", ax[i]-r, ay[i]-(r*2), ax[i]+r, ay[i]+r);
                if(i==1)
                {
                    ay[i]-=50;
                }
                else if(i==2)
                {
                    ay[i]-=35;
                }
                else if(i==3)
                {
                    ay[i]-=70;
                }
                else if(i==4)
                {
                    ay[i]-=85;
                }
                else
                {
                    ay[i]-=50;
                }
                if(ay[i]-r<=r)
                {
                    ay[i]+=70;
                }
                readimagefile("kabadi1.gif", ax[i]-r, ay[i]-r, ax[i]+r, ay[i]+r);
                indicators(i, j);
                i=i_other;
            }
            if(c=='s' || c=='S')    //Shifts co-ordinates down, varies from player to player. Erases the last location, and draws again at new location.
            {
                readimagefile("EnergyFiller1.jpg", ax[i]-r, ay[i]-(r*2), ax[i]+r, ay[i]+r);
                if(i==1)
                {
                    ay[i]+=50;
                }
                else if(i==2)
                {
                    ay[i]+=35;
                }
                else if(i==3)
                {
                    ay[i]+=70;
                }
                else if(i==4)
                {
                    ay[i]+=85;
                }
                else
                {
                    ay[i]+=50;
                }
                if(ay[i]+r>=720)
                {
                    ay[i]-=70;
                }
                readimagefile("kabadi1.gif", ax[i]-r, ay[i]-r, ax[i]+r, ay[i]+r);
                indicators(i, j);
                i=i_other;
            }
            if(c=='q' || c=='Q')    //Switches player. Erases pointer for last player and draws new one for current controlling player.
            {
                readimagefile("EnergyFiller1.jpg", ax[i]-r, ay[i]-(r*2), ax[i]+r, ay[i]-r);
                i++;
                if(i>5)
                {
                    i=1;
                }
                readimagefile("kabadi1.gif", ax[i]-r, ay[i]-r, ax[i]+r, ay[i]+r);
                indicators(i, j);
                energy1_clear();
                energy1(i);
            }
            if(c=='c')      //Replenishes lost energy.
            {
                if(energya[i]>=energyad[i])
                {
                    energya[i]=energyad[i];
                }
                else if(energya[i]<=20)
                {
                    energya[i]=20;
                }
                else
                {
                    energya[i]+=13;
                }
            }



            if(c=='j' || c=='J')    //Shifts co-ordinates left, varies from player to player. Erases the last location, and draws again at new location.
            {
                readimagefile("EnergyFiller1.jpg", bx[j]-r, by[j]-(2*r), bx[j]+r, by[j]+r);
                if(j==1)
                {
                    bx[j]-=50;
                }
                else if(j==2)
                {
                    bx[j]-=35;
                }
                else if(j==3)
                {
                    bx[j]-=70;
                }
                else if(j==4)
                {
                    bx[j]-=85;
                }
                else
                {
                    bx[j]-=50;
                }
                if(bx[j]-r<=r)
                {
                    bx[j]+=50;
                }
                if(roundcount%2==1)
                {
                    if(bx[j]-r<=690)
                    {
                        bx[j]+=30+r;
                    }
                }
                readimagefile("kabadi2.gif", bx[j]-r, by[j]-r, bx[j]+r, by[j]+r);
                indicators(i, j);

                j=j_other;
            }
            if(c=='l' || c=='L')    //Shifts co-ordinates right, varies from player to player. Erases the last location, and draws again at new location.
            {

                readimagefile("EnergyFiller1.jpg", bx[j]-r, by[j]-(2*r), bx[j]+r, by[j]+r);
                if(j==1)
                {
                    bx[j]+=50;
                }
                else if(j==2)
                {
                    bx[j]+=35;
                }
                else if(j==3)
                {
                    bx[j]+=70;
                }
                else if(j==4)
                {
                    bx[j]+=85;
                }
                else
                {
                    bx[j]+=50;
                }
                if(bx[j]+r>=1370)
                {
                    bx[j]-=80;
                }
                readimagefile("kabadi2.gif", bx[j]-r, by[j]-r, bx[j]+r, by[j]+r);
                indicators(i, j);
                j=j_other;
            }
            if(c=='i' || c=='I')    //Shifts co-ordinates up, varies from player to player. Erases the last location, and draws again at new location.
            {

                readimagefile("EnergyFiller1.jpg", bx[j]-r, by[j]-(2*r), bx[j]+r, by[j]+r);
                if(j==1)
                {
                    by[j]-=50;
                }
                else if(j==2)
                {
                    by[j]-=35;
                }
                else if(j==3)
                {
                    by[j]-=70;
                }
                else if(j==4)
                {
                    by[j]-=85;
                }
                else
                {
                    by[j]-=50;
                }
                if(by[j]-r<=r)
                {
                    by[j]+=50+r;
                }
                readimagefile("kabadi2.gif", bx[j]-r, by[j]-r, bx[j]+r, by[j]+r);
                indicators(i, j);
                j=j_other;
            }
            if(c=='k')  //Shifts co-ordinates down, varies from player to player. Erases the last location, and draws again at new location.
            {
                readimagefile("EnergyFiller1.jpg", bx[j]-r, by[j]-(2*r), bx[j]+r, by[j]+r);
                if(j==1)
                {
                    by[j]+=50;
                }
                else if(j==2)
                {
                    by[j]+=35;
                }
                else if(j==3)
                {
                    by[j]+=70;
                }
                else if(j==4)
                {
                    by[j]+=85;
                }
                else
                {
                    by[j]+=50;
                }
                if(by[j]+r>=720)
                {
                    by[j]-=100-r;
                }
                readimagefile("kabadi2.gif", bx[j]-r, by[j]-r, bx[j]+r, by[j]+r);
                indicators(i, j);
                j=j_other;
            }
            if(c=='p')     //Switches player. Erases last player's pointer and draws anew for current, controlling player.
            {
                readimagefile("EnergyFiller1.jpg", bx[j]-r, by[j]-(2*r), bx[j]+r, by[j]-r);
                j++;
                if(j>5)
                {
                    j=1;
                }
                readimagefile("kabadi2.gif", bx[j]-r, by[j]-r, bx[j]+r, by[j]+r);
                //draw_team2(j);
                indicators(i, j);
                energy2_clear();
                energy2(j);
            }

            if(c=='b' || c=='B')    //Replenishes lost energy.
            {
                if(energyb[j]>=520)
                {
                    energyb[j]=520;
                }
                else if(energyb[j]<=400)
                {
                    energyb[j]=400;
                }
                else
                {
                    energyb[j]-=13;
                }
            }
}

void player1attack(int& i, int& j, int& loop)
{
            int cv, ct=5;
            c=(char)getch();
            i_other=i;
            j_other=j;
            if(c=='a' || c=='A')
            {
                readimagefile("EnergyFiller1.jpg", ax[i]-r, ay[i]-(r*2), ax[i]+r, ay[i]+r);
                if(i==1)
                {
                    ax[i]-=40;
                }
                else if(i==2)
                {
                    ax[i]-=60;
                }
                else if(i==3)
                {
                    ax[i]-=35;
                }
                else if(i==4)
                {
                    ax[i]-=85;
                }
                else
                {
                    ax[i]-=50;
                }
                if(ax[i]-r<=r)
                {
                    ax[i]+=50;
                }
                if(ax[i]-r<=690)
                {
                    ax[i]=700+r;
                }
                readimagefile("kabadi1.gif", ax[i]-r, ay[i]-r, ax[i]+r, ay[i]+r);
                indicators(i, j);
                i=i_other;
            }
            if(c=='d' || c=='D')
            {

                readimagefile("EnergyFiller1.jpg", ax[i]-r, ay[i]-(r*2), ax[i]+r, ay[i]+r);
                if(i==1)
                {
                    ax[i]+=40;
                }
                else if(i==2)
                {
                    ax[i]+=60;
                }
                else if(i==3)
                {
                    ax[i]+=35;
                }
                else if(i==4)
                {
                    ax[i]+=85;
                }
                else
                {
                    ax[i]+=50;
                }
                if(ax[i]+r>=1380)
                {
                    ax[i]-=100;
                }
                readimagefile("kabadi1.gif", ax[i]-r, ay[i]-r, ax[i]+r, ay[i]+r);
                indicators(i, j);
                i=i_other;
            }
            if(c=='w' || c=='W')
            {

                readimagefile("EnergyFiller1.jpg", ax[i]-r, ay[i]-(r*2), ax[i]+r, ay[i]+r);
                if(i==1)
                {
                    ay[i]-=40;
                }
                else if(i==2)
                {
                    ay[i]-=60;
                }
                else if(i==3)
                {
                    ay[i]-=35;
                }
                else if(i==4)
                {
                    ay[i]-=85;
                }
                else
                {
                    ay[i]-=50;
                }
                if(ay[i]-r<=r)
                {
                    ay[i]+=70;
                }
                readimagefile("kabadi1.gif", ax[i]-r, ay[i]-r, ax[i]+r, ay[i]+r);
                indicators(i, j);
                i=i_other;
            }
            if(c=='s' || c=='S')
            {
                readimagefile("EnergyFiller1.jpg", ax[i]-r, ay[i]-(r*2), ax[i]+r, ay[i]+r);
                if(i==1)
                {
                    ay[i]+=40;
                }
                else if(i==2)
                {
                    ay[i]+=60;
                }
                else if(i==3)
                {
                    ay[i]+=35;
                }
                else if(i==4)
                {
                    ay[i]+=85;
                }
                else
                {
                    ay[i]+=50;
                }
                if(ay[i]+r>=720)
                {
                    ay[i]-=70;
                }
                readimagefile("kabadi1.gif", ax[i]-r, ay[i]-r, ax[i]+r, ay[i]+r);
                indicators(i, j);
                i=i_other;
            }
            if(c=='c' || c=='C')
            {
                if(energya[i]>=energyad[i])
                {
                    energya[i]=energyad[i];
                }
                else if(energya[i]<=20)
                {
                    energya[i]=20;
                }
                else
                {
                    energya[i]+=7;
                }
            }




            if(c=='j' || c=='J' && notelim[loop]==1)
            {
                readimagefile("EnergyFiller1.jpg", bx[j]-r, by[j]-r-r, bx[j]+r, by[j]+r);
                if(j==1)
                {
                    bx[j]-=50;
                }
                else if(j==2)
                {
                    bx[j]-=35;
                }
                else if(j==3)
                {
                    bx[j]-=70;
                }
                else if(j==4)
                {
                    bx[j]-=25;
                }
                else
                {
                    bx[j]-=30;
                }
                if(bx[j]<=r)
                {
                    bx[j]+=50;
                }
                if((bx[j]-r)<=690)
                {
                    bx[j]+=80;
                }
                readimagefile("kabadi2.gif", bx[j]-r, by[j]-r, bx[j]+r, by[j]+r);
                indicators(i, j);
                j=j_other;
            }
            if(c=='l' || c=='L' && notelim[loop]==1)
            {

                readimagefile("EnergyFiller1.jpg", bx[j]-r, by[j]-r-r, bx[j]+r, by[j]+r);
                if(j==1)
                {
                    bx[j]+=50;
                }
                else if(j==2)
                {
                    bx[j]+=35;
                }
                else if(j==3)
                {
                    bx[j]+=70;
                }
                else if(j==4)
                {
                    bx[j]+=25;
                }
                else
                {
                    bx[j]+=30;
                }
                if(bx[j]+r>=1380)
                {
                    bx[j]-=100;
                }
                readimagefile("kabadi2.gif", bx[j]-r, by[j]-r, bx[j]+r, by[j]+r);
                indicators(i, j);
                j=j_other;
            }
            if(c=='i' || c=='I' && notelim[loop]==1)
            {

                readimagefile("EnergyFiller1.jpg", bx[j]-r, by[j]-r-r, bx[j]+r, by[j]+r);
                if(j==1)
                {
                    by[j]-=50;
                }
                else if(j==2)
                {
                    by[j]-=35;
                }
                else if(j==3)
                {
                    by[j]-=70;
                }
                else if(j==4)
                {
                    by[j]-=25;
                }
                else
                {
                    by[j]-=30;
                }
                if(by[j]-r<=r)
                {
                    by[j]+=60;
                }
                readimagefile("kabadi2.gif", bx[j]-r, by[j]-r, bx[j]+r, by[j]+r);
                indicators(i, j);
                j=j_other;
            }
            if(c=='k' || c=='K' && notelim[loop]==1)
            {
                readimagefile("EnergyFiller1.jpg", bx[j]-r, by[j]-r-r, bx[j]+r, by[j]+r);
                if(j==1)
                {
                    by[j]+=50;
                }
                else if(j==2)
                {
                    by[j]+=35;
                }
                else if(j==3)
                {
                    by[j]+=70;
                }
                else if(j==4)
                {
                    by[j]+=25;
                }
                else
                {
                    by[j]+=30;
                }
                if(by[j]+r>=720)
                {
                    by[j]-=100;
                }
                readimagefile("kabadi2.gif", bx[j]-r, by[j]-r, bx[j]+r, by[j]+r);
                indicators(i, j);
                j=j_other;
            }
            if(c=='p' || c=='P')
            {
                readimagefile("EnergyFiller1.jpg", bx[j]-r, by[j]-(2*r), bx[j]+r, by[j]-r);
                j++;
                if(j>5)
                {
                    j=1;
                }
                readimagefile("kabadi2.gif", bx[j]-r, by[j]-r, bx[j]+r, by[j]+r);
                indicators(i, j);
                energy2_clear();
                energy2(j);
            }
}

void player2attack(int& i, int& j, int& loop)
{
            int cv, ct=5;
            c=(char)getch();
            i_other=i;
            j_other=j;
            if(c=='a' || c=='A' && noteli[loop]==1)
            {
                readimagefile("EnergyFiller1.jpg", ax[i]-r, ay[i]-(r*2), ax[i]+r, ay[i]+(r*2));
                if(i==1)
                {
                    ax[i]-=40;
                }
                else if(i==2)
                {
                    ax[i]-=60;
                }
                else if(i==3)
                {
                    ax[i]-=35;
                }
                else if(i==4)
                {
                    ax[i]-=70;
                }
                else
                {
                    ax[i]-=50;
                }
                if(ax[i]-r<=20)
                {
                    ax[i]+=100;
                }
                readimagefile("kabadi1.gif", ax[i]-r, ay[i]-r, ax[i]+r, ay[i]+r);
                indicators(i, j);
                i=i_other;
            }
            if(c=='d' || c=='D' && noteli[loop]==1)
            {

                readimagefile("EnergyFiller1.jpg", ax[i]-r, ay[i]-(r*2), ax[i]+r, ay[i]+(r*2));
                if(i==1)
                {
                    ax[i]+=40;
                }
                else if(i==2)
                {
                    ax[i]+=60;
                }
                else if(i==3)
                {
                    ax[i]+=35;
                }
                else if(i==4)
                {
                    ax[i]+=70;
                }
                else
                {
                    ax[i]+=50;
                }
                if(ax[i]+r>=1380)
                {
                    ax[i]-=100-r;
                }
                if(ax[i]+r>=690)
                {
                    ax[i]-=80-r;
                }
                readimagefile("kabadi1.gif", ax[i]-r, ay[i]-r, ax[i]+r, ay[i]+r);
                indicators(i, j);
                i=i_other;
            }
            if(c=='w' || c=='W' && noteli[loop]==1)
            {

                readimagefile("EnergyFiller1.jpg", ax[i]-r, ay[i]-(r*2), ax[i]+r, ay[i]+(r*2));
                if(i==1)
                {
                    ay[i]-=40;
                }
                else if(i==2)
                {
                    ay[i]-=60;
                }
                else if(i==3)
                {
                    ay[i]-=35;
                }
                else if(i==4)
                {
                    ay[i]-=70;
                }
                else
                {
                    ay[i]-=50;
                }
                if(ay[i]-r<=r)
                {
                    ay[i]+=60;
                }
                readimagefile("kabadi1.gif", ax[i]-r, ay[i]-r, ax[i]+r, ay[i]+r);
                indicators(i, j);
                i=i_other;
            }
            if(c=='s' || c=='S' && noteli[loop]==1)
            {
                readimagefile("EnergyFiller1.jpg", ax[i]-r, ay[i]-(r*2), ax[i]+r, ay[i]+(r*2));
                if(i==1)
                {
                    ay[i]+=40;
                }
                else if(i==2)
                {
                    ay[i]+=60;
                }
                else if(i==3)
                {
                    ay[i]+=35;
                }
                else if(i==4)
                {
                    ay[i]+=70;
                }
                else
                {
                    ay[i]+=50;
                }
                if(ay[i]+r>=720)
                {
                    ay[i]-=50-r;
                }
                readimagefile("kabadi1.gif", ax[i]-r, ay[i]-r, ax[i]+r, ay[i]+r);
                indicators(i, j);
                i=i_other;
            }
            if(c=='q' || c=='Q')
            {
                readimagefile("EnergyFiller1.jpg", ax[i]-r, ay[i]-(r*2), ax[i]+r, ay[i]-r);
                i++;
                if(i>5)
                {
                    i=1;
                }
                readimagefile("kabadi1.gif", ax[i]-r, ay[i]-r, ax[i]+r, ay[i]+r);
                indicators(i, j);
                energy1_clear();
                energy1(i);
            }
            /*ct=5;
            for(cv=1;cv<=5;cv++)
            {
                if(ct==0)
                {
                    break;
                }
                if(cv==j)
                {
                    continue;
                }
                if((ax[i]+r>=ax[cv]-r || ay[i]+r>=ay[cv]-r || ax[i]+r<=ax[cv]+r+20 || ay[i]+r<=ay[cv]+r+20) || noteli[loop]==1)
                {
                    readimagefile("kabadi1.gif", ax[i]-r, ay[i]-r, ax[i]+r, ay[i]+r);
                    readimagefile("kabadi1.gif", ax[cv]-r, ay[cv]-r, ax[cv]+r, ay[cv]+r);
                }
                ct--;
            }*/




            if(c=='j' || c=='J')
            {
                readimagefile("EnergyFiller1.jpg", bx[j]-r, by[j]-r-r, bx[j]+r, by[j]+r);
                if(j==1)
                {
                    bx[j]-=50;
                }
                else if(j==2)
                {
                    bx[j]-=35;
                }
                else if(j==3)
                {
                    bx[j]-=70;
                }
                else if(j==4)
                {
                    bx[j]-=25;
                }
                else
                {
                    bx[j]-=30;
                }
                if(bx[j]-r<=r)
                {
                    bx[j]+=50+r;
                }
                readimagefile("kabadi2.gif", bx[j]-r, by[j]-r, bx[j]+r, by[j]+r);
                indicators(i, j);
                j=j_other;
            }
            if(c=='l' || c=='L')
            {

                readimagefile("EnergyFiller1.jpg", bx[j]-r, by[j]-r-r, bx[j]+r, by[j]+r);
                if(j==1)
                {
                    bx[j]+=50;
                }
                else if(j==2)
                {
                    bx[j]+=35;
                }
                else if(j==3)
                {
                    bx[j]+=70;
                }
                else if(j==4)
                {
                    bx[j]+=25;
                }
                else
                {
                    bx[j]+=30;
                }
                if(bx[j]+r>=1380)
                {
                    bx[j]-=100;
                }
                if(bx[j]+r>690)
                {
                    bx[j]-=100-r;
                }
                readimagefile("kabadi2.gif", bx[j]-r, by[j]-r, bx[j]+r, by[j]+r);
                indicators(i, j);
                j=j_other;
            }
            if(c=='i' || c=='I')
            {

                readimagefile("EnergyFiller1.jpg", bx[j]-r, by[j]-r-r, bx[j]+r, by[j]+r);
                if(j==1)
                {
                    by[j]-=50;
                }
                else if(j==2)
                {
                    by[j]-=35;
                }
                else if(j==3)
                {
                    by[j]-=70;
                }
                else if(j==4)
                {
                    by[j]-=25;
                }
                else
                {
                    by[j]-=30;
                }
                if(by[j]-r<=r)
                {
                    by[j]+=100;
                }
                readimagefile("kabadi2.gif", bx[j]-r, by[j]-r, bx[j]+r, by[j]+r);
                indicators(i, j);
                j=j_other;
            }
            if(c=='k' || c=='K')
            {
                readimagefile("EnergyFiller1.jpg", bx[j]-r, by[j]-r-r, bx[j]+r, by[j]+r);
                if(j==1)
                {
                    by[j]+=50;
                }
                else if(j==2)
                {
                    by[j]+=35;
                }
                else if(j==3)
                {
                    by[j]+=70;
                }
                else if(j==4)
                {
                    by[j]+=25;
                }
                else
                {
                    by[j]+=30;
                }
                if(by[j]+r>=720)
                {
                    by[j]-=100-r;
                }
                readimagefile("kabadi2.gif", bx[j]-r, by[j]-r, bx[j]+r, by[j]+r);
                indicators(i, j);
                j=j_other;
            }
            if(c=='b' || c=='B')
            {
                if(energyb[j]>=1341)
                {
                    energyb[j]=1330;
                }
                else if(energyb[j]<=energybd[j])
                {
                    energyb[j]=energybd[j];
                }
                else
                {
                    energyb[j]-=7;
                }
            }
}

void round_start()
{
    delay(100);
    if(roundcount%2==1) //If Team 1 attacks.
    {
        h=1;
        while(ax[i]<690) //Moves independently until midline is crossed.
        {
            players_move();
            midline();
            round();
            readimagefile("kabadi1.gif", ax[i]-r, ay[i]-r, ax[i]+r, ay[i]+r);
        }
            int remain=5;
            while(ax[i]>=690)  //Round starts.
            {
                player1attack(i, j, loop);
                energy1_clear();
                energy2_clear();
                midline();
                round();
                readimagefile("kabadi1.gif", ax[i]-r, ay[i]-r, ax[i]+r, ay[i]+r);
                energy1(i);
                energy2(j);
                for(loop=1;loop<=5;loop++)  //Checks if a player is in proximity with a player of the opposing team in a loop.
                {
                    if((ax[i]+r>=bx[loop]-r && ay[i]+r>=by[loop]-r && ax[i]-r<=bx[loop]+r+10 && ay[i]-r<=by[loop]+r+10) && notelim[loop]==1)
                    {
                        mciSendString("play eliminate.wav", NULL, 0, NULL);
                        readimagefile("EnergyFiller1.jpg", bx[loop]-r, by[loop]-r-r, bx[loop]+r, by[loop]+r); //Erases the eliminated player.
                        energy1_clear();
                        energy2_clear();
                        midline();
                        round();
                        readimagefile("kabadi1.gif", ax[i]-r, ay[i]-r, ax[i]+r, ay[i]+r);
                        indicators(i, j);
                        energy1(i);
                        energy2(j);
                        notelim[loop]=0;    //Marks that player's availability '0'.
                        remain--;   //Decreases defending team's remaining player count.
                        pp1+=5;     //Awards five points to attacking team.
                        points1();
                        break;
                    }
                }
                while(notelim[j]==0)    //Switches to next player periodically.
                        {
                            readimagefile("EnergyFiller1.jpg", bx[j]-r, by[j]-r-r, bx[j]+r, by[j]+r);
                            j++;
                            if(j>5)
                            {
                                j=1;
                            }
                            if(remain==0)   //If all players are eliminated, round ends.
                            {
                                break;
                            }
                            else
                            {
                                midline();
                                indicators(i, j);
                                readimagefile("kabadi1.gif", ax[i]-r, ay[i]-r, ax[i]+r, ay[i]+r);
                            }
                        }

                if(remain==0 || energya[i]<=21) //If energy reaches zero, round ends.
                {
                    delay(800);
                    break;
                }
                energy1_clear();
                if(c=='a' || c=='s' || c=='w' || c=='d' || c=='c')energya[i]-=6;
                if(energya[i]<=20)
                {
                    energya[i]=20;
                    break;
                }
                energy1(i);
            }
        }
    else    //When Team 2 attacks. All functions similar to Team 1's.
    {
        while(bx[j]>690)
            {
                players_move();
                midline();
                round();
                readimagefile("kabadi2.gif", bx[j]-r, by[j]-r, bx[j]+r, by[j]+r);
            }
            int remain=5;
            while(bx[j]<=690)
            {
                player2attack(i, j, loop);
                midline();
                energy1_clear();
                energy2_clear();
                round();
                readimagefile("kabadi2.gif", bx[j]-r, by[j]-r, bx[j]+r, by[j]+r);
                energy1(i);
                energy2(j);
                for(loop=1;loop<=5;loop++)
                {
                    if(bx[j]-r<=ax[loop]+r && by[j]+r>=ay[loop]-r && bx[j]-r>=ax[loop]-r-10 && by[j]-r<=ay[loop]+r+5 && noteli[loop]==1)
                    {
                        mciSendString("play eliminate.wav", NULL, 0, NULL);
                        readimagefile("EnergyFiller1.jpg", ax[loop]-r, ay[loop]-r-r, ax[loop]+r, ay[loop]+r);
                        midline();
                        energy1_clear();
                        energy2_clear();
                        readimagefile("kabadi2.gif", bx[j]-r, by[j]-r, bx[j]+r, by[j]+r);
                        indicators(i, j);
                        energy1_clear();
                        energy2_clear();
                        energy1(i);
                        energy2(j);
                        round();
                        remain--;
                        noteli[loop]=0;
                        pp2+=5;
                        points2();
                        break;
                    }
                }
                while(noteli[i]==0)
                        {
                            readimagefile("EnergyFiller1.jpg", ax[i]-r, ay[i]-r-r-r, ax[i]+r, ay[i]+r);
                            midline();
                            i++;
                            if(i>5)
                            {
                                i=1;
                            }
                            if(remain==0)
                            {
                                break;
                            }
                            else
                            {
                                midline();
                                indicators(i, j);
                                readimagefile("kabadi1.gif", ax[i]-r, ay[i]-r, ax[i]+r, ay[i]+r);
                            }
                        }
                if(remain==0 || energyb[j]>=1341)
                {
                    delay(800);
                    break;
                }
                energy2_clear();
                if(c=='i' || c=='j' || c=='k' || c=='l' || c=='b')energyb[j]+=6;
                if(energyb[j]>=1340)
                {
                    energyb[j]=1341;
                    break;
                }
                energy2(j);
            }
    }
}

void round_over()   //Draws the round-over image and starts next round.
{
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 0);
    if(roundcount==1)
    {
        readimagefile("round1.jpg", 0, 0, 1380, 820);
    }
    else if(roundcount==2)
    {
        readimagefile("round2.jpg", 0, 0, 1380, 820);
    }
    else if(roundcount==3)
    {
        readimagefile("round3.jpg", 0, 0, 1380, 820);
    }
    else if(roundcount==4)
    {
        readimagefile("round4.jpg", 0, 0, 1380, 820);
    }
    else if(roundcount==5)
    {
        readimagefile("round5.jpg", 0, 0, 1380, 820);
    }
    else if(roundcount==6)
    {
        readimagefile("round6.jpg", 0, 0, 1380, 820);
    }
    else if(roundcount==7)
    {
        readimagefile("round7.jpg", 0, 0, 1380, 820);
    }
    else if(roundcount==8)
    {
        readimagefile("round8.jpg", 0, 0, 1380, 820);
    }
    else if(roundcount==9)
    {
        readimagefile("round9.jpg", 0, 0, 1380, 820);
    }
    else if(roundcount==10)
    {
        readimagefile("round10.jpg", 0, 0, 1380, 820);
    }
}

void new_game()     //Returns all values to default values and starts round.
{
    cleardevice();
    for(v=1;v<=5;v++)
    {
        ax[v]=axd[v];
        bx[v]=bxd[v];
        ay[v]=ayd[v];
        by[v]=byd[v];
        energya[v]=energyad[v];
        energyb[v]=energybd[v];
        notelim[v]=1;
        noteli[v]=1;
    }
    notelim[0]=0;
    noteli[0]=0;
    i=1;
    j=1;
    cleardevice();
    field();
    draw_team1(i);
    draw_team2(j);
    indicators(i, j);
    round_start();
}

void com_move(int& once)
{
    int ran[6]={112, 106, 105, 107, 108, 98};
    int cv;
    cv=(rand()%2);  //Either moves or switches player.
    c=ran[cv];
    if((c=='p' || c=='P') && once!=0)   //Can switch player (before attacking) up to thrice.
        {
                j++;
                if(j>5)
                {
                    j=1;
                }
           readimagefile("EnergyFiller1.jpg", bx[j]-r, by[j]-r, bx[j]+r, by[j]+r);
                if(j==1)
                {
                    bx[j]-=50;
                }
                else if(j==2)
                {
                    bx[j]-=35;
                }
                else if(j==3)
                {
                    bx[j]-=70;
                }
                else if(j==4)
                {
                    bx[j]-=85;
                }
                else
                {
                    bx[j]-=50;
                }
                if(bx[j]-r<=20)
                {
                    bx[j]+=100;
                }
                if(roundcount%2==1)
                {
                    if(bx[j]-r<=690)
                    {
                        bx[j]+=100;
                    }
                }
                readimagefile("kabadi2.gif", bx[j]-r, by[j]-r, bx[j]+r, by[j]+r);
                indicatorsolo(i);
                j=j_other;
            energy2_clear();
            energy2(j);
            once--;
        }
        else if((c=='p' || c=='P') && once==0)
        {
            c='j';
            readimagefile("EnergyFiller1.jpg", bx[j]-r, by[j]-r, bx[j]+r, by[j]+r);
                if(j==1)
                {
                    bx[j]-=50;
                }
                else if(j==2)
                {
                    bx[j]-=35;
                }
                else if(j==3)
                {
                    bx[j]-=70;
                }
                else if(j==4)
                {
                    bx[j]-=85;
                }
                else
                {
                    bx[j]-=50;
                }
                if(bx[j]-r<=20)
                {
                    bx[j]+=100;
                }
                if(roundcount%2==1)
                {
                    if(bx[j]-r<=690)
                    {
                        bx[j]+=100;
                    }
                }
                readimagefile("kabadi2.gif", bx[j]-r, by[j]-r, bx[j]+r, by[j]+r);
                indicatorsolo(i);
                j=j_other;
        }

        if(c=='j' || c=='J')
            {
                readimagefile("EnergyFiller1.jpg", bx[j]-r, by[j]-r, bx[j]+r, by[j]+r);
                if(j==1)
                {
                    bx[j]-=50;
                }
                else if(j==2)
                {
                    bx[j]-=35;
                }
                else if(j==3)
                {
                    bx[j]-=70;
                }
                else if(j==4)
                {
                    bx[j]-=85;
                }
                else
                {
                    bx[j]-=50;
                }
                if(bx[j]-r<=20)
                {
                    bx[j]+=100;
                }
                if(roundcount%2==1)
                {
                    if(bx[j]-r<=690)
                    {
                        bx[j]+=100;
                    }
                }
                readimagefile("kabadi2.gif", bx[j]-r, by[j]-r, bx[j]+r, by[j]+r);
                indicatorsolo(i);
                j=j_other;
            }
}

void com_attack(int& en)
{
    int ran[3];
    int cv, dp;
    float dist, mi=10000, temp, distx, disty;
    for(cv=1;cv<=5;cv++)    //Calculates which defending player is closest.
    {
        dist=sqrt(abs(((ax[cv]-bx[j])*(ax[cv]-bx[j]))+((ay[cv]-by[j]))*(ay[cv]-by[j])));
        if(dist<=mi && noteli[cv]==1)
        {
            mi=dist;
            dp=cv;
        }
    }
    temp=dist;
    if(bx[j]>=ax[dp])
    {
        ran[0]='j';
    }
    else
    {
        ran[0]='l';
    }
    if(by[j]>ay[dp])
    {
        ran[1]='i';
    }
    else
    {
        ran[1]='k';
    }
    if(abs(bx[j]-ax[dp])>=abs(by[j]-ay[dp]))
    {
        c=ran[0];
    }
    else
    {
        c=ran[1];
    }
    if(energyb[j]>=1330 && en!=0)
    {
        c='b';
        en--;
    }
    if(c=='j' || c=='J')
            {
                readimagefile("EnergyFiller1.jpg", bx[j]-r, by[j]-r, bx[j]+r, by[j]+r);
                if(j==1)
                {
                    bx[j]-=50;
                }
                else if(j==2)
                {
                    bx[j]-=35;
                }
                else if(j==3)
                {
                    bx[j]-=70;
                }
                else if(j==4)
                {
                    bx[j]-=85;
                }
                else
                {
                    bx[j]-=50;
                }
                if(bx[j]-r<=20)
                {
                    bx[j]+=100;
                }
                readimagefile("kabadi2.gif", bx[j]-r, by[j]-r, bx[j]+r, by[j]+r);
                indicatorsolo(i);
                j=j_other;
            }
            if(c=='l' || c=='L')
            {

                readimagefile("EnergyFiller1.jpg", bx[j]-r, by[j]-r, bx[j]+r, by[j]+r);
                if(j==1)
                {
                    bx[j]+=50;
                }
                else if(j==2)
                {
                    bx[j]+=35;
                }
                else if(j==3)
                {
                    bx[j]+=70;
                }
                else if(j==4)
                {
                    bx[j]+=85;
                }
                else
                {
                    bx[j]+=50;
                }
                if(bx[j]+r>=1380)
                {
                    bx[j]-=100;
                }
                if(bx[j]+r>=690)
                {
                    bx[j]-=100;
                }
                readimagefile("kabadi2.gif", bx[j]-r, by[j]-r, bx[j]+r, by[j]+r);
                indicatorsolo(i);
                j=j_other;
            }
            if(c=='i' || c=='I')
            {

                readimagefile("EnergyFiller1.jpg", bx[j]-r, by[j]-r, bx[j]+r, by[j]+r);
                if(j==1)
                {
                    by[j]-=50;
                }
                else if(j==2)
                {
                    by[j]-=35;
                }
                else if(j==3)
                {
                    by[j]-=70;
                }
                else if(j==4)
                {
                    by[j]-=85;
                }
                else
                {
                    by[j]-=50;
                }
                if(by[j]-r<=r)
                {
                    by[j]+=70;
                }
                readimagefile("kabadi2.gif", bx[j]-r, by[j]-r, bx[j]+r, by[j]+r);
                indicatorsolo(i);
                j=j_other;
            }
            if(c=='k' || c=='K')
            {
                readimagefile("EnergyFiller1.jpg", bx[j]-r, by[j]-r, bx[j]+r, by[j]+r);
                if(j==1)
                {
                    by[j]+=50;
                }
                else if(j==2)
                {
                    by[j]+=35;
                }
                else if(j==3)
                {
                    by[j]+=70;
                }
                else if(j==4)
                {
                    by[j]+=85;
                }
                else
                {
                    by[j]+=50;
                }
                if(by[j]+r>=720)
                {
                    by[j]-=100;
                }
                readimagefile("kabadi2.gif", bx[j]-r, by[j]-r, bx[j]+r, by[j]+r);
                indicatorsolo(i);
                j=j_other;
            }
            if(c=='b' || c=='B')
            {
                if(energyb[j]>=1341)
                {
                    energyb[j]=1330;
                }
                else if(energyb[j]<=400)
                {
                    energyb[j]=400;
                }
                else
                {
                    energyb[j]-=10;
                }
            }

}

void com_defence(int& loop)
{
    int ran[3];
    int cv, dp, ct=5;
    float dist, mi=10000, temp, distx, disty;
    ct=5;
    for(cv=1;cv<=5;cv++)    //Calculates which defending player is closest.
    {

        dist=sqrt(abs(((ax[i]-bx[cv])*(ax[i]-bx[cv]))+((ay[i]-by[cv]))*(ay[i]-by[cv])));
        if(dist<=mi && notelim[cv]==1)
        {
            mi=dist;
            dp=cv;
        }
    }
    j=dp;
    temp=dist;
    if(bx[j]<=ax[i])
    {
        ran[0]='j';
    }
    else
    {
        ran[0]='l';
    }
    if(by[j]<ay[i])
    {
        ran[1]='i';
    }
    else
    {
        ran[1]='k';
    }
    if(abs(bx[j]-ax[i])<=abs(by[j]-ay[i]))
    {
        c=ran[0];
    }
    else
    {
        c=ran[1];
    }
    if(c=='j' || c=='J' && notelim[j]==1)
            {
                readimagefile("EnergyFiller1.jpg", bx[j]-r, by[j]-r-r, bx[j]+r, by[j]+r);
                if(j==1)
                {
                    bx[j]-=50;
                }
                else if(j==2)
                {
                    bx[j]-=35;
                }
                else if(j==3)
                {
                    bx[j]-=70;
                }
                else if(j==4)
                {
                    bx[j]-=85;
                }
                else
                {
                    bx[j]-=50;
                }
                if(bx[j]-r<=20)
                {
                    bx[j]+=100;
                }
                if(bx[j]-r<=700)
                {
                    bx[j]+=100;
                }
                readimagefile("kabadi2.gif", bx[j]-r, by[j]-r, bx[j]+r, by[j]+r);
                indicatorsolo(i);
                j=j_other;
            }
            if(c=='l' || c=='L' && notelim[j]==1)
            {

                readimagefile("EnergyFiller1.jpg", bx[j]-r, by[j]-r-r, bx[j]+r, by[j]+r);
                if(j==1)
                {
                    bx[j]+=50;
                }
                else if(j==2)
                {
                    bx[j]+=35;
                }
                else if(j==3)
                {
                    bx[j]+=70;
                }
                else if(j==4)
                {
                    bx[j]+=85;
                }
                else
                {
                    bx[j]+=50;
                }
                if(bx[j]+r>=1380)
                {
                    bx[j]-=100;
                }
                readimagefile("kabadi2.gif", bx[j]-r, by[j]-r, bx[j]+r, by[j]+r);
                indicatorsolo(i);
                j=j_other;
            }
            if(c=='i' || c=='I' && notelim[j]==1)
            {

                readimagefile("EnergyFiller1.jpg", bx[j]-r, by[j]-r-r, bx[j]+r, by[j]+r);
                if(j==1)
                {
                    by[j]-=50;
                }
                else if(j==2)
                {
                    by[j]-=35;
                }
                else if(j==3)
                {
                    by[j]-=70;
                }
                else if(j==4)
                {
                    by[j]-=85;
                }
                else
                {
                    by[j]-=50;
                }
                if(by[j]-r<=r)
                {
                    by[j]+=70;
                }
                readimagefile("kabadi2.gif", bx[j]-r, by[j]-r, bx[j]+r, by[j]+r);
                indicatorsolo(i);
                j=j_other;
            }
            if(c=='k' || c=='K' && notelim[j]==1)
            {
                readimagefile("EnergyFiller1.jpg", bx[j]-r, by[j]-r-r, bx[j]+r, by[j]+r);
                if(j==1)
                {
                    by[j]+=50;
                }
                else if(j==2)
                {
                    by[j]+=35;
                }
                else if(j==3)
                {
                    by[j]+=70;
                }
                else if(j==4)
                {
                    by[j]+=85;
                }
                else
                {
                    by[j]+=50;
                }
                if(by[j]+r>=720)
                {
                    by[j]-=100;
                }
                readimagefile("kabadi2.gif", bx[j]-r, by[j]-r, bx[j]+r, by[j]+r);
                indicatorsolo(i);
                j=j_other;
            }
            if(c=='p' || c=='P')
            {
            readimagefile("EnergyFiller1.jpg", bx[j]-r, by[j]-r-r-r, bx[j]+r, by[j]-r);
                while(notelim[j]==0)
                {
                j++;
                if(j>5)
                {
                    j=1;
                }
                }
            readimagefile("kabadi2.gif", bx[j]-r, by[j]-r, bx[j]+r, by[j]+r);
            indicatorsolo(i);
            energy2_clear();
            energy2(j);
            once--;
            }
}

void solo_move()    //Same as "players_move".
{
            c=(char)getch();
            i_other=i;
            j_other=j;
            if(c=='a' || c=='A')
            {
                readimagefile("EnergyFiller1.jpg", ax[i]-r, ay[i]-r-r, ax[i]+r, ay[i]+r);
                if(i==1)
                {
                    ax[i]-=50;
                }
                else if(i==2)
                {
                    ax[i]-=35;
                }
                else if(i==3)
                {
                    ax[i]-=70;
                }
                else if(i==4)
                {
                    ax[i]-=85;
                }
                else
                {
                    ax[i]-=50;
                }
                if(ax[i]-r<=20)
                {
                    ax[i]+=100;
                }
                readimagefile("kabadi1.gif", ax[i]-r, ay[i]-r, ax[i]+r, ay[i]+r);
                indicatorsolo(i);
                i=i_other;
            }
            if(c=='d' || c=='D')
            {

                readimagefile("EnergyFiller1.jpg", ax[i]-r, ay[i]-r-r, ax[i]+r, ay[i]+r);
                if(i==1)
                {
                    ax[i]+=50;
                }
                else if(i==2)
                {
                    ax[i]+=35;
                }
                else if(i==3)
                {
                    ax[i]+=70;
                }
                else if(i==4)
                {
                    ax[i]+=85;
                }
                else
                {
                    ax[i]+=50;
                }
                if(ax[i]+r>=1380)
                {
                    ax[i]-=100;
                }
                if(ax[i]+r>=685 && roundcount%2==0)
                {
                    ax[i]-=100;
                }
                readimagefile("kabadi1.gif", ax[i]-r, ay[i]-r, ax[i]+r, ay[i]+r);
                indicatorsolo(i);
                i=i_other;
            }
            if(c=='w' || c=='W')
            {

                readimagefile("EnergyFiller1.jpg", ax[i]-r, ay[i]-r-r, ax[i]+r, ay[i]+r);
                if(i==1)
                {
                    ay[i]-=50;
                }
                else if(i==2)
                {
                    ay[i]-=35;
                }
                else if(i==3)
                {
                    ay[i]-=70;
                }
                else if(i==4)
                {
                    ay[i]-=85;
                }
                else
                {
                    ay[i]-=50;
                }
                if(ay[i]-r<=r)
                {
                    ay[i]+=70;
                }
                readimagefile("kabadi1.gif", ax[i]-r, ay[i]-r, ax[i]+r, ay[i]+r);
                indicatorsolo(i);
                i=i_other;
            }
            if(c=='s' || c=='S')
            {
                readimagefile("EnergyFiller1.jpg", ax[i]-r, ay[i]-r-r, ax[i]+r, ay[i]+r);
                if(i==1)
                {
                    ay[i]+=50;
                }
                else if(i==2)
                {
                    ay[i]+=35;
                }
                else if(i==3)
                {
                    ay[i]+=70;
                }
                else if(i==4)
                {
                    ay[i]+=85;
                }
                else
                {
                    ay[i]+=50;
                }
                if(ay[i]+r>=720)
                {
                    ay[i]-=70;
                }
                readimagefile("kabadi1.gif", ax[i]-r, ay[i]-r, ax[i]+r, ay[i]+r);
                indicatorsolo(i);
                i=i_other;
            }
            if(c=='q' || c=='Q')
            {
                readimagefile("EnergyFiller1.jpg", ax[i]-r, ay[i]-r-r, ax[i]+r, ay[i]-r);
                i++;
                if(i>5)
                {
                    i=1;
                }
                readimagefile("kabadi1.gif", ax[i]-r, ay[i]-r, ax[i]+r, ay[i]+r);
                indicatorsolo(i);
                energy1_clear();
                energy1(i);
            }
            if(c=='c')
            {
                if(energya[i]>=energyad[i])
                {
                    energya[i]=energyad[i];
                }
                else if(energya[i]<=20)
                {
                    energya[i]=20;
                }
                else
                {
                    energya[i]+=13;
                }
            }
}

void solo_defence() //Same as "plater2attack".
{
            c=(char)getch();
            i_other=i;
            j_other=j;
            if(c=='a' || c=='A' && noteli[i]==1)
            {
                readimagefile("EnergyFiller1.jpg", ax[i]-r, ay[i]-r-r, ax[i]+r, ay[i]+r);
                if(i==1)
                {
                    ax[i]-=50;
                }
                else if(i==2)
                {
                    ax[i]-=35;
                }
                else if(i==3)
                {
                    ax[i]-=70;
                }
                else if(i==4)
                {
                    ax[i]-=85;
                }
                else
                {
                    ax[i]-=50;
                }
                if(ax[i]<=r)
                {
                    ax[i]+=80;
                }
                readimagefile("kabadi1.gif", ax[i]-r, ay[i]-r, ax[i]+r, ay[i]+r);
                indicatorsolo(i);
                i=i_other;
            }
            if(c=='d' || c=='D' && noteli[i]==1)
            {

                readimagefile("EnergyFiller1.jpg", ax[i]-r, ay[i]-r-r, ax[i]+r, ay[i]+r);
                if(i==1)
                {
                    ax[i]+=50;
                }
                else if(i==2)
                {
                    ax[i]+=35;
                }
                else if(i==3)
                {
                    ax[i]+=70;
                }
                else if(i==4)
                {
                    ax[i]+=85;
                }
                else
                {
                    ax[i]+=50;
                }
                if(ax[i]+r>=1380)
                {
                    ax[i]-=100;
                }
                if(ax[i]+r>690)
                {
                    ax[i]=670-r;
                }
                readimagefile("kabadi1.gif", ax[i]-r, ay[i]-r, ax[i]+r, ay[i]+r);
                indicatorsolo(i);
                i=i_other;
            }
            if(c=='w' || c=='W' && noteli[i]==1)
            {

                readimagefile("EnergyFiller1.jpg", ax[i]-r, ay[i]-r-r, ax[i]+r, ay[i]+r);
                if(i==1)
                {
                    ay[i]-=50;
                }
                else if(i==2)
                {
                    ay[i]-=35;
                }
                else if(i==3)
                {
                    ay[i]-=70;
                }
                else if(i==4)
                {
                    ay[i]-=85;
                }
                else
                {
                    ay[i]-=50;
                }
                if(ay[i]<=r)
                {
                    ay[i]+=80;
                }
                readimagefile("kabadi1.gif", ax[i]-r, ay[i]-r, ax[i]+r, ay[i]+r);
                indicatorsolo(i);
                i=i_other;
            }
            if(c=='s' || c=='S' && noteli[i]==1)
            {
                readimagefile("EnergyFiller1.jpg", ax[i]-r, ay[i]-r-r, ax[i]+r, ay[i]+r);
                if(i==1)
                {
                    ay[i]+=50;
                }
                else if(i==2)
                {
                    ay[i]+=35;
                }
                else if(i==3)
                {
                    ay[i]+=70;
                }
                else if(i==4)
                {
                    ay[i]+=85;
                }
                else
                {
                    ay[i]+=50;
                }
                if(ay[i]>=720)
                {
                    ay[i]-=80;
                }
                readimagefile("kabadi1.gif", ax[i]-r, ay[i]-r, ax[i]+r, ay[i]+r);
                indicatorsolo(i);
                i=i_other;
            }
            if(c=='q' || c=='Q')
            {
                readimagefile("EnergyFiller1.jpg", ax[i]-r, ay[i]-r-r, ax[i]+r, ay[i]-r);
                do
                {
                i++;
                if(i>5)
                {
                    i=1;
                }
                }
                while(notelim[i]==0);
                readimagefile("kabadi1.gif", ax[i]-r, ay[i]-r, ax[i]+r, ay[i]+r);
                indicatorsolo(i);
                energy1_clear();
                energy1(i);
            }
            if(c=='c')
            {
                if(energya[i]>=energyad[i])
                {
                    energya[i]=energyad[i];
                }
                else if(energya[i]<=20)
                {
                    energya[i]=20;
                }
                else
                {
                    energya[i]+=13;
                }
            }
}

void solo_attack()  //Same as "player1attack".
{
            c=(char)getch();
            i_other=i;
            j_other=j;
            if(c=='a' || c=='A')
            {
                readimagefile("EnergyFiller1.jpg", ax[i]-r, ay[i]-r-r, ax[i]+r, ay[i]+r);
                if(i==1)
                {
                    ax[i]-=50;
                }
                else if(i==2)
                {
                    ax[i]-=35;
                }
                else if(i==3)
                {
                    ax[i]-=70;
                }
                else if(i==4)
                {
                    ax[i]-=85;
                }
                else
                {
                    ax[i]-=50;
                }
                if(ax[i]-r<=r)
                {
                    ax[i]+=100;
                }
                if(ax[i]-r<=695)
                {
                    ax[i]+=100;
                }
                readimagefile("kabadi1.gif", ax[i]-r, ay[i]-r, ax[i]+r, ay[i]+r);
                indicatorsolo(i);
                i=i_other;
            }
            if(c=='d' || c=='D')
            {

                readimagefile("EnergyFiller1.jpg", ax[i]-r, ay[i]-r-r, ax[i]+r, ay[i]+r);
                if(i==1)
                {
                    ax[i]+=50;
                }
                else if(i==2)
                {
                    ax[i]+=35;
                }
                else if(i==3)
                {
                    ax[i]+=70;
                }
                else if(i==4)
                {
                    ax[i]+=85;
                }
                else
                {
                    ax[i]+=50;
                }
                if(ax[i]+r>=1380)
                {
                    ax[i]-=100;
                }
                readimagefile("kabadi1.gif", ax[i]-r, ay[i]-r, ax[i]+r, ay[i]+r);
                indicatorsolo(i);
                i=i_other;
            }
            if(c=='w' || c=='W')
            {

                readimagefile("EnergyFiller1.jpg", ax[i]-r, ay[i]-r-r, ax[i]+r, ay[i]+r);
                if(i==1)
                {
                    ay[i]-=50;
                }
                else if(i==2)
                {
                    ay[i]-=35;
                }
                else if(i==3)
                {
                    ay[i]-=70;
                }
                else if(i==4)
                {
                    ay[i]-=85;
                }
                else
                {
                    ay[i]-=50;
                }
                if(ay[i]-r<=20)
                {
                    ay[i]+=70;
                }
                readimagefile("kabadi1.gif", ax[i]-r, ay[i]-r, ax[i]+r, ay[i]+r);
                indicatorsolo(i);
                i=i_other;
            }
            if(c=='s' || c=='S')
            {
                readimagefile("EnergyFiller1.jpg", ax[i]-r, ay[i]-r-r, ax[i]+r, ay[i]+r);
                if(i==1)
                {
                    ay[i]+=50;
                }
                else if(i==2)
                {
                    ay[i]+=35;
                }
                else if(i==3)
                {
                    ay[i]+=70;
                }
                else if(i==4)
                {
                    ay[i]+=85;
                }
                else
                {
                    ay[i]+=50;
                }
                if(ay[i]+r>=720)
                {
                    ay[i]-=80;
                }
                readimagefile("kabadi1.gif", ax[i]-r, ay[i]-r, ax[i]+r, ay[i]+r);
                indicatorsolo(i);
                i=i_other;
            }
            if(c=='c')
            {
                if(energya[i]>=energyad[i])
                {
                    energya[i]=energyad[i];
                }
                else if(energya[i]<=20)
                {
                    energya[i]=20;
                }
                else
                {
                    energya[i]+=10;
                }
            }

}

void solo_round_start() //Same as "round_start".
{
    if(roundcount%2==1)
    {
        once=3;
        while(ax[i]<690)
        {
            energy1_clear();
            energy1(i);
            solo_move();
            com_move(once);
            midline();
            round();
            readimagefile("kabadi1.gif", ax[i]-r, ay[i]-r, ax[i]+r, ay[i]+r);
            energy1_clear();
            energy2_clear();
            energy1(i);
            energy2(j);
        }
            int remain=5;
            while(ax[i]>690)
            {
                energy2_clear();
                energy2(j);
                solo_attack();
                com_defence(loop);
                midline();
                round();
                readimagefile("kabadi1.gif", ax[i]-r, ay[i]-r, ax[i]+r, ay[i]+r);
                energy1_clear();
                energy2_clear();
                energy1(i);
                energy2(j);
                for(loop=1;loop<=5;loop++)
                {
                    if((ax[i]+r>=bx[loop]-r && ay[i]+r>=by[loop]-r && ax[i]+r<=bx[loop]+r+20 && ay[i]+r<=by[loop]+r+20) && notelim[loop]==1)
                    {
                        mciSendString("play eliminate.wav", NULL, 0, NULL);
                        readimagefile("EnergyFiller1.jpg", bx[loop]-r, by[loop]-r, bx[loop]+r, by[loop]+r);
                        readimagefile("kabadi1.gif", ax[i]-r, ay[i]-r, ax[i]+r, ay[i]+r);
                        energy1_clear();
                        energy2_clear();
                        energy1(i);
                        energy2(j);
                        midline();
                        readimagefile("kabadi1.gif", ax[i]-r, ay[i]-r, ax[i]+r, ay[i]+r);
                        energy1_clear();
                        energy2_clear();
                        energy1(i);
                        energy2(j);
                        round();
                        notelim[loop]=0;
                        remain--;
                        pp1+=5;
                        points1();
                        break;
                    }
                }
                while(notelim[j]==0)
                        {
                            readimagefile("EnergyFiller1.jpg", bx[j]-r, by[j]-r-r, bx[j]+r, by[j]+r);
                            j++;
                            if(j>5)
                            {
                                j=1;
                            }
                            if(remain==0)
                            {
                                break;
                            }
                            else
                            {
                                indicatorsolo(i);
                                readimagefile("kabadi1.gif", ax[i]-r, ay[i]-r, ax[i]+r, ay[i]+r);
                            }
                        }
                if(remain==0 || energya[i]<=21)
                {
                    delay(800);
                    break;
                }
                energy1_clear();
                energya[i]-=7;
                if(energya[i]<=20)
                {
                    energya[i]=20;
                    break;
                }
                energy1(i);
            }
        }
    else
    {
        while(bx[j]>690)
            {
                energy2_clear();
                energy2(j);
                com_move(once);
                solo_move();
                round();
                readimagefile("kabadi2.gif", bx[j]-r, by[j]-r, bx[j]+r, by[j]+r);
                energy1_clear();
                energy2_clear();
                energy1(i);
                energy2(j);
            }
            int remain=5;
            int en=3;
            while(bx[j]<690)
            {
                energy1_clear();
                energy1(i);
                com_attack(en);
                solo_defence();
                midline();
                readimagefile("kabadi2.gif", bx[j]-r, by[j]-r, bx[j]+r, by[j]+r);
                energy1_clear();
                energy2_clear();
                energy1(i);
                energy2(j);
                round();
                for(loop=1;loop<=5;loop++)
                {
                    if(bx[j]-r<=ax[loop]+r && by[j]-r>=ay[loop]-r && bx[j]-r>=ax[loop]-r-20 && by[j]<=ay[loop]+r+20 && noteli[loop]==1)
                    {
                        mciSendString("play eliminate.wav", NULL, 0, NULL);
                        readimagefile("EnergyFIller1.jpg", ax[loop]-r, ay[loop]-r, ax[loop]+r, ay[loop]+r);
                        readimagefile("kabadi2.gif", bx[j]-r, by[j]-r, bx[j]+r, by[j]+r);
                        energy1_clear();
                        energy2_clear();
                        energy1(i);
                        energy2(j);
                        midline();
                        readimagefile("kabadi2.gif", bx[j]-r, by[j]-r, bx[j]+r, by[j]+r);
                        energy1_clear();
                        energy2_clear();
                        energy1(i);
                        energy2(j);
                        round();
                        remain--;
                        noteli[loop]=0;
                        pp2+=5;
                        points2();
                        break;
                    }
                }
                while(noteli[i]==0)
                        {
                            readimagefile("EnergyFiller1.jpg", ax[i]-r, ay[i]-r-r-r, ax[i]+r, ay[i]+r);
                            i++;
                            if(i>5)
                            {
                                i=1;
                            }
                            if(remain==0)
                            {
                                break;
                            }
                            else
                            {
                                indicatorsolo(i);
                                readimagefile("kabadi1.gif", ax[i]-r, ay[i]-r, ax[i]+r, ay[i]+r);
                            }
                        }
                if(remain==0 || energyb[j]>=1341)
                {
                    delay(800);
                    break;
                }
                energy2_clear();
                energyb[j]+=6;
                if(energyb[j]>=1340)
                {
                    energyb[j]=1341;
                    break;
                }
                energy2(j);
            }
    }
}

void solo_new() //Same as "new_game".
{
    cleardevice();
    for(v=1;v<=5;v++)
    {
        ax[v]=axd[v];
        bx[v]=bxd[v];
        ay[v]=ayd[v];
        by[v]=byd[v];
        energya[v]=energyad[v];
        energyb[v]=energybd[v];
        notelim[v]=1;
        noteli[v]=1;
    }
    notelim[0]=0;
    noteli[0]=0;
    i=1;
    j=1;
    cleardevice();
    field();
    draw_team1(i);
    draw_team2(j);
    indicatorsolo(i);
    solo_round_start();
}

void main_menu(int& mmkey)
{
    mciSendString("play menu.wav", NULL, 0, NULL);  //Starts playing main menu music.
    mmkey=1;
    char mmc;
    mmc=68;
    cleardevice();
    readimagefile("main menu.jpg", 0, 0, 1380, 820);    //Draws main menu.
    readimagefile("pointer main menu.jpg", 330, 340, 380, 380); //Draws main menu indicator.
    do
    {
        mmc=(char)getch();
        if(mmc==80)
        {
            mmkey++;    //Moves down if down-arrow key is pressed.
        }
        else if(mmc==72)
        {
            mmkey--;    //Moves up if up-arrow key is pressed.
        }
        else if(mmc==13)    //Exits main-menu and executes function if Enter key is pressed.
        {
            break;
        }
        if(mmkey<1)     //Returns to lowest menu option.
        {
            mmkey=6;
        }
        else if(mmkey>6)    //Returns to first menu option.
        {
            mmkey=1;
        }
        if(mmkey==1)
        {
            readimagefile("menufiller.jpg", 330, 330, 380, 1000);       //Erases last pointer location.
            readimagefile("pointer main menu.jpg", 330, 340, 380, 380); //Draws new pointer location.
        }
        else if(mmkey==2)
        {
            readimagefile("menufiller.jpg", 330, 330, 380, 1000);
            readimagefile("pointer main menu.jpg", 330, 415, 380, 455);
        }
        else if(mmkey==3)
        {
            readimagefile("menufiller.jpg", 330, 330, 380, 1000);
            readimagefile("pointer main menu.jpg", 330, 480, 380, 520);
        }
        else if(mmkey==4)
        {
            readimagefile("menufiller.jpg", 330, 330, 380, 1000);
            readimagefile("pointer main menu.jpg", 330, 550, 380, 590);
        }
        else if(mmkey==5)
        {
            readimagefile("menufiller.jpg", 330, 330, 380, 1000);
            readimagefile("pointer main menu.jpg", 330, 620, 380, 660);
        }
        else if(mmkey==6)
        {
            readimagefile("menufiller.jpg", 330, 330, 380, 1000);
            readimagefile("pointer main menu.jpg", 330, 690, 380, 730);
        }

    }
    while(mmc!=13); //Takes input until Enter-key is pressed.
}

void leaderboard()  //Prints the past winners from first to latest.
{
    cleardevice();
    readimagefile("leaderboard.jpg", 0, 0, 1380, 750);
    char buff[1000], tmp[100][1000], tp=1, namcou=11;
    int lx=300;
    int ly=147;
    FILE *highs;
    highs=fopen("leaderboard.txt", "r");
    while(fgets(buff, 100, highs) != NULL)
    {
        strcpy(tmp[tp], buff);
        tp++;
    }
    tp--;
    while(tp!=0)
    {
        if(namcou==0)
        {
            break;
        }
        setcolor(WHITE);
        settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 6);
        outtextxy(lx, ly, tmp[tp]);
        ly+=57;
        tp--;
        namcou--;
    }
    getch();
}

void two_player()
{
        mciSendString("stop menu.wav", NULL, 0, NULL);  //Stops menu music.
        roundcount=1;   //Starts game from round 1.
        pp1=0;  //Initially Team 1 scores are 0.
        pp2=0;  //Initially Team 2 scores are 0.
        cleardevice();
        for(roundcount=1;roundcount<=10;roundcount++)   //Runs 10 rounds.
        {
            song();
            new_game();
            song_end();
            cleardevice();
            round_over();
            mciSendString("play roundover.wav", NULL, 0, NULL);
            delay(1200);
            mciSendString("stop roundover.wav", NULL, 0, NULL);
        }
        if(pp1>pp2) //If 1p wins.
        {
            readimagefile("1pwin.jpg", 0, 0, 1380, 820);\
            mciSendString("play tie.wav", NULL, 0, NULL);
            delay(2000);
            mciSendString("stop tie.wav", NULL, 0, NULL);
            cleardevice();
        }
        else if(pp2>pp1)    //If 2p wins.
        {
            readimagefile("2pwin.jpg", 0, 0, 1380, 820);
            mciSendString("play tie.wav", NULL, 0, NULL);
            delay(2000);
            mciSendString("stop tie.wav", NULL, 0, NULL);
            cleardevice();
        }
        else    //If the game is tied.
        {
            readimagefile("tie.jpg", 0, 0, 1380, 820);
            mciSendString("play tie.wav", NULL, 0, NULL);
            delay(2000);
            mciSendString("stop tie.wav", NULL, 0, NULL);
            cleardevice();
        }
        enter_name();
        readimagefile("gameover.jpg", 0, 0, 1380, 820);
        mciSendString("play gameover.wav", NULL, 0, NULL);
        delay(2500);
        mciSendString("stop gameover.wav", NULL, 0, NULL);
}

void one_player()   //Same as "two_player".
{
        mciSendString("stop menu.wav", NULL, 0, NULL);
        roundcount=1;
        pp1=0;
        pp2=0;
        cleardevice();
        for(roundcount=1;roundcount<=10;roundcount++)
        {
            song();
            solo_new();
            song_end();
            cleardevice();
            round_over();
            mciSendString("play roundover.wav", NULL, 0, NULL);
            delay(1200);
            mciSendString("stop roundover.wav", NULL, 0, NULL);
        }
        if(pp1>pp2)
        {
            readimagefile("solowin.jpg", 0, 0, 1380, 820);
            mciSendString("play win.wav", NULL, 0, NULL);
            delay(1000);
            mciSendString("stop win.wav", NULL, 0, NULL);
            cleardevice();
        }
        else if(pp2>pp1)
        {
            readimagefile("sololose.jpg", 0, 0, 1380, 820);
            mciSendString("play lose.wav", NULL, 0, NULL);
            delay(1000);
            mciSendString("stop lose.wav", NULL, 0, NULL);
            cleardevice();
        }
        else
        {
            readimagefile("solotie.jpg", 0, 0, 1380, 820);
            mciSendString("play tie.wav", NULL, 0, NULL);
            delay(1000);
            mciSendString("stop tie.wav", NULL, 0, NULL);
            cleardevice();
        }
        enter_name();
        readimagefile("gameover.jpg", 0, 0, 1380, 820);
        delay(1000);
}

void instructions() //Draws the instructions page. Returns to menu if any button is pressed.
{
        readimagefile("howto.jpg", 0, 0, 1380, 750);
        getch();
        cleardevice();
        readimagefile("instructions.jpg", 0, 0, 1380, 750);
        c=(char)getch();
}

void credits()      //Prints names of people whose assistance contributed to the game. Returns to main menu once it ends.
{
        mciSendString("stop menu.wav", NULL, 0, NULL);
        mciSendString("play friends.wav", NULL, 0, NULL);
        readimagefile("creditsmade.jpg", 0, 0, 1380, 750);
        delay(6500);
        cleardevice();
        readimagefile("creditsspecialt.jpg", 0, 0, 1380, 750);
        delay(9000);
        cleardevice();
        readimagefile("creditsspecial1.jpg", 0, 0, 1380, 750);
        delay(9500);
        cleardevice();
        readimagefile("creditsspecial.jpg", 0, 0, 1380, 750);
        delay(9500);
        cleardevice();
        readimagefile("creditsthanks.jpg", 0, 0, 1380, 750);
        delay(9500);
        mciSendString("stop friends.wav", NULL, 0, NULL);
        cleardevice();
}

void game()         //Takes input from main menu and runs function.
{
    mmkey=1;
    main_menu(mmkey);
    roundcount=1;

    if(mmkey==1)
    {
        one_player();
        game();
    }
    else if(mmkey==2)
    {
        two_player();
        game();
    }
    else if(mmkey==3)
    {
        leaderboard();
        game();
    }
    else if(mmkey==4)
    {
        instructions();
        game();
    }
    else if(mmkey==5)
    {
        credits();
        game();
    }
}

main()
{
    initwindow(1380, 750);
    game();
    closegraph();
    return 0;
}
