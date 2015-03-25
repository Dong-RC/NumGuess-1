#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

//generate 3 different random number.
int gener_random(int *p)
{
    int resulta,resultb,resultc;
    srand(time(NULL));
    resulta=rand()%10;
    resultb=rand()%10;
    resultc=rand()%10;
    while (resultb==resulta)
    {
        resultb=rand()%10;
    }
    while ((resultc==resulta)||(resultc==resultb))
    {
        resultc=rand()%10;
    }
    *p=resulta;
    *(p+1)=resultb;
    *(p+2)=resultc;
}

//check the game result, and return the number of right position.
int check(int a,int b,int c,int resulta,int resultb,int resultc)
{
    int result[3]={resulta,resultb,resultc};
    int posright=0;
    int numright=0;
    posright=(a==resulta)+(b==resultb)+(c==resultc);
    //get rid of the case a=b||a=c.
    if ((resulta==a)||(resulta==b)||(resulta==c))
    {
        ++numright;
    }
     if ((resultb==a)||(resultb==b)||(resultb==c))
    {
        ++numright;
    }
     if ((resultc==a)||(resultc==b)||(resultc==c))
    {
        ++numright;
    }
    numright=numright-posright;
    cout<<posright<<"A"<<numright<<"B"<<endl;
    return posright;
}



int main()
{
    int resulta,resultb,resultc,a,b,c,times,wintime=0,losetime=0;
    int *p;
    char play_or_not;
    cout<<"��Ҫ����Ϸ��(Y/N)?"<<endl;
    cin>>play_or_not;
    while (play_or_not!='N')
    {
        //the process of the game.
        if (play_or_not=='Y')
        {
            gener_random(p);
            resulta=*p;
            resultb=*(p+1);
            resultc=*(p+2);
            times=0;
            while (1)
            {
                times=times+1;
                cout<<"��������²������"<<endl;
                cin>>a>>b>>c;
                if (check(a,b,c,resulta,resultb,resultc)==3)
                {
                    cout<<"��ϲ����¶���"<<endl;
                    wintime=wintime+1;
                    break;
                }
                if (times==7)
                {
                    cout<<"���ź�����û���ڹ涨�����ڲ¶ԡ����� "<<resulta<<" "<<resultb<<" "<<resultc<<endl;
                    losetime=losetime+1;
                    break;
                }
            }
        }
        cout<<"��Ҫ����Ϸ��(Y/N)?"<<endl;
        cin>>play_or_not;
    }
    cout<<"��һ������"<<wintime+losetime<<"�֣�Ӯ��"<<wintime<<"�֣�����"<<losetime<<"��"<<endl;
}
