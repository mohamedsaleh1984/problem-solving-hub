#include "../common.h"

//bool IsIncreasingOrder(vector<int> products) {
//    if (products.size() == 1)
//        return true;
//
//    for (int i = 1; i < products.size(); i++)
//    {
//        if (products[i - 1] > products[i])
//            return false;
//    }
//    return true;
//}
//
//int allSum(vector<int> products) {
//    int iSum = 0;
//    for (auto el : products)
//        iSum += el;
//    return iSum;
//}
//
//long findMaxProductsHelpers(vector<int> products) {
//
//    map<int, int> mapper;
//    for (int i = 0; i < products.size(); i++)
//        mapper[products[i]] = i;
//
//    sort(products.begin(), products.end());
//    long product = 0;
//    for (int i = products.size() - 1; i >= 0; i--) {
//
//        int indx = mapper[products[i]];
//        if (indx + 1 >= products.size()) {
//            product += products[indx];
//        }
//        else
//        {
//            int nextValue = mapper[indx];
//            if()
//        }
//        
//
//        bool isLess = 
//
//
//
//
//    }
//    return product;
//}
//
//long findMaxProducts(vector<int> products) {
//    if (products.size() == 0)
//        return 0;
//    if (products.size() == 1)
//        return products[0];
//
//    if (IsIncreasingOrder(products))
//        return allSum(products);
//
//    return findMaxProductsHelpers(products);
//}

int main()
{
  /*  vector<int> prods{ 7,4,5,2,6,5 };

   long res =  findMaxProducts(prods);

   cout << res << endl;*/
        

    return 0;
}

