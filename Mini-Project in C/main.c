
// printf is used for displaying on console and scanf is used for taking input from console
// fprintf is used for printing or storing in text file and fscanf is used to read data from textfile while for fscanf we need to use pointer created for the file

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>


//Creating structures
struct playlist
{
    char name[100];
    char singer[100];
    char album[100];
    char sr[4];
}p;

struct node  //for doubly linkedlist
{
    char sr[4];
    char name[60];
    char singer[60];
    char album[60];
    struct node *prev,*next;
}n;
struct node *start=NULL;

struct music_sort
{
    char mname[100];
    char msinger[100];
    char malbum[100];

}ms;
struct music_sort mssort[100],mstemp;

struct album_sort
{
    char aname[100];
    char asinger[100];
    char aalbum[100];
}as;
struct album_sort assort[100],astemp;

struct singer_sort
{
    char sname[100];
    char ssinger[100];
    char salbum[100];
}ss;
struct singer_sort sssort[100],sstemp;

struct create_playlist
{
    char csr[4];
    char cname[100];
    char csinger[100];
    char calbum[100];
}cp;
struct create_playlist playlist[100],cplaylist[100];


//Creating Functions
void showMusic();
void showplaylistMusic();
void inventory();
void sortmusic();
void sortalbum();
void sortsinger();
void addMusic();
void createPlaylist();


//Declaring Global Variable
FILE *fs;  //declaring file pointer
int length;


//main Function
void main()
{
    int op; //initializing for switch
    do{
        printf("<:::::Playlist Manager:::::>\n");
        printf("1 : Show All Music\n2 : Add New Music in Database\n3 : Playlist\n4 : Exit\nYour Choice >>> ");
        scanf("%d",&op);
        printf("\n");
        getchar();  //to catch nextline of scanf
        switch(op)
        {
            case 1 : showMusic();
                     break;

            case 2 : addMusic();
                     break;

            case 3 : createPlaylist();
                     break;

            case 4 : printf("Exit...");
                     break;

            default : printf("Select Correct Option...\n");
                      break;
        }
      }while(op!=4);
    getch();
}


//showMusic Function
void showMusic()
{
    int op2;  //initializing for switch
    printf("According to :\n1 : Default\n2 : Music Name\n3 : Album Name\n4 : Singer Name\nYour Option >>> ");
    scanf("%d",&op2);
    getchar();  //to catch nextline of scanf
    printf("\n");
    switch(op2)
    {
        case 1 : printf("<----Default---->\n");
                 inventory();
                 break;

        case 2 : printf("<----Music Name Sorted---->\n");
                 sortmusic();
                 break;

        case 3 : printf("<----Album Name Sorted---->\n");
                 sortalbum();
                 break;

        case 4 : printf("<----Singer Name Sorted---->\n");
                 sortsinger();
                 break;

        default : printf("Select correct option to proceed...\n\n");
                  break;
    }
}


// showplaylistMusic function
void showplaylistMusic()
{
    int op2;  //initializing for switch
    printf("According to :\n1 : Music Name\n2 : Album Name\n3 : Singer Name\nYour Option >>> ");
    scanf("%d",&op2);
    getchar();  //to catch nextline of scanf
    printf("\n");
    switch(op2)
    {
        case 1 : printf("<----Music Name Sorted---->\n");
                 sortmusic();
                 break;

        case 2 : printf("<----Album Name Sorted---->\n");
                 sortalbum();
                 break;

        case 3 : printf("<----Singer Name Sorted---->\n");
                 sortsinger();
                 break;

        default : printf("Select correct option to proceed...\n\n");
                  break;
    }
}


