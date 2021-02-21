#include <conio.h>
#include <cstdio>
#include <iostream>
#include <string.h>
#include <cstdlib>
using namespace std;
static int p = 0;
class a
{

  char flightn[5], pilot[10], arrival[5], depart[5], from[10], to[10], seat[8][4][10];

public:

  void install();
  void allotment();
  void empty();
  void show();
  void avail();
  void position(int i);
}

flight[10];

void vline(char ch)

{
  for (int i=80;i>0;i--)
  cout<<ch;

}

void a::install()

{

  cout<<"Enter flight no: ";

  cin>>flight[p].flightn;

  cout<<"\nEnter pilot's name: ";

  cin>>flight[p].pilot;

  cout<<"\nArrival time: ";

  cin>>flight[p].arrival;

  cout<<"\nDeparture: ";

  cin>>flight[p].depart;

  cout<<"\nFrom: \t\t\t";

  cin>>flight[p].from;

  cout<<"\nTo: \t\t\t";

  cin>>flight[p].to;

  flight[p].empty();

  p++;

}

void a::allotment()

{

  int seat;

  char number[5];

  top:

  cout<<"flight no: ";

  cin>>number;

  int n;

  for(n=0;n<=p;n++)

  {

    if(strcmp(flight[n].flightn,number)==0)

    break;

  }

  while(n<=p)

  {

    cout<<"\nSeat Number: ";

    cin>>seat;

    if(seat>32)

    {

      cout<<"\nThere are only 20 seats available in this flight.";

    }

    else

    {

    if (strcmp(flight[n].seat[seat/4][(seat%4)-1], "Empty")==0)

      {

        cout<<"Enter passanger's name: ";

        cin>>flight[n].seat[seat/4][(seat%4)-1];

        break;

      }

    else

      cout<<"The seat no. is already reserved.\n";

      }

      }

    if(n>p)

    {

      cout<<"Enter correct flight no.\n";

      goto top;

    }

  }


void a::empty()

{

  for(int i=0; i<8;i++)

  {

    for(int j=0;j<4;j++)

    {

      strcpy(flight[p].seat[i][j], "Empty");

    }

  }

}

void a::show()

{

  int n;

  char number[5];

  cout<<"Enter flight no: ";

  cin>>number;

  for(n=0;n<=p;n++)

  {

    if(strcmp(flight[n].flightn, number)==0)

    break;

  }

while(n<=p)

{

  vline('*');

  cout<<"flight no: \t"<<flight[n].flightn

  <<"\npilot: \t"<<flight[n].pilot<<"\t\tArrival time: \t"

  <<flight[n].arrival<<"\tDeparture time:"<<flight[n].depart

  <<"\nFrom: \t\t"<<flight[n].from<<"\t\tTo: \t\t"<<

  flight[n].to<<"\n";

  vline('*');

  flight[0].position(n);

  int a=1;

  for (int i=0; i<8; i++)

  {

    for(int j=0;j<4;j++)

    {

      a++;

      if(strcmp(flight[n].seat[i][j],"Empty")!=0)

      cout<<"\nThe seat no "<<(a-1)<<" is reserved for "<<flight[n].seat[i][j]<<".";

    }

  }

  break;

  }

  if(n>p)

    cout<<"Enter correct flight no: ";

}

void a::position(int l)

{

  int s=0;p=0;

  for (int i =0; i<8;i++)

  {

    cout<<"\n";

    for (int j = 0;j<4; j++)

    {

      s++;

      if(strcmp(flight[l].seat[i][j], "Empty")==0)

        {

          cout.width(5);

          cout.fill(' ');

          cout<<s<<".";

          cout.width(10);

          cout.fill(' ');

          cout<<flight[l].seat[i][j];

          p++;

        }

        else

        {

        cout.width(5);

        cout.fill(' ');

        cout<<s<<".";

        cout.width(10);

        cout.fill(' ');

        cout<<flight[l].seat[i][j];

        }

      }

    }

  cout<<"\n\nThere are "<<p<<" seats empty in flight No: "<<flight[l].flightn;

  }

void a::avail()

{


  for(int n=0;n<p;n++)

  {

    vline('*');

    cout<<"flight no: \t"<<flight[n].flightn<<"\npilot: \t"<<flight[n].pilot

    <<"\t\tArrival time: \t"<<flight[n].arrival<<"\tDeparture Time: \t"

    <<flight[n].depart<<"\nFrom: \t\t"<<flight[n].from<<"\t\tTo: \t\t\t"

    <<flight[n].to<<"\n";

    vline('*');

    vline('_');

  }

}

int main()

{

system("cls");

int w;

while(1)

{

    //system("cls");
    cout<<"\n\n";
    cout<<"\t\t**AIRWAYS RESERVATION SYSTEM**";

  cout<<"\n\n";

  cout<<"\t\t\t1.Install\n\t\t\t"

  <<"2.Reservation\n\t\t\t"

  <<"3.Show\n\t\t\t"

  <<"4.flights Available \n\t\t\t"

  <<"5.Exit";

  cout<<"\n\t\t\tEnter your choice:- ";

  cin>>w;

  switch(w)

  {

    case 1:  flight[p].install();

      break;

    case 2:  flight[p].allotment();

      break;

    case 3:  flight[0].show();

      break;

    case 4:  flight[0].avail();

      break;

    case 5:  exit(0);

  }

}

return 0;
}
