
#include <iostream>
#include <fstream>
#include<string>
#include <vector>

//using namespace std; //I am aware I souldn't do this but untill I know more of what I need this will stay here.
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::fstream;
using std::vector;

class DietPlan
{
public:
	//Default Constructor
	DietPlan();
	//Copy constructor
	//DietPlan(DietPlan &copy); //Shallow Copy
	//Getters
	int getCalories();
	string getDate();
	string getPlanName();
	//Setters
	void setCalories(int newGoalCalories);
	void setName(string newPlanName); 
	void setDate(string newDate);
	//Edit
	void editGoals();
	//Destructor
	//~DietPlan(); //Im not really allocating memory sooo yeah
private:
	int mGoalCalories;
	string mDate;
	string mPlanName;
};

class ExercisePlan
{
public:
	//Constructor
	ExercisePlan ();
	//Copy Constructor
	//ExercisePlan(ExercisePlan &copy);
	//Getters
	int getStepGoal();
	string getExercisePlan();
	string getDate();
	//Setters
	void setSteps(int newSetSteps);
	void setExPlan(string newExPlanName);
	void setExDate(string newExDate);
	void editExerPlan();
	//Destructor
	//~ExercisePlan();
private:
	int mSteps;
	string mExercisePlan;
	string mExDate;
};

class FitnessAppWrapper
{
public:
	//Constructors
	FitnessAppWrapper();
	//Copy Constructor
	//FitnessAppWrapper(FitnessAppWrapper &copy);
	//Functions
	void runApp();
	void displayDailyDiePlan(DietPlan plan);
	void displayDailyExPlan(ExercisePlan plan);
	void displayWeakDiePlan(vector <DietPlan> &weeklyPlan);
	void displayWeakExPlan(vector <ExercisePlan> &weeklyPlan);
	int displayMenu();
	int editDiePlan();
	int editExerPlan();
	//Destrctor
	~FitnessAppWrapper();

private:
	void loadDailyDiePlan(fstream &fileStream, DietPlan &plan);
	void loadDailyExPlan(fstream &fileStream, ExercisePlan &plan);
	void loadWeakDiePlan(fstream &fileStream, vector <DietPlan> &weeklyPlan);
	void loadWeakExPlan(fstream &fileStream, vector <ExercisePlan> &weeklyPlan);
	void storeDailyDiePlan(fstream &fileStream, DietPlan &plan);
	void storeDailyExPlan(fstream &fileStream, ExercisePlan &plan);
	void storeWeakDiePlan(fstream &fileStream, vector <DietPlan> &weeklyPlan);
	void storeWeakExPlan(fstream &fileStream, vector <ExercisePlan> &weeklyPlan);
	//Vectors
	vector<DietPlan> vDietPlan;
	vector<ExercisePlan> vExerPlan;
	//Member variables
	fstream mDietPlanText;
	fstream mExerciseText; 
};

//overloading
fstream & operator>> (fstream &lhs, DietPlan &rhs);
fstream & operator >> (fstream &lhs, ExercisePlan &rhs);
fstream & operator << (fstream &lhs, DietPlan &rhs);
fstream & operator << (fstream &lhs, ExercisePlan &rhs);
fstream & operator << (fstream &lhs, ExercisePlan &rhs);