//inventory Function or default function
void inventory()
{
    fs=fopen("musicDB.txt","r"); //opening file in read mode
    if(fs==NULL)  //if file is empty
    {
        puts("Null");
        fclose(fs);  //closing file
    }
    else
    {
        while(fscanf (fs,"%[^\t]\t%[^\t]\t%[^\t]\t%[^\n]\n",p.sr,p.name,p.album,p.singer)!=EOF )  //reading from file and storing into playlist structure
            {
                printf("Sr. No.: %s\nMusic  : %s\nAlbum  : %s\nSinger : %s\n\n",p.sr,p.name,p.album,p.singer);
            }
        printf("\n");
    }
    fclose(fs);  //closing file
}


// sortmusic Function
void sortmusic()
{
    int i=0;  //initializing for structure array
    fs=fopen("musicDB.txt","r");  //opening file in read mode
    if(fs==NULL)  //if file is empty
    {
        puts("Null");
        fclose(fs);  //closing file
    }
    else
    {
        while(fscanf (fs,"%[^\t]\t%[^\t]\t%[^\t]\t%[^\n]\n",p.sr,p.name,p.album,p.singer)!=EOF ) //reading from file and storing into playlist structure
            {
                strcpy(mssort[i].mname,p.name);  //copying to music_sort structure from playlist structure
                strcpy(mssort[i].malbum,p.album);  //copying to music_sort structure from playlist structure
                strcpy(mssort[i].msinger,p.singer);  //copying to music_sort structure from playlist structure
                i=i+1;
            }
    }
    fclose(fs);  //closing file
    length=i;  //storing number of lines of playlist database
    for(int j=0;j<i;j++)  //sorting music_sort structure according to name of music
    {
        for(int k=0;k<i-1;k++)
        {
            if(strcmp(mssort[k].mname,mssort[k+1].mname)>0)  //comparing string according to ascii value
            {
                mstemp=mssort[k+1];
                mssort[k+1]=mssort[k];
                mssort[k]=mstemp;
            }
        }
    }
    char cpsr[4];  //initializing for converting to string
    for(int x=0;x<i;x++)
    {
        itoa(x+1,cpsr,10);  //convert integer data-type to string type
        strcpy(playlist[x].csr,cpsr);  //copying serial number(cpsr) to create_playlist structure
        strcpy(playlist[x].cname,mssort[x].mname);  //copying to create_playlist structure
        strcpy(playlist[x].calbum,mssort[x].malbum);  //copying to create_playlist structure
        strcpy(playlist[x].csinger,mssort[x].msinger);  //copying to create_playlist structure
    }
    char msr[4];
    fs=fopen("musicsort.txt","w");  //opening file in write mode
    for(int l=0;l<i;l++)
    {
        itoa(l+1,msr,10);  //convert integer data-type to string type
        fprintf(fs,"%s\t%s\t%s\t%s\n",msr,mssort[l].mname,mssort[l].malbum,mssort[l].msinger);  //writing in musicsort file
        printf("Sr. No.: %s\nMusic  : %s\nAlbum  : %s\nSinger : %s\n\n",msr,mssort[l].mname,mssort[l].malbum,mssort[l].msinger);
    }
    fclose(fs);  //closing file
}


