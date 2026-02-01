#include<stdio.h>
#include<string.h>
void shortname(char name [])
{
  char *word;
  char *last;
  word=strtok(name," ");
  while (word != NULL)
  {
    last = word;
    word= strtok (NULL, " ");
  }
  word = strtok(name, " ");
  while (word != last)
  {
    printf("%c.", word[0]);
  }
  printf("%s",last);
}
int main()
{
  char name[100];

  printf("enter full name:");
  fgets(name,sizeof(name),stdin);

  shortname(name);

  return 0;
  
}