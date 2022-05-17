#ifndef LAAB9_REPO_H
#define LAAB9_REPO_H

#include <iostream>
#include <vector>
#include "../Product/Product.h"
#include "IRepo.h"
using namespace std;
template<class T> class Repo: public IRepo<T> {
private:
    vector<T> v;
public:
    /**
     * constructor default
     */
    Repo()= default;

    /**
     * adds product to repo
     * @param prod - product
     */
    void add_entity(T &prod) override{
        this->v.push_back(prod);
    }

    /**
     * gets all products from repo
     * @return - all products from repo
     */
    vector<T> get_all_file() override{
        return v;
    }

    /**
     * gets an product by id
     * @param id - id of the product
     * @return - the product with given id
     */
    T get_by_id_file(int id) override{
        for (Product &p: v) {
            if (p.get_id() == id) {
                return p;
            }
        }
        throw std::runtime_error("No entity with specified id found");
    }

    /**
     * deletes a product from repo
     * @param prod - product
     */
    void delete_from_file(T prod) override{
        Product toDelete = get_by_id(prod.get_id());
        for (int i = 0; i< v.size(); i++) {
            if (v[i].get_id() == prod.get_id()) {
                v.erase(v.begin()+i);
            }
        }
    }

    /**
     * updates a product
     * @param old_prod - old product
     * @param new_prod - new product
     */
    void update_file(T &old_prod, T new_prod) override{
        for(int i =0; i< v.size(); i++)
            if(v[i].get_id() == old_prod.get_id()){
                v[i] = new_prod;
            }
    }

    /**
     * gets the number of products
     * @return the number of products from repo
     */
    int getSize(){
        return v.size();
    }

    /**
     * verify if a product is in repo
     * @param P - product
     * @return true if the product is in repo, false otherwise
     */
    bool find(T P) override{
        for (T &i: v) {
            if (i == P)
                return true;
        }
        return false;
    }

    /**
     * destructor
     */
    ~Repo()= default;

};


#endif //LAAB9_REPO_H
