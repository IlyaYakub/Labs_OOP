#include "Classes.h"

// Реализация класса "Человек"
Human::Human()
{
    name = "";
    surname = "";
    patronomic = "";
    birth_year = "";
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
    job_title = "";
    academic_degree = "";
    speciality = "";
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
TeacherCommissionMember::TeacherCommissionMember(
    const std::string& job_title,          const std::string& academic_degree, 
    const std::string& speciality,         const std::vector<std::string>& science_works,
    const std::string& commission_name,    const std::string& appointment_year,
    const std::string& certificate_number, const std::vector<std::string>& biography,
    const std::vector<std::string>& commission_works)
{
    this->job_title = job_title;
    this->academic_degree = academic_degree;
    this->speciality = speciality;
    this->science_works = science_works;
    this->commission_name = commission_name;
    this->appointment_year = appointment_year;
    this->certificate_number = certificate_number;
    this->biography = biography;
    this->commission_works = commission_works;
}
