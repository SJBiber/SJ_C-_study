#include <iostream>

class Time
{
private:
    int hours;
    int mins;

public:
    Time();
    Time(int , int);
    void addHours(int);
    void addMins(int);
    Time sum(Time&);
    Time operator+(Time&);
    virtual void show();
    /*
    1. 기초 클래스에서 가상메서드를 선언하면 
    그 함수는 기초 클래스 및 파생되는 클래스에서 모두 가상이 된다.
    2. 객체에 대한 참조를 사용하여 , 캑체를 지시하는 포인터를 사용하여
    가상 메서드가 호출되면 참조나 포인터를 위해 정의된 메서드를 사용하지 않고
    객체형을 위해 정의된 메서드를 사용한다. > 동적 결합
    3. 상속을 위해 기초 클래스로 사용할 클래스를 정의할 때,
    파생 클래스에서 다시 정의해야 되는 클래스 메서드들은 가상 함수로 선언 해야 한다.
    */
    virtual ~Time();
    int getHour() { return hours;}
    int getMin() { return mins;}
    friend Time operator*(int ,Time&);
    friend std::ostream&operator<<(std::ostream& os , Time& t)
    {
        os << t.hours << "시간 " << t.mins << "분";
        return os;
    }
};

// class의 hours , min 값 초기화
Time::Time()
{
    hours = mins = 0;
};

// class의 hours , min 값에 h, m을 각각 세팅
Time::Time(int h , int m)
{
    hours   = h;
    mins    = m;
};

// class 의 private hours 값에 int 값 h를 더함
void Time::addHours(int h)
{
    hours += h;
};

// class 의 private mins 값에 int 값 m을 더함
void Time::addMins(int m)
{
    mins    += m;
    hours   += mins / 60;
    mins    %= 60;
};

Time Time::sum(Time& t)
{
    Time sum;
    sum.mins    = mins + t.mins;
    sum.hours   = hours + t.hours;
    sum.hours   += sum.mins / 60;
    sum.mins    %= 60;
    return sum;
};

Time Time::operator+(Time& t)
{
    Time sum;
    sum.mins    = mins + t.mins;
    sum.hours   = hours + t.hours;
    sum.hours   += sum.mins / 60;
    sum.mins    %= 60;
    return sum;
};

void Time::show()
{
    std::cout << "시간 : " << hours << std::endl;
    std::cout << "분 : " << mins << std::endl;
};

Time::~Time()
{

};

Time operator*(int n, Time& t)
{
    Time result;
    long resultMin = t.hours * n * 60 + t.mins * n;
    result.hours = resultMin / 60;
    result.mins  = resultMin % 60;
    return result;

}


// 상속 관련 class 정의
class NewTime : public Time {
private :
    int day;
public :
    NewTime();
    NewTime(int ,int ,int );
    //void print();
    void show();
};

NewTime::NewTime() : Time(){
    day = 0;
}

NewTime::NewTime(int h,int m,int d) : Time(h,m){
    day = d;
}

void NewTime::show(){
    std::cout<<"일 : " << day << std::endl;
    std::cout<<"시간 : "<< getHour()<< std::endl;
    std::cout<<"분 : " << getMin()<< std::endl;
    //show();
}