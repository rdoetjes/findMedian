#include <iostream>
#include <vector>
#include <stdlib.h>

class MedianFinder {

  private:
    //We put this on the MOTHAFUCKIN HEAP because we have no idea how large this fucker
    //will become!
    std::vector<int> *list;
    
  public:
    /** initialize your data structure here. */
    /* Hell NO!!! Your structure should be private 
     * Why else do you have an addNum method?
     * And I don't think that in this case you would like this structure to be public
     * because otherwise a better more suitable approach would be to pass a pointer to
     * a vector into a static function to do this, MOTHAFUCKER
     */
    MedianFinder() {
        list = new std::vector<int>;
    }
    
    void addNum(int num) {
        list->push_back(num);
    }
    
    double findMedian() {
        int s = list->size(); //total number (we use this more than once so precalculate)
        int m = s >> 1; //middle of the list (we use this at least once in either outcome)
	sort(list->begin(), list->end());
        return (s & 1 ? list->at(m) : (double)(list->at(m - 1) + list->at(m)) / 2.0); 
    }
    
    ~MedianFinder() {
       if (list!=NULL) delete list; 
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
int main(){  
  MedianFinder f;
  f.addNum(1);
  f.addNum(2);
  f.addNum(3);
  std::cout << "Median for {1, 2, 3}: " << f.findMedian() << std::endl;
  f.addNum(4);
  f.addNum(2);
  f.addNum(7);
  std::cout << "Median for {1, 2, 3, 4, 2, 7}: " << f.findMedian() << std::endl;

  return 0;
}
