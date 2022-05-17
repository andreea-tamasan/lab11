#include "Service.h"

Service::Service(IRepo<Product> &r,IRepo<Money> &r2) : repo(r), repo2(r2) {};

void Service::create(Product &prod) {
    this->repo.add_entity(prod);
}

void Service::update(Product old_ent, Product new_ent) {
    repo.update_file(old_ent, new_ent);
}

void Service::delete_prod(Product prod) {
    repo.delete_from_file(prod);
}

std::vector<Product> Service::get_all() {
    return repo.get_all_file();
}

Product Service::get_by_id(int id) {
    return repo.get_by_id_file(id);
}

vector<Product> Service::show_product_by_name(string name) {
    vector <Product> v;
    for (auto &p: repo.get_all_file())
        if (p.get_name() == name){
            v.push_back(p);
        }
    return v;
}

int Service::buy(int id, double sum) {
    if (repo.find(repo.get_by_id_file(id))) {
        int can_1 = 0,can_5=0,can_10=0,can_50=0;
        int i_1 = repo2.get_by_id_file(1).getunban();
        int i_5 = repo2.get_by_id_file(1).getcincibani();
        int i_10 = repo2.get_by_id_file(1).getzecebani();
        int i_50 = repo2.get_by_id_file(1).getcincizecibani();
        Money money_old (1,i_1,i_5,i_10,i_50);
        double rest = sum - repo.get_by_id_file(id).get_price();
        sum =rest;
        int change = sum*100;

        int can_50_2 = min(change / 50, this->repo2.get_by_id_file(1).getcincizecibani());
        if(change>0){
        can_50 = min(change / 50, this->repo2.get_by_id_file(1).getcincizecibani());
        //this->repo2.get_by_id_file(1).setcinzecidebani(i_50 -can_50);
        change = change - can_50 * 50;}

        int can_10_2 = min(change / 10, this->repo2.get_by_id_file(1).getzecebani());
        if(change>0){
        can_10 = min(change / 10, this->repo2.get_by_id_file(1).getzecebani());
        //this->repo2.get_by_id_file(1).setzecebani(i_10-can_10);
        change =change - can_10 * 10;}

        int can_5_2 = min(change / 5, this->repo2.get_by_id_file(1).getcincibani());
        if(change>0){
        can_5 = min(change / 5, this->repo2.get_by_id_file(1).getcincibani());
        //this->repo2.get_by_id_file(1).setcincibani(i_5-can_5);
        change = change- can_5 * 5;}

        int can_1_2 = min(change / 1, this->repo2.get_by_id_file(1).getunban());
        if(change>0){
        can_1 = min(change / 1, this->repo2.get_by_id_file(1).getunban());
        //this->repo2.get_by_id_file(1).setunban(i_1-can_1);
        change = change- can_1 * 1;
        }
        //if(can_1 <0 && can_1 >=i_1)
        //    can_1=0;
        //if(can_5 <0 && can_1 >=i_5)
        //    can_5=0;
        //if(can_10 <0 && can_10 >=i_10)
        //    can_10=0;
        //if(can_50 <0 && can_50 >=i_50)
        //    can_50=0;
        if(get_by_id(id).get_sold() == 0) {
            repo2.get_by_id_file(1).setunban(i_1);
            repo2.get_by_id_file(1).setcincibani(i_5);
            repo2.get_by_id_file(1).setzecebani(i_10);
            repo2.get_by_id_file(1).setcinzecidebani(i_50);
            cout<<"Nu exista suficient stoc. ";
        }

        if(rest<0){
            repo2.get_by_id_file(1).setunban(i_1);
            repo2.get_by_id_file(1).setcincibani(i_5);
            repo2.get_by_id_file(1).setzecebani(i_10);
            repo2.get_by_id_file(1).setcinzecidebani(i_50);
            cout<<"Nu ati introdus suficienti bani. ";
        }

        if (change == 0 && rest >=0 && get_by_id(id).get_sold()>0)
        {
            Money money_new(1,i_1-can_1 ,i_5 - can_5,i_10 - can_10,i_50 - can_50);
            cout << "Aparatu da rest, bravo! ";
            Product oldP(id,get_by_id(id).get_cod(),get_by_id(id).get_name(),get_by_id(id).get_price(),get_by_id(id).get_sold());
            Product newP(id,get_by_id(id).get_cod(),get_by_id(id).get_name(),get_by_id(id).get_price(),get_by_id(id).get_sold()-1);
            update(oldP,newP);
            //repo2.update_file(money_old,money_new);
            repo2.delete_from_file(money_old);
            repo2.add_entity(money_new);
            cout<<rest;
        }
        if(change !=0)
        {
            cout << "Aparatu nu da rest, cry about it. ";
            repo2.get_by_id_file(1).setunban(i_1);
            repo2.get_by_id_file(1).setcincibani(i_5);
            repo2.get_by_id_file(1).setzecebani(i_10);
            repo2.get_by_id_file(1).setcinzecidebani(i_50);
            return 0;
        }
    }
    else return 0;
}

int Service::find(Product P) {
    return repo.find(P);
}

void Service::show_money() {
    cout<<" 1 ban: " <<repo2.get_by_id_file(1).getunban()<< ";5 bani: "<<repo2.get_by_id_file(1).getcincibani() << " ;10 bani: "<<repo2.get_by_id_file(1).getzecebani() << " ;50 bani: "<<repo2.get_by_id_file(1).getcincizecibani();
}

void Service::read_money(int nr1, int nr2, int nr3, int nr4) {
    int i_1 = repo2.get_by_id_file(1).getunban();
    int i_5 = repo2.get_by_id_file(1).getcincibani();
    int i_10 = repo2.get_by_id_file(1).getzecebani();
    int i_50 = repo2.get_by_id_file(1).getcincizecibani();
    Money money_old (1,i_1,i_5,i_10,i_50);
    Money money_new(1,nr1 ,nr2,nr3,nr4);
    repo2.delete_from_file(money_old);
    repo2.add_entity(money_new);

}

void Service::add_money_to_tonomat(int nr1, int nr2, int nr3, int nr4) {
    int i_1 = repo2.get_by_id_file(1).getunban();
    int i_5 = repo2.get_by_id_file(1).getcincibani();
    int i_10 = repo2.get_by_id_file(1).getzecebani();
    int i_50 = repo2.get_by_id_file(1).getcincizecibani();
    Money money_old (1,i_1,i_5,i_10,i_50);
    Money money_new(1,nr1+i_1, nr2 + i_5 , nr3 + i_10 , i_50+nr4);
    repo2.delete_from_file(money_old);
    repo2.add_entity(money_new);

}

Service::~Service() = default;
