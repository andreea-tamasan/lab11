#ifndef LAAB9_MONEYSERVICE_H
#define LAAB9_MONEYSERVICE_H
#include "../Money/Money.h"
#include "../Repo/IRepo.h"

class MoneyService {
private:
    IRepo<Money> &repo;
public:
    MoneyService(IRepo<Money> &iRepo);

    void create(Money money);

    void update(Money oldEntity, Money newEntity);

    void del(unsigned int i);

    vector <Money> getAll();

    Money getById(int id);

    ~MoneyService();
};



#endif //LAAB9_MONEYSERVICE_H
