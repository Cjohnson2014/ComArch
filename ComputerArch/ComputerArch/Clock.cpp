#include "Clock.h"

#if defined(__WIN32__) || defined(_WIN32) || defined(WIN32) || defined(__WINDOWS__) || defined(__TOS_WIN__)

#include <windows.h>

inline void delay(unsigned long ms)
{
    Sleep(ms);
}

#else

#include <unistd.h>

inline void delay(unsigned long ms)
{
    usleep(ms);
}

#endif

void Clock::tick(unsigned long ms)
{
    delay(ms);
    Clock::toggleEdge();
}

void Clock::toggleEdge()
{
    if (Clock::currentEdge == Clock::HI)
    {
        Clock::currentEdge = Clock::LO;
    }
    else
    {
        Clock::currentEdge = Clock::HI;
    }
}

void Clock::setEdge(Clock::Edge edge)
{
    Clock::currentEdge = edge;
}

Clock::Edge Clock::getEdge()
{
    return Clock::currentEdge;
}

