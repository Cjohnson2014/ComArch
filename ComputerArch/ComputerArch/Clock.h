#ifndef CLOCK_H
#define CLOCK_H

class Clock {

    public:

        enum Edge {
            LO = 0,
            HI = 1
        };

        void tick(unsigned long ms);
        void toggleEdge();
        void setEdge(Edge edge);
        Edge getEdge();

    private:

        Edge currentEdge;

};

#endif
