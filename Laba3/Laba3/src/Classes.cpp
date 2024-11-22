#include "Classes.h"

// Реализация класса "Человек"
Human::Human() 
{
    name = "Undefined name";
    surname = "Undefined surname";
    patronomic = "Undefined patronomic";
    birth_year = "Undefined birth year";
}

Human::Human(
    const std::string& name,
    const std::string& surname,
    const std::string& patronomic,
    const std::string& birth_year) 
{
    this->name = name;
    this->surname = surname;
    this->patronomic = patronomic;
    this->birth_year = birth_year;
}


// Реализация класса "Преподаватель университета"
TeacherUniversity::TeacherUniversity()
{
    job_title = "Undefined job title";
    academic_degree = "Undefined academic degree";
    speciality = "Undefiend speciality";
    science_works.clear();
}

TeacherUniversity::TeacherUniversity(
    const std::string& job_title,
    const std::string& academic_degree,
    const std::string& speciality, 
    const std::vector<std::string>& science_works)
{
    this->job_title = job_title;
    this->academic_degree = academic_degree;
    this->speciality = speciality;
    this->science_works = science_works;
}


// Реализация класса "Член комиссии"
CommissionMember::CommissionMember()
{
    commission_name = "Undefined commision name";
    appointment_year = "Undefined appointment year";
    certificate_number = "Undefined certificate number";
}

CommissionMember::CommissionMember(
    const std::string& commission_name, 
    const std::string& appointment_year, 
    const std::string& certificate_number,
    const std::vector<std::string>& biography) 
{
    this->commission_name = commission_name;
    this->appointment_year = appointment_year;
    this->certificate_number = certificate_number;
    this->biography = biography;
}



// Реализация класса "Преподаватели – члены комиссии"
TeacherCommissionMember::TeacherCommissionMember(const std::vector<std::string> commission_works) {
    this->commission_works = commission_works;
}