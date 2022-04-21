#include "movieList.hpp"
#include "filter.hpp"
#include <iostream>

int main(){

	MovieList movie;
	movie.setCharac({"Title", "Genre", "Length", "Release", "Rating"});
	movie.addMovie({"Titanic", "Romance", "C", "A", "C"});
	movie.addMovie({"Avengers: Endgame", "Action", "C", "C", "C"});
	movie.addMovie({"Spiderman: Far from Home", "Action", "B", "C", "C"});
	movie.addMovie({"Tangled", "Adventure", "A", "B", "C"});
	movie.addMovie({"City Lights", "Romance", "A", "B", "C"});
	movie.addMovie({"Diehard", "Action", "B", "A", "C"});
	movie.addMovie({"The Great Gatsby", "Romance", "B", "C", "A"});
	movie.addMovie({"Forrest Gump", "Comedy", "B", "A", "B" });
	movie.addMovie({"Back to the Future", "Scifi", "A", "A", "C"});
	movie.addMovie({"Spiderman 3", "Action", "Superhero", "B", "B", "A"});
	movie.addMovie({"A Quiet Place", "Thriller", "A", "C", "C"});
	movie.addMovie({"IT", "Horror", "B", "C", "C"});
	movie.addMovie({"The Conjuring", "Horror", "A", "C", "C"});
	movie.addMovie({"West Side Story", "Musical", "B", "A", "C"});
	movie.addMovie({"Avatar", "Scifi", "B", "B", "B"});
	movie.addMovie({"The Notebook", "Romance", "B", "B", "A"});
	movie.addMovie({"Twilight", "Romance", "B", "B", "A"});
	movie.addMovie({"Harry Potter and the Sorcerer’s Stone", "Fantasy", "B", "B", "B"});
	movie.addMovie({"The Greatest Showman", "Musical", "A", "C", "A"});
	movie.addMovie({"Mission: Impossible", "Action", "A", "A", "A"});
	movie.addMovie({"Indiana Jones and the Crystal Skull", "Adventure", "B", "B", "B"});

	std::string title;
	std::string genre;
	std::string length;
	std::string release;
	std::string rating;
	std::string s;
	std::string s2;
	int input = 0;

	while (input != 1 || input != 2 || input != 3 || input != 4) 
	{ 
		std::cout << "Hello! Welcome to Netflix 2.0, where we recommend you movies based on the following critera: Title, genre, length, release year, and movie rating!" << "\n" << std::endl;
		std::cout << "What feature would you like to filter your movies with? " << std::endl;
		std::cout << "1. Genre" << std::endl;
		std::cout << "2. Movie length" << std::endl;
		std::cout << "3. Release year" << std::endl;
		std::cout << "4. Rating" << std::endl;
		std::cin >> input;
		if (input == 1) 
		{
			std::cout << "Choose a genre: Romance, Action, Adventure, Comedy, Fantasy, Scifi, Thriller, Horror, Musical: ";
			std::cin >> genre;
			movie.setSelection(new FIND(&movie, "Genre", genre));
			s = "Genre";
			s2 = genre;
			std::cout << std::endl;
		}
		else if (input == 2) 
		{
			std::cout << "Choose a movie runtime range:" << std::endl;
			std::cout << "A. Less than 120 minutes" <<std::endl;
			std::cout << "B. Between 120 and 180 minutes" << std::endl;
			std::cout << "C. Between 180 and 240 minutes" << std::endl;
			std::cin >> length;
			movie.setSelection(new FIND(&movie, "Length", length));
			s = "Length";
			s2 = length;
			std::cout << std::endl;
		}
		else if (input == 3)
		{
			std::cout << "Choose a release year range:" << std::endl;
			std::cout << "A. Movies released before 2000" << std::endl;
			std::cout << "B. Movies released between 2001 and 2010" << std::endl;
			std::cout << "C. Movies released after 2010" << std::endl;
			std::cin >> release;
			movie.setSelection(new FIND(&movie, "Release", length));
			s = "Release";
			s2 = release;
			std::cout << std::endl;
		}
		else if (input == 4)
		{
			std::cout << "Choose a movie rating range:" << std::endl;
			std::cout << "A. Movies less than 70% rating" << std::endl;
			std::cout << "B. Movies with rating between 71 and 85%" << std::endl;
			std::cout << "C. Movies with rating above 85%" << std::endl;
			std::cin >> rating;
			movie.setSelection(new FIND(&movie, "Rating", rating));
			s = "Rating";
			s2 = rating;
			std::cout << std::endl;
		}
		else
		{
			std::cout << "Invalid input. Try again." << std::endl;
		}
	break;
	}

	int input2 = 0;
	int input3 = 10;
	std::string genre2;
        std::string length2;
        std::string release2;
        std::string rating2;

	std::cout << "Would you like to select another filter?" << std::endl;
	std::cout << "1. First filter AND second filter" << std::endl;
        std::cout << "2. First filter OR second filter" << std::endl;
        std::cout << "3. First filter and NOT second filter" << std::endl;
        std::cout << "4. None" << std::endl;
        std::cin >> input2;
	
	if (input2 == 4)
	{
        	movie.printMovies(std::cout);
		std::cout << std::endl;
        	return 0;
	}
	else	
	{
		if (input2 == 1) 
		{
			while (input3 != 1 || input3 != 2 || input3 != 3 || input3 != 4)
			{
				std::cout << "What feature would you like to filter your movies with? " << std::endl;	
				std::cout << "1. Genre" << std::endl;  
				std::cout << "2. Movie length" << std::endl;
        		        std::cout << "3. Release year" << std::endl;
                		std::cout << "4. Rating" << std::endl;
		                std::cin >> input3;
        		        if (input3 == 1){
                        		std::cout << "Choose a genre: Romance, Action, Adventure, Comedy, Fantasy, Scifi, Thriller, Horror, Musical: ";
	                        	std::cin >> genre2;
					movie.setSelection(new AND(new FIND(&movie, "Genre", genre2), new FIND(&movie, s, s2)));
	        	                std::cout << std::endl;
        	     		}
	        	        else if (input3 == 2) {
                	        	std::cout << "Choose a movie runtime range:" << std::endl;
	                        	std::cout << "A. Less than 120 minutes" <<std::endl;
		                        std::cout << "B. Between 120 and 180 minutes" << std::endl;
        		                std::cout << "C. Between 180 and 240 minutes" << std::endl;	
                		        std::cin >> length2;
			                movie.setSelection(new AND(new FIND(&movie, "Length", length2), new FIND(&movie, s, s2)));
                        		std::cout << std::endl;
		                }
		                else if (input3 == 3)
        		        {
                		        std::cout << "Choose a release year range:" << std::endl;
                        		std::cout << "A. Movies released before 2000" << std::endl;
		                        std::cout << "B. Movies released between 2001 and 2010" << std::endl;
        		                std::cout << "C. Movies released after 2010" << std::endl;
                		        std::cin >> release2;
				        movie.setSelection(new AND(new FIND(&movie, "Release", release2), new FIND(&movie, s, s2)));
                        		std::cout << std::endl;
	                	}
		                else if (input3 == 4)
        		        {
                		        std::cout << "Choose a movie rating range:" << std::endl;
                        		std::cout << "A. Movies less than 70% rating" << std::endl;
	 	                        std::cout << "B. Movies with rating between 71 and 85%" << std::endl;
        		                std::cout << "C. Movies with rating above 85%" << std::endl;
                		        std::cin >> rating2;
				        movie.setSelection(new AND(new FIND(&movie, "Rating", rating2), new FIND(&movie, s, s2)));
                        		std::cout << std::endl;
                		}
		                else
				{
				std::cout << "Invalid input. Try again." << std::endl;
				}
				break;
			}
		}
		else if (input2 == 2) 
		{
			while (input3 != 1 || input3 != 2 || input3 != 3 || input3 != 4)
			{
				std::cout << "What feature would you like to filter your movies with? " << std::endl;
	              	        std::cout << "1. Genre" << std::endl;
        	                std::cout << "2. Movie length" << std::endl;
	        	        std::cout << "3. Release year" << std::endl;
        	        	std::cout << "4. Rating" << std::endl;
	                	std::cin >> input3;
                        	if (input3 == 1)
                                {
	                                std::cout << "Choose a genre: Romance, Action, Adventure, Comedy, Fantasy, Scifi, Thriller, Horror, Musical: ";
        	                        std::cin >> genre2;
		                        movie.setSelection(new OR(new FIND(&movie, "Genre", genre2), new FIND(&movie, s, s2)));
                	                std::cout << std::endl;
                       	        }
                               	else if (input3 == 2)
	                        {
      	                                std::cout << "Choose a movie runtime range:" << std::endl;
               	                        std::cout << "A. Less than 120 minutes" <<std::endl;
                       	                std::cout << "B. Between 120 and 180 minutes" << std::endl;
                               	        std::cout << "C. Between 180 and 240 minutes" << std::endl;
                                       	std::cin >> length2;
	                                movie.setSelection(new OR(new FIND(&movie, "Length", length2), new FIND(&movie, s, s2)));
                                        std::cout << std::endl;
       	                        }
               	                else if (input3 == 3)
                       	        {
                               	        std::cout << "Choose a release year range:" << std::endl;
                                       	std::cout << "A. Movies released before 2000" << std::endl;
                                        std::cout << "B. Movies released between 2001 and 2010" << std::endl;
       	                                std::cout << "C. Movies released after 2010" << std::endl;
               	                        std::cin >> release2;
		                        movie.setSelection(new OR(new FIND(&movie, "Release", release2), new FIND(&movie, s, s2)));
                       	                std::cout << std::endl;
                               	}
                                else if (input3 == 4)
       	                        {
               	                        std::cout << "Choose a movie rating range:" << std::endl;
                       	                std::cout << "A. Movies less than 70% rating" << std::endl;
                                        std::cout << "B. Movies with rating between 71 and 85%" << std::endl;
       	                                std::cout << "C. Movies with rating above 85%" << std::endl;
               	                        std::cin >> rating2;
				        movie.setSelection(new OR(new FIND(&movie, "Rating", rating2), new FIND(&movie, s, s2)));
                       	                std::cout << std::endl;
                               	}
                                else
       	                        {
               	                std::cout << "Invalid input. Try again." << std::endl;
                       	        }
				break;
			}
		}
		else if (input2 == 3) 
		{
			 while (input3 != 1 || input3 != 2 || input3 != 3 || input3 != 4)
         	         {
               	                std::cout << "What feature would you like to filter your movies with? " << std::endl;
                       	        std::cout << "1. Genre" << std::endl;
                               	std::cout << "2. Movie length" << std::endl;
                                std::cout << "3. Release year" << std::endl;
       	                        std::cout << "4. Rating" << std::endl;
               	                std::cin >> input3;
                       	        if (input3 == 1)
                               	{
                                        std::cout << "Choose a genre: Romance, Action, Adventure, Comedy, Fantasy, Scifi, Thriller, Horror, Musical: ";
       	                                std::cin >> genre2;
		                        movie.setSelection(new AND(new FIND(&movie, s, s2), new NOT(new FIND(&movie, "Genre", genre2))));
               	                        std::cout << std::endl;
                       	        }
                               	else if (input3 == 2)
                                {
       	                                std::cout << "Choose a movie runtime range:" << std::endl;
               	                        std::cout << "A. Less than 120 minutes" <<std::endl;
                       	                std::cout << "B. Between 120 and 180 minutes" << std::endl;
                               	        std::cout << "C. Between 180 and 240 minutes" << std::endl;
                                       	std::cin >> length2;
				        movie.setSelection(new AND(new FIND(&movie, s, s2), new NOT(new FIND(&movie, "Length", length2))));
                                        std::cout << std::endl;
       	                        }
               	                else if (input3 == 3)
                       	        {
                               	        std::cout << "Choose a release year range:" << std::endl;
                                       	std::cout << "A. Movies released before 2000" << std::endl;
                                        std::cout << "B. Movies released between 2001 and 2010" << std::endl;
       	                                std::cout << "C. Movies released after 2010" << std::endl;
               	                        std::cin >> release2;
				        movie.setSelection(new AND(new FIND(&movie, s, s2), new NOT(new FIND(&movie, "Release", release2))));
                       	                std::cout << std::endl;
                               	}
                                else if (input3 == 4)
       	                        {
               	                        std::cout << "Choose a movie rating range:" << std::endl;
                       	                std::cout << "A. Movies less than 70% rating" << std::endl;
                               	        std::cout << "B. Movies with rating between 71 and 85%" << std::endl;
                                       	std::cout << "C. Movies with rating above 85%" << std::endl;
                                        std::cin >> rating2;
				        movie.setSelection(new AND(new FIND(&movie, s, s2), new NOT(new FIND(&movie, "Rating", rating2))));
       	                                std::cout << std::endl;
               	                }
                       	        else
                               	{
	                                std::cout << "Invalid input. Try again." << std::endl;
               	                }
				break;
			}
			
		}
		movie.printMovies(std::cout);
		std::cout << std::endl;
	}
	return 0;
}