// sortalbum Function
void sortalbum()
{
    int i=0;
    fs=fopen("musicDB.txt","r");  //opening file in read mode
    if(fs==NULL)  //if file is empty
    {
        puts("Null");
        fclose(fs);  //closing file
    }
    else
    {
        while(fscanf (fs,"%[^\t]\t%[^\t]\t%[^\t]\t%[^\n]\n",p.sr,p.name,p.album,p.singer)!=EOF ) //reading from file and storing into playlist structure
            {
                strcpy(assort[i].aname,p.name);  //copying to album_sort structure from playlist structure
                strcpy(assort[i].aalbum,p.album);  //copying to album_sort structure from playlist structure
                strcpy(assort[i].asinger,p.singer);  //copying to album_sort structure from playlist structure
                i=i+1;
            }
    }
    fclose(fs);  //closing file
    length=i;  //storing number of lines of playlist database
    for(int j=0;j<i;j++)  //sorting album_sort structure according to album name of music
    {
        for(int k=0;k<i-1;k++)
        {
            if(strcmp(assort[k].aalbum,assort[k+1].aalbum)>0)  //comparing string according to ascii value
            {
                astemp=assort[k+1];
                assort[k+1]=assort[k];
                assort[k]=astemp;
            }
        }
    }
    char cpsr[4];
    for(int x=0;x<i;x++)
    {
        itoa(x+1,cpsr,10);  //convert integer data-type to string type
        strcpy(playlist[x].csr,cpsr);  //copying serial number(cpsr) to create_playlist structure
        strcpy(playlist[x].cname,assort[x].aname);  //copying to create_playlist structure
        strcpy(playlist[x].calbum,assort[x].aalbum);  //copying to create_playlist structure
        strcpy(playlist[x].csinger,assort[x].asinger);  //copying to create_playlist structure
    }
    char asr[4];
    fs=fopen("albumsort.txt","w");  //opening file in write mode
    for(int l=0;l<i;l++)
    {
        itoa(l+1,asr,10);  //convert integer data-type to string type
        fprintf(fs,"%s\t%s\t%s\t%s\n",asr,assort[l].aname,assort[l].aalbum,assort[l].asinger);  //writing in albumsort file
        printf("Sr. No.: %s\nAlbum  : %s\nMusic  : %s\nSinger : %s\n\n",asr,assort[l].aalbum,assort[l].aname,assort[l].asinger);
    }
    fclose(fs);  //closing file
}


// sortsinger Function
void sortsinger()
{
    int i=0;
    fs=fopen("musicDB.txt","r");  //opening file in read mode
    if(fs==NULL)
    {
        puts("Null");
        fclose(fs);  //closing file
    }
    else
    {
        while(fscanf (fs,"%[^\t]\t%[^\t]\t%[^\t]\t%[^\n]\n",p.sr,p.name,p.album,p.singer)!=EOF ) //reading from file and storing into playlist structure
            {
                strcpy(sssort[i].sname,p.name);
                strcpy(sssort[i].salbum,p.album);
                strcpy(sssort[i].ssinger,p.singer);
                i=i+1;
            }
    }
    fclose(fs);  //closing file
    length=i;  //storing number of lines of playlist database
    for(int j=0;j<i;j++)
    {
        for(int k=0;k<i-1;k++)
        {
            if(strcmp(sssort[k].ssinger,sssort[k+1].ssinger)>0)  //comparing string according to ascii value
            {
                sstemp=sssort[k+1];
                sssort[k+1]=sssort[k];
                sssort[k]=sstemp;
            }
        }
    }
    char cpsr[4];
    for(int x=0;x<i;x++)
    {
        itoa(x+1,cpsr,10);  //convert integer data-type to string type
        strcpy(playlist[x].csr,cpsr);  //copying serial number(cpsr) to create_playlist structure
        strcpy(playlist[x].cname,sssort[x].sname);  //copying to create_playlist structure
        strcpy(playlist[x].calbum,sssort[x].salbum);  //copying to create_playlist structure
        strcpy(playlist[x].csinger,sssort[x].ssinger);  //copying to create_playlist structure
    }
    char ssr[4];
    fs=fopen("singersort.txt","w");  //opening file in write mode
    for(int l=0;l<i;l++)
    {
        itoa(l+1,ssr,10);
        fprintf(fs,"%s\t%s\t%s\t%s\n",ssr,sssort[l].sname,sssort[l].salbum,sssort[l].ssinger);  //writing in singersort file
        printf("Sr. No.: %s\nSinger : %s\nMusic  : %s\nAlbum  : %s\n\n",ssr,sssort[l].ssinger,sssort[l].sname,sssort[l].salbum);
    }
    fclose(fs);  //closing file
}


