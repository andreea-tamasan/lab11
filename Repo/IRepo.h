#ifndef LAAB9_IREPO_H
#define LAAB9_IREPO_H
#include "../Product/Product.h"
#include <vector>
using namespace std;
template<class T> class IRepo {
//protected:
//    vector<Product> v;
public:
    /**
     * adds a product
     * @param prod - product
     */
    virtual void add_entity(T &prod) = 0;

    /**
     * shows all the products
     * @return - all the entities from file/memory
     */
    virtual vector<T> get_all_file() = 0;

    /**
     * deletes a product
     * @param prod - product
     */
    virtual void delete_from_file(T prod) = 0;

    /**
     * updates a product
     * @param old_prod - old product to update
     * @param new_prod - new product after update
     */
    virtual void update_file(T &old_prod, T new_prod) = 0;

    /**
     * gets a product after an id
     * @param id - id of a product
     * @return - the product with the given id
     */
    virtual T get_by_id_file(int id) = 0;

    /**
     * search if a product is in the file/memory
     * @param P - product
     * @return true if the product is find, false otherwise
     */
    virtual bool find(T P) = 0;
};


#endif //LAAB9_IREPO_H
