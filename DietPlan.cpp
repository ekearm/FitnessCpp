#include "Header.h"
//Diet Plan funtions and fun stuff
DietPlan::DietPlan()
{
	this->mDate = "";
	this->mPlanName = "" ; 
	this->mGoalCalories= 0;
}

/*DietPlan::DietPlan(DietPlan &copy)
{
	this->mDate = copy.getDate();
	this->mPlanName = copy.getPlanName(); 
	this->mGoalCalories = copy.getCalories();
}*/

string DietPlan::getDate()
{
	return  this->mDate;
}

string DietPlan::getPlanName()
{
	return this->mPlanName; 
}

int DietPlan::getCalories()
{
	return this->mGoalCalories;
}

void DietPlan::setName(string newPlanName)
{
	 mPlanName = newPlanName; 
}
//Precondiotn userinput must ba anb integer.
 void DietPlan:: editGoals()
{
	int newGetCalories;
	cout << "Enter new goal" << endl;
	cin >> newGetCalories;
	this->setCalories(newGetCalories);
	cout << newGetCalories << endl; 
}
 //Sets the calories!
 void DietPlan:: setCalories(int newGoalCalories)
 {
	 mGoalCalories = newGoalCalories; 
 }

 void DietPlan:: setDate(string newDate)
 {
	 mDate = newDate; 
 }
 //This ended up being moved to the fitnessapp wrapper.
//Precondition Stream is open - file is open
//fstream &operator>> (fstream &lhs, DietPlan &rhs)
//{
//	char name[100];
//	lhs.getline(name, 100);
//	rhs.setName(name);
//	//Next lines ar like above but with Date
//	//Same with calories without get line
//	lhs >> mGoalCalories;
//	rhs.setCalories;
//	return rhs; 
//}
