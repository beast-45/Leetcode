class Bank {
public:
    int n;
    vector<long long> accounts;
    
    Bank(vector<long long>& balance) {
        n = balance.size();
        accounts = balance;
    }

    bool validAccountNum(int accNum){
        return accNum >= 0 && accNum < n;
    }

    bool transfer(int account1, int account2, long long money) {
        int acc1 = account1-1 , acc2 = account2-1;
        if(validAccountNum(acc1) && validAccountNum(acc2)){
            if(accounts[acc1] < money) return false;
            else{
                accounts[acc1] -= money;
                accounts[acc2] += money;
                return true;
            }
        }
        return false;
    }
    
    bool deposit(int account, long long money) {
        if(validAccountNum(account-1)){
            accounts[account-1] += money;
            return true;
        }
        return false;
    }
    
    bool withdraw(int account, long long money) {
        if(validAccountNum(account-1) && money <= accounts[account-1]){
            accounts[account-1] -= money;
            return true;
        }
        return false;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */