
#include <iostream>
using namespace std;

// Abstract class
class Course
{
public:
    virtual void duration() = 0;
};

// OnlineCourse class
class OnlineCourse : public Course
{
private:
    int weeks;
    int hoursPerWeek;

public:
    OnlineCourse(int w, int h)
    {
        weeks = w;
        hoursPerWeek = h;
    }

    void duration() override
    {
        cout << "Online Course Duration: "
            << weeks << " weeks" << endl;

        cout << "Total Study Hours: "
            << weeks * hoursPerWeek << " hours" << endl;
    }
};

// OfflineCourse class
class OfflineCourse : public Course
{
private:
    int months;
    int hoursPerDay;

public:
    OfflineCourse(int m, int h)
    {
        months = m;
        hoursPerDay = h;
    }

    void duration() override
    {
        cout << "Offline Course Duration: "
            << months << " months" << endl;

        cout << "Total Study Hours (assuming 30 days/month): "
            << months * 30 * hoursPerDay << " hours" << endl;
    }
};

// Main function
int main()
{
    OnlineCourse online(8, 3);
    OfflineCourse offline(6, 4);

    cout << "Online Course:" << endl;
    online.duration();

    cout << "\nOffline Course:" << endl;
    offline.duration();

    return 0;
}
