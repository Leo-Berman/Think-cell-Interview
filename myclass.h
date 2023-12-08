#include <map>
#include<iostream>
#include<stdio.h>
template<typename K, typename V>
class interval_map {
	friend void IntervalMapTest();
	V m_valBegin;
	std::map<K,V> m_map;
public:
	// constructor associates whole range of K with val
	interval_map(V const& val)
	: m_valBegin(val)
	{}

    std::map<K,V> retmap(){
        return m_map;
    }

	// Assign value val to interval [keyBegin, keyEnd).
	// Overwrite previous values in this interval.
	// Conforming to the C++ Standard Library conventions, the interval
	// includes keyBegin, but excludes keyEnd.
	// If !( keyBegin < keyEnd ), this designates an empty interval,
	// and assign must do nothing.
	void assign( K const& keyBegin, K const& keyEnd, V const& val ) {
		// INSERT YOUR SOLUTION HERE
		
		// First check to see if any operation needs to be done
		// at all and if not return
		//
		if(!(keyBegin<keyEnd)){
			
			// exit the function
			//
			return;
		}

        // get the value that currently takes up the first index of
		// space you want to fill
        //
        auto IBegin = m_map.lower_bound(keyBegin);

        // get the next value to see if you would overlap by inserting
		// the interval given
        //
        auto IEnd = m_map.lower_bound(keyEnd);
		
		/* check to see if there is overlap or if you've reached the end of your map */
		/*Referenced later as overlapped cases*/
    	
		// declaration of pair that may or may not be used
		//
		std::pair<K,V> mypair;

		// Flag in here to see if pair has been changed
		//
    	bool extrapair = false;

		// First condition checks to see if our interval end is at the last value
		// of the map
		// Second condition check to see if we the end of our interval is going to
		// overlap the next interval
		//
    	if((IEnd == m_map.end()) || (keyEnd < IEnd->first)){

			// If either condition is met, we need to update mypair that will
			// be inserted at the end so we don't lose the extra information
			//

			// Resumes the pair at the end of our inserted pair
			//
    	    mypair.first = keyEnd;

			// Uses the given function to give the pair the old value
			//
    	    mypair.second = operator[](keyEnd); 

			// set the flag to have a pair change
			//
			extrapair = true;
    	}

		// First condition checks to see if our interval begin is at the last value
		// of the map
		// Second condition checks to see if we are trying to insert something in
		// the middle of a value
		//
    	else if ((IBegin == m_map.end()) || (keyBegin < IBegin->first)){
    	    
			// If either condition is met, we need to update mypair that will
			// be inserted at the end so we don't lose the extra information
			//

			// Resumes the pair at the end of our inserted pair
			//
			mypair.first = keyEnd;

			// Uses the given function to give the pair the old value
			//
    	    mypair.second = operator[](keyBegin);

			// set the flag to have a pair change
			//
			extrapair = true;
    	}

		// if not inserted at end erase all the inbetween pairs
		//
		if(IEnd != m_map.end()){
        	m_map.erase(IBegin,IEnd);
    	}

		// create a pair to insert change
		//
		std::pair<K,V>insertpair;
    	insertpair.first = keyBegin;
    	insertpair.second = val;

		// insert change
		//
    	m_map.insert(insertpair);
	
		// check to see if overlapped case was generated
		//
    	if(extrapair == true){

			// if so insert new pair
			//
			m_map.insert(mypair);
		}

	}

	// look-up of the value associated with key
	V const& operator[]( K const& key ) const {
		auto it=m_map.upper_bound(key);
		if(it==m_map.begin()) {
			return m_valBegin;
		} else {
			return (--it)->second;
		}
	}
};

// Many solutions we receive are incorrect. Consider using a randomized test
// to discover the cases that your implementation does not handle correctly.
// We recommend to implement a test function that tests the functionality of
// the interval_map, for example using a map of int intervals to char.