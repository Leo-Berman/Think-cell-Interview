#include"myclass.h"

using namespace:: std;
int main(){

    interval_map<int,char>* mymap = new interval_map<int,char>('a');
    char hold;
    char hold2;
    // Get an iterator pointing to the first element in the
    // map
    map<int, char>::iterator it = mymap->retmap().begin();
 
    // Iterate through the map and print the elements
    /*while (it != mymap->retmap().end()) {
        cout << "Key: " << it->first
             << ", Value: " << it->second << endl;
        ++it;
    }*/
    hold = mymap->operator[](23);
    hold2 = mymap->operator[](30);
    cout << "Original Beginning of Interval = " << hold << endl;
    cout << "Original End of Interval = " << hold2 << endl;
    mymap->assign(23,26,'w');
    hold = mymap->operator[](23);
    hold2 = mymap->operator[](27);
    cout << "New Beginning of Interval = " << hold << endl;
    cout << "New End of Interval = " << hold2 << endl;
    //mymap->assign(10,20,'w');
    //hold = mymap->operator[](15);
    //cout << " My char = " << hold << endl;




}