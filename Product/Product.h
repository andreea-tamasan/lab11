#ifndef LAAB9_PRODUCT_H
#define LAAB9_PRODUCT_H
#include <string>
#include <ostream>

using namespace std;

class Product {
private:
    int id,cod,price,sold;
    string name;
public:
    /**
     * default constructor
     */
    Product();

    /**
     * copy constructor
     * @param prod - product
     */
    Product(const Product& prod);

    /**
     * constructor with parameters
     * @param i - id of the product
     * @param cod - code of the product
     * @param name - name of the product
     * @param price - price of the product
     * @param sold - stock of the product
     */
    Product(int i, int cod,string name,int price, int sold);

     /**
      * stock getter
      * @return - int - stock of a product
      */
    int get_sold();
    /**
     * stock setter
     * @param s  - stock of a product
     */
    void set_sold(int s);

    /**
     * code getter
     * @return int - code of a product
     */
    int get_cod();

    /**
     * code setter
     * @param cod  - code of a product
     */
    void set_cod(int cod);

    /**
     * name getter
     * @return string - name of a product
     */
    string get_name();

    /**
     * name setter
     * @param n - name of a product
     */
    void set_name(string n);

    /**
     * price getter
     * @return int - price of a product
     */
    int get_price();

    /**
     * price setter
     * @param p - price of a product
     */
    void set_price(int p);

    /**
     * id getter
     * @return int - id of a product
     */
    int get_id();

    /**
     * id setter
     * @param i - id of a product
     */
    void set_id(int i);

    Product& operator=(const Product& pr);

    bool operator==(const Product& pr);

    friend ostream &operator<<(ostream &os, const Product &product);

    ~Product();
};


#endif //LAAB9_PRODUCT_H
