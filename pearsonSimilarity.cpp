#include "sameCatUser.cpp"

//This function computes the pearson similarity between two items
double pearson(int movID1, int movID2)
{
  //num1 and num2 are the movie IDs that wait for computing the similarity
  //transfer the int movieID to strings
  string num1 = inttostr(movID1);
  string num2 = inttostr(movID2);

  if(sameCat(movID1, movID2) == -1)
    return -1;
  vector<string> vecUser;
  vecUser = userRateBoth(movID1, movID2);

  double sim=0.0, sim_up=0, sim_d1=0, sim_d2=0;
  double avgR1=0.0, avgR2=0.0;

  int count1=0, count2=0;
  //vecR and vecRint store the data in the file ratings.dat
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
  
  //Find the average ratings for the two movies
  for(vector<string>::size_type i=0; i<vecR.size(); i++)
  {
    if(vecR[i].at(1) == num1){
      avgR1 += vecRint[i].at(2);
      count1 ++;
    }
    else if(vecR[i].at(1) == num2){
      avgR2 += vecRint[i].at(2);
      count2 ++;
    }
  }
  avgR1 = avgR1/count1;
  avgR2 = avgR2/count2;

  for(vector<string>::size_type i=0; i != vecUser.size(); i++){
    int value1, value2;
    for(vector<string>::size_type j=0; j != vecR.size(); j++){
      if(vecR[j].at(0) == vecUser.at(i) && vecR[j].at(1) == num1){
        value1=vecRint[j].at(2); 
      }
      else if(vecR[j].at(0) == vecUser.at(i) && vecR[j].at(1) == num2){
        if(vecR[j].at(0) == vecUser.at(i) && vecR[j].at(1) == num2){
          value2 = vecRint[j].at(2); 
        }
      }
    }
    sim_up = sim_up + (value1 - avgR1) * (value2 - avgR2);
    sim_d1 = sim_d1 + (value1 - avgR1) * (value1 - avgR1);
    sim_d2 = sim_d2 + (value2 - avgR2) * (value2 - avgR2);
  }
  sim_d1 = sqrt(sim_d1);
  sim_d2 = sqrt(sim_d2);
  sim = sim_up / (sim_d1 * sim_d2);

  cout<<"The Pearson(correlation)-based similarity between "<<num1<<" and "<<num2<<" is: "<<sim<<endl;
  return sim;
}

int main()
{
  pearson(6,9);
  return 0;
}
