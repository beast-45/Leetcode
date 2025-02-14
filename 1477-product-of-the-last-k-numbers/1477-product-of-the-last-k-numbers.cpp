class ProductOfNumbers {
public:
    vector<int> product{1};
    ProductOfNumbers() {
    }

    void add(int num) {
        if(num == 0){
            product.clear();
            product.push_back(1);
        }
        else{
            product.push_back(product.back()*num);
        }
    }

    int getProduct(int k) {
        int n = product.size();
        return k >= n ? 0 : product[n-1]/product[n-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */