#include <string.h>
#include <stdlib.h>
#include "main.h"
#define SIZEBUFFER MINSIZE*1
//shitcode228
#define Check(buffer) if(*buffer != '"' || *(buffer+1) != ':' || *(buffer+2) != '"' && *buffer) return 0;\
 buffer+=3;
#define Check1(buffer) if(*buffer != '"' || *(buffer+1) != ',' || *(buffer+2) != '"' && *buffer) return 0;
char * getOnlyJson(char*buffer)
{

while(*buffer != '{' && *buffer)
 *buffer++;
if(*buffer != '{')return 0;
int jsonSize = strlen(buffer);
char * buf = (char*)malloc(sizeof(char)*jsonSize+1);
buf = strdup(buffer);
return buf;
}

void getDifficulty(char*buf,float*work)
{
char * buffer = getOnlyJson(buf);
if(*buffer == 0) return 0;
void * first = buffer;
while(*buffer && *buffer != 'd' || *(buffer+1)!='i' || *(buffer+2)!='f' || *(buffer+3)!='f' || *(buffer+4)!='i'
|| *(buffer+5)!='c' || *(buffer+6)!='u' || *(buffer+7)!='l' || *(buffer+8)!='t' || *(buffer+9)!='y')
 *buffer++;
if(*buffer != 'd' || *(buffer+1)!='i' || *(buffer+2)!='f' || *(buffer+3)!='f' || *(buffer+4)!='i'
|| *(buffer+5)!='c' || *(buffer+6)!='u' || *(buffer+7)!='l' || *(buffer+8)!='t' || *(buffer+9)!='y')
return 0;
buffer+=12;
*work = atof(buffer);
free(first);
}

int getP(char*buffer,char*data)
{
int count=0;
while(*buffer != '"' && *buffer)

{
count++;
*data=*buffer;
*data++;
*buffer++;
}
if(!*buffer) return 0;
return count;
}

char ** getWork(char*buf)
{
char * buffer = getOnlyJson(buf);
if(*buffer == 0) return 0;
void * first = buffer;
if(*buffer != '{') return 0;
while(
*buffer && 
*buffer != '"' 
|| *(buffer+1) != 'd' 
|| *(buffer+2) != 'a' 
|| *(buffer+3) != 't' 
|| *(buffer+4) != 'a'  
) *buffer++;
if(*buffer != '"')return 0;
buffer+=7;
if(*buffer != '"') return 0;
*buffer++;
char * data = (char*)malloc(sizeof(char) * strlen(buffer));
buffer+=getP(buffer,data);
Check1(buffer);
buffer+=2;
if(*(buffer) != '"' ||  *(buffer+1) != 'h' ||  *(buffer+2) != 'a' ||  *(buffer+3) != 's' ||  *(buffer+4) != 'h' ||  *(buffer+5) != '1' || *(buffer+6) != '"' && *buffer) return 0;
buffer+=6;

Check(buffer);

char * hash1 = (char*)malloc(sizeof(char) * strlen(buffer));
buffer+=getP(buffer,hash1);
Check1(buffer);
buffer+=2;

if(*buffer && *buffer != '"' || *(buffer+1) != 't' || *(buffer+2) != 'a' || *(buffer+3) != 'r' || *(buffer+4) != 'g' || *(buffer+5) != 'e' || *(buffer+6) != 't' || *(buffer+7) != '"') return 0;
buffer+=7;

Check(buffer);
char * target = (char*)malloc(sizeof(char) * strlen(buffer));
buffer+=getP(buffer,target);
printf("\ndata:%s\nhash1:%s\ntarget:%s\n",data,hash1,target);
free(first);
}