// addMusic Function
void addMusic()
{
    fs=fopen("musicDB.txt","r");  //opening file in read mode
    if(fs==NULL)  //if file is empty
    {
        puts("Cannot Open File");
        exit(1);
    }
    char chr;
    int cl=2;
    chr=getc(fs);  //assigning value position of file pointer
    while(chr!=EOF)  //counting number of lines to initialize sr. no. for adding music
    {
        if(chr=='\n')
            cl=cl+1;
        chr=getc(fs);  //assigning value position of file pointer
    }
    fclose(fs);  //closing file
    fs=fopen("musicDB.txt","a");  //opening file in append mode
    if(fs==NULL) //if file is empty
    {
        puts("Cannot Open File");
        exit(1);
    }
    fclose(fs);
    fs=fopen("musicDB.txt","a");  //opening file in append mode
    char po,o='y';
    while(o=='y')
    {
        printf("Serial Number     : %d\n",cl);
        printf("Enter Music Name  : ");
        gets(p.name);
        printf("Enter Album Name  : ");
        gets(p.album);
        printf("Enter Singer Name : ");
        gets(p.singer);
        int lc=cl;
        itoa(lc,p.sr,10);  //convert integer data-type to string type
        fprintf(fs,"\n%s\t%s\t%s\t%s",strupr(p.sr),strupr(p.name),strupr(p.album),strupr(p.singer));  //writing in musicDB file by uppercasing every char
        printf("Press y to continue or press any key to exit : ");
        fflush(stdin);  //use to clear the output buffer and move buffered data to console
        po=getche();  //will get char
        o=tolower(po);  //converting to lower case
        cl=cl+1;  //line or sr. no. counter increment
        printf("\n\n");
    }
    fclose(fs);  //closing file
}


