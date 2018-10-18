#include <bits/stdc++.h>
using namespace std;
#define DEBUG2(x) do { std::cerr << #x << ": " << x << std::endl; } while (0)


string infile,outfile;
vector<double> points_x;
vector<double> points_y;
vector<double> step_x;
vector<double> step_y;
double typeError;
double k_value;
double numInputPoints;
double steps_used;
double totalError;

void readInputFile()
{
	ifstream infiler;
	infiler.open(infile.c_str());
	infiler>>k_value;
	infiler>>typeError;
	infiler>> numInputPoints;
	points_x.resize(numInputPoints);
	points_y.resize(numInputPoints);
	for(int i=0;i<numInputPoints;i++)
	{
		infiler>>points_x[i]>>points_y[i];
	}
	infiler.close();
}

void readOutFile()
{
	ifstream outfiler;
	outfiler.open(outfile.c_str());
	outfiler>>steps_used;
	step_x.resize(steps_used);
	step_y.resize(steps_used);
	for(int i=0;i<steps_used;i++)
	{
		outfiler>>step_x[i]>>step_y[i];
	}
	outfiler.close();
}

bool someErrorOccured = false;

void calcError()
{
	// check that steps used is in check
	if(steps_used>k_value)
	{
		cout<<"Error: You have used more steps than are expected!"<<endl;
		someErrorOccured= true;
		return;
	}
	// check that steps are sorted
	for(int i=0;i<int(step_x.size())-1;i++)
	{
		if(step_x[i]>=step_x[i+1])
		{
			cout<<"Error: X-coordinates of Steps are strictly increasing!!"<<endl;
			someErrorOccured= true;
			return;
		}
	}
	// check that first step_x is less than or equal to first points_x
	if(step_x[0]>points_x[0])
	{
		someErrorOccured = true;
		cout<<"Error: Your steps starting X-coordinate is greater point[0]'s X-coordinate; Step is not defined"<<endl;
		return;
	}

	if(typeError==0)
	{
		int step_index=0;
		totalError=0;
		for(int i=0;i<numInputPoints;i++)
		{
			if(step_index==(steps_used-1))
			{
				totalError+=(pow((step_y[step_index]-points_y[i]),2)/numInputPoints);
			}
			else
			{
				if(step_index<(steps_used-2))
				{
					if(points_x[i]>=step_x[step_index+2])
					{
						someErrorOccured = true;
						cout<<"Error: There's some redundant level in your step-function!";
						cout<<"No use of level :"<< step_y[step_index+1]<<endl;
						return;
					}
				}

				if(points_x[i]>=step_x[step_index] && points_x[i]<step_x[step_index+1])
				{
					//x-coordinate is totally in the middle
					totalError+=(pow((step_y[step_index]-points_y[i]),2)/numInputPoints);
				}
				else if(points_x[i]>=step_x[step_index+1])
				{
					//equal to next x-step
					step_index+=1;
					totalError+=(pow((step_y[step_index]-points_y[i]),2)/numInputPoints);
				}
				else
				{
					someErrorOccured = true;
					cout<<"Error: Theres's some error in the input points, X-coordinates of inputs are not sorted!"<<endl;
					return;
				}
			}
		}
	}
	else
	{
		int step_index=0;
		totalError=double(0.0);
		for(int i=0;i<numInputPoints;i++)
		{
			if(step_index==(steps_used-1))
			{
				totalError= max(fabs((step_y[step_index]-points_y[i])),totalError);
			}
			else
			{
				if(step_index<(steps_used-2))
				{
					if(points_x[i]>=step_x[step_index+2])
					{
						someErrorOccured = true;
						cout<<"Error: There's some redundant level in your step-function!";
						cout<<"No use of level :"<< step_y[step_index+1]<<endl;
						return;
					}
				}
				if(points_x[i]>=step_x[step_index] && points_x[i]<step_x[step_index+1])
				{
					//x-coordinate is totally in the middle
					totalError= max(fabs((step_y[step_index]-points_y[i])),totalError);
				}
				else if(points_x[i]>=step_x[step_index+1])
				{
					//equal to next x-step
					step_index+=1;
					totalError= max(fabs((step_y[step_index]-points_y[i])),totalError);
				}
				else
				{
					someErrorOccured = true;
					cout<<"Error: Theres's some error in the input points, X-coordinates of inputs are not sorted!"<<endl;
					return;
				}
			}
		}
	}
}

int main(int argc, char* argv[])
{
	string arg1(argv[1]);
    string arg2(argv[2]);
    infile = arg1;
    outfile= arg2;
    readInputFile();
    readOutFile();
    calcError();
    if(someErrorOccured)
    {
    	return 0;
    }
    else
    {
    	if(typeError==0)
    	{
    		cout<< "Mean Squared Error: "<< totalError << endl;
    	}
    	else
    	{
    		cout<< "Max Error: "<< totalError << endl;
    	}
    }
    return 0;
}