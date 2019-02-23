#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <typeinfo>
using namespace std;
struct POINT{
    int point_x;
    int point_y;
    char name_of_point;
    POINT();
    POINT(int _point_x, int _point_y, char _name_of_point);
    virtual bool isEqual(const POINT& obj) const { return obj.name_of_point == name_of_point; };

};
POINT::POINT(int _point_x, int _point_y, char _name_of_point)
{
        point_x = _point_x;
        point_y = _point_y;
        name_of_point = _name_of_point;
}
POINT::POINT()
{

}
class Task :POINT
{
    POINT Pkt_A;
    POINT Pkt_B;
    POINT Pkt_C;
    POINT Pkt_D;
    POINT Pkt_E;
    POINT FIRST_POINT;
    POINT MIN_OF_POINT;
   int number_of_points;
   vector<POINT> array_of_points;
   vector<double> score_of_points;
   vector<double> length_way;
public:

    Task();
    void Add_points();
    void First_pointt();
    void First_check();
    void Another_check();
    void Last_way();
    void sum_of_whole_way();
};


int main()
{
    Task task;
    return 0;
}
void Task::sum_of_whole_way()
{
    double sum = 0;
    for(int i = 0; i<length_way.size();i++)
    {
        sum += length_way[i];
    }
    cout<<sum<<endl;
}
Task::Task()
{

    number_of_points = 5;
    Add_points();
    First_pointt();
    First_check();
    Another_check();
    Another_check();
    Another_check();
    Last_way();
    sum_of_whole_way();


}
void Task::Last_way()
{
double sum;
double sqr;

    for(int i=0;i<array_of_points.size();i++)
    {
        sum = pow(FIRST_POINT.point_x - MIN_OF_POINT.point_x,2.00)+ pow(FIRST_POINT.point_y - MIN_OF_POINT.point_y,2.00);
        sqr = sqrt(sum);

        cout<<sqr<<endl;
        length_way.push_back(sqr);

    }
}
void Task::Another_check()
{
    score_of_points.clear();
    double sum;
    double sqr;
    double minim;

     for(int i = 0 ;i<number_of_points;i++)
        {
            char r = MIN_OF_POINT.name_of_point;
            char z = array_of_points[i].name_of_point;

            if(r==z)
            {
                array_of_points.erase(array_of_points.begin()+i);
            }
        }



    for(int i=0;i<array_of_points.size();i++)
    {
        sum = pow(array_of_points[i].point_x - MIN_OF_POINT.point_x,2.00)+ pow(array_of_points[i].point_y - MIN_OF_POINT.point_y,2.00);
        sqr = sqrt(sum);
        score_of_points.push_back(sqr);
        cout<<score_of_points[i]<<endl;
    }
    minim = *min_element(begin(score_of_points),end(score_of_points));

    for(int i =0;i<array_of_points.size();i++)
    {
        if(minim == score_of_points[i])
        {
           MIN_OF_POINT.point_x = array_of_points[i].point_x;
           MIN_OF_POINT.point_y = array_of_points[i].point_y;
           MIN_OF_POINT.name_of_point = array_of_points[i].name_of_point;
        }
    }
length_way.push_back(minim);
    number_of_points--;
}
void Task::First_check()
{
    double sum;
    double sqr;
    double minim;


    for(int i = 0 ;i<5;i++)
    {
       char q = FIRST_POINT.name_of_point ;
       char w = array_of_points[i].name_of_point;

        if(q==array_of_points[i].name_of_point)
        {
            array_of_points.erase(array_of_points.begin()+i);
        }
    }




    for(int i=0;i<array_of_points.size();i++)
    {
        sum = pow(array_of_points[i].point_x - FIRST_POINT.point_x,2.00)+ pow(array_of_points[i].point_y - FIRST_POINT.point_y,2.00);
        sqr = sqrt(sum);
        score_of_points.push_back(sqr);
        cout<<score_of_points[i]<<endl;
    }

    minim = *min_element(begin(score_of_points),end(score_of_points));

    for(int i =0;i<array_of_points.size();i++)
    {
        if(minim == score_of_points[i])
        {
           MIN_OF_POINT.point_x = array_of_points[i].point_x;
           MIN_OF_POINT.point_y = array_of_points[i].point_y;
           MIN_OF_POINT.name_of_point = array_of_points[i].name_of_point;
        }
    }
length_way.push_back(minim);
   number_of_points--;
}
void Task::Add_points()
{
   cout<<"Please give destination of point A,1/5"<<endl;
   cin>>Pkt_A.point_x>>Pkt_A.point_y;
   Pkt_A.name_of_point='A';
   cout<<"Please give destination of point B,2/5"<<endl;
   cin>>Pkt_B.point_x>>Pkt_B.point_y;
   Pkt_B.name_of_point = 'B';
   cout<<"Please give destination of point C,3/5"<<endl;
   cin>>Pkt_C.point_x>>Pkt_C.point_y;
   Pkt_C.name_of_point = 'C';
   cout<<"Please give destination of point D,4/5"<<endl;
   cin>>Pkt_D.point_x>>Pkt_D.point_y;
   Pkt_D.name_of_point = 'D';
   cout<<"Please give destination of point E,5/5"<<endl;
   cin>>Pkt_E.point_x>>Pkt_E.point_y;
   Pkt_E.name_of_point = 'E';

   array_of_points.push_back(Pkt_A);
   array_of_points.push_back(Pkt_B);
   array_of_points.push_back(Pkt_C);
   array_of_points.push_back(Pkt_D);
   array_of_points.push_back(Pkt_E);
}
void Task::First_pointt()
{
    char ch;
    cout<<"Choose your first point"<<endl;
    cin>>ch;
    switch(ch)
    {
        case  'A':
        FIRST_POINT.name_of_point = Pkt_A.name_of_point;
        FIRST_POINT.point_x = Pkt_A.point_x;
        FIRST_POINT.point_y = Pkt_A.point_y;
        break;
        case 'B':
        FIRST_POINT.name_of_point = Pkt_B.name_of_point;
        FIRST_POINT.point_x =Pkt_B.point_x;
        FIRST_POINT.point_y = Pkt_B.point_y;
        break;
        case 'C':
        FIRST_POINT.name_of_point = Pkt_C.name_of_point;
        FIRST_POINT.point_x =Pkt_C.point_x;
        FIRST_POINT.point_y = Pkt_C.point_y;
        break;
        case 'D':
        FIRST_POINT.name_of_point = Pkt_D.name_of_point;
        FIRST_POINT.point_x =Pkt_D.point_x;
        FIRST_POINT.point_y = Pkt_D.point_y;
        break;
        case 'E':
        FIRST_POINT.name_of_point = Pkt_E.name_of_point;
        FIRST_POINT.point_x = Pkt_E.point_x;
        FIRST_POINT.point_y = Pkt_E.point_y;
        break;
        default:
            cout<<" ";
            break;
    }
}
