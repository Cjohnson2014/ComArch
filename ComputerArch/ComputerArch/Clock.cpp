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
    this->toggleEdge();
}

void Clock::toggleEdge()
{
    if (this->currentEdge == Clock::HI)
    {
        this->currentEdge = Clock::LO;
    }
    else
    {
        this->currentEdge = Clock::HI;
    }
}

void Clock::setEdge(Clock::Edge edge)
{
    this->currentEdge = edge;
}

Clock::Edge Clock::getEdge()
{
    return this->currentEdge;
}

