#ifndef LAAB9_REPOFILE_H
#define LAAB9_REPOFILE_H

#include <iostream>
#include <fstream>
#include "../Product/Product.h"
#include "Repo.h"
#include <vector>
#include "IRepo.h"
#include "../Exception/Exception.h"

using namespace std;
template<class T> class RepoFile: public IRepo<T>{
private:
    const char* filename{};
    vector<T> v;
public:
    /**
     * constuctor default
     */
    RepoFile() = default;

    /**
     * reads from file
     * @param fname - name of the file
     */
    RepoFile(const char* fname) {
        this->filename = fname;
        ifstream f(fname);
        while (!f.eof()) {
            int id, cod, price,sold;
            string name;
            f >> id >> cod >> name >> price>>sold;
            if (!name.empty()) {
                Product p(id, cod, name, price, sold);
                v.push_back(p);
            }
        }
        f.close();
    }

    /**
     * adds an product to file
     * @param prod - product
     */
    void add_entity(Product &prod) override{
        this->v.push_back(prod);
        this->save_to_File();
    }

    /**
     * deletes a product from file
     * @param prod - product
     */
    void delete_from_file(Product prod) override{
        Product toDelete = get_by_id_file(prod.get_id());
        for (int i = 0; i< v.size(); i++) {
            if (v[i].get_id() == prod.get_id()) {
                v.erase(v.begin()+i);
            }
        }
        this->save_to_File();

    }

    /**
     * updates a product from file
     * @param old_prod - old product
     * @param new_prod - new product
     */
    void update_file(Product &old_prod, Product new_prod) override{
        for(int i =0; i< v.size(); i++)
            if(v[i].get_id() == old_prod.get_id()){
                v[i] = new_prod;
            }
        this->save_to_File();
    }

    /**
     * saves the products in file
     */
    void save_to_File() {
        ofstream g(this->filename);
        for (auto &prod: v){
            g << to_string(prod.get_id()) << " " << to_string(prod.get_cod()) << " " << prod.get_name() << " " << to_string(prod.get_price()) << " " <<to_string(prod.get_sold())<<endl;
        }
        g.close();
    }

    /**
     * gets all the products from file
     * @return all the products
     */
    vector<Product> get_all_file() override{
        return v;
    }

    /**
     * gets the number of products in file
     * @return - the number of products in file
     */
    int size_file(){
        return (int)v.size();
    }

    /**
     * verify if a products is in file
     * @param P - product
     * @return true if the products is in file, false otherwise
     */
    bool find(Product P) override{
        for (Product &i: v) {
            if (i.get_id() == P.get_id())
                return true;
        }
        return false;
    }

    /**
     * gets a product with a given id
     * @param id - id of a product
     * @return the product with given id
     */
    Product get_by_id_file(int id) override{
        for (Product &p: v) {
            if (p.get_id() == id) {
                return p;
            }
        }throw MyException("Nu exista. ");
    }

    /**
     * destructor
     */
    ~RepoFile(){
        fstream f(filename);
        if (f.is_open())
            f.close();
    }
};
#endif //LAAB9_REPOFILE_H
