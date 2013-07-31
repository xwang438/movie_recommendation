#include "clusterUserMethods.cpp"

// Using Declarations
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;

//This method provides the recommended movies for each user.
int main()
{
    ofstream outfile;
    outfile.open("recommendation.txt");
    cluster_with_user cu;
    cu.sort_cluster();
    cout<<"Finished sort_cluster!"<<endl;
    cu.userRated();
    cout<<"Finished userRated!"<<endl;
    cu.clusterRating();
    cout<<"Finished clusterRating!"<<endl;

    //recom are the recommended movies for each user
    vector<vector<string> > recommendation;
    int n=0;
    for(int i = 0; i != cu.vecRating.size(); i++)
    {
      vector<string> rn;
      string num = inttostr(i+1);
      int mark;
      string cluster;
      rn.push_back(cu.vecRating[i].at(0));
      for(int j = 0; j != cu.sortCluster.size(); j++){
        if(cu.sortCluster[j].at(1) == cu.vecRating[i].at(0))
          cluster = cu.sortCluster[j].at(0);
      }
      for(int jj = 0; jj != cu.totalMovie.size(); jj++){
        if(cu.totalMovie[jj].at(0) == cluster){
          for(int k = 2; k != cu.totalMovie[jj].size(); k++){
            mark = 0;
            for(int l = 1; l != cu.vecRating[i].size(); l++){
              if(cu.totalMovie[jj].at(k) == cu.vecRating[i].at(l))
                mark++;
            }
            if(mark == 0)
              rn.push_back(cu.totalMovie[jj].at(k));
          }
        }
      }
      recommendation.push_back(rn);
      cout<<"Finished "<<i<<" th user's recommendation!"<<endl;
    }          
    for(int i = 0; i < recommendation.size(); i++){
      for(int j = 0; j < recommendation[i].size(); j++){
        outfile<<recommendation[i].at(j)<<"\t";
      }
      outfile<<endl;
    }
    outfile.close();
    return 0;
}