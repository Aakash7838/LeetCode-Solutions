class MedianFinder {
public:
    priority_queue<int> maxpq;
    priority_queue<int, vector<int>, greater<int>> minpq;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxpq.empty() || num <= maxpq.top()){
            maxpq.push(num);
        }else{
            minpq.push(num);
        }

        // if min have more than max so push in max 
        if((int)maxpq.size() > (int)minpq.size()+1){
            minpq.push(maxpq.top());
            maxpq.pop();
        }
        if((int)minpq.size() > (int)maxpq.size()){
            maxpq.push(minpq.top());
            minpq.pop();
        }
    }
    
    double findMedian() {
        if(maxpq.size() > minpq.size()){
            return (double)maxpq.top();
        }

        return (double)(maxpq.top() + minpq.top())/2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */