#ifndef LAAB9_SERVICE_H
#define LAAB9_SERVICE_H

#include "../Repo/IRepo.h"
#include "../Repo/Repo.h"
#include "../Repo/RepoFile.h"
#include "../Repo/RepoMoney.h"
#include "../Product/Product.h"
#include "../Money/Money.h"
class Service{
private:
    IRepo<Product> &repo;
    IRepo<Money> &repo2;
    //Money money = Money(1,1,2,5,1);
public:
    Service();
    /**
     * constructor
     * @param r - repository object
     */
    Service(IRepo<Product> &r, IRepo<Money> &r2);

    /**
     * destructor
     */
    ~Service();

    /**
     * add a product to repo
     * @param prod - product
     */
    void create(Product &prod);

    /**
     * update a product from repo
     * @param old_ent - old product
     * @param new_ent - new product
     */
    void update(Product old_ent, Product new_ent);

    /**
     * delete a product from repo
     * @param prod - product
     */
    void delete_prod(Product prod);

    /**
     * gets all the products from repo
     * @return all the products from repo
     */
    std::vector <Product> get_all();

    /**
     * gets an product by id
     * @param id - id of the product
     * @return - the product with given id
     */
    Product get_by_id(int id);

    /**
     * buy a product from repo
     * @param id - id of a product
     * @param sum - the customer amount
     * @return specific message if the customer can buy the product or not
     */
    int buy(int id, double sum);

    /**
     * gets products for a given name
     * @param name - name of the product
     * @return - the products with the given name
     */
    vector<Product> show_product_by_name(string name);

    /**
     * verify if the products is in repo
     * @param P - product
     * @return true if the product is in repo, false otherwise
     */
    int find(Product P);

    /**
     * shows the money left
     */
    void show_money();

    /**
     * insert number of coins
     */
    void read_money(int nr1, int nr2, int nr3, int nr4);

    void add_money_to_tonomat(int nr1, int nr2, int nr3, int nr4);

};


#endif //LAAB9_SERVICE_H
