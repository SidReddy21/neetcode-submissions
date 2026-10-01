class BrowserHistory {

private:
    int i = 0;
    vector<string> pages;
public:
    BrowserHistory(string homepage) {
        pages = {homepage};
    }
    
    void visit(string url) {
        pages.erase(pages.begin()+i+1,pages.end());
        i++;
        pages.push_back(url);
    }
    
    string back(int steps) {
        if(i-steps < 0){
            i = 0;
            return pages.front();
        }else{
            i-=steps;
            return pages[i];
        }
    }
    
    string forward(int steps) {
        if(steps+i >= pages.size()){
            i = pages.size()-1;
            return pages.back();
        }else{
            i+=steps;
            return pages[i];
        }
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */