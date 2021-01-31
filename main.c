#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct kelime
{
    char word[200];
    int adet;
};
struct n
{
    struct n*next;
    char *word;
    int adet;
};
typedef struct n node;

void bastir(node*r)
{
    while(r!=NULL )
    {
        printf("%s %d\n",r->word,r->adet);
        r=r->next;
    }
}

node *siralama(node*r,struct kelime *a,int flag,int j)
{
    if(r==NULL)
    {
        r=( node*)malloc(sizeof(node));
        r->next=NULL;
        r->adet=a[j].adet;
        r->word=a[j].word;

        return r;

    }

    if(r->adet<a[j].adet)
    {

        node*temp=(node*)malloc(sizeof(node));
        temp->adet=a[j].adet;
        temp->word=a[j].word;
        temp->next=r;
        r=temp;

        return temp;

    }

    node*iter=r;
    while(iter->next!=NULL && iter->next->adet>a[j].adet)
    {
        iter=iter->next;
    }
    node*temp=(node*)malloc(sizeof(node));
    temp->next=iter->next;
    iter->next=temp;
    temp->adet=a[j].adet;
    temp->word=a[j].word;

    return r;
}
int main()
{
    int flag=0;
    node*root;
    root=NULL;


    struct kelime *kelime_1;
    kelime_1=(struct kelime*)malloc(sizeof(struct kelime)*100);


    FILE *fp=fopen("metin.txt","r");

    for(int i=0; !feof(fp); i++)
    {
        fscanf(fp,"%s",kelime_1[i].word);
        kelime_1[i].adet=1;
        flag++;
    }
    for(int j = 0; j<flag; j++)
    {
        for( int k =j+1; k<flag; k++)
        {
            if(strcmp(kelime_1[j].word,kelime_1[k].word)==0)
            {
                kelime_1[j].adet++;
                kelime_1[k].adet++;
            }

        }

    }
    for(int i=0; i<flag; i++)
    {
        for(int j=i+1; j<flag;)
        {
            if(strcmp(kelime_1[i].word,kelime_1[j].word)==0)
            {
                for(int k=j; k<flag; k++)
                {
                    strcpy(kelime_1[k].word,kelime_1[k+1].word);
                    kelime_1[k].adet=kelime_1[k+1].adet;

                }
                flag--;
            }
            else
            {
                j++;
            }
        }
    }
    for(int i=0; i<flag; i++)
    {
        root=siralama(root,kelime_1,flag,i);
    }

    bastir(root);
}























