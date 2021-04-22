#include <iostream>
#include <vector>
#include <stdlib.h>

/* This is a leetcode "coding test": https://leetcode.com/problems/find-median-from-data-stream/
 * This demonstrates the uselessness of coding questions.
 * it doesn't test insight;
 */

class MedianFinder {

private:
  //We poin this on the MOTHAFUCKIN HEAP because we have no idea how large this mothafucker
  //will become!
  std::vector<int> *list;
    
public:
    /** initialize your data structure here. */
    /* Hell NO MOTHAFUCKER!!! Your structure should be private 
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
       size_t  mid = (list->size() >> 1); // precalculate this as it's used in both situations and shifting is faster than /

       if (list->size() % 2 == 0)
         return static_cast<double>( (double)(list->at(mid-1) + (double)list->at(mid)) / 2);
       else
         return static_cast<double>(list->at(mid));
    }
    
    /*
     * Why the fuck wasn't there a destructir in your stupid fucking template?
     * Why did I have to put in the mothafucking effort?
     */
    ~MedianFinder() {
       if (list!=NULL)
         delete list; 
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
  f.addNum(3);
  f.addNum(2);
  f.addNum(3);
  std::cout << "Median for {3, 2, 3}: " << f.findMedian() << std::endl;
  f.addNum(3);
  f.addNum(2);
  f.addNum(3);
  std::cout << "Median for {3, 2, 1, 5, 2, 3}: " << f.findMedian() << std::endl;

  return 0;
}
