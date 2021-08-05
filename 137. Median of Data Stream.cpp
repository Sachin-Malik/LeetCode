class MedianFinder {
public:
/** initialize your data structure here. */
priority_queue<int,vector<int>,greater<int> > second;
priority_queue<int> first;

int nums=0;
MedianFinder() {

}

void addNum(int num) {
        if(first.size()==0) {
                first.push(num);
                nums++;
                return;
        }
        if(first.size()==second.size()) {
                int s_top=second.top();
                if(num>s_top) {
                        first.push(second.top());
                        second.pop();
                        second.push(num);
                }else{
                        first.push(num);
                }
        }else{
                int f_top=first.top();
                if(num>f_top) {
                        second.push(num);
                }else{
                        second.push(first.top());
                        first.pop();
                        first.push(num);
                }
        }
        nums++;
}

double findMedian() {

        if(nums%2==1) {
                return first.top();
        }
        double a=first.top();
        double b=second.top();

        a=(a+b)/(double)2;
        return a;
}
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
