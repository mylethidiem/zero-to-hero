#include <Windows.h>
#include <iomanip>
#include <iostream>
#include <stdlib.h>

#define LIMIT_COUNT 60
#define LIMIT_COUNT_HOURS 99
struct Time {
  unsigned int seconds = 0;
  unsigned int minutes = 0;
  unsigned int hours = 0;
};

void Reset(Time &t) {
  t.seconds = 0;
  t.minutes = 0;
  t.hours = 0;
}

void UpdateWatch() {
  Time stopWatch;
  int isStopwatchWork = 1;
  while (1) {
    std::cout << std::setfill('0') << std::setw(2) << stopWatch.hours << ":";
    std::cout << std::setfill('0') << std::setw(2) << stopWatch.minutes << ":";
    std::cout << std::setfill('0') << std::setw(2) << stopWatch.seconds;
    std::cout << std::endl
              << "SPACE: Pause"
              << "\t\t\tESC: Exit";
    if (GetAsyncKeyState(VK_SPACE)) {
      while (true) {
        if (GetAsyncKeyState(VK_SPACE)) {
          Sleep(1000);
          break;
        }
      }
    }
    if (GetAsyncKeyState(VK_ESCAPE)) {
      break;
    }

    if (stopWatch.seconds == LIMIT_COUNT) {
      stopWatch.minutes++;
      stopWatch.seconds = 0;
    } else if (stopWatch.minutes == LIMIT_COUNT) {
      stopWatch.hours++;
      stopWatch.minutes = 0;
    } else if (stopWatch.hours == LIMIT_COUNT_HOURS) {
      Reset(stopWatch);
    }
    stopWatch.seconds++;
    Sleep(1000);
    system("cls");
  }
}

int main()
// int StopWatch()
{
  UpdateWatch();
  return 0;
}
