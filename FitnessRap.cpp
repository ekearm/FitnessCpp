#include "Header.h"

FitnessAppWrapper:: FitnessAppWrapper()
{
	mDietPlanText.open("DietPlans.txt");
	mExerciseText.open("ExercisePlan.txt");
}
//Didn't really need this
/*FitnessAppWrapper::FitnessAppWrapper (FitnessAppWrapper &copy)
{
	while ()
}*/

int FitnessAppWrapper::displayMenu()
{
	int option = 0;

	//do
	//{
		cout << "1. Load weekly diet plan from file." << endl;
		cout << "2. Load weekly exercise plan from file." << endl;
		cout << "3.Store weekly diet plan to file." << endl;
		cout << "4. Store weekly exercise plan to file." << endl;
		cout << "5. Display weekly diet plan to screen." << endl;
		cout << "6. Display weekly exercise plan to screen." << endl;
		cout << "7. Edit daily diet plan." << endl;
		cout << "8. Edit daily exercise plan" << endl;
		cout << "9. Exit" << endl;
		cin >> option;
	//} while (option  9 && option > 1);

	return option;
}


//txt open and at beginning of file
void FitnessAppWrapper::loadDailyDiePlan(fstream &fileStream, DietPlan &plan)
{
	fileStream >> plan; 

}
void FitnessAppWrapper::loadDailyExPlan(fstream &fileStream, ExercisePlan &plan)
{
	fileStream >> plan;

}
void FitnessAppWrapper::loadWeakDiePlan(fstream &fileStream, vector <DietPlan> &weeklyPlan)
{
	for (int i = 0; i < 7; i++)
	{
		DietPlan *tmp = new DietPlan(); 
		loadDailyDiePlan(mDietPlanText, *tmp);
		weeklyPlan.push_back(*tmp);
	}
}
void FitnessAppWrapper::loadWeakExPlan(fstream &fileStream, vector <ExercisePlan> &weeklyPlan)
{
	for (int i = 0; i < 7; i++)
	{
		ExercisePlan *tmp = new ExercisePlan();
		loadDailyExPlan(mExerciseText, *tmp);
		weeklyPlan.push_back(*tmp);
	}

}
void FitnessAppWrapper::storeDailyDiePlan(fstream &fileStream, DietPlan &plan)
{
	fileStream << plan; 
}
void FitnessAppWrapper::storeDailyExPlan(fstream &fileStream, ExercisePlan &plan)
{
	fileStream << plan;
}
void FitnessAppWrapper::storeWeakDiePlan(fstream &fileStream, vector <DietPlan> &weeklyPlan)
{
	for (int i = 0; i < weeklyPlan.size() ; i++)
	{
		storeDailyDiePlan(mDietPlanText, weeklyPlan[i]);
	}
}
void FitnessAppWrapper::storeWeakExPlan(fstream &fileStream, vector <ExercisePlan> &weeklyPlan)
{
	for (int i = 0; i < weeklyPlan.size(); i++)
	{
		storeDailyExPlan(mExerciseText, weeklyPlan[i]);
	}
}
void FitnessAppWrapper::runApp()
{
	int option = -1;
	while (option != 9)
	{
		option = displayMenu();
		switch (option)
		{
		case 1:
			this->loadWeakDiePlan(mDietPlanText, vDietPlan);
			break;
		case 2:
			this->loadWeakExPlan(mExerciseText, vExerPlan);
			break;
		case 3:
			this->storeWeakDiePlan(mDietPlanText, vDietPlan);
			break;
		case 4:
			this->storeWeakExPlan(mExerciseText, vExerPlan);
			break;
		case 5:
			this->displayWeakDiePlan(vDietPlan);
			break;
		case 6:
			this->displayWeakExPlan(vExerPlan);
			break;
		case 7:
			this->vDietPlan[editDiePlan()].editGoals();
			break;
		case 8:
			this->vExerPlan[editExerPlan()].editExerPlan();
			break;
		case 9:
			break;
		}
	}
}

int FitnessAppWrapper::editDiePlan()
{
	int choices = 0;

	cout << "Which Diet Plan Would you like to edit? " << endl;
	cin >> choices; 
	return choices; 
}
int FitnessAppWrapper::editExerPlan()
{
	int choices = 0; 

	cout << "Which Exercise Plan Would you like to edit? " << endl;
	cin >> choices; 
	return choices; 
}

void FitnessAppWrapper::displayDailyDiePlan(DietPlan plan)
{
	cout << plan.getPlanName() << endl;
	cout << plan.getCalories() << endl;
	cout << plan.getDate() << endl;
}
void FitnessAppWrapper::displayDailyExPlan(ExercisePlan plan)
{
	cout << plan.getExercisePlan() << endl;
	cout << plan.getStepGoal() << endl;
	cout << plan.getDate() << endl;
}
void FitnessAppWrapper::displayWeakDiePlan(vector <DietPlan> &weeklyPlan)
{
	for (int i = 0; i < weeklyPlan.size(); i++)
	{
		displayDailyDiePlan(weeklyPlan[i]);
	}
}
void FitnessAppWrapper::displayWeakExPlan(vector <ExercisePlan> &weeklyPlan)
{
	for (int i = 0; i < weeklyPlan.size(); i++)
	{
		displayDailyExPlan(weeklyPlan[i]);
	}
}

FitnessAppWrapper::~FitnessAppWrapper()
{
	storeWeakDiePlan(mDietPlanText,vDietPlan);
	storeWeakExPlan(mExerciseText,vExerPlan);
	mDietPlanText.close();
	mExerciseText.close();
	for (int i = 0; i < vDietPlan.size(); i++)
	{
		free(&vDietPlan[i]);
	}
	for (int i = 0; i < vExerPlan.size(); i++)
	{
		free(&vExerPlan[i]);
	}

}

fstream & operator >> (fstream &lhs, DietPlan &rhs)
{
	char planName[30];
	lhs.getline(planName, 30);
	rhs.setName(planName);
	char kCalGoal [10];
	lhs.getline(kCalGoal,10);
	rhs.setCalories(atoi(kCalGoal));
	char date [15]; 
	lhs.getline(date, 15);
	rhs.setDate(date);
	char blankLine [2];
	lhs.getline(blankLine, 2);

	return lhs; 
}
fstream & operator >> (fstream &lhs, ExercisePlan &rhs)
{
	char planName[30];
	lhs.getline(planName, 30);
	rhs.setExPlan(planName);
	char steps[15];
	lhs.getline(steps,15);
	rhs.setSteps(atoi(steps));
	char date[15];
	lhs.getline(date, 15);
	rhs.setExDate(date);
	char blankLine[2];
	lhs.getline(blankLine, 2);

	return lhs;
}

fstream & operator << (fstream &lhs, DietPlan &rhs)
{
	lhs << rhs.getPlanName() << endl;
	lhs << rhs.getCalories() << endl;
	lhs << rhs.getDate() << endl;
	lhs << endl;

	return lhs;
}

fstream & operator << (fstream &lhs, ExercisePlan &rhs)
{
	lhs << rhs.getExercisePlan() << endl;
	lhs << rhs.getStepGoal() << endl;
	lhs << rhs.getDate() << endl;
	lhs << endl;

	return lhs; 
}