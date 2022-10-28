#include "train.h"

Train::Train()
    : destination(""), trainId(0), departureTime(""), places(0) {}
Train::Train(std::string dest, int trainId, std::string dep, int places)
    : destination(dest), trainId(trainId), departureTime(dep), places(places) {}
std::string Train::toString(){
    return this->destination + ", " + std::to_string(this->trainId) + ", " +
            this->departureTime + ", " + std::to_string(this->places);
}
