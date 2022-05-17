#include "Product.h"

#include <utility>

Product::Product() {
    this->id = 0;
    this->name = "";
    this->cod = 0;
    this->price = 0;
    this->sold = 0;
}

Product::Product(const Product &prod) {
    this->name = prod.name;
    this->cod = prod.cod;
    this->price = prod.price;
    this->id = prod.id;
    this->sold = prod.sold;
}

Product::Product(int i, int cod, string name, int price, int sold) {
    this->name = move(name);
    this->cod = cod;
    this->price = price;
    this->id = i;
    this->sold = sold;
}

int Product::get_cod() {
    return this->cod;
}

void Product::set_cod(int cod) {
    this->cod = cod;
}


std::string Product::get_name() {
    return this->name;
}

void Product::set_name(std::string n) {
    this->name = std::move(n);
}

int Product::get_price() {
    return this->price;
}

void Product::set_price(int p) {
    Product::price = p;
}

int Product::get_id() {
    return this->id;
}

void Product::set_id(int i) {
    this->id = i;

}

int Product::get_sold() {
    return this->sold;
}

void Product::set_sold(int s) {
    this->sold = s;
}


Product::~Product() {
    this->name = "";
}

bool Product::operator==(const Product &pr) {
    return this->cod == pr.cod && this->price == pr.price && this->name == pr.name && this->sold == sold;
}

Product &Product::operator=(const Product &pr) {
    this->set_id(pr.id);
    this->set_cod(pr.cod);
    this->set_price(pr.price);
    this->set_name(pr.name);
    this->set_sold(pr.sold);
    return *this;
}

ostream &operator<<(ostream &os, const Product &product) {
    os << "id: " << product.id << " cod: " << product.cod << " price: " << product.price << " name: " << product.name<< " sold: "<<product.sold;
    return os;
}




