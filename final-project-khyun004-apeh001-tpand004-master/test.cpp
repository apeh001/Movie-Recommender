#include "movieList.hpp"
#include "gtest/gtest.h"
#include "filter.hpp"
#include <sstream>
#include <iostream>


TEST(MovieListTest, NormalInput){
  MovieList movie;
  std::ostringstream sout;
  movie.setCharac({"Book Title", "Pages", "Author", "Genre"});
  movie.addMovie({"Harry Potter and the Sorcerer's Stone", "362", "JK Rowling", "Fantasy"});
  movie.addMovie({"Pride and Prejudice", "273", "Jane Austen", "Classic"});
  movie.addMovie({"Animal Farm", "120", "George Orwell", "Classic"});
  movie.setSelection(new FIND(&movie, "Author", "George Orwell"));
  movie.printMovies(sout);
  EXPECT_EQ("Animal Farm\n", sout.str());
}

TEST(MovieListTest, AndCheck){
  MovieList movie;
  std::ostringstream sout;
  movie.setCharac({"Book Title", "Pages", "Author", "Genre"});
  movie.addMovie({"Harry Potter and the Sorcerer's Stone", "362", "JK Rowling", "Fantasy"});
  movie.addMovie({"Pride and Prejudice", "273", "Jane Austen", "Classic"});
  movie.addMovie({"Animal Farm", "120", "George Orwell", "Classic"});
  movie.setSelection(new AND(new FIND(&movie, "Genre", "Classic"), new FIND(&movie, "Author", "Jane Austen")));
  movie.printMovies(sout);
  EXPECT_EQ("Pride and Prejudice\n", sout.str());
}

TEST(MovieListTest, AndNotCheck){
  MovieList movie;
  std::ostringstream sout;
  movie.setCharac({"Book Title", "Pages", "Author", "Genre"});
  movie.addMovie({"Harry Potter and the Sorcerer's Stone", "362", "JK Rowling", "Fantasy"});
  movie.addMovie({"Pride and Prejudice", "273", "Jane Austen", "Classic"});
  movie.addMovie({"Animal Farm", "120", "George Orwell", "Classic"});
  movie.setSelection(new AND(new FIND(&movie, "Genre", "Classic"), new NOT(new FIND(&movie, "Pages", "120"))));
  movie.printMovies(sout);
  EXPECT_EQ("Pride and Prejudice\n", sout.str());
}

TEST(MovieListTest, OrCheck){
  MovieList movie;
  std::ostringstream sout;
  movie.setCharac({"Book Title", "Pages", "Author", "Genre"});
  movie.addMovie({"Harry Potter and the Sorcerer's Stone", "362", "JK Rowling", "Fantasy"});
  movie.addMovie({"Pride and Prejudice", "273", "Jane Austen", "Classic"});
  movie.addMovie({"Animal Farm", "120", "George Orwell", "Classic"});
  movie.setSelection(new OR(new FIND(&movie, "Genre", "Fantasy"), new FIND(&movie, "Pages", "273")));
  movie.printMovies(sout);
  EXPECT_EQ("Harry Potter and the Sorcerer's Stone\nPride and Prejudice\n", sout.str());
}

TEST(MovieListTest, CaseSensitivity){
  MovieList movie;
  std::ostringstream sout;
  movie.setCharac({"Book Title", "Pages", "Author", "Genre"});
  movie.addMovie({"Harry Potter and the Sorcerer's Stone", "362", "JK Rowling", "Fantasy"});
  movie.addMovie({"Pride and Prejudice", "273", "Jane Austen", "Classic"});
  movie.addMovie({"Animal Farm", "120", "George Orwell", "Classic"});
  movie.setSelection(new FIND(&movie, "Genre", "CLAssic"));
  movie.printMovies(sout);
  EXPECT_EQ("", sout.str());
}

TEST(MovieListTest, Substring){
  MovieList movie;
  std::ostringstream sout;
  movie.setCharac({"Book Title", "Pages", "Author", "Genre"});
  movie.addMovie({"Harry Potter and the Sorcerer's Stone", "362", "JK Rowling", "Fantasy"});
  movie.addMovie({"Pride and Prejudice", "273", "Jane Austen", "Classic"});
  movie.addMovie({"Animal Farm", "120", "George Orwell", "Classic"});
  movie.setSelection(new FIND(&movie, "Genre", "ssic"));
  movie.printMovies(sout);
  EXPECT_EQ("Pride and Prejudice\nAnimal Farm\n", sout.str());
}

TEST(MovieListTest, NoInput){
  MovieList movie;
  std::ostringstream sout;
  movie.setCharac({"Book Title", "Pages", "Author", "Genre"});
  movie.addMovie({"Harry Potter and the Sorcerer's Stone", "362", "JK Rowling", "Fantasy"});
  movie.addMovie({"Pride and Prejudice", "273", "Jane Austen", "Classic"});
  movie.addMovie({"Animal Farm", "120", "George Orwell", "Classic"});
  movie.setSelection(new FIND(&movie, "Book Title", ""));
  movie.printMovies(sout);
  EXPECT_EQ("Harry Potter and the Sorcerer's Stone\nPride and Prejudice\nAnimal Farm\n", sout.str());
}

TEST(MovieListTest, WrongFilterInput){
  MovieList movie;
  std::ostringstream sout;
  movie.setCharac({"Book Title", "Pages", "Author", "Genre"});
  movie.addMovie({"Harry Potter and the Sorcerer's Stone", "362", "JK Rowling", "Fantasy"});
  movie.addMovie({"Pride and Prejudice", "273", "Jane Austen", "Classic"});
  movie.addMovie({"Animal Farm", "120", "George Orwell", "Classic"});
  movie.setSelection(new FIND(&movie, "Author", "273"));
  movie.printMovies(sout);
  EXPECT_EQ("", sout.str());
}

TEST(MovieListTest, ComplexSubstringCheck){
  MovieList movie;
  std::ostringstream sout;
  movie.setCharac({"Book Title", "Pages", "Author", "Genre"});
  movie.addMovie({"Harry Potter and the Sorcerer's Stone", "362", "JK Rowling", "Fantasy"});
  movie.addMovie({"Pride and Prejudice", "273", "Jane Austen", "Classic"});
  movie.addMovie({"Animal Farm", "120", "George Orwell", "Classic"});
  movie.setSelection(new AND(new FIND(&movie, "Genre", "tasy"), new FIND(&movie, "Pages", "36")));
  movie.printMovies(sout);
  EXPECT_EQ("Harry Potter and the Sorcerer's Stone\n", sout.str());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
