#pragma once

#include <string>
#include <iostream>
#include <vector>

// Класс "Человек"
class Human {
public:
    Human();
    Human(const std::string& name, 
          const std::string& surname, 
          const std::string& patronomic,
          const std::string& birth_year);

    Human(const Human& human) = default;
    virtual ~Human() = default;

    const std::string& getName()       const { return name;       }
    const std::string& getSurname()    const { return surname;    }
    const std::string& getPatronomic() const { return patronomic; }
    const std::string& getBirthYear()  const { return birth_year; }

    void setName(const std::string& name)             { this->name = name;             }
    void setSurname(const std::string& surname)       { this->surname = surname;       }
    void setPatronomic(const std::string& patronomic) { this->patronomic = patronomic; }
    void setBirthYear(const std::string& birth_year)  { this->birth_year = birth_year; }

protected:
    std::string name;
    std::string surname;
    std::string patronomic;
    std::string birth_year;
};

// Класс "Преподаватель университета"
class TeacherUniversity : public Human {
public:
    TeacherUniversity();
    TeacherUniversity(
        const std::string& job_title,
        const std::string& academic_degree, 
        const std::string& speciality,
        const std::vector<std::string>& science_works);

    TeacherUniversity(const TeacherUniversity& teacher) = default;
    ~TeacherUniversity() = default;

    const std::string& getJobTitle()                  const { return job_title; }
    const std::string& getAcademicDegree()            const { return academic_degree; }
    const std::string& getSpeciality()                const { return speciality; }
    const std::vector<std::string>& getScienceWorks() const { return science_works; }

    void setJobTitle(const std::string& job_title)                      { this->job_title = job_title;             }
    void setAcademicDegree(const std::string& academic_degree)          { this->academic_degree = academic_degree; }
    void setSpeciality(const std::string& speciality)                   { this->speciality = speciality;           }
    void setScienceWorks(const std::vector<std::string>& science_works) { this->science_works = science_works;     }

protected:
    std::string job_title;
    std::string academic_degree;
    std::string speciality;
    std::vector<std::string> science_works;
};

// Класс "Член комиссии"
class CommissionMember : virtual public Human {
public:
    CommissionMember() = default;
    CommissionMember(
        const std::string& commission_name,
        const std::string& appointment_year,
        const std::string& certificate_number,
        const std::vector<std::string>& biography);

    CommissionMember(const CommissionMember& c_member) = default;
    ~CommissionMember() = default;

    const std::string& getCommissionName()         const { return commission_name;    }
    const std::string& getAppointmentYear()        const { return appointment_year;   }
    const std::string& getCertificateNumber()      const { return certificate_number; }
    const std::vector<std::string>& getBiography() const { return biography;          }

    void setCommissionName(const std::string& commission_name)       { this->commission_name = commission_name;       }
    void setAppointmentYear(const std::string& appointment_year)     { this->appointment_year = appointment_year;     }
    void setCertificateNumber(const std::string& certificate_number) { this->certificate_number = certificate_number; }
    void setBiography(const std::vector<std::string>& biography)     { this->biography = biography;                   }

protected:
    std::string commission_name;
    std::string appointment_year;
    std::string certificate_number;
    std::vector<std::string> biography;
};

// Класс "Преподаватели – члены комиссии"
class TeacherCommissionMember : public TeacherUniversity, public CommissionMember {
public:
    TeacherCommissionMember() = default;
    TeacherCommissionMember(const std::string& job_title,          const std::string& academic_degree, 
                            const std::string& speciality,         const std::vector<std::string>& science_works,
                            const std::string& commission_name,    const std::string& appointment_year, 
                            const std::string& certificate_number, const std::vector<std::string>& biography,
                            const std::vector<std::string>& commission_works);

    TeacherCommissionMember(const TeacherCommissionMember& tcm) = default;
    ~TeacherCommissionMember() = default;

    const std::vector<std::string>& getCommissionWorks() const { return commission_works; }
    void setCommissionWorks(const std::vector<std::string>& commission_works) { this->commission_works = commission_works; }

protected:
    std::vector<std::string> commission_works;
};
