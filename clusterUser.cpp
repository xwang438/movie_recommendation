#include "similarity.h"

// Using Declarations
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;

//This class contains the vectors that will be used for further computation
class cluster_with_user{
   private:
    const int countCluster; 
    const int userNo;

   public:
    cluster_with_user();
    vector<vector<string> >sortCluster; //sortCluster stores the sorted users with their cluster ID
    vector<vector<string> >genre;      //genre stores each type and the movies belong to each type will be appended.
    vector<vector<string> >vecRating;   //vecRating stores the movies that have been rated by each user
    vector<vector<string> >totalMovie;  //totalMovie stores the movies rated by each cluster.
    void sort_cluster();
    void movie_type();
    void userRated();
    void clusterRating();
    virtual ~cluster_with_user();
};

cluster_with_user::cluster_with_user():countCluster(54), userNo(6040){}
cluster_with_user::~cluster_with_user(){}