// createPlaylist function
void createPlaylist()
{
    int ch;
    printf("1.Create New Playlist\n2.Open Existing Playlist\nYour choice >> ");
    scanf("%d",&ch);
    printf("\n");
    switch(ch)  //for create new playlist or open exisiting playlist
    {
        case 1 : fs=fopen("Playlist.txt","w"); //opening file in write mode so it will be blank and no previous playlist data will be available
                 fclose(fs);  //closing file
                 int ccpsr,cpsr=1,len=0,len2,z,i,choice,choice2,delsr,plcl=0;
                 char fcpsr[4],chr1,chr2,clen[4];
                 showplaylistMusic();
                 int sel;
                 do
                 {
                     printf("_____Create Playlist_____\nEnter 1 : Add\nEnter 2 : Display\nEnter 3 : Delete\nEnter 4 : Done\nYour Choice >>> ");
                     scanf("%d",&sel);
                     printf("\n");
                     switch(sel)
                     {
                         case 1 : printf("Enter Sr. No. of Music to Add to Playlist >>> ");
                                  scanf("%d",&choice);
                                  printf("\n");
                                  choice2=choice-1;
                                  if((choice2>length-1)||(choice2<0))
                                      printf("Enter proper Sr. No. of Music...\n\n");
                                  else
                                  {
                                      fs=fopen("Playlist.txt","r");
                                      chr2=getc(fs);
                                      while(chr2!=EOF)  //counting number of lines to initialize sr. no.
                                      {
                                         if(chr2=='\n')
                                             cpsr=cpsr+1;
                                         chr2=getc(fs);  //assigning value position of file pointer
                                      }
                                      fclose(fs);
                                      char cpl[4];
                                      itoa(choice2,cpl,10);  //convert integer data-type to string type
                                      ccpsr=cpsr;
                                      itoa(ccpsr,fcpsr,10);  //convert integer data-type to string type
                                      fs=fopen("Playlist.txt","a");  //opening file in append mode
                                      fprintf(fs,"%s\t%s\t%s\t%s\n",fcpsr,playlist[choice2].cname,playlist[choice2].calbum,playlist[choice2].csinger);  //writing in Playlist file
                                      fclose(fs);  //closing file
                                      cpsr=1;
                                  }
                                  break;

                         case 2 : fs=fopen("Playlist.txt","r");  //opening file in read mode
                                  if(fs==NULL)  //if file is empty
                                  {
                                      puts("Null");
                                      fclose(fs);  //closing file
                                  }
                                  else
                                  {
                                      while(fscanf (fs,"%[^\t]\t%[^\t]\t%[^\t]\t%[^\n]\n",cp.csr,cp.cname,cp.calbum,cp.csinger)!=EOF ) //reading from file and storing into playlist structure
                                          {
                                               printf("Sr. No.: %s\nMusic  : %s\nAlbum  : %s\nSinger : %s\n\n",cp.csr,cp.cname,cp.calbum,cp.csinger);
                                          }
                                      printf("\n");
                                  }
                                  fclose(fs);  //closing file
                                  break;

                         case 3 : fs=fopen("Playlist.txt","r");  //opening file in read mode
                                  if(fs==NULL)  //if file is empty
                                  {
                                      puts("Null");
                                      fclose(fs);  //closing file
                                  }
                                  else
                                  {
                                      i=0;
                                      while(fscanf (fs,"%[^\t]\t%[^\t]\t%[^\t]\t%[^\n]\n",cp.csr,cp.cname,cp.calbum,cp.csinger)!=EOF ) //reading from file and storing into playlist structure
                                          {
                                             printf("Sr. No.: %s\nMusic  : %s\nAlbum  : %s\nSinger : %s\n\n",cp.csr,cp.cname,cp.calbum,cp.csinger);
                                             strcpy(cplaylist[i].cname,cp.cname);  //copying to music_sort structure from playlist structure
                                             strcpy(cplaylist[i].calbum,cp.calbum);  //copying to music_sort structure from playlist structure
                                             strcpy(cplaylist[i].csinger,cp.csinger);  //copying to music_sort structure from playlist structure
                                             i=i+1;
                                          }
                                      printf("\n");
                                  }
                                  fclose(fs);  //closing file
                                  printf("Enter Sr. No. of music to remove from playlist : ");
                                  scanf("%d",&delsr);
                                  printf("\n");
                                  fs=fopen("Playlist.txt","r");  //opening file in read mode
                                  chr1=getc(fs);  //assigning value position of file pointer
                                  plcl=0;
                                  while(chr1!=EOF)  //counting number of lines to initialize sr. no.
                                  {
                                     if(chr1=='\n')
                                         plcl=plcl+1;
                                     chr1=getc(fs);  //assigning value position of file pointer
                                  }
                                  fclose(fs);  //closing file
                                  len=0;
                                  fs=fopen("Playlist.txt","w");  //opening file in write mode
                                  for(z=0;z<plcl;z++)
                                  {
                                      if(z==(delsr-1))
                                      {
                                             continue;
                                      }
                                      else
                                      {
                                          len=len+1;
                                          len2=len;
                                          itoa(len2,clen,10);
                                          fprintf(fs,"%s\t%s\t%s\t%s\n",clen,cplaylist[z].cname,cplaylist[z].calbum,cplaylist[z].csinger);  //writing in Playlist file
                                      }

                                  }
                                  fclose(fs);  //closing file
                                  break;

                         case 4 : printf("Done with playlist...\n\n");
                                  break;

                         default : printf("Select Correct Option...\n");
                     }
                 }while(sel!=4);
                 break;

        case 2 : cpsr=1,len=0,plcl=0;  //case 2 for opening exisiting playlist
                 do
                 {
                     printf("\n_____Previous Playlist_____\nEnter 1 : Add\nEnter 2 : Display\nEnter 3 : Delete\nEnter 4 : Modify\nEnter 5 : Done\nYour Choice >>> ");
                     scanf("%d",&sel);
                     printf("\n");
                     switch(sel)
                     {
                     case 1 : showplaylistMusic();
                              printf("Enter Sr. No. of Music to Add to Playlist >>> ");
                              scanf("%d",&choice);
                              printf("\n");
                              choice2=choice-1;
                              if((choice2>length-1)||(choice2<0))
                                  printf("Enter proper Sr. No. of Music...\n\n");
                              else
                              {
                                  fs=fopen("Playlist.txt","r");
                                  chr2=getc(fs);
                                  while(chr2!=EOF)  //counting number of lines to initialize sr. no.
                                  {
                                     if(chr2=='\n')
                                         cpsr=cpsr+1;
                                     chr2=getc(fs);  //assigning value position of file pointer
                                  }
                                  fclose(fs);
                                  char cpl[4];
                                  itoa(choice2,cpl,10);  //convert integer data-type to string type
                                  ccpsr=cpsr;
                                  itoa(ccpsr,fcpsr,10);  //convert integer data-type to string type
                                  fs=fopen("Playlist.txt","a");  //opening file in append mode
                                  fprintf(fs,"%s\t%s\t%s\t%s\n",fcpsr,playlist[choice2].cname,playlist[choice2].calbum,playlist[choice2].csinger);  //writing in Playlist file
                                  fclose(fs);  //closing file
                                  cpsr=1;
                              }
                              break;

                     case 2 : fs=fopen("Playlist.txt","r");  //opening file in read mode
                              if(fs==NULL)  //if file is empty
                              {
                                  puts("Null");
                                  fclose(fs);  //closing file
                              }
                              else
                              {
                                  while(fscanf (fs,"%[^\t]\t%[^\t]\t%[^\t]\t%[^\n]\n",cp.csr,cp.cname,cp.calbum,cp.csinger)!=EOF ) //reading from file and storing into playlist structure
                                       printf("Sr. No.: %s\nMusic  : %s\nAlbum  : %s\nSinger : %s\n\n",cp.csr,cp.cname,cp.calbum,cp.csinger);
                                   printf("\n");
                              }
                              fclose(fs);  //closing file
                              break;

                     case 3 : fs=fopen("Playlist.txt","r");  //opening file in read mode
                              if(fs==NULL)  //if file is empty
                              {
                                  puts("Null");
                                  fclose(fs);  //closing file
                              }
                              else
                              {
                                  i=0;
                                  while(fscanf (fs,"%[^\t]\t%[^\t]\t%[^\t]\t%[^\n]\n",cp.csr,cp.cname,cp.calbum,cp.csinger)!=EOF ) //reading from file and storing into playlist structure
                                  {
                                      printf("Sr. No.: %s\nMusic  : %s\nAlbum  : %s\nSinger : %s\n\n",cp.csr,cp.cname,cp.calbum,cp.csinger);
                                      strcpy(cplaylist[i].cname,cp.cname);  //copying to music_sort structure from playlist structure
                                      strcpy(cplaylist[i].calbum,cp.calbum);  //copying to music_sort structure from playlist structure
                                      strcpy(cplaylist[i].csinger,cp.csinger);  //copying to music_sort structure from playlist structure
                                      i=i+1;
                                  }
                                  printf("\n");
                              }
                              fclose(fs);  //closing file
                              printf("Enter Sr. No. of music to remove from playlist : ");
                              scanf("%d",&delsr);
                              printf("\n");
                              fs=fopen("Playlist.txt","r");  //opening file in read mode
                              chr1=getc(fs);  //assigning value position of file pointer
                              plcl=0;
                              while(chr1!=EOF)  //counting number of lines to initialize sr. no.
                              {
                                 if(chr1=='\n')
                                     plcl=plcl+1;
                                 chr1=getc(fs);  //assigning value position of file pointer
                              }
                              fclose(fs);  //closing file
                              len=0;
                              fs=fopen("Playlist.txt","w");  //opening file in write mode
                              for(z=0;z<plcl;z++)
                              {
                                  if(z==(delsr-1))
                                  {
                                         continue;
                                  }
                                  else
                                  {
                                      len=len+1;
                                      len2=len;
                                      itoa(len2,clen,10);
                                      fprintf(fs,"%s\t%s\t%s\t%s\n",clen,cplaylist[z].cname,cplaylist[z].calbum,cplaylist[z].csinger);  //writing in Playlist file
                                  }
                              }
                              fclose(fs);  //closing file
                              break;

                     case 4 : fs=fopen("Playlist.txt","r");  //opening file in read mode
                              if(fs==NULL)  //if file is empty
                              {
                                  puts("Null");
                                  fclose(fs);  //closing file
                              }
                              else
                              {
                                 start=NULL;  //initializing start as NULL for linkedlist
                                 struct node *new_node,*ptr;  //creating variable of struct node for using double linklist
                                 while(fscanf (fs,"%[^\t]\t%[^\t]\t%[^\t]\t%[^\n]\n",n.sr,n.name,n.singer,n.album)!=EOF ) //reading from file and storing into playlist structure
                                 {
                                     new_node = (struct node *)malloc(sizeof(struct node));  //assigning size to new node
                                     strcpy(new_node->sr,n.sr);  //storing data from textfile into structure node of DLL
                                     strcpy(new_node->name,n.name);  //storing data from textfile into structure node of DLL
                                     strcpy(new_node->singer,n.singer);  //storing data from textfile into structure node of DLL
                                     strcpy(new_node->album,n.album);  //storing data from textfile into structure node of DLL
                                     if(start == NULL)
                                     {
                                         start = new_node;  //initializing start as new node if it's null
                                         new_node->prev=NULL;
                                     }
                                     else
                                     {
                                         ptr = start;
                                         while(ptr->next !=NULL)
                                         ptr = ptr->next;
                                         ptr->next = new_node;
                                     }
                                     new_node->prev=ptr;  //connecting previous ptr with new node or data
                                     new_node->next=NULL;  //initializing next of new node to null
                                 }
                              }
                              fclose(fs);  //closing file
                              struct node *ptr,*final_ptr,*next_ptr,*pre_ptr;
                              int num,final_num,s,sr,len=0;
                              ptr=start;
                              while(ptr!=NULL)  //for counting musics and initializing sr. no. for respective music
                              {

                                  len=len+1;
                                  ptr=ptr->next;
                              }
                              printf("Enter the serial number of the song you want to shift : ");
                              scanf("%d",&num);
                              printf("\n");
                              ptr=start;
                              sr=atoi(ptr->sr);  //for converting into integer as sr is in char/string
                              while(sr!=num)  //traversing till user input number
                               {
                                ptr=ptr->next;
                                sr=atoi(ptr->sr);  //for converting into integer as sr is in char/string
                               }
                              printf("If you want to shift the song to Before other song PRESS 1\n\t\t\tOR\nIf you want to shift the song to After other song PRESS 2\nYour Choice >>> ");
                              scanf("%d",&s);
                              printf("\n");
                              switch(s)
                              {
                                  case 1 : printf("Enter the serial no. of the song Before which you want to shift song : ");
                                           scanf("%d",&final_num);
                                           final_ptr=start;
                                           sr=atoi(final_ptr->sr);  //for converting into integer as sr is in char/string
                                           while(sr!=final_num)
                                           {
                                               final_ptr=final_ptr->next;
                                               sr=atoi(final_ptr->sr);  //for converting into integer as sr is in char/string
                                           }
                                           pre_ptr=final_ptr->prev;
                                           next_ptr=ptr->next;
                                           if(next_ptr==NULL&& final_num!=1)  //putting last song before any song(except first)
                                           {
                                               ptr->prev->next=NULL;
                                               ptr->next=final_ptr;
                                               final_ptr->prev=ptr;
                                               ptr->prev=pre_ptr;
                                               pre_ptr->next=ptr;

                                           }
                                           else if((next_ptr==NULL) && (final_num==1))  //putting last song before first song
                                           {
                                               ptr->prev->next=NULL;
                                               ptr->next=final_ptr;
                                               ptr->prev=NULL;
                                               final_ptr->prev=ptr;
                                           }
                                           else if((next_ptr!=NULL) && (final_num==1))  //putting any song(except last) before first song
                                           {
                                               ptr->prev->next=next_ptr;
                                               next_ptr->prev=ptr->prev;
                                               ptr->prev=NULL;
                                               ptr->next=final_ptr;
                                               final_ptr->prev=ptr;
                                           }
                                           else
                                           {
                                               ptr->prev->next=ptr->next;
                                               next_ptr->prev=ptr->prev;
                                               ptr->next=final_ptr;
                                               ptr->prev=pre_ptr;
                                               pre_ptr->next=ptr;
                                               final_ptr->prev=ptr;
                                           }
                                           if(final_num==1)
                                               start=ptr;
                                           break;

                                 case 2 : printf("Enter the serial no. of the song After which you want to shift song : ");
                                          scanf("%d",&final_num);
                                          final_ptr=start;
                                          sr=atoi(final_ptr->sr);  //for converting into integer as sr is in char/string
                                          while(sr!=final_num)
                                          {
                                              final_ptr=final_ptr->next;
                                              sr=atoi(final_ptr->sr);  //for converting into integer as sr is in char/string
                                          }
                                          next_ptr=final_ptr->next;
                                          if((next_ptr==NULL) && (final_num!=1) &&(ptr!=start)) //insert any song(except 1st) after last song
                                          {
                                              ptr->prev->next=ptr->next;
                                              ptr->next->prev=ptr->prev;
                                              ptr->next=NULL;
                                              ptr->prev=final_ptr;
                                              final_ptr->next=ptr;
                                          }
                                          else if((ptr==start) && (final_num==len))  //insert first song after last song
                                          {
                                              start=ptr->next;
                                              ptr->next->prev=NULL;
                                              final_ptr->next=ptr;
                                              ptr->prev=final_ptr;
                                              ptr->next=NULL;
                                          }
                                          else if(ptr->next==NULL) //insert last song after any song
                                          {
                                              ptr->prev->next=NULL;
                                              ptr->next=final_ptr->next;
                                              final_ptr->next->prev=ptr;
                                              final_ptr->next=ptr;
                                              ptr->prev=final_ptr;
                                          }
                                          else if((ptr==start) && (final_num!=len)) //insert first song after any song(except last)
                                          {
                                              start=ptr->next;
                                              ptr->next->prev=NULL;
                                              ptr->next=final_ptr->next;
                                              final_ptr->next->prev=ptr;
                                              final_ptr->next=ptr;
                                              ptr->prev=final_ptr;
                                          }
                                          else
                                          {
                                              ptr->prev->next=ptr->next;
                                              ptr->next->prev=ptr->prev;
                                              ptr->next=final_ptr->next;
                                              ptr->prev=final_ptr;
                                              next_ptr->prev=ptr;
                                              final_ptr->next=ptr;
                                          }
                                          break;
                              }
                              ptr=start;
                              i=1;
                              fs=fopen("Playlist.txt","w");
                              while(ptr!=NULL)
                              {
                                  printf("Sr. No.: %d\nAlbum  : %s\nMusic  : %s\nSinger : %s\n\n",i,ptr->name,ptr->singer,ptr->album);
                                  fprintf(fs,"%d\t%s\t%s\t%s\n",i,ptr->name,ptr->singer,ptr->album);  //writing in Playlist file
                                  ptr=ptr->next;
                                  i=i+1;
                              }
                              fclose(fs);
                              break;

                     case 5 : printf("Done with Playlist...\n\n");
                              break;

                     default : printf("Select Correct Option...\n");
                               break;
                     }
                 }while(sel!=5);
    }
}
