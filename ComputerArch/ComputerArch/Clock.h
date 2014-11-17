#ifndef CLOCK_H
#define CLOCK_H

class Clock {

    public:

        enum Edge {
            LO = 0,
            HI = 1
        };

        static void tick(unsigned long ms);
        static void toggleEdge();
        static void setEdge(Edge edge);
        static Edge getEdge();

    private:

        static Edge currentEdge;

};

#endif
