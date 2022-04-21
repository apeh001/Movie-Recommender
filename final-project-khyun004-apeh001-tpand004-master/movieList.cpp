#include "movieList.hpp"
#include "filter.hpp"
#include <algorithm>
#include <iostream>

MovieList::~MovieList() {
    delete filter;
}

const std::string& MovieList::movieData(int row, int column) const {
    return movies.at(row).at(column);
}

std::string& MovieList::movieData(int row, int column) {
    return movies.at(row).at(column);
}

void MovieList::setSelection(Filter* newFilter) {
    delete filter;
    filter = newFilter;
}

void MovieList::printMovies(std::ostream& out) const {
    if(filter == nullptr) 
    {
        for(unsigned i = 0; i < movies.size(); i++)
	{
	    out << movies.at(i).at(0);
            out << '\n';
        }
    }
    else 
    {
        for(unsigned i = 0; i < movies.size(); i++)
	{
            if(filter->filter(this, i))
	    {
		out << movies.at(i).at(0);
                out << '\n';
            }
        }
    }    
}

void MovieList::setCharac(const std::vector<std::string>& characs) {
    features = characs;
}

void MovieList::addMovie(const std::vector<std::string>& movieData) {
    movies.push_back(movieData);
}

int MovieList::getFeature(const std::string& name) const {
    for(int i=0; i< features.size(); i++)
        if(features.at(i) == name)
            return i;
    return -1;
}
