#include "sameCatUser.cpp"

//This function computes the adjusted cosine similarity between two items
double cosine(int movID1, int movID2)
{
  //num1 and num2 are the movie IDs that wait for computing the similarity
  //transfer the int movieID to strings
  string num1 = inttostr(movID1);
  string num2 = inttostr(movID2);
  if(sameCat(movID1, movID2) == -1)
    return -1;
  vector<string> vecUser;
  vecUser = userRateBoth(movID1, movID2);
  vector<vector<string> > vecR = storefile("ratings.dat", ':', 2);
  vector<vector<int> > vecRint;
  for(int i = 0; i != vecR.size(); i ++){
    vector<int> vr;
    for(int j = 0; j != vecR[i].size(); j ++){
      int temp = strtoint(vecR[i].at(j));
      vr.push_back(temp);
    }
    vecRint.push_back(vr);
  }
    
  double sim=0.0, sim_up=0, sim_d1=0, sim_d2=0;

  //find the average rating for the user
  double avgU[vecUser.size()];
  for(int i = 0; i != vecUser.size(); i++)
    avgU[i] = 0;
  int count;

  for(int i = 0; i != vecUser.size(); i++){
    count = 0;
    for(int j=0; j < vecR.size(); j++){
      if(vecR[j].at(0) == vecUser.at(i)){
        avgU[i] = avgU[i] + vecRint[j].at(2);
        count++;
      }
    }
    avgU[i] = avgU[i] / count;
  }

  for(int i = 0; i < vecUser.size(); i++){
    int value1, value2;
    for(int j = 0; j < vecR.size(); j++){
      if(vecR[j].at(0) == vecUser.at(i) && vecR[j].at(1) == num1)
        value1 = vecRint[j].at(2); 
      else if(vecR[j].at(0) == vecUser.at(i) && vecR[j].at(1) == num2){
        if(vecR[j].at(0) == vecUser.at(i) && vecR[j].at(1) == num2){
          value2=vecRint[j].at(2); 
        }
      }
    }
    sim_up = sim_up + (value1 - avgU[i]) * (value2 - avgU[i]);
    sim_d1 = sim_d1 + (value1 - avgU[i]) * (value1 - avgU[i]);
    sim_d2 = sim_d2 + (value2 - avgU[i]) * (value2 - avgU[i]);
  }
  sim_d1 = sqrt(sim_d1);
  sim_d2 = sqrt(sim_d2);
  sim = sim_up / (sim_d1 * sim_d2);
  cout<<"The adjusted cosine similarity between these two movies is: "<<sim<<endl;
  return sim;
}

int main()
{
  cosine(6,9);
  return 0;
}