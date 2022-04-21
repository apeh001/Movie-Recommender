#ifndef _MOVIELIST_HPP_
#define _MOVIELIST_HPP_

#include <string>
#include <initializer_list>
#include <vector>
#include <iosfwd>

class Filter;

class MovieList {
    public:
	std::vector<std::string> features;
	std::vector<std::vector<std::string> > movies;
	Filter* filter = nullptr;

	~MovieList();
	const std::string& movieData(int row, int column) const;
	std::string& movieData(int row, int column);
	void setSelection(Filter* newFilter);
	void printMovies(std::ostream& out) const;
	void setCharac(const std::vector<std::string>& characs);
	void addMovie(const std::vector<std::string>& movieData);
	int getFeature(const std::string& name) const;
	
};

#endif
