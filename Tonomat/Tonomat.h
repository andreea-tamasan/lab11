//
// Created by Home on 09.05.2022.
//

#ifndef LAAB9_TONOMAT_H
#define LAAB9_TONOMAT_H
#include "../Product/Product.h"
#include "../Service/Service.h"
class Tonomat {
private:
    Service service;
protected:
    int products[100];
public:
    Tonomat();

    Tonomat(Service &ser);


    void remove(Product &P);

    void nrProducts();

    ~Tonomat();

};


#endif //LAAB9_TONOMAT_H
