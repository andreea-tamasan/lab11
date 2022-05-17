#include "tests/Tests.h"
#include "UI/UI.h"

int main() {
    tests();
    RepoFile<Product> repo(R"(C:\Users\Home\Desktop\laab9-repoFile\products.txt)");
    RepoMoney<Money> repo2(R"(C:\Users\Home\Desktop\laab9-repoFile\money.txt)");
    //RepoFile<Product> repo("products.txt");
    Service service(repo,repo2);
    UI ui(service);
    ui.run_menu();
    return 0;
}
