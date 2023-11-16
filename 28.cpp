#include<cstring>
using std::string;
struct Subject{
	char* subject_name;
};

class Department{
//needs to store subjects of a department
	int dept_num;
protected:
	string dept_name;
	int num_of_subjs;
	Subject* subjs_arr;

public:
	Department(const int &dept_num, const string &dept_name, const int &num_of_subjs);
	//will need to allocate char** on the fly in constuctor defn
	bool has_dept_number(const int &dept_num){return this->dept_num == dept_num;}
		 
};
//save objects of Department in an array
//student gets department allocated by storing pointer to this object

class Student{
//enrolled student
protected:
	string name;
	int roll_num;
	Department* student_department;
public:
	Student(const string &name, const int &roll_num,const int &dept_num);
		
};
class GradeCard:protected Student, private Department{
	private:
	Student* gradecard_student;
	int semester_num;
	public:
	GradeCard(const int &roll_num,const int &semester);//will ask for subject 
	void show()
};

