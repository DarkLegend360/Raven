//Double Ended Queue
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int Que[SIZE];
int F=-1,R=-1;

void Display()
{
    int i;
    if(F==-1)
        printf("Empty");
    else if(F<R)
    {
        for(i=F;i<=R;i++)
            printf("%d ",Que[i]);
    }
    else
    {
        for(i=F;i<SIZE;i++)
            printf("%d ",Que[i]);
        for(i=0;i<=R;i++)
            printf("%d ",Que[i]);
        printf("\n");
    }

}
void Ins_Front(int ele)
{
    if((F == 0 && R == SIZE-1)|| F == R+1)
        printf("OverFlow");
    else if(F==-1)
        F=R=0;
    else if(F==0)
        F=SIZE-1;
    else
        F--;
    Que[F]=ele;
}

void Ins_Rear(int ele)
{
    if((F == 0 && R == SIZE-1)|| R==F-1)
        printf("OverFlow");
    else if(F==-1)
        F=R=0;
    else if(R==SIZE-1 && F>0)
        R=0;
    else
        R++;
    Que[R]=ele;
}

int Del_Front()
{
    int item;
    if(F==-1)
    {
        printf("UnderFlow");
        return -1;
    }
    else if(F==R)
    {
        item=Que[F];
        F=R=-1;
    }
    else if(F==SIZE-1)
    {
        item=Que[F];F=0;
    }
    else
        item=Que[F++];
    return item;
}

int Del_Rear()
{
    int item;
    if(R==-1)
    {
        printf("UnderFlow");
        return -1;
    }
    else if(F==R)
    {
        item=Que[R];
        F=R=-1;
    }
    else if(R==0)
    {
        item=Que[R];
        R=SIZE-1;
    }
    else
        item=Que[R--];
    return item;
}

void main()
{
    int ch,ele;
    while(1)
    {
        printf("1.Enqueue\n2.Dequeue\n3.Display\nChoice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            {
                printf("1.Front\n2.Rear\nChoice:");
                scanf("%d",&ch);
                switch(ch)
                {
                    case 1:
                    {
                        printf("Enter Element:");
                        scanf("%d",&ele);
                        Ins_Front(ele);
                        break;
                    }
                    case 2:
                    {
                        printf("Enter Element:");
                        scanf("%d",&ele);
                        Ins_Rear(ele);
                        break;
                    }

                }
                break;
            }
            case 2:
            {
                printf("1.Front\n2.Rear\nChoice:");
                scanf("%d",&ch);
                switch(ch)
                {
                    case 1:
                    {
                        ele=Del_Front();
                        if(ele!=-1) printf("Element is %d\n",ele);
                        break;
                    }
                    case 2:
                    {
                        ele=Del_Rear();
                        if(ele!=-1) printf("Element is %d\n",ele);
                        break;
                    }
                }
                break;
            }
            case 3:
            {

                Display();
                break;
            }
            default: printf("Invalid Option.");
        }
    }
}
