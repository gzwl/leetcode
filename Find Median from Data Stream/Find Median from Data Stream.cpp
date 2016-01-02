/*
    用一个小顶堆和一个大顶堆来维护输入的数据
    其中大顶堆来存输入数据中小的那一半，小顶堆来存大的那一半
    小顶堆和大顶堆的size差不能大于1
*/
class MedianFinder {
private:
    priority_queue<int> small;  //大顶堆
    priority_queue<int,vector<int>,greater<int> > large;    //小顶堆
public:

    // Adds a number into the data structure.
    void addNum(int num) {
        if(small.empty())   small.push(num);
        else {
            //判断输入是大的一半还是小的一半
            if(num <= small.top())  small.push(num);
            else    large.push(num);

            //维护大小差不超过1
            if(small.size() > large.size() + 1) {
                large.push(small.top());small.pop();
            }
            if(large.size() > small.size() + 1) {
                small.push(large.top());large.pop();
            }
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        //看中位数是在小的那一半还是大的那一半
        if(large.size() == small.size())    return (double)(large.top() + small.top()) / 2;
        else    return large.size() > small.size() ? large.top() : small.top();
    }
};


// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();

