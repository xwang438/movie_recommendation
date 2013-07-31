#include "clusterUserMethods.cpp"

// Using Declarations
using std::ifstream;
using std::ofstream;

//this function determines if the two movies are in the same category   
int sameCat(int movID1, int movID2){ 
  cluster_with_user cu;
  cu.sort_cluster();
  cu.movie_type();

  //transfer the int movie ID to strings
  string num1 = inttostr(movID1);
  string num2 = inttostr(movID2);
  
  //determine if the two movies are in the same category
  vector<string> vecCat;
  for(vector<string>:: size_type m=0; m<cu.genre.size(); m++){
    int markType = 0;
    for(string::size_type mm=0; mm<cu.genre[m].size(); mm++){
      if(cu.genre[m].at(mm) == num1)
        markType++;
      if(cu.genre[m].at(mm) == num2)
        markType++;
    }
    if(markType >= 2){     
      vecCat.push_back(cu.genre[m].at(0));
    }
  }
  if(vecCat.size()==0)
  {
    cout<<"The two movies are not in the same catalog!"<<endl;
    return -1;
  }

  cout<<"The catalog the movies are in: ";
  for(vector<string>::size_type m=0; m<vecCat.size(); m++)
    cout<<vecCat.at(m)<<"\t";

  return 0;
}

//This function finds the users that rated both of the movies, 
//vecUser stores the users who have rated both of the movies
vector<string> userRateBoth(int movID1, int movID2){
  cluster_with_user cu;
  cu.sort_cluster();
  cu.movie_type();
  cu.userRated();
      
  //transfer the int movie ID to strings
  string num1 = inttostr(movID1);
  string num2 = inttostr(movID2);

  //vecUser is the vector of the users who have rated both of the movies
  vector<string> vecUser;
  for(vector<string>:: size_type m=0; m != cu.vecRating.size(); m++){
    int markUser=0;
    for(string::size_type mm=1; mm != cu.vecRating[m].size(); mm++){
      if(cu.vecRating[m].at(mm) == num1)
        markUser++;
      if(cu.vecRating[m].at(mm) == num2)
        markUser++;
    }
    if(markUser >= 2){
      vecUser.push_back(cu.vecRating[m].at(0));
    }
  }  
  cout<<"The number of users who have rated both of the movies: "<<vecUser.size()<<endl;
  return vecUser;
}
