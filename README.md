movie_recommendation
====================

In the project, I did item_based collaborative filtering and recommendation based on the 1m netflix dataset

1 Finding the recommended movies for each user.
This involves finding the movies in the movie universe that the user hasn’t seen. 
Find the movies rated by each cluster. And find the movies had been rated by each user. Then recommend movies that has been 
rated by the cluster but not by the user. recommendation.cpp realizes this.

2 Item based collaborative filtering.
 a. Classify the movies based on different genres.
 b. Find the movies rated by each user.
 c. Given two movie ID, compute the pearson/cosine similarity if they belong to the same genre.

