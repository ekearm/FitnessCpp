#include "Header.h"
//Constructor
ExercisePlan::ExercisePlan()
{
	this->mExDate = "";
	this->mExercisePlan = "";
	this->mSteps = 0;
}
//Didn't use the copy constructor.
/*ExercisePlan::ExercisePlan(ExercisePlan &copy)
{
	this->mExDate = copy.getDate();
	this->mExercisePlan = copy.getExercisePlan();
	this->mSteps = copy.getStepGoal();
}*/

int ExercisePlan::getStepGoal()
{
	return this->mSteps;
}

string ExercisePlan::getDate()
{
	return  this->mExDate;
}

string ExercisePlan::getExercisePlan()
{
	return this->mExercisePlan;
}

void ExercisePlan::setSteps(int newSetSteps)
{
	mSteps = newSetSteps;
}

void ExercisePlan::setExPlan(string newExPlanName)
{
	mExercisePlan = newExPlanName;
}
void ExercisePlan::setExDate(string newExDate)
{
	mExDate = newExDate;
}

void ExercisePlan::editExerPlan()
{
	int newGetStepsPlan;
	cout << "Enter new goal" << endl;
	cin >> newGetStepsPlan;
	this->setSteps(newGetStepsPlan);
	cout << newGetStepsPlan << endl;
}