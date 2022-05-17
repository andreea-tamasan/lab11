#ifndef LAAB9_UI_H
#define LAAB9_UI_H


#include "../Service/Service.h"

class UI {
private:
    Service service;

    void add_product();

    void show_all();

    void delete_product(int id);

    void update_product(int id, int id_new, int cod, string name, int price, int sold);

    void show_product_name();

public:
    /**
     * constructor default
     */
    //UI();

    /**
     * constructor
     * @param ser - service
     */
    UI(Service &ser);

    /**
     * run menu - the aplication
     */
    void run_menu();

    /**
     * function for customer to buy a product
     * id - id product
     * s - sum of money
     */
    void achizitionare(int id,double s);

    /**
     * shows the money left
     */
    void show_money();

    /**
     * reads the number of coins
     */
    void read_money(int nr1, int nr2, int nr3, int nr4);
    /**
     * destructor
     */
    ~UI();





};


#endif //LAAB9_UI_H
