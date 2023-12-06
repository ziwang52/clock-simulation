//zi wang
//lab5out
//digital clock

#include <iostream>
#include "graph1.h"

using namespace std;

class Clock
{
private:
  int hour;
  int min;
  int sec;


public:
  Clock();
  bool setHour(int hour);
  bool setMin(int min);
  bool setSec(int sec);
  int getHour();
  int getMin();
  int getSec();
  void draw();

};


Clock::Clock()
{
  //Set private data fields to default values
  hour = 0;
  min = 0;
  sec =0;
}


bool Clock::setHour(int hour)
{

  //Implement rules for hour when out of range  
  if (hour < 0)
  {
    hour = 0;
    return false;
  }

  if (hour > 11)
  {
    hour = 11;
    return false;
  }

  //OW hour is in range assign to height
  this->hour = hour;

  return true;
}
//Implement rules for min when out of range  
bool Clock::setMin(int min)
{
  if (min < 0)
  {
    min = 0;
    return false;
  }

  if (min > 59)
  {
    min = 59;
    return false;
  }

  //OW min is in range assign to height
  this->min = min;

  return true;
}

bool Clock::setSec(int sec)
{
  //Implement rules for sec when out of range
  if (sec < 0)
  {
    sec = 0;
    return false;
  }

  if (sec > 59)
  {
    sec = 59;
    return false;
  }

  //OW sec is in range assign to height
  this->sec = sec;

  return true;
}

int Clock::getHour()
{
  return hour;
}

int Clock::getMin()
{
  
  return min;
}

int Clock::getSec()
{
  return sec;
}

void Clock::draw()
{
  //Draw the clock
  int alpha_sec =0;
  int alpha_min = 0;
  int alpha_hour = 0;
  int sec_x= 0,sec_y=0,hour_x=0,hour_y=0, min_x=0, min_y =0;
  const int center_x =197+123;
  const int center_y = 189+50;
  const double PI=3.1415;
  int secondhand=0;
  int minhand = 0;
  int hourhand = 0;
  drawRect(0, 0, 650, 550);
  displayPNG("clock_face.png",123,50);
 
  alpha_sec= sec*6;
  alpha_min = min * 6 + (sec / 60.0) * 6;
  alpha_hour = hour * 30 + (min / 60.0) * 30;  

  //draw second hand
  if ((alpha_sec >= 0) && (alpha_sec < 90))
  {
    sec_x = center_x + (cos((90 - alpha_sec) * PI / 180.0)) * 150;
    sec_y = center_y - (sin((90 - alpha_sec) * PI / 180.0)) * 150;
  }
  if ((alpha_sec >= 90) && (alpha_sec < 180))
  {
    sec_x = center_x + (cos((alpha_sec - 90) * PI / 180.0)) * 150;
    sec_y = center_y + (sin((alpha_sec - 90) * PI / 180.0)) * 150;

  }
  if ((alpha_sec >= 180) && (alpha_sec < 270))
  {
    sec_x = center_x - (cos((270 - alpha_sec) * PI / 180.0)) * 150;
    sec_y = center_y + (sin((270 - alpha_sec) * PI / 180.0)) * 150;

  }
  if ((alpha_sec >= 270) && (alpha_sec < 360))
  {
    sec_x = center_x - (cos((alpha_sec - 270) * PI / 180.0)) * 150;
    sec_y = center_y - (sin((alpha_sec - 270) * PI / 180.0)) * 150;

  }
   secondhand=drawLine(center_x,center_y, sec_x, sec_y,2);
  setColor(secondhand,255,0,0);
//draw minutes hand
  if ((alpha_min >= 0) && (alpha_min < 90))
  {
    min_x = center_x + (cos((90 - alpha_min) * PI / 180.0)) * 180;
    min_y = center_y - (sin((90 - alpha_min) * PI / 180.0)) * 180;
  }
  if ((alpha_min >= 90) && (alpha_min < 180))
  {
    min_x = center_x + (cos((alpha_min - 90) * PI / 180.0)) * 180;
    min_y = center_y + (sin((alpha_min - 90) * PI / 180.0)) * 180;

  }
  if ((alpha_min >= 180) && (alpha_min < 270))
  {
    min_x = center_x - (cos((270 - alpha_min) * PI / 180.0)) * 180;
    min_y = center_y + (sin((270 - alpha_min) * PI / 180.0)) * 180;

  }
  if ((alpha_min >= 270) && (alpha_min < 360))
  {
    min_x = center_x - (cos((alpha_min - 270) * PI / 180.0)) * 180;
    min_y = center_y - (sin((alpha_min - 270) * PI / 180.0)) * 180;

  }
  minhand=drawLine(center_x, center_y, min_x, min_y, 4);
  setColor(minhand,0,0,0);
//draw hour hand
  if ((alpha_hour >= 0) && (alpha_hour < 90))
  {
    hour_x = center_x + (cos((90 - alpha_hour) * PI / 180.0)) * 133;
    hour_y = center_y - (sin((90 - alpha_hour) * PI / 180.0)) * 133;
  }
  if ((alpha_hour >= 90) && (alpha_hour < 180))
  {
    hour_x = center_x + (cos((alpha_hour - 90) * PI / 180.0)) * 133;
    hour_y = center_y + (sin((alpha_hour - 90) * PI / 180.0)) * 133;

  }
  if ((alpha_hour >= 180) && (alpha_hour < 270))
  {
    hour_x = center_x - (cos((270 - alpha_hour) * PI / 180.0)) * 133;
    hour_y = center_y + (sin((270 - alpha_hour) * PI / 180.0)) * 133;

  }
  if ((alpha_hour >= 270) && (alpha_hour < 360))
  {
    hour_x = center_x - (cos((alpha_hour - 270) * PI / 180.0)) * 133;
    hour_y = center_y - (sin((alpha_hour - 270) * PI / 180.0)) * 133;

  }
  hourhand=drawLine(center_x, center_y, hour_x, hour_y, 4);
  setColor(hourhand, 0, 0, 0);

}

int main()
{
  //Variable Declaration/Initialization
  int hour =0;
  int min =0;
  int sec = 0;
  bool result = false;
  
   Clock clock1;

  char repeat;

  //Display the Graphics
  displayGraphics();

  do
  {
    //Prompt for the time info
    cout << "Enter the number of seconds: ";
    cin >> sec;

    //Prompt for the radius
    cout << "Enter the number of minutes: ";
    cin >> min;


    cout << "Enter the number of hours: ";
    cin >> hour;
    
   //Set hour for clock – display message if hour is out of range
    result = clock1.setHour( hour);
    if (!result)
    {
      cout << "input to hour is invalid - setting value to within range" << endl;
    }

    //Set min for clock – display message if min is out of range
    result = clock1.setMin(min);
    if (!result)
    {
      cout << "input to minutes is invalid - setting value to within range" << endl;
    }

    //Set Second for clock – display message if hour is out of range
    result = clock1.setSec(sec);
    if (!result)
    {
      cout << "input to Second is invalid - setting value to within range" << endl;
    }


    //Draw the clock
    clock1.draw();
   
    gout<<setPos(280,440)<<setColor(0,0,0)<<"Time: "<<hour<<":"<<min<<":"<<sec<<endg;


    cout << "\nWould you like to repeat? (y/n): ";
    cin >> repeat;


    clearGraphics();
    system("cls");

  } while (repeat == 'y' || repeat == 'Y');

  return 0;
}

