#ifndef __FILTER_HPP__
#define __FILTER_HPP__

#include <cstring>

using namespace std;

class Filter {
    public:
	virtual ~Filter() = default;
	virtual bool filter(const MovieList* list, int row) const = 0;
};

class Filter_feature : public Filter {
    protected:
	int column;
    public:
	Filter_feature(const MovieList* list, const string& name) {
	    column = list->getFeature(name);
	}
	virtual bool filter(const MovieList* list, int row) const {
	    return filter(list->movieData(row, column));
	}
	virtual bool filter(const string& s) const = 0;
};

class AND : public Filter {
    protected:
	Filter* f1 = nullptr;
	Filter* f2 = nullptr;
    public: 
	AND(Filter* filter1, Filter* filter2) {
	    f1 = filter1;
	    f2 = filter2;
	}
	virtual bool filter(const MovieList* list, int row) const {
	    return f1->filter(list, row) && f2->filter(list, row);
	}
	~AND() {
	    delete f1;
	    delete f2;
	}
};

class OR : public Filter {
    protected:
	Filter* f1 = nullptr;
	Filter* f2 = nullptr;
    public:
	OR(Filter* filter1, Filter* filter2) {
	    f1 = filter1;
	    f2 = filter2;
	}
	virtual bool filter(const MovieList* list, int row) const {
	    return f1->filter(list, row) || f2->filter(list, row);
	}
	~OR() {
	    delete f1;
	    delete f2;
	}
};

class NOT : public Filter {
    protected:
	Filter* f1 = nullptr;
    public: 
	NOT(Filter* filter1) {
	    f1 = filter1;
	}
	virtual bool filter(const MovieList* list, int row) const {
	    return !(f1->filter(list, row));
	}
	~NOT() {
	    delete f1;
	}
};

class FIND : public Filter_feature {
	protected:
		string feature_2;
	public:
		FIND(const MovieList* movie, const string& features, const string& feature2) : Filter_feature(movie, features) {
   		feature_2 = feature2;
	}
	virtual bool filter(const string& featurename) const{
		if(featurename.find(feature_2) == string::npos){
			return false;
		}
		else{
			return true;
		}
	}
};


		
	
#endif 
