using namespace std;
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

void readit ();
void calcit (double[10], double[10], double[10], double[10], double[10], double[10]);
void writeit (double, double, double, double, double, double, double, double, double);
void readit2 (double, double, double, double, double, double);
void calcit2(double, double, double, double, double, double, double, double);
void writeit2 ();


int main ()
{
    readit ();
    system ("pause");
    return 0;
}

void readit ()
{
     char trash[80];
     double tim15[10], tem15[10], tim20[10], tem20[10], tim25[10], tem25[10];
     int x;
     ifstream datain ("curingdata.txt");
     
     for (x=0; x<3; x++)
     datain.getline (trash, 80);
     
     for (x=0; x<10; x++)
     {
         datain >> tim15[x];
         datain >> tem15[x];
         datain >> tim20[x];
         datain >> tem20[x];
         datain >> tim25[x];
         datain >> tem25[x];
     }
     calcit (tim15, tem15, tim20, tem20, tim25, tem25);
     
}

void calcit (double tim15[10], double tem15[10], double tim20[10], double tem20[10],
double tim25[10], double tem25[10])

{
    int x;
    double summx15=0, summx20=0, summx25=0, summy15=0, summy20=0, summy25=0;
    double xbar15, xbar20, xbar25, ybar15, ybar20, ybar25;
    double proddif15, proddif20, proddif25;
    double squaredif15, squaredif20, squaredif25;
    double m15, m20, m25, b15, b20, b25;
    double r15, r20, r25;
    double prodxy15=0, prodxy20=0, prodxy25=0, prodxsq15=0, prodxsq20=0, 
    prodxsq25=0, prodysq15=0, prodysq20=0, prodysq25=0;

  
    
    for (x=0; x<10; x++)
    {
        summx15= summx15 + log(tim15[x]);
        summx20= summx20 + log(tim20[x]);
        summx25= summx25 + log(tim25[x]);
        summy15= summy15 + tem15[x];
        summy20= summy20 + tem20[x];
        summy25= summy25 + tem25[x];
    }

    xbar15= summx15/10;
    xbar20= summx20/10;
    xbar25= summx25/10;
    ybar15= summy15/10;
    ybar20= summy20/10;
    ybar25= summy25/10;
    
    for (x=0; x<10; x++)
    {
        proddif15= (log(tim15[x])-xbar15)*(tem15[x]-ybar15)+proddif15;
        squaredif15= squaredif15 + pow((log(tim15[x])-xbar15), 2);
        
        proddif20= (log(tim20[x])-xbar20)*(tem20[x]-ybar20)+proddif20;
        squaredif20= squaredif20 + pow((log(tim20[x])-xbar20), 2);
        
        proddif25= (log(tim25[x])-xbar25)*(tem25[x]-ybar25)+proddif25;
        squaredif25= squaredif25 + pow((log(tim25[x])-xbar25), 2);
    }
    
    m15= proddif15/squaredif15;
    m20= proddif20/squaredif20;
    m25= proddif25/squaredif25;
    
    b15= ybar15-m15*xbar15;
    b20= ybar20-m20*xbar20;
    b25= ybar25-m25*xbar25;
    
    for(x=0; x<10; x++)
    {
             prodxy15= prodxy15 + log(tim15[x])*tem15[x];
             prodxy20= prodxy20 + log(tim20[x])*tem20[x];
             prodxy25= prodxy25 + log(tim25[x])*tem25[x];
             prodxsq15= prodxsq15 + pow(log(tim15[x]),2);
             prodxsq20= prodxsq20 + pow(log(tim20[x]),2);
             prodxsq25= prodxsq25 + pow(log(tim25[x]),2);
             prodysq15= prodysq15 + pow(tem15[x],2);
             prodysq20= prodysq20 + pow(tem20[x],2);
             prodysq25= prodysq25 + pow(tem25[x],2);
    }         
    
    r15= (prodxy15-10*xbar15*ybar15)/((sqrt(prodxsq15-10*pow(xbar15,2)))*
    (sqrt(prodysq15-10*pow(ybar15,2))));
    
    r20= (prodxy20-10*xbar20*ybar20)/((sqrt(prodxsq20-10*pow(xbar20,2)))*
    (sqrt(prodysq20-10*pow(ybar20,2))));
    
    r25= (prodxy25-10*xbar25*ybar25)/((sqrt(prodxsq25-10*pow(xbar25,2)))*
    (sqrt(prodysq25-10*pow(ybar25,2))));
  
  writeit(m15,b15,r15,m20,b20,r20,m25,b25,r25);
}
    
