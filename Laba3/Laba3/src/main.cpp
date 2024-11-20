//Реализовать класс «Человек», включающий в себя фамилию, имя,
//отчество, год рождения и методы, позволяющие изменять / получать значения
//этих полей.
//Реализовать следующие производные классы :
//− «Преподаватель университета» с полями : должность, ученая степень,
//специальность, список научных трудов(массив строк);
//− «Член комиссии» с полями : название комиссии, год назначения в
//комиссию, номер свидетельства, автобиография(массив строк);
//− «Преподаватели – члены комиссии»(производный от первого и
//    второго класса).Дополнительное поле – список работ, выполненных в
//    комиссии.
//    Классы должны содержать методы доступа и изменения всех полей.


#include "Classes.h"
#include <iostream>
#include <vector>


void printHumanInfo(const Human& human) {
    std::cout << "Человек: \n";
    std::cout << "\tИмя: " << human.getName() << "\n";
    std::cout << "\tФамилия: " << human.getSurname() << "\n";
    std::cout << "\tОтчество: " << human.getPatronomic() << "\n";
    std::cout << "\tГод рождения: " << human.getBirthYear() << "\n\n";
}

void printTeacherInfo(const TeacherUniversity& teacher) {
    std::cout << "Преподаватель университета: \n";
    std::cout << "\tДолжность: " << teacher.getJobTitle() << "\n";
    std::cout << "\tУчёная степень: " << teacher.getAcademicDegree() << "\n";
    std::cout << "\tСпециальность: " << teacher.getSpeciality() << "\n";
    std::cout << "\tНаучные работы: \n\n";
    for (const auto& work : teacher.getScienceWorks()) {
        std::cout << "\t\t- " << work << "\n";
    }
}

void printCommissionMemberInfo(const CommissionMember& member) {
    std::cout << "\nЧлен комиссии: \n";
    std::cout << "\tНазвание комиссии: " << member.getCommissionName() << "\n";
    std::cout << "\tГод назначения: " << member.getAppointmentYear() << "\n";
    std::cout << "\tНомер свидетельства: " << member.getCertificateNumber() << "\n";
    std::cout << "\tБиография: \n\n";
    for (const auto& bio : member.getBiography()) {
        std::cout << "\t\t- " << bio << "\n";
    }
}

void printTeacherCommissionMemberInfo(const TeacherCommissionMember& teacherMember) {
    std::cout << "\nПреподаватель - член комиссии: \n";
    std::cout << "\tДолжность: " << teacherMember.getJobTitle() << "\n";
    std::cout << "\tУчёная степень: " << teacherMember.getAcademicDegree() << "\n";
    std::cout << "\tСпециальность: " << teacherMember.getSpeciality() << "\n";
    std::cout << "\tНаучные работы: \n\n";
    for (const auto& work : teacherMember.getScienceWorks()) {
        std::cout << "\t\t- " << work << "\n";
    }
    std::cout << "\tРаботы в комиссии: \n";
    for (const auto& work : teacherMember.getCommissionWorks()) {
        std::cout << "\t\t- " << work << "\n";
    }
}


int main() {
    setlocale(0, "");

    // Создание объектов класса Human
    Human human1("Иван", "Иванов", "Иванович", "1980");
    Human human2("Мария", "Петрова", "Александровна", "1990");

    printHumanInfo(human1);
    printHumanInfo(human2);


    // Изменение данных объекта Human
    human1.setName("Иван");
    human1.setSurname("Сидоров");
    std::cout << "\nОбновленный Человек 1:\n";
    printHumanInfo(human1);


    // Создание объектов класса TeacherUniversity
    std::vector<std::string> scienceWorks = { "Научная работа 1", "Научная работа 2" };
    TeacherUniversity teacher("Профессор", "Доктор наук", "Информатика", scienceWorks);

    printTeacherInfo(teacher);


    // Создание объектов класса CommissionMember
    std::vector<std::string> biography = { "Родился в 1980", "Закончил университет в 2000" };
    CommissionMember member("Приёмная комиссия", "2022", "123456", biography);

    printCommissionMemberInfo(member);


    // Создание объектов класса TeacherCommissionMember
    std::vector<std::string> commissionWorks = { "Работа в комиссии 1", "Работа в комиссии 2" };
    TeacherCommissionMember teacherMember("Доцент", "Кандидат наук", "Математика",
                                           scienceWorks, "Аттестационная комиссия", "2023",
                                          "654321", biography, commissionWorks);

    printTeacherCommissionMemberInfo(teacherMember);

    // Проверка работы сеттеров и геттеров в дочернем
    member.setName("ilya");
    std::cout << member.getName();

    return 0;
}
