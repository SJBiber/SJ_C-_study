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
    void show();
    ~Time();
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
