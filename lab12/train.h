#include <string>

#ifndef TRAIN_H
#define TRAIN_H


class Train
{
public:
    Train();
    Train(std::string dest, int trainId = 0, std::string dep = "", int places = 0);
    ~Train(){}
    std::string toString();
private:
//    std::setDepartureTime();
    std::string destination;
    int trainId;
    std::string departureTime;
    int places;

};

#endif // TRAIN_H
