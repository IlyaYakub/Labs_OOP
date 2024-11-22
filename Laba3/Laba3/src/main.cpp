#include "Classes.h"
#include <iostream>
#include <vector>

void printHumanInfo(const Human& human) {
    std::cout << "Человек:\n";
    std::cout << "\tИмя: " << human.getName() << "\n";
    std::cout << "\tФамилия: " << human.getSurname() << "\n";
    std::cout << "\tОтчество: " << human.getPatronomic() << "\n";
    std::cout << "\tГод рождения: " << human.getBirthYear() << "\n";
}

void printTeacherInfo(const TeacherUniversity& teacher) {
    std::cout << "Преподаватель университета:\n";
    std::cout << "\tДолжность: " << teacher.getJobTitle() << "\n";
    std::cout << "\tУчёная степень: " << teacher.getAcademicDegree() << "\n";
    std::cout << "\tСпециальность: " << teacher.getSpeciality() << "\n";
    std::cout << "\tНаучные работы:\n";
    for (const auto& work : teacher.getScienceWorks()) {
        std::cout << "\t\t- " << work << "\n";
    }
}

void printCommissionMemberInfo(const CommissionMember& member) {
    std::cout << "Член комиссии:\n";
    std::cout << "\tНазвание комиссии: " << member.getCommissionName() << "\n";
    std::cout << "\tГод назначения: " << member.getAppointmentYear() << "\n";
    std::cout << "\tНомер свидетельства: " << member.getCertificateNumber() << "\n";
    std::cout << "\tБиография:\n";
    for (const auto& bio : member.getBiography()) {
        std::cout << "\t\t- " << bio << "\n";
    }
}

void printTeacherCommissionMemberInfo(const TeacherCommissionMember& teacherMember) {
    std::cout << "Преподаватель - член комиссии:\n";
    std::cout << "\tДолжность: " << teacherMember.getJobTitle() << "\n";
    std::cout << "\tУчёная степень: " << teacherMember.getAcademicDegree() << "\n";
    std::cout << "\tСпециальность: " << teacherMember.getSpeciality() << "\n";
    std::cout << "\tНаучные работы:\n";
    for (const auto& work : teacherMember.getScienceWorks()) {
        std::cout << "\t\t- " << work << "\n";
    }
    std::cout << "\tРаботы в комиссии:\n";
    for (const auto& work : teacherMember.getCommissionWorks()) {
        std::cout << "\t\t- " << work << "\n";
    }
}

int main() {
    setlocale(0, "");

    Human human1("Иван", "Иванов", "Иванович", "1980");
    Human human2("Мария", "Петрова", "Александровна", "1990");

    std::cout << "Информация о людях:\n";
    printHumanInfo(human1);
    printHumanInfo(human2);

    //Изменение данных объекта Human
    human1.setName("Иван");
    human1.setSurname("Сидоров");
    std::cout << "\nОбновленная информация о человеке 1:\n";
    printHumanInfo(human1);


    //Создание объектов класса TeacherUniversity
    std::vector<std::string> scienceWorks = { "Научная работа 1", "Научная работа 2" };
    TeacherUniversity teacher("Профессор", "Доктор наук", "Информатика", scienceWorks);

    std::cout << "\nИнформация о преподавателе:\n";
    printTeacherInfo(teacher);


    // Создание объектов класса CommissionMember
    std::vector<std::string> biography = { "Родился в 1980", "Закончил университет в 2000" };
    CommissionMember member("Приёмная комиссия", "2022", "123456", biography);

    std::cout << "\nИнформация о члене комиссии:\n";
    printCommissionMemberInfo(member);


    // Создание объектов класса TeacherCommissionMember
    std::vector<std::string> commissionWorks = { "Работа в комиссии 1", "Работа в комиссии 2" };
    TeacherCommissionMember teacherMember(commissionWorks);

    std::cout << "\nИнформация о преподавателе - члене комиссии:\n";
    printTeacherCommissionMemberInfo(teacherMember);

    return 0;
}
