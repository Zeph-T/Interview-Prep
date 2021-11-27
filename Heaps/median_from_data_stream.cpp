class MedianFinder {
public:
    priority_queue<int>maxHeap;
    priority_queue<int,vector<int> , greater<int>>minHeap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxHeap.size() == 0 or maxHeap.top() > num){
            maxHeap.push(num);
        }else minHeap.push(num);
        
        if(minHeap.size() > (maxHeap.size() + 1)){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }else if((minHeap.size() + 1) < maxHeap.size()){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    } 
    
    double findMedian() {
        if(maxHeap.size() == minHeap.size()){
            int d1 = maxHeap.top();
            int d2 = minHeap.top();
            double median = (double)(d1 + d2)/2;
            return median;
        }else if(maxHeap.size() > minHeap.size()){
            return maxHeap.top();
        }else{
            return minHeap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */