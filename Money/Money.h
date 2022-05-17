#ifndef LAAB9_MONEY_H
#define LAAB9_MONEY_H
#include <iostream>
#include <ostream>
using namespace std;
class Money {
private:
    int unban, cincibani, zecebani,cincizecibani;
    int id;
public:
    /**
     * default constructor
     */
    Money();

    /**
     * constructor with parameters
     * @param unban - moneda 1 ban
     * @param cincibani - moneda 5 bani
     * @param zecebani - moneda 10 bani
     * @param cincizecibani - moneda 50 bani
     */
    Money(int id,int unban, int cincibani,int zecebani,int cincizecibani);

    /**
     * id getter
     * @return int - id
     */
    int get_id();
    /**
     * 1 ban getter
     * @return int - 1 ban
     */
    int getunban();

    /**
     * 5 bani getter
     * @return int - 5 bani
     */
    int getcincibani();

    /**
     * 10 bani getter
     * @return int - 10 bani
     */
    int getzecebani();

    /**
     * 50 bani getter
     * @return int - 50 bani
     */
    int getcincizecibani();

    /**
     * 1 ban setter
     * @param unban - moneda 1 ban
     */
    void setunban(int unban);

    /**
     * 5 bani setter
     * @param cincibani - moneda 5 bani
     */
    void setcincibani(int cincibani);

    /**
     * 10 bani setter
     * @param zecebani - moneda 10 bani
     */
    void setzecebani(int zecebani);

    /**
     * 50 bani setter
     * @param cinzecidebani -moneda 50 bani
     */
    void setcinzecidebani(int cincizecibani);

    /**
     * id setter
     * @param id - id product
     */
    void set_id(int id);

    //
    bool operator==(const Money& m);

    /**
     * shows how much money are left
     * @param os - ofstream
     * @param money - money
     * @return mesagge
     */
    friend ostream &operator<<(ostream &os, const Money &money);

    Money& operator=(const Money& m);
    /**
     * destructor
     */
    ~Money();
};
#endif //LAAB9_MONEY_H
