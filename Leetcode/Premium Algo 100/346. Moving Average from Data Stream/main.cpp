#include<queue>
using namespace std;
class MovingAverage {
public:
    queue<int>pq;
    int lim=0;
    double average=0,sum=0;
    explicit MovingAverage(int size) {
        lim=size;
    }

    double next(int val) {
        pq.push(val);
        sum+=val;
        average=sum/(1.0*(int)pq.size());
        if(pq.size()==lim){
            auto top=pq.front();
            sum-=top;
            pq.pop();
        }
        return average;

    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */