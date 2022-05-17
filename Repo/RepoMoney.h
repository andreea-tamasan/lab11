//
// Created by Home on 10.05.2022.
//

#ifndef LAAB9_REPOMONEY_H
#define LAAB9_REPOMONEY_H
#include <iostream>
#include <fstream>
#include "Repo.h"
#include "../Money/Money.h"
#include <vector>
#include "IRepo.h"
#include "../Exception/Exception.h"
using namespace std;
template<class T> class RepoMoney: public IRepo<T>{
private:
    const char* filename{};
    vector<T> v;
public:
    RepoMoney() = default;

    RepoMoney(const char* fname) {
        this->filename = fname;
        ifstream f(fname);
        while (!f.eof()) {
            int id, stoc_unban, stoc_cincibani, stoc_zecebani,stoc_cincizecibani;
            f>>id>>stoc_unban>>stoc_cincibani>>stoc_zecebani>>stoc_cincizecibani;
            if (id!=0) {
                Money money(id,stoc_unban, stoc_cincibani, stoc_zecebani,stoc_cincizecibani);
                v.push_back(money);
            }
        }
        f.close();
    }

    void add_entity(Money &money) override{
        this->v.push_back(money);
        this->save_to_File();
    }

    void delete_from_file(Money money) override{
        //int toDelete = money.get_id();
        //for (int i = 0; i< v.size(); i++) {
        //    if (v[i].get_id() == money.get_id()) {
        //        v.erase(v.begin()+i);
        //    }
        //}
        v.clear();
        this->save_to_File();

    }

    void update_file(Money &old_prod, Money new_prod) override{
        //for(int i = 0; i< v.size(); i++)
        //    if(v[i].get_id() == old_prod.get_id()){
        //        v[i] = new_prod;
        //    }
        Money aux;
        aux = old_prod;
        new_prod = aux;
        this->save_to_File();
    }

    void save_to_File() {
        ofstream g(this->filename);
        for (auto &prod: v){
            g << to_string(prod.get_id()) << " " << to_string(prod.getunban()) << " " << prod.getcincibani() << " " << to_string(prod.getzecebani()) << " " <<to_string(prod.getcincizecibani())<<endl;
        }
        g.close();
    }

    vector<Money> get_all_file() override{
        return v;
    }

    int size_file(){
        return (int)v.size();
    }

    Money get_by_id_file(int id) override{
        for (Money &p: v) {
            if (p.get_id() == id) {
                return p;
            }
        }throw MyException("Nu exista banii cu id-ul dat.");
    }

    bool find(T P) override{
        for(T &i: v){
            if(i == P)
                return true;
        }
        return false;
    }

    ~RepoMoney(){
        fstream f(filename);
        if (f.is_open())
            f.close();
    }};

#endif //LAAB9_REPOMONEY_H
