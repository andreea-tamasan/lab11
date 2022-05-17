#include "UI.h"
#include <iostream>

using namespace std;


UI::UI(Service &ser) : service(ser){}

void UI::add_product() {
    int id, cod, price,sold;
    string name;
    cout << "Give id:";
    cin >> id;
    cout << "Give the code of the product:";
    cin >> cod;
    cout << "Give the name of the product:";
    cin >> name;
    cout << "Give the price of the product:";
    cin >> price;
    cout << "Give the sold of the product:";
    cin >> sold;
    for(auto& p: service.get_all()){
        if(id == p.get_id())
            throw MyException("Exista produs cu id-ul dat.");
    }
    if(id<=0)
        throw MyException("Exista produs cu id-ul dat.");
    Product product(id, cod, name, price, sold);
    service.create(product);
}

void UI::show_all() {
    for (auto &pr: service.get_all()) {
        cout << pr.get_id() << " " << pr.get_cod() << " " << pr.get_name() << " " << pr.get_price() <<" " << pr.get_sold()<< endl;
    }

}

void UI::delete_product(int id) {
    if(service.find(service.get_by_id(id))) {
        for (auto &pr: service.get_all()) {
            if (id == pr.get_id()) {
                service.delete_prod(pr);
            }

        }
    }else
    throw MyException("Nu exista produdul cu id-ul dat.");

}

void UI::update_product(int id, int id_new, int cod, string name, int price,int sold) {
    if(service.find(service.get_by_id(id))){
    Product new_prod(id_new, cod, name, price,sold);
    for (auto &pr: service.get_all()) {
        if (id == pr.get_id()) {
            service.update(pr, new_prod);
        }
    }}else
    throw MyException("Nu exista produsul cu id-ul dat.");
}

void UI::show_money() {
    service.show_money();
}

void UI::achizitionare(int id,double s) {
    if(service.find(service.get_by_id(id)))
        service.buy(id,s);
    else
        throw MyException("Nu exista identitate cu id-ul dat.");
}


void UI::run_menu() {
    bool ok = true;
    while (ok) {
        cout << endl;

        cout << "1. Add a product." << endl;
        cout << "2. Delete a product." << endl;
        cout << "3. Update a product." << endl;
        cout << "4. Show products with a given name." << endl;
        cout << "5. Buy a product." << endl;
        cout << "6. Show money left in tonomat." << endl;
        cout << "7. Reset the money in tonomat." << endl;
        cout << "s. Show products." << endl;
        cout << "x. Close" << std::endl;
        char option;
        cout << "Give option: ";
        cin >> option;
        cout << endl;
        switch (option) {
            case '1': {
                add_product();
                break;
            }
            case 's': {
                show_all();
                break;
            }
            case '2':{
                int id;
                cout<<"Give an id of the product you want to delete: ";
                cin>>id;
                delete_product(id);
                break;
            }
            case '3':{
                int id;
                cout << "Give the id of the product you want to update: ";
                cin >> id;
                int id_new, cod, price,sold;
                string name;
                cout << "Give the new id:";
                cin >> id_new;
                cout << "Give the new code of the product:";
                cin >> cod;
                cout << "Give the new name of the product:";
                cin >> name;
                cout << "Give the new price of the product:";
                cin >> price;
                cout<<"Give pieces for product: ";
                cin>>sold;
                update_product(id,id_new,cod,name,price,sold);
                break;
            }
            case '4': {
                string n;
                cin>>n;
                vector<Product> v =service.show_product_by_name(n);
                
                for (auto &p: v)
                        cout << p.get_id() << " " << p.get_cod() << " " << p.get_name() << " " << p.get_price() << endl;
                break;
            }
            case '5':{
                double s;
                int nr_1 , nr_5, nr_10, nr_50;
                int id;
                cout << "Dati id produsului de achizitionat: ";
                cin >> id;
                cout<<"Dati nr monede de 1 ban: ";
                cin>>nr_1;
                cout<<"Dati nr monede de 5 bani: ";
                cin>>nr_5;
                cout<<"Dati nr monede de 10 bani: ";
                cin>>nr_10;
                cout<<"Dati nr monede de 50 bani: ";
                cin>>nr_50;
                s = (nr_1 + 5*nr_5 + 10*nr_10 + 50*nr_50)/100.0;
                service.add_money_to_tonomat(nr_1,nr_5,nr_10,nr_50);
                achizitionare(id,s);
                break;
            }
            case '6':{
                show_money();
                break;
            }
            case '7':{
                int nr1, nr2, nr3, nr4;
                cout<<"Give nr of 1 coins: ";
                cin>>nr1;
                cout<<"Give nr of 5 coins: ";
                cin>>nr2;
                cout<<"Give nr of 10 coins: ";
                cin>>nr3;
                cout<<"Give nr of 50 coins: ";
                cin>>nr4;
                read_money(nr1,nr2,nr3,nr4);
                break;
            }
            case 'x':
                ok = false;
                break;
            default:
                cout << "Wrong! Try again!" << endl;
        }
    }
}

void UI::read_money(int nr1, int nr2, int nr3, int nr4) {
    service.read_money(nr1,nr2,nr3,nr4);
}

UI::~UI() = default;
