/*
 *  https://leetcode.com/problems/apply-discount-every-n-orders/submissions/
 *  (c) Mohammad Hasanzadeh Mofrad, 2020
 *  (e) m.hasanzadeh.mofrad@gmail.com
 */
 
class Cashier {
public:
    int n;
    int m;
    int discount;
    std::unordered_map<int, int> products;
    Cashier(int n_, int discount_, vector<int>& products_, vector<int>& prices_) {
        n = n_;
        m = 0;
        discount = discount_;
        
        int size = products_.size();
        for(int i = 0; i < size; i++) {
            products[products_[i]] = prices_[i];
        }
    }
    
    double getBill(vector<int> product_, vector<int> amount_) {
        double bill = 0;
        m++;
        
        int size = product_.size();
        for(int i = 0; i < size; i++) {
            bill += (products[product_[i]] * amount_[i]); 
        }
        
        if(m == n) {
            bill -= (discount * bill) / 100;
            m=0;
        }
        return bill;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */