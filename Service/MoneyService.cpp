//
// Created by Home on 10.05.2022.
//

#include "MoneyService.h"

MoneyService::MoneyService(IRepo<Money> &iRepo): repo(iRepo){}

void MoneyService::create(Money money) {
    repo.add_entity(money);
}

void MoneyService::update(Money oldEntity, Money newEntity) {
    repo.update_file(oldEntity,newEntity);
}

void MoneyService::del(unsigned int i) {
    repo.delete_from_file(repo.get_by_id_file(i));
}

vector<Money> MoneyService::getAll() {
    return repo.get_all_file();
}

Money MoneyService::getById(int id) {
    return repo.get_by_id_file(id);
}

MoneyService::~MoneyService() {}


