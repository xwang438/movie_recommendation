#include "clusterUser.cpp"

// Using Declarations
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;

//These methods are in clusterUser.cpp
//This method sorts the cluster_with_userID based on the cluster ID.
void cluster_with_user::sort_cluster()
{
    vector<vector<string> >vecCluster = storefile("cluster_with_userID.txt",'\t', 1);

    for(int i=0; i<countCluster; i++){
        for(int j=0; j<vecCluster.size(); j++){
            string temp = vecCluster[j].at(1);
            string num = inttostr(i+1);
            if(temp == num){
                vector<string> sc;
                sc.push_back(num);
                sc.push_back(vecCluster[j].at(0));
                sortCluster.push_back(sc);
            }
        }
    }  
}

//This method produces a new file which contains the user ID and their corresponding rated movies based on ratings.dat
void cluster_with_user::userRated()
{
  vector<vector<string> > vecR = storefile("ratings.dat", ':', 2);
  for(int i=0; i!= userNo; i++){
    string userID = inttostr(i+1);
    vector<string> vrg;
    vrg.push_back(userID);
    for(int j=0; j!= vecR.size(); j++){
      if(userID == vecR[j].at(0))
        vrg.push_back(vecR[j].at(1));
    }
    vecRating.push_back(vrg);
  }
}

//This method produces a new file which contains the cluster ID and their corresponding rated movies based on ratings.dat
void cluster_with_user::clusterRating()
{
  // For each cluster in the matrix find the total movies
  for(int i=0; i<countCluster; i++)
  {
    vector<string> tm;
    string num = inttostr(i+1);
    tm.push_back(num);
    for(int j = 0; j < sortCluster.size(); j ++){
      if(sortCluster[j].at(0) == num){
        for(int k = 0; k < vecRating.size(); k ++)
          if(vecRating[k].at(0) == sortCluster[j].at(1)){
            for(int l = 1; l != vecRating[k].size(); l ++)
              tm.push_back(vecRating[k].at(l));
          }
      }
    }
    totalMovie.push_back(tm);
  }
  for(int i = 0; i != totalMovie.size(); i++){
    sort(totalMovie[i].begin()+1, totalMovie[i].end());
    totalMovie[i].erase(std::unique(totalMovie[i].begin()+1, totalMovie[i].end()), totalMovie[i].end());
  }
}

//This method produces a new file which contains the movie type name and the corresponding movies
void cluster_with_user::movie_type()
{
  vector<vector<string> >vecMovie = storefile("movies.dat", ':', 2);
  vector<vector<string> >vectype;  //vectype stores the types for each movie
  for(int i = 0; i != vecMovie.size(); i++){
    string temp = vecMovie[i].at(2);
    int pos1 = 0, pos2 = pos1 + 1;
    vector<string> vt;
    for(int j = 0; j != temp.length(); j++){
      if(temp.at(j) == '|'){
          pos2 = j;
          vt.push_back(temp.substr(pos1,pos2-pos1));
          pos1=pos2+1;
      }
    }
    vt.push_back(temp.substr(pos1));
    vectype.push_back(vt);    
  }
  vector<string> type1, type2, type3, type4, type5, type6, type7, type8, type9, type10, type11, type12, type13, type14, type15, type16, type17, type18;
  type1.push_back("Action");
  genre.push_back(type1);
  type2.push_back("Adventure");
  genre.push_back(type2);
  type3.push_back("Animation");
  genre.push_back(type3);
  type4.push_back("Children's");
  genre.push_back(type4);
  type5.push_back("Comedy");
  genre.push_back(type5);
  type6.push_back("Crime");
  genre.push_back(type6);
  type7.push_back("Documentary");
  genre.push_back(type7);
  type8.push_back("Drama");
  genre.push_back(type8);
  type9.push_back("Fantasy");
  genre.push_back(type9);
  type10.push_back("Film-Noir");
  genre.push_back(type10);
  type11.push_back("Horror");
  genre.push_back(type11);
  type12.push_back("Musical");
  genre.push_back(type12);
  type13.push_back("Mystery");
  genre.push_back(type13);
  type14.push_back("Romance");
  genre.push_back(type14);
  type15.push_back("Sci-Fi");
  genre.push_back(type15);
  type16.push_back("Thriller");
  genre.push_back(type16);
  type17.push_back("War");
  genre.push_back(type17);
  type18.push_back("Western");
  genre.push_back(type18);
    
  for(vector<string>::size_type ii=0; ii<genre.size(); ii++){
    for(vector<string>::size_type i=0; i<vectype.size(); i++)
      for(vector<string>::size_type j=0; j<vectype[i].size(); j++)
        if(vectype[i].at(j) == genre[ii].at(0))
          genre[ii].push_back(vecMovie[i].at(0));
  }
}