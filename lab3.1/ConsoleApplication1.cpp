
#include <iomanip>
#include <iostream>
#include <string>
#include <thread>
#include <time.h>
#include <csignal> 

using namespace std;

clock_t timerStart, timerStop;

class CountdownTimer
{
private:
    int totalTime;
    int remainingTime;

public:
    CountdownTimer(int seconds)
    {
        totalTime = seconds;
        remainingTime = seconds;
    }

    CountdownTimer(const string& timeString)
    {
        totalTime = stoi(timeString);
        remainingTime = totalTime;
    }

    CountdownTimer(int minutes, int seconds)
    {
        totalTime = minutes * 60 + seconds;
        remainingTime = totalTime;
    }

    static void handleInterrupt(int signal)
    {
        cout << "\nTimer interrupted. Exiting...\n";
        exit(0);
    }

    void run()
    {
        signal(SIGINT, handleInterrupt);

        cout << "Timer started for " << totalTime << " seconds." << endl;

        clock_t startTime = clock();
        timerStart = clock();
        while (remainingTime > 0)
        {
            if (clock() - startTime >= CLOCKS_PER_SEC)
            {
                cout << "Time remaining: " << std::setw(2) << remainingTime << " seconds." << std::endl;
                cout << "------------------------" << std::endl;
                startTime = clock();
                remainingTime--;
            }
        }
        timerStop = clock();

        cout << "Time's up! Bell rings.\a" << endl;
        cout << "Time taken: " << (double)(timerStop - timerStart) / CLOCKS_PER_SEC << " seconds\n\n\n" << endl;
    }
};

int main()
{
    CountdownTimer timer1(3);
    timer1.run();

    CountdownTimer timer2("7");
    timer2.run();

    CountdownTimer timer3(1, 1);
    timer3.run();

    return 0;
}