void writeit(double m15, double b15, double r15, double m20, double b20, double r20,
double m25, double b25, double r25)
{
       cout << "Linear regression results of temp vs time:  temp = intercept"
       << " + slope*ln(time)" << endl << endl;
       
       cout << setw(23) << left << "# of circuit boards" << setw(11)<<left << "slope" 
       << setw(15)<<left  << "intercept" << "r-squared" << endl;
       
       cout << setfill ('-') << setw(61) << "-" << endl;
       cout << setfill (' ') << left << setprecision(4);

       cout << setw(8) << " "  << setw(15) << "15.0" << setw(12) 
       << m15 << setw(15) << b15  << setw(15) << pow(r15,2) << endl;
       
       cout << setw(12) << right << "20.0" << setw(16) 
       << m20 << setw(13) << b20  << setw(15) << pow(r20,2) << endl;
       
       cout << setw(12) << right << "25.0" << setw(16) 
       << m25 << setw(12) << b25  << setw(16) << pow(r25,2) << endl;
       
       readit2 (m15, b15, m20, b20, m25, b25);
}

void readit2 (double m15, double b15, double m20, double b20, double m25, double b25)
{
     double xboards, ytemp;
     
trapp1: cout << "\nEnter the number of boards [between 5 and 30] that you want"
             << " to cure" << endl;
        cout << "Number of boards to process = ";
        cin  >> xboards;
        cout << endl;
        
        if (xboards<4||xboards>30)
        {
           cout << "The number of boards you entered is not valid" << endl;
           goto trapp1;
        }
        
trapp2: cout << "Enter the temperature [between 100 and 200 F] the boards are"
             << " to be heated to" << endl;
        cout << "Temperature to heat boards to = ";
        cin  >> ytemp;
        cout << endl;
        
        if (ytemp<100||ytemp>200)
        {
           cout << "The temperature entered is not valid" << endl << endl;
           goto trapp2;
        }
        
        calcit2(m15, b15, m20, b20, m25, b25, xboards, ytemp);
}

void calcit2(double m15, double b15, double m20, double b20, double m25,
double b25, double xboards, double ytemp)
{
       double mavg;
       int x;
       double Mm, Mb, Ym, Yb, boardavg, slopeavg, bavg;
       double sumboardavg, sumslopeavg, sumbavg;
       double time;
       
       boardavg = (15+20+25+xboards)/4;
       slopeavg = (m15+m20+m25)/3;
       bavg     = (b15+b20+b25)/3;

    
       sumboardavg = (15-boardavg)+(20-boardavg)+(25-boardavg);//+(xboards-boardavg);
       sumslopeavg = (m15-slopeavg)+(m20-slopeavg)+(m25-slopeavg);
       sumbavg = (b15-bavg)+(b20-bavg)+(b25-bavg);
       
       //Mm = (sumboardavg*sumslopeavg)/(pow(sumboardavg,2));
       
       //Mb = (sumboardavg*sumbavg)/(pow(sumboardavg,2));
       
       Ym = Mm*xboards;
       
       Yb = ytemp-sumslopeavg*sumboardavg;
       
      // time = exp((ytemp)/Ym);
     
      Mm = sumbavg*sumslopeavg/pow(sumbavg,2);
      
      Mb= sumslopeavg-Mm*sumbavg;
      
      time= exp((ytemp-Mb)/Mm);
      cout << time << endl;
}
