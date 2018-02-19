#include<stdio.h>
#include<Windows.h>
//#include<math.h>
CirCle1()//Ô²Ðý×ª
{
    int x =300, y = 0;
    int drection = 0;
    while (1)
    {
        if(drection)
            x--;
        else
            x++;
        if(x>=983)
          {
           drection=1;

           }
        else if(x<383)
        {
            drection =0;
           // x++;
        }
        int sum;
        if(drection==0)
        {
        for(y=0;y<766;y++)
        {
            sum=(x-683)*(x-683)+(y-383)*(y-383);
            if(sum==300*300)
            {
                SetWindowPos((HWND)0x00191188, NULL, x, y, 2, 2, 0);
               // SetWindowPos((HWND)0x004B122A,NULL, x+300, y+200, 3, 3, 0);
               // Sleep(2);
                break;
            }
        }
        }
        else
            for(y=766;y>0;y--)
            {
                sum=(x-683)*(x-683)+(y-383)*(y-383);
                if(sum==300*300)
                {
                    SetWindowPos((HWND)0x00191188, NULL, x, y, 2, 2, 0);
                   // SetWindowPos((HWND)0x004B122A,NULL, x, y, 2, 2, 0);
                    //Sleep(2);
                    break;
                }
            }

    }
}
CirCle2(int dx)//Ô²Ðý×ª
{
    int x =340, y = 0;
    int i=0;
    int drection = 0;
    while (1)
    {
        if(drection)
            x--;
        else
            x++;
        if(x>983-dx)
          {
           drection=1;
           }
        else if(x<383-dx)
        {
            drection =0;
           // x++;
        }
        int sum;
        if(drection==0)
        {
        for(y=0;y<766;y++)
        {
            sum=(x-683-dx)*(x-683-dx)+(y-383)*(y-383);
            if(sum==300*300)
            {
               // SetWindowPos((HWND)0x00191188, NULL, x, y, 2, 2, 0);
                SetWindowPos((HWND)0x004B122A,NULL, x, y, 3, 3, 0);
               // Sleep(2);
                break;
            }
        }
        }
        else
            for(y=766;y>0;y--)
            {
                sum=(x-683-30)*(x-683-30)+(y-383)*(y-383);
                if(sum==300*300)
                {
                   // SetWindowPos((HWND)0x00191188, NULL, x, y, 2, 2, 0);
                    SetWindowPos((HWND)0x004B122A,NULL, x, y, 2, 2, 0);
                    //Sleep(2);
                    break;
                }
            }
        //if(rand()%10==3)
       // printf("%d",1);
        //    break;
    }
   // for(i=0;i<30;i++)
   // CirCle2(i);
}
int main001(void)
{

    //CirCle1();
//   srand((unsigned)(time(NULL)));
   // for(int i=0;i<100;i++)
   // {
        CirCle2(30);
   // }
    return 0;
//    //printf("Hello World!\n");
//    int x =300, y = 0;
//    int drection = 0;
//    while (1)
//    {
//        if(drection)
//            x--;
//        else
//            x++;
//        if(x>=1366)
//          {
//           drection=1;

//           }
//        else if(x<=0)
//        {
//            drection =0;
//           // x++;
//        }
//        int sum;
//        if(drection==0)
//        {
//        for(y=0;y<766;y++)
//        {
//            sum=(x-683)*(x-683)+(y-383)*(y-383);
//            if(sum==300*300)
//            {
//                SetWindowPos((HWND)0x00191188, NULL, x, y, 2, 2, 0);
//                SetWindowPos((HWND)0x004B122A,NULL, x+300, y+200, 3, 3, 0);
//               // Sleep(2);
//                break;
//            }
//        }
//        }
//        else
//            for(y=766;y>0;y--)
//            {
//                sum=(x-683)*(x-683)+(y-383)*(y-383);
//                if(sum==300*300)
//                {
//                    SetWindowPos((HWND)0x00191188, NULL, x, y, 2, 2, 0);
//                    SetWindowPos((HWND)0x004B122A,NULL, x, y, 2, 2, 0);
//                    //Sleep(2);
//                    break;
//                }
//            }

//    }
//    return 0;
}

int main()
{
    while(1)
    {
        printf("-");
        sleep(500);
        printf("\b");

        printf("/");
        sleep(500);
        printf("\b");

        printf("|");
        sleep(500);
        printf("\b");

        printf("\\");
        sleep(500);
        printf("\b");
    }
    return 0;
}
