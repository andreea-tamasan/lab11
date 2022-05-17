//
// Created by Home on 09.05.2022.
//

#include "Tonomat.h"

Tonomat::Tonomat(Service &ser): service(ser){}


void Tonomat::remove(Product &P) {
    service.delete_prod(P);
}

Tonomat::~Tonomat() {}

void Tonomat::nrProducts() {
    for(int i=0;i< sizeof(products);i++){
        if(service.find(service.get_by_id(i)))
            products[i]--;
    }
}



