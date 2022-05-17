#include "Tests.h"
#include "../Repo/Repo.h"
#include "../Service/Service.h"


#include <vector>
#include <cassert>
#include <fstream>

void test_constructor() {
    Product product;
    assert(product.get_cod() == 0);
    assert(product.get_price() == 0);
    assert(product.get_name().empty());
}

void test_setter() {
    Product product;
    std::string s = "bomboana";
    product.set_id(1);
    product.set_cod(1);
    product.set_price(10);
    product.set_name(s);
    assert(product.get_price() == 10);
    assert(product.get_cod() == 1);
    assert(product.get_id() == 1);
    assert(product.get_name() == s);
}

void test_constructor2() {
    Product product(1, 1, "cioco", 15,5);
    assert(product.get_price() == 15);
    assert(product.get_name() == "cioco");
    assert(product.get_id() == 1);
    assert(product.get_cod() == 1);
    assert(product.get_sold() == 5);
}

void test_repo_get_all(Repo<Product> repo1) {
    Product product(1, 10, "cioco", 15,2);
    Product product2(2, 20, "twix", 10,2);
    Product product3(3, 30, "7days", 5,2);
    Product product4(4, 40, "bomboana", 7,2);

    repo1.add_entity(product);
    repo1.add_entity(product2);
    repo1.add_entity(product3);
    repo1.add_entity(product4);

    assert(repo1.getSize() == 4);

}

void test_add_repo(Repo<Product> repo1) {
    Product product(1, 10, "cioco", 15,2);
    Product product2(2, 20, "twix", 10,2);
    Product product3(3, 30, "7days", 5,2);
    Product product4(4, 40, "bomboana", 7,2);

    repo1.add_entity(product);
    repo1.add_entity(product2);
    repo1.add_entity(product3);
    repo1.add_entity(product4);

    assert(repo1.get_by_id_file(1) == product);
    assert(repo1.get_by_id_file(2) == product2);
    assert(repo1.get_by_id_file(3) == product3);
    assert(repo1.get_by_id_file(4) == product4);
}


//void test_repo_modify() {
//    Repo repo2;
//    Product product(1, 10, "cioco", 15);
//    Product product2(2, 20, "twix", 10);
//    Product product3(3, 30, "7days", 5);
//    Product product4(4, 40, "bomboana", 7);
//
//    repo2.add_product(product);
//    repo2.add_product(product2);
//    repo2.add_product(product3);
//
//    assert(repo2.getSize() == 3);
//    assert(repo2.get_all().size() == 3);
//
//    repo2.modify_product(product2, product4);
//    assert(repo2.get_by_id(4) == product4);
//}
//
//void test_repoFile(){
//    remove("productsteste.txt");
//    fstream f;
//    f.open("productsteste.txt", ios::in);
//    f.open("productsteste.txt", ios::out);
//    RepoFile repo("productsteste.txt");
//
//    Product p1( 1, 100, "Pateu", 4);
//    Product p2( 2, 101, "Napolitane", 5);
//    Product p3( 3, 102, "Bomboane", 6);
//    Product p4(4, 103, "Suc", 7);
//
//    repo.add_entity(p1);
//    repo.add_entity(p2);
//    repo.add_entity(p3);
//
//    assert(repo.size_file() == 3);
//    assert(repo.get_by_id_file(1) == p1);
//}
//
//void test_functionalitate(){
//    remove("productsteste.txt");
//    fstream f;
//    f.open("productsteste.txt", ios::in);
//    f.open("productsteste.txt", ios::out);
//    RepoFile repo("productsteste.txt");
//
//    Service service(repo);
//    Product p1( 1, 100, "Pateu", 4);
//    Product p2( 2, 101, "Napolitane", 5);
//    Product p3( 3, 102, "Pateu", 6);
//
//    service.create(p1);
//    service.create(p2);
//    service.create(p3);
//
//    vector<Product> vector = service.show_product_by_name("Pateu");
//    assert(vector.size() == 2);
//}


void tests() {
    test_constructor();
    test_setter();
    test_constructor2();
    //test_repo_get_all(repo1);
    //test_add_repo(repo1);
    //test_repo_modify();
    //test_repoFile();
    //test_functionalitate();
}
