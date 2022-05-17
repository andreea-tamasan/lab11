#include "Money.h"

Money::Money() {
    this->unban =0;
    this->cincibani=0;
    this->zecebani=0;
    this->cincizecibani=0;
}

Money::Money(int id,int unban, int cincibani, int zecebani, int cincizecibani) {
    this->id =id;
    this->unban =unban;
    this->cincibani=cincibani;
    this->zecebani=zecebani;
    this->cincizecibani=cincizecibani;
}

Money::~Money() {
}

int Money::get_id() {
    return this->id;
}

int Money::getunban() {
    return this->unban;
}

int Money::getcincibani() {
    return this->cincibani;
}

int Money::getzecebani() {
    return this->zecebani;
}

int Money::getcincizecibani() {
    return this->cincizecibani;
}

void Money::setunban(int unban) {
    this->unban = unban;
}

void Money::setcincibani(int cincibani) {
    this->cincibani=cincibani;
}

void Money::setzecebani(int zecebani) {
    this->zecebani=zecebani;
}

void Money::setcinzecidebani(int cincizecibani) {
    this->cincizecibani = cincizecibani;
}

void Money::set_id(int id) {
    this->id = id;
}

bool Money::operator==(const Money& m) {
    return this->unban == m.unban && this->cincibani == m.cincibani && this->zecebani == m.zecebani && cincizecibani == m.cincizecibani;
}

ostream &operator<<(ostream &os, const Money &money) {
    os<<"Nr monede 1 ban: "<<money.unban<<" ,5 bani: "<<money.cincibani<<" ,10 bani: "<<money.zecebani<<" 50 bani:  "<<money.cincizecibani;
    return os;
}

Money &Money::operator=(const Money &m) {
    this->set_id(m.id);
    this->setunban(m.unban);
    this->setcincibani(m.cincibani);
    this->setzecebani(m.zecebani);
    this->setcinzecidebani(m.cincizecibani);
    return *this;
}




