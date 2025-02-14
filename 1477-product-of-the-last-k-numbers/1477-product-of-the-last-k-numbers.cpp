class ProductOfNumbers {
public:
    vector<int> nums, pp;
    
    ProductOfNumbers() {
        pp.push_back(1);
    }

    void add(int num) {
        
            if(num == 0){
                pp.clear();
               pp.push_back(1);
            }
            else if(pp.size() == 0){
                pp.push_back(num);
            }
            else
               pp.push_back(num * pp.back());
    }

    int getProduct(int k) {
        if (pp.size() <= k)
            return 0;
        return pp.back() / pp[pp.size() - k - 1];

        // int result=1;
        // for(int i = nums.size()-k;i<nums.size();i++){
        //     result *= nums[i];
        // }
        // return result;